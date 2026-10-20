#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <ESP32Servo.h>

Adafruit_MPU6050 mpu;

#define SDA_PIN 21
#define SCL_PIN 22

const int rcPins[6] = {23, 19, 18, 5, 17, 16};
const int escPins[4] = {25, 26, 27, 14};

Servo esc[4];

volatile uint32_t rcRiseTime[6] = {0};
volatile uint16_t rcPulse[6] = {0};
volatile uint32_t rcLastSignal[6] = {0};

portMUX_TYPE rcMux = portMUX_INITIALIZER_UNLOCKED;

bool sensorReady = false;

void IRAM_ATTR rcInterrupt0() { readRC(0); }
void IRAM_ATTR rcInterrupt1() { readRC(1); }
void IRAM_ATTR rcInterrupt2() { readRC(2); }
void IRAM_ATTR rcInterrupt3() { readRC(3); }
void IRAM_ATTR rcInterrupt4() { readRC(4); }
void IRAM_ATTR rcInterrupt5() { readRC(5); }

void IRAM_ATTR readRC(int channel) {
    uint32_t now = micros();

    if (digitalRead(rcPins[channel])) {
        rcRiseTime[channel] = now;
    } else {
        uint32_t width = now - rcRiseTime[channel];

        if (width >= 900 && width <= 2200) {
            portENTER_CRITICAL_ISR(&rcMux);
            rcPulse[channel] = width;
            rcLastSignal[channel] = now;
            portEXIT_CRITICAL_ISR(&rcMux);
        }
    }
}

void setup() {
    Serial.begin(115200);
    delay(1000);

    Serial.println("\nDrone Flight Controller - Bench Test");

    Wire.begin(SDA_PIN, SCL_PIN);

    if (mpu.begin()) {
        sensorReady = true;

        mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
        mpu.setGyroRange(MPU6050_RANGE_500_DEG);
        mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

        Serial.println("MPU6050 detected.");
    } else {
        Serial.println("ERROR: MPU6050 not detected.");
    }

    for (int i = 0; i < 6; i++) {
        pinMode(rcPins[i], INPUT);
    }

    attachInterrupt(digitalPinToInterrupt(rcPins[0]), rcInterrupt0, CHANGE);
    attachInterrupt(digitalPinToInterrupt(rcPins[1]), rcInterrupt1, CHANGE);
    attachInterrupt(digitalPinToInterrupt(rcPins[2]), rcInterrupt2, CHANGE);
    attachInterrupt(digitalPinToInterrupt(rcPins[3]), rcInterrupt3, CHANGE);
    attachInterrupt(digitalPinToInterrupt(rcPins[4]), rcInterrupt4, CHANGE);
    attachInterrupt(digitalPinToInterrupt(rcPins[5]), rcInterrupt5, CHANGE);

    ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);

    for (int i = 0; i < 4; i++) {
        esc[i].setPeriodHertz(50);
        esc[i].attach(escPins[i], 1000, 2000);
        esc[i].writeMicroseconds(1000);
    }

    Serial.println("ESC outputs initialized at minimum command.");
    Serial.println("Bench-test mode: no flight stabilization.");
}

void loop() {
    uint16_t channels[6];
    uint32_t lastSignal[6];

    portENTER_CRITICAL(&rcMux);
    for (int i = 0; i < 6; i++) {
        channels[i] = rcPulse[i];
        lastSignal[i] = rcLastSignal[i];
    }
    portEXIT_CRITICAL(&rcMux);

    uint32_t now = micros();
    bool receiverOK = true;

    for (int i = 0; i < 6; i++) {
        if (lastSignal[i] == 0 ||
            (uint32_t)(now - lastSignal[i]) > 100000) {
            receiverOK = false;
        }
    }

    for (int i = 0; i < 4; i++) {
        esc[i].writeMicroseconds(1000);
    }

    Serial.println("\n--- Flight Controller Status ---");

    Serial.print("Receiver: ");
    Serial.println(receiverOK ? "SIGNAL OK" : "SIGNAL LOST");

    for (int i = 0; i < 6; i++) {
        Serial.print("CH");
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(channels[i]);
        Serial.println(" us");
    }

    if (sensorReady) {
        sensors_event_t accel, gyro, temp;
        mpu.getEvent(&accel, &gyro, &temp);

        Serial.print("Accel (m/s^2): ");
        Serial.print(accel.acceleration.x);
        Serial.print(", ");
        Serial.print(accel.acceleration.y);
        Serial.print(", ");
        Serial.println(accel.acceleration.z);

        Serial.print("Gyro (rad/s): ");
        Serial.print(gyro.gyro.x);
        Serial.print(", ");
        Serial.print(gyro.gyro.y);
        Serial.print(", ");
        Serial.println(gyro.gyro.z);
    } else {
        Serial.println("Sensor unavailable.");
    }

    delay(250);
}
