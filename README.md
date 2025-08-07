<img width="1900" height="400" alt="Image" src="https://github.com/user-attachments/assets/e3a674ce-3668-499e-834d-9837164faf4b" />

# 🌱 EcoDrone – VTOL Hybrid Drone Project (Educational Purpose)

**EcoDrone** is an **educational project** developed as part of the **2025 Engineering Sciences Olympiad (Olympiades de Sciences de l'Ingénieur)**.

This GitHub repository focuses **only on the software and data acquisition aspects** of the project, as I was personally in charge of the **SIN (Information and Digital Systems)** domain.

> ⚠️ I do **not cover** the structural, aerodynamic or mechanical design of the aircraft, as they were handled by other team members in ITEC specialization.

---

## 📌 Project Overview

EcoDrone is a **VTOL hybrid drone-airplane** capable of:
- **Vertical takeoff using 4 motors**
- Switching to **gliding mode using 2 motors** in cruise flight
- Logging and monitoring **current consumption** to study energy optimization

The context of the project was to think of a more energy-efficient and faster alternative in the field of delivery (pharmaceutical products, food, etc.).
The goal is to explore __innovative solutions__ to improve the **energy efficiency** of lightweight aerial systems by combining the **advantages of drones, helicopters, and airplanes**.

## 🧰 Prerequisite (SIN scope)

- The aircraft model we'll be using is **Krick Klemm L 25d E 1:7 kit** [link](https://www.r-models.eu/kits-a-construire/1151-avion-en-kit-klemm-l25d-e-lasercut-1859mm-krick-402579214391.html)

- **Arduino UNO** (data logging & sensor acquisition)
- **4x A2212 13T 1000Kv Brushless Motor**
- **2X SG90 9g Micro Servo**
- **ACS712** current sensor
- **DC0-25V** voltage sensor

### Tools/Softwares used

- **Arduino IDE** (C++)
- **digital laser tachometer**
- **multimeter**
- **SolidWork** (for the simulation)

## ❗Getting Started – Project Workflow

In this project, my role was to :
- Design the Arduino programs for the quadrotor vertical takeoff mode and the twin-engine horizontal glide mode.
- Study the energy consumption of these 2 operating modes

## 🔍 Study of the A2212 Brushless Motor
🎯 __Objective :__

This section presents the analysis of the **A2212 1000KV brushless motor** behavior based on the **PWM pulse width** applied via Arduino.  
The study aims to model the **current**, **power**, and **RPM** responses to help optimize energy use in our hybrid drone system.

## 1. 📈 Current vs. PWM Pulse Width

Using the collected data, we established the relationship between **current (I)** and **PWM pulse width**.  
The best-fit model is a **quadratic regression** *(using ChatGPT)*: 

$$I = -7.399880 × 10⁻⁷ × PWM² + 2.824110 × 10⁻³ × PWM - 1.979421$$




---

## 🛡 License

This project is under the **MIT License**.  
Feel free to reuse, adapt, or contribute — for educational purposes only.



## 💬 Disclaimer

This repository is part of a **high school educational project only**.  
The information shared here **does not represent a certified or deployable flight system**.  
All materials were created for learning, testing, and personal experimentation.

---

## 💌 Contact

If you'd like to learn more or contribute to the software/Arduino side, feel free to open an issue or send a message.  
✨ Made with care by Yass
