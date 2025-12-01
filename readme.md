# Air Quality Monitor - IoT Project

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

An IoT-based Air Quality Monitoring System using ESP8266 NodeMCU that measures temperature, humidity, and air quality in real-time and displays data on the Blynk mobile app.

## 📋 Table of Contents
- [Problem Statement](#problem-statement)
- [Features](#features)
- [Components Required](#components-required)
- [Circuit Diagram](#circuit-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Results](#results)
- [Future Scope](#future-scope)
- [Contributors](#contributors)

## 🎯 Problem Statement

Indoor air quality affects health, comfort, and productivity. People cannot detect harmful gas levels or humidity/temperature changes. This project provides a low-cost, portable, real-time air monitoring solution.

## ✨ Features

- Real-time monitoring of temperature, humidity, and air quality
- Wi-Fi connectivity for remote access
- Data visualization on Blynk mobile app
- Serial monitor output for debugging
- Low-cost and portable design
- Easy to deploy in homes, schools, or offices

## 🔧 Components Required

| Component | Quantity | Description |
|-----------|----------|-------------|
| ESP8266 NodeMCU | 1 | Wi-Fi microcontroller |
| DHT11 | 1 | Temperature & humidity sensor |
| MQ135 | 1 | Air quality sensor (gases, pollution) |
| Jumper Wires | Several | For connections |
| USB Cable | 1 | For power and programming |
| Breadboard | 1 | Optional for prototyping |

## 📐 Circuit Diagram

### Pin Connections

**DHT11 Sensor:**
- VCC → 3.3V (NodeMCU)
- GND → GND
- DATA → D4 (GPIO2)

**MQ135 Sensor:**
- VCC → 3.3V
- GND → GND
- A0 → A0 (Analog pin)

![Circuit Diagram](circuit/circuit_diagram.png)

## 🚀 Installation

### Prerequisites

1. **Arduino IDE** (Download from [arduino.cc](https://www.arduino.cc/en/software))
2. **ESP8266 Board Package**
3. **Required Libraries:**
   - DHT sensor library
   - Blynk library
   - ESP8266WiFi library

### Step 1: Install Arduino IDE

Download and install Arduino IDE for your operating system.

### Step 2: Add ESP8266 Board to Arduino IDE

1. Open Arduino IDE
2. Go to **File → Preferences**
3. Add this URL to "Additional Board Manager URLs":
```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
```
4. Go to **Tools → Board → Boards Manager**
5. Search for "ESP8266" and install it

### Step 3: Install Required Libraries

1. Go to **Sketch → Include Library → Manage Libraries**
2. Search and install:
   - **DHT sensor library** by Adafruit
   - **Adafruit Unified Sensor**
   - **Blynk** by Volodymyr Shymanskyy

### Step 4: Setup Blynk App

1. Download **Blynk IoT** app (iOS/Android)
2. Create a new account
3. Create a new template/device
4. Add widgets:
   - Gauge widget for Temperature (Virtual Pin V1)
   - Gauge widget for Humidity (Virtual Pin V2)
   - Gauge widget for Air Quality (Virtual Pin V3)
5. Copy your **Auth Token**

### Step 5: Configure the Code

1. Open `code/air_quality_monitor.ino` in Arduino IDE
2. Update these lines with your credentials:
```cpp
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";
```

3. Select **Board**: NodeMCU 1.0 (ESP-12E Module)
4. Select correct **Port**
5. Click **Upload**

## 💻 Usage

1. Connect the ESP8266 to your computer via USB
2. Upload the code
3. Open **Serial Monitor** (115200 baud rate)
4. Device will connect to Wi-Fi and Blynk
5. Open Blynk app to view real-time data
6. Monitor air quality, temperature, and humidity

## 📊 Results

### Serial Monitor Output
- Real-time sensor readings
- Wi-Fi connection status
- Blynk connection status

### Blynk Dashboard
- Temperature display
- Humidity percentage
- Air Quality Index (AQI)

![Blynk Dashboard](images/blynk_dashboard.png)

## 🔮 Future Scope

- [ ] Add CO₂ sensor for better accuracy
- [ ] Add PM2.5 sensor for particulate matter detection
- [ ] Implement alarm/notifications for poor air quality
- [ ] Add battery power for portability
- [ ] Create dedicated mobile app
- [ ] Add data logging to SD card
- [ ] Implement machine learning for air quality prediction

## 🎓 Applications

- Home air quality monitoring
- Smart home automation
- School/office environment monitoring
- Indoor pollution detection
- Health and wellness tracking

## 🙏 Acknowledgments

- OpenWeather API for weather data references
- Blynk IoT platform for mobile app integration
- Arduino community for libraries and support


ESP8266 NodeMCU Pin Connections
================================

DHT11 Sensor:
- VCC → 3.3V
- GND → GND  
- DATA → D4 (GPIO2)

MQ135 Sensor:
- VCC → 3.3V (or 5V if available)
- GND → GND
- A0 → A0 (Analog Input)

Power:
- USB Cable to NodeMCU for power and programming

Blynk Virtual Pins:
- V1 → Temperature
- V2 → Humidity
- V3 → Air Quality Index
```

### **F. Required Libraries (`libraries/required_libraries.txt`)**
```
Required Arduino Libraries:
===========================

1. ESP8266WiFi (Built-in with ESP8266 board package)
2. BlynkSimpleEsp8266 (Install via Library Manager)
3. DHT sensor library by Adafruit (v1.4.x or higher)
4. Adafruit Unified Sensor (v1.1.x or higher)

Installation Instructions:
1. Open Arduino IDE
2. Go to Sketch → Include Library → Manage Libraries
3. Search for each library by name
4. Click "Install"
