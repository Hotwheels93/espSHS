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


## Pinout:


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
### Caution!### 
Your api_key in main_window.ino has to match the api_key in the PHP post script named "post-esp-data_window.php", otherwise the request will fail


**Step 3:** Upload PHP script to your destination server (i.e. Raspberry Pi)

**Step 4:** Create MySQL database structure

**Step 5:** Flash ESP8266 using the main_window.ino sketch

**Step 6:** Done! You can now check if the data in your db updates successfully. 


### Troubleshooting:###

**Database not updated**

1. Check the Wifi credentials supplied in the main_window.ino sketch
2. Check the URL to your PHP script in the main_window.ino sketch
3. Check that api_key matches in main_window.ino and post-esp-data_window.php
4. Check wiring in pinout of reed sensor

