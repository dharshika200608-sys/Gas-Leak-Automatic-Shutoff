# Gas Leak Automatic Shut-Off System

## Project
Gas Detection, Alert & Automatic Shut-Off System using ESP8266.

## Hardware Used
- NodeMCU 1.0 (ESP-12E Module) / ESP8266
- MQ-2 gas sensor
- Relay module
- Buzzer
- LED

## Working
1. MQ-2 senses the gas concentration.
2. ESP8266 reads the analog sensor value through A0.
3. The sensor value is compared with a threshold value.
4. If the value reaches or exceeds the threshold:
   - LED turns ON.
   - Buzzer turns ON.
   - Relay changes to the shut-off state.
5. If the value is below the threshold:
   - LED and buzzer remain OFF.
   - Relay remains in the normal state.

## Pin Mapping Used in the Project Code
| Component | ESP8266 Pin |
|---|---|
| MQ-2 Analog Output | A0 |
| LED | D3 / GPIO0 |
| Buzzer | D2 / GPIO4 |
| Relay | D1 / GPIO5 |

## Threshold
The code currently uses `460` as the starting threshold, matching the value visible in the original Arduino IDE photo. This value should be calibrated with the actual sensor and environment before real use.

## Code
See `Code/gas_leak_system.ino`.

## Images
Project photographs are stored in the `Images` folder.

## Important Safety Note
This repository is for an educational prototype. Do not connect the relay to mains electricity or a real gas-supply shut-off valve unless the complete hardware, isolation, ratings, enclosure, and safety design have been professionally verified.
