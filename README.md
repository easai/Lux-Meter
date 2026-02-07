# Lux Meter

<img src="https://github.com/easai/Lux-Meter/blob/main/images/IMG_2940.jpeg" width="300" alt="Lux Meter"/>

## Overview
This project measures ambient light using a VEML7700 digital light sensor connected to an ESP32 C3 SuperMini. The measured light level is shown on a 128x64 SSD1306 OLED display. Both devices share the same I2C bus and operate at 3.3 V.

## Features
• Reads ambient light using the VEML7700  
• Displays integer lux values on the SSD1306 OLED  
• Uses the ESP32 C3 SuperMini I2C pins  
• Designed for PlatformIO with Arduino framework  
• Supports separate environments for firmware and testing  

## Pin Configuration

<img src="https://github.com/easai/Lux-Meter/blob/main/images/IMG_2946.jpeg" width="300" alt="Lux Meer internal layout" />

### ESP32 C3 SuperMini to VEML7700
| ESP32 C3 Pin | VEML7700 Pin |
|--------------|--------------|
| 3V3          | 3V3          |
| GND          | GND          |
| GPIO 8       | SDA          |
| GPIO 9       | SCL          |

### ESP32 C3 SuperMini to SSD1306 OLED
| ESP32 C3 Pin | SSD1306 Pin |
|--------------|-------------|
| 3V3          | VCC         |
| GND          | GND         |
| GPIO 8       | SDA         |
| GPIO 9       | SCL         |

## I2C Addresses
| Device        | Address |
|---------------|---------|
| SSD1306 OLED  | 0x3C    |
| VEML7700      | 0x10    |

## Display Layout

<img src="https://github.com/easai/Lux-Meter/blob/main/images/IMG_2945.jpeg" width="300" alt="Lux Meter in operation" />

The OLED shows a small LUX label at the top and a large integer lux value below it.


