# Conveyor Belt Product Counter with GSM Alert

An embedded system that counts products on a conveyor belt, stops the belt when a target count is reached, and sends an SMS alert. An emergency switch stops the belt immediately and sends an alert too.

## Features
- Set the target count with a 4x4 keypad
- Automatic product counting with an IR sensor
- Live target and count shown on a 16x2 LCD
- Conveyor motor driven through an L293D motor driver
- SMS alert through a GSM module when the target is reached
- Emergency stop using an external interrupt (EINT0), which also sends an SMS# Conveyor Belt Product Counter with GSM Alert

An embedded system that counts products on a conveyor belt, stops the belt when a target count is reached, and sends an SMS alert. An emergency switch stops the belt immediately and sends an alert too.

## Features
- Set the target count with a 4x4 keypad
- Automatic product counting with an IR sensor
- Live target and count shown on a 16x2 LCD
- Conveyor motor driven through an L293D motor driver
- SMS alert through a GSM module when the target is reached
- Emergency stop using an external interrupt (EINT0), which also sends an SMS
- Restarts automatically and asks for a new target after each run

## Hardware
| Component | Purpose |
|---|---|
| LPC2129 ARM7 board | Main controller |
| 4x4 keypad | Enter the target |
| IR sensor | Detect products |
| 16x2 LCD | Display status |
| L293D + DC motor | Conveyor drive |
| GSM module (SIM800/SIM900) + SIM | Send SMS |
| Push button | Emergency stop |

## Pin connections
| Function | Pin |
|---|---|
| Keypad columns | P1.23 to P1.26 |
| Keypad rows | P1.27 to P1.30 |
| IR sensor | P0.4 |
| Motor (L293D input 1A) | P0.10 |
| Emergency switch (EINT0) | P0.16 |
| GSM TX / RX | P0.1 (RXD0) / P0.0 (TXD0) |
| LCD | 17 18 19 20 21 22 23 24|

## How it works
1. At power on, the LCD shows the project title, then "ENTER TARGET".
2. The user types the target digit on the keypad and presses `#`.
3. The motor starts and the LCD shows `Target:X` and `Count:0`.
4. Each time the IR sensor detects a product, the count increases and the LCD updates.
5. When the count equals the target:
   - the motor stops
   - the LCD shows "TARGET REACHED"
   - an SMS "Target reached. Conveyor stopped." is sent
   - after a short delay the system returns to step 1
6. If the emergency switch is pressed at any time, the motor stops, the LCD shows "EMERGENCY SITUATION", an SMS is sent, and the system halts until it is reset.

## Software
- Language: Embedded C
- IDE: Keil uVision4
- Files:
  - `mini_project1.c`: main program
  - `lcdleaderfile.h`: LCD functions
  - `keypad.h`: keypad scanning
  - `uart.h`: UART0 driver
  - `gsm.h`: GSM AT commands (`GSM_INIT`, `GSM_SMS`)
  - `external_interrupt.h`: emergency interrupt (EINT0)
  - `delay_header.h`: delay function

## How to run
1. Open the project in Keil uVision4 and build it (0 errors expected).
2. Connect the hardware as in the pin table and block diagram.
3. Insert a SIM with balance and set your phone number in `gsm.h`.
4. Flash the `.hex` file to the board with Flash Magic.
5. Power on, enter the target, and press `#`.

## Limitations and future work
- The target is a single digit (1 to 9)
- Add multi-digit targets
- Add a reset or restart key after an emergency
- Add a buzzer or LED indicator
- Restarts automatically and asks for a new target after each run

## Hardware
| Component | Purpose |
| LPC2129 ARM7 board | Main controller |
| 4x4 keypad | Enter the target |
| IR sensor | Detect products |
| 16x2 LCD | Display status |
| L293D + DC motor | Conveyor drive |
| GSM module (SIM800/SIM900) + SIM | Send SMS |
| Push button | Emergency stop |

## Pin connections
| Function | Pin |
| Keypad columns | P1.23 to P1.26 |
| Keypad rows | P1.27 to P1.30 |
| IR sensor | P0.4 |
| Motor (L293D input 1A) | P0.10 |
| Emergency switch (EINT0) | P0.16 |
| GSM TX / RX | P0.1 (RXD0) / P0.0 (TXD0) |
| LCD | 17 18 19 20 21 22 23 24 |

## How it works
1. At power on, the LCD shows the project title, then "ENTER TARGET".
2. The user types the target digit on the keypad and presses `#`.
3. The motor starts and the LCD shows `Target:X` and `Count:0`.
4. Each time the IR sensor detects a product, the count increases and the LCD updates.
5. When the count equals the target:
   - the motor stops
   - the LCD shows "TARGET REACHED"
   - an SMS "Target reached. Conveyor stopped." is sent
   - after a short delay the system returns to step 1
6. If the emergency switch is pressed at any time, the motor stops, the LCD shows "EMERGENCY SITUATION", an SMS is sent, and the system halts until it is reset.

## Software
- Language: Embedded C
- IDE: Keil uVision4
- Files:
  - mini_project1.c: main program
  - lcdleaderfile.h: LCD functions
  - keypad.h: keypad scanning
  - uart.h: UART0 driver
  - gsm.h: GSM AT commands (GSM_INIT, GSM_SMS)
  - external_interrupt.h: emergency interrupt (EINT0)
  - delay_header.h: delay function

## How to run
1. Open the project in Keil uVision4 and build it (0 errors expected).
2. Connect the hardware as in the pin table and block diagram.
3. Insert a SIM with balance and set your phone number in `gsm.h`.
4. Flash the `.hex` file to the board with Flash Magic.
5. Power on, enter the target, and press `#`
