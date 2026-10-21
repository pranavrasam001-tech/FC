# Drone Flight Controller PCB 

## About the Project

I designed this Drone Flight Controller PCB using EasyEDA to learn how a flight controller board is designed from scratch. The board uses an ESP32-based control section and includes connections for motor ESCs, power regulation, LEDs, and other external components.

Through this project, I explored how different electronic components are connected and arranged on a PCB for drone-related applications.

## Features

- ESP32-based control section
- Motor ESC connections
- Power input and voltage regulation
- LED indicators
- Connectors for external components
- Compact PCB layout
- Designed for drone-related projects

## Tools and Components Used

**Software:**
- EasyEDA

**Components:**
- ESP32
- Voltage regulator
- LEDs
- Resistors
- Capacitors
- Connectors
- Pin headers
- Motor ESC connections

## What I Did

- Researched the basic components needed for a drone flight controller.
- Created the circuit schematic in EasyEDA.
- Added the ESP32, power section, LEDs, resistors, capacitors, and connectors.
- Connected the components using wires and net labels.
- Checked component connections and values.
- Assigned footprints to the components.
- Converted the schematic into a PCB layout.
- Arranged the components to make the board layout organized.
- Routed the PCB tracks and reviewed the connections.
- Used the 3D view to check the overall board design.
- Generated Gerber and drill files for PCB manufacturing.

## PCB Design Preview

### 1. Circuit Schematic

The schematic shows how the different components are connected in the circuit.

![Circuit Schematic](https://github.com/user-attachments/assets/1abb1d07-9d4a-4ada-823b-18dbd84c535b)

### 2. PCB Layout

The PCB layout shows the component placement and routed tracks on the board.
<img width="878" height="606" alt="image" src="https://github.com/user-attachments/assets/6b202009-fef9-4590-954e-9a82eb8b9bb7" />




### 3. 3D PCB View

The 3D view helps visualize the overall board design and component arrangement.
<img width="902" height="642" alt="image" src="https://github.com/user-attachments/assets/c1c2ccff-2327-4175-ab30-4d58a3dc2c9f" />



## Applications

This design can serve as a starting point for learning and experimenting with:

- Small drone electronics
- Motor control projects
- RC-based projects
- DIY flight controller development
- PCB design and embedded electronics

**Note:** The board is a design project. Actual flight operation requires suitable firmware, hardware assembly, and testing to verify that the controller works correctly.

## What I Learned

Building this project helped me gain practical experience in PCB design and circuit development.

I learned how to:

- Research and select electronic components.
- Create circuit schematics in EasyEDA.
- Use net labels to organize circuit connections.
- Assign footprints to components.
- Arrange components on a PCB.
- Route PCB tracks.
- Review a design using the 3D viewer.
- Generate Gerber and drill files for manufacturing.

  ## Bill of Materials (BOM)

| Name | Designator | Quantity | Unit Price (USD) | Total Cost (USD) |
|---|---|---:|---:|---:|
| ESP32 DevKit V1 (30-pin) | 2 | 1 | 3.00 | 3.00 |
| 4-Pin Header | IIC_RAIL_1, IIC_RAIL_2, IIC_RAIL_3, IIC_RAIL_4, MOT5ESC, MOT7ESC, MOT8ESC | 7 | 0.233 | 1.631 |
| MPU6050 | M1 | 1 | 1.00 | 1.00 |
| 4-Pin Header | MOT6ESC | 1 | 0.233 | 0.233 |
| 2-Pin Connector | RC_POW2, RX_TX2 | 2 | 0.10 | 0.20 |
| 6-Pin Receiver Header | U2 | 1 | 0.34 | 0.34 |
| 300Ω Resistor | U3 | 1 | 0.396 | 0.396 |
| Red LED | U4 | 1 | 0.3832 | 0.3832 |
| **Total Component Cost** | | | | **7.1832** |

## Project Structure

```text
Drone-Flight-Controller-PCB/
│
├── Schematic/
├── PCB Layout/
├── Gerber Files/
├── Drill Files/
├── Images/
└── README.md
