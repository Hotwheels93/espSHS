# espSHS

<h3 align="center">ESP8266 based Smart Home System</h3>

Developer: Martin Hocquel
Date: 12/2020


## Features:

- Window open/close status control via reed sensor
- Room temperature & humidity monitoring 
- GUI control panel running on Raspberry Pi


## Part list:

- ESP8266 with Analog Input
- Reed sensor
- BME280 sensor / DHT22
- Raspberry Pi 3B+ + 4,3" Touch Display


## Requirements:

1. Webserver with PHP support (see Apache and PHP setup for RPi)
2. MySQL database
3. WiFi


## Installation

### Step 1: Clone Repo
 
  ```sh
  git clone https://github.com/Hotwheels93/espSHS.git
  ```

### Step 2: Edit main_window.ino

Change Wifi credentials
  ```sh
  // Wifi credentials
const char* ssid     = "YourSSIDname";
const char* password = "YourWifiPassword!";
  ```

Change URL, api_key, sensorName and sensorLocation:
  ```sh

const char* serverName = "http://YOURHOSTADRESS.XYZ/post-esp-data_window.php";
String apiKeyValue = "YOURAPIKEY123456";

String sensorName = "ReedSensor";
String sensorLocation = "Room_1";

  ```

