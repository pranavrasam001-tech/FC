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

| No. | Quantity | Comment | Designator | Footprint | Value | Manufacturer Part | Manufacturer | Supplier Part | Supplier | JLCPCB Price (USD) | LCSC Price (USD) | Line Total (USD) |
|---:|---:|---|---|---|---|---|---|---|---|---:|---:|---:|
| 1 | 1 | ESP32-DEVKIT-V1-30PIN | 2 | ESP32-DEVKITV1_ESP32-DEVKITV1 | — | — | — | — | — | — | — | 769.0059 |
| 2 | 8 | 171825-4 | IIC_RAIL_1, IIC_RAIL_2, IIC_RAIL_3, IIC_RAIL_4, MOT5ESC, MOT6ESC, MOT7ESC, MOT8ESC | HDR-TH_4P-P2.54-D1.0 | — | 171825-4 | TE Connectivity | C210162 | LCSC | 0.035 | — | 0.2800 |
| 3 | 1 | MPU6050 | M1 | MPU6050 | — | — | — | — | — | — | — | 769.0059 |
| 4 | 2 | 1 | RC_POW2, RX_TX2 | BERG2 | — | Berg2 | — | — | — | — | — | 769.0059 |
| 5 | 1 | BERG RAIL_6 RC receiver 6ch pwm | U2 | BERG_6 | — | — | — | — | — | — | — | 769.0059 |
| 6 | 1 | 300Ω | U3 | RES-TH_BD3.8-L10.3-P14.30-D0.7 | — | OF301JE | Ohmite | C3395810 | LCSC | 0.0632 | — | 0.0632 |
| 7 | 1 | 15400394A3590 | U4 | LED-TH_BD3.0-P2.54-RD-RED | — | 15400394A3590 | Würth | C5478689 | LCSC | 0.0586 | — | 0.0586 |

## PCB Fabrication Cost Estimate (JLCPCB)


| Item | Assumption | Low (USD) | High (USD) |
|---|---|---:|---:|
| Bare PCB (5 pcs) | 2 layers, ≤100 × 100 mm, 1.6 mm, HASL | $2.00 | $2.00 |
| Shipping to India | Express courier, varies by weight | $15.00 | $25.00 |
| Customs / GST (India) | Import charges | $3.00 | $6.00 |
| **Fabrication Total** | | **$20.00** | **$33.00** |
| | | | |
| Priced Components (from BOM sheet) | ESP32, MPU6050, BERG headers unpriced | $0.40 | $0.40 |
| **Grand Total (Fabrication + Priced Parts)** | | **$20.40** | **$33.40** |

### Pricing Summary

| Description | Amount (USD) |
|---|---:|
| Priced components subtotal | 0.4018 |

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
