# Bluetooth-Controlled Car System

This project is a **Bluetooth-Controlled Car System**, designed to control a car using a mobile app and Bluetooth connectivity. The system utilizes various hardware components and software to enable smooth and precise operation.

## Features
- **Bluetooth Control**: Operate the car using a mobile app via Bluetooth.
- **Motor Driver**: Control the car's forward, backward, left, and right movements.
- **Indicator Lights**: Blink left or right indicator lights during turns.

## Components
1. **Microcontroller**: Arduino or similar
2. **Bluetooth Module**: HC-05 or HC-06
3. **Motor Driver Pins**: ENA, ENB, IN1, IN2, IN3, IN4
4. **Indicator Lights**: LEFT_LIGHT, RIGHT_LIGHT
5. **Power Supply**: Battery pack

## How It Works
1. The user connects their smartphone to the car via a Bluetooth app.
2. Commands sent from the app control the car's movement (forward, backward, left, right).
3. The motor driver pins control the car's motors based on received commands.
4. Indicator lights blink during left or right turns.

## Software Setup
- **Programming Language**: C/C++ (Arduino IDE)

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/maanojneupaneweb/bluetooth-car-system.git
   ```
2. Open the project in Arduino IDE.
3. Upload the code to the microcontroller.

## Usage
1. Power on the system.
2. Pair your smartphone with the Bluetooth module.
3. Use the mobile app to control the car.
4. Monitor the LED screen for system information.

## Future Improvements
- Integrate a camera for real-time video streaming.
- Implement advanced obstacle detection and avoidance.
- Add a mobile app interface with more features.

## License
This project is licensed under the [MIT License](LICENSE).

---

Feel free to contribute and improve the system!
