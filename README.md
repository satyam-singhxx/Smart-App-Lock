# Smart App Lock Project Readme

## Overview

Welcome to the Smart App Lock project! This project combines the power of a car door actuator, ESP32 microcontroller, Ubidots cloud platform, and a mobile app called Smart Lock to create a secure and intelligent locking system for various applications.

## Project Components

1. **Car Door Actuator:**
   - This component serves as the physical mechanism for locking and unlocking. It is commonly used in automotive applications for controlling door locks.

2. **ESP32 Microcontroller:**
   - The ESP32 acts as the brain of the system, handling the communication between the car door actuator, Ubidots cloud, and the mobile app.

3. **Ubidots Cloud Platform:**
   - Ubidots is a cloud-based IoT platform that facilitates real-time data monitoring and control. In this project, it helps to manage the state of the lock and provides a secure way to interact with the ESP32.

4. **Smart Lock Mobile App:**
   - The mobile app, named Smart Lock, serves as the user interface for interacting with the locking system. It allows users to remotely control the lock, receive status updates, and configure settings.

## Project Setup

### Hardware Connections:

- Connect the car door actuator to the ESP32 microcontroller following the manufacturer's guidelines.
- Ensure the ESP32 is connected to the internet, either through Wi-Fi or other available methods.
- Configure the ESP32 to communicate with Ubidots. Provide the necessary credentials and settings in the code.

### Ubidots Configuration:

- Create an account on the Ubidots platform (https://ubidots.com/).
- Set up a new device and create variables to represent the lock status (locked/unlocked) and any additional data you want to monitor.
- Obtain the Ubidots API key and device ID for integration with the ESP32 code.

### Mobile App Installation:

- Download and install the Smart Lock app from the respective app store on your mobile device (iOS/Android).

### Application Workflow:

1. The mobile app sends commands to the Ubidots cloud platform to control the lock.
2. The ESP32 microcontroller periodically checks the status on Ubidots and controls the car door actuator accordingly.
3. The car door actuator physically locks or unlocks the system.
4. The current status is updated in real-time on the Ubidots platform and reflected in the mobile app.

## Additional Contents

The project folder contains the following additional data:

### Screenshots

- [Link to Screenshots](https://github.com/satyam-singhxx/Smart-App-Lock/blob/main/App%20Screenchort.jpeg)
  - View screenshots of the Smart Lock mobile app to get a visual overview of its user interface.

### Smart Lock App

- [Smart Lock App](https://github.com/satyam-singhxx/Smart-App-Lock/blob/main/Smart%20Lock.apk)
  - The Smart Lock mobile app itself. Install it on your mobile device to interact with the locking system.

### Project Report

- [Project Report](https://github.com/satyam-singhxx/Smart-App-Lock/blob/main/project%20report.docx)
  - Find detailed information about the project, including a PowerPoint presentation (PPT), synopsis, and other project-related documents.

### ESP32 Sketch

- [ESP32 Sketch](https://github.com/satyam-singhxx/Smart-App-Lock/blob/main/LOCK_FINAL/LOCK_FINAL.ino)
  - The Arduino sketch for the ESP32 microcontroller. Use this code to program your ESP32 for the Smart App Lock project.

## Running the Project

1. Upload the provided ESP32 code to your microcontroller after configuring it with your Wi-Fi credentials and Ubidots API key.
2. Power up the system and ensure that the ESP32 is connected to the internet.
3. Open the Smart Lock mobile app and log in with your credentials.
4. Use the app to control the lock, monitor status, and configure settings.

## Troubleshooting

If you encounter any issues, please email me on satyam9430308305@gmail.com

## Acknowledgments

This project is made possible by the collaborative efforts of the open-source community and the following technologies:

- Car Door Actuator Manufacturer
- Espressif (ESP32)
- Ubidots IoT Platform
- Smart Lock Mobile App Developers

## License

This project is licensed under the [MIT License](LICENSE), allowing you to modify and distribute the code for your purposes. See the LICENSE file for details.
