# Smart Autonomous Rescue Robot

## 🚑 Project Description
The Smart Autonomous Rescue Robot is an advanced Arduino-based robotic system designed for rescue and safety operations in hazardous environments. It combines autonomous navigation, object detection, and environmental monitoring with remote control functionality.

---

## 🔥 Key Features
- Autonomous obstacle avoidance
- Human detection using PIR sensor
- Fire detection using flame sensor
- Gas leakage detection using MQ sensor
- Bluetooth remote control
- Intelligent decision-making logic
- Buzzer alerts for emergency situations

---

## 🧠 Modes of Operation
### Manual Mode
- Controlled via Bluetooth commands
- User decides movement direction

### Autonomous Mode
- Robot scans surroundings
- Detects obstacles
- Chooses safest path automatically

### Safety Mode
- Stops robot if danger detected
- Alerts user using buzzer and serial messages

---

## 🧩 Components Used
- Arduino UNO
- L298N Motor Driver
- Ultrasonic Sensor (HC-SR04)
- PIR Sensor
- Flame Sensor
- Gas Sensor (MQ-2)
- Servo Motor (SG90)
- Bluetooth Module (HC-05)
- Buzzer
- Robot chassis with DC motors

---

## 🔌 Pin Configuration
| Component | Arduino Pin |
|---------|-------------|
| Ultrasonic TRIG | 2 |
| Ultrasonic ECHO | 3 |
| Servo | 4 |
| ENA | 5 |
| ENB | 6 |
| Motor IN1-IN4 | 8–11 |
| PIR Sensor | 12 |
| Buzzer | 13 |
| Flame Sensor | A0 |
| Gas Sensor | A1 |

---

## 📱 Bluetooth Commands
| Command | Action |
|--------|-------|
| F | Forward |
| B | Backward |
| L | Left |
| R | Right |
| S | Stop |
| A | Autonomous Mode |
| M | Manual Mode |

---

## 🚀 Applications
- Disaster rescue operations
- Fire safety monitoring
- Industrial hazard inspection
- Robotics competitions
- Smart surveillance systems

---

## 🔮 Future Enhancements
- ESP32 camera integration
- IoT dashboard monitoring
- GPS tracking
- AI-based human recognition
- Voice command control

---

## 👨‍💻 Author
Achuthan Rameshkumar
# robot-emg
