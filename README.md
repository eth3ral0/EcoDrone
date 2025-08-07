<img width="1900" height="400" alt="Image" src="https://github.com/user-attachments/assets/e3a674ce-3668-499e-834d-9837164faf4b" />

# 🌱 EcoDrone – VTOL Hybrid Drone Project (Educational Purpose)

**EcoDrone** is an **educational project** developed as part of the **2025 Engineering Sciences Olympiad (Olympiades de Sciences de l'Ingénieur)**.

This GitHub repository focuses **only on the software and data acquisition aspects** of the project, as I was personally in charge of the **SIN (Information and Digital Systems)** domain.

> ⚠️ I do **not cover** the structural, aerodynamic or mechanical design of the aircraft, as they were handled by other team members in ITEC specialization.
> I apologize in advance for the lack of data, but I've tried to reconstruct our project as coherently as possible.

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
- **4x LiPo 3S battery (2600 to 3200 mAh)**
- **4x 30A ESC**
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

### 1. Current vs. PWM Pulse Width

Using the collected data, we established the relationship between **current (I)** and **PWM pulse width**.  
The best-fit model is a **quadratic regression** *(using ChatGPT)*: 

$$I = -7.399880 × 10⁻⁷ × PWM² + 2.824110 × 10⁻³ × PWM - 1.979421$$

This equation allows us to predict the **current consumption** based on the PWM signal.

<img width="998" height="663" alt="Image" src="https://github.com/user-attachments/assets/be4206ec-9201-466a-9b85-7148fdc51aaa" />

### 2. Power vs. PWM Pulse Width

The electric power was calculated using the formula:

$$P = U x I$$

Assuming a constant voltage **U**, we obtained the following **linear regression** to model power (W) as a function of PWM:

$$W = 0.007211 × PWM - 4.429927$$

<img width="901" height="604" alt="Image" src="https://github.com/user-attachments/assets/791dc512-ea41-4218-a118-d4faa1f529ea" />

### 3. RPM vs. PWM Pulse Width

We also analyzed the **rotational speed (RPM)** in relation to PWM. The resulting model is:

$$RPM = 18.106667 × PWM - 16202.666667$$

<img width="994" height="707" alt="Image" src="https://github.com/user-attachments/assets/7083b41b-9b6a-4a02-b16b-f1af37129991" />

### 4. RPM vs. Current (I)

To link **electrical consumption** to **mechanical behavior**, we derived the following polynomial equation:

$$RPM = -2.490250 × 10⁴ × I² + 4.898924 × 10⁴ × I - 9132.579$$

<img width="1364" height="915" alt="image" src="https://github.com/user-attachments/assets/ff346314-ef5d-49d8-9748-c6c58ded7a8f" />

### Conclusion of this study : 

*There is a pdf version (in french) [here](A2212_STUDY_(FR).pdf) of this study if you need it.*

This experiment helped characterize the **electrical and mechanical response** of the A2212 motor to varying PWM signals.  
We established equations for:
- **Current** as a function of PWM
- **Power** as a function of PWM
- **RPM** as a function of both PWM and Current

To improve precision in future experiments, we recommend using **four more accurate current sensors (0–0.9 A range)** to capture finer variations during motor tests.

## Real-Life Tests – Motor Control & Rotation System

After modeling the motor’s behavior, we moved on to testing it **physically** using Arduino.  
The tests were performed progressively to validate each component of the propulsion and transition system.

---

### 🔹 1. Test with a Single Motor

We began by testing a single brushless motor using:
- An **ESC (Electronic Speed Controller)**
- A **PWM signal** generated by Arduino
- A **manual ramp-up** to observe changes in speed and current

*Purpose:* validate PWM control and current logging on one motor safely.

⚡**1 brushless motor assembly simulation :**
<img width="1343" height="775" alt="image" src="https://github.com/user-attachments/assets/731c000b-0955-45d8-b9e2-eb3d01e5eb63" />
[sources](arduino.blaisepascal.fr/controler-un-moteur-brushless/)

📁 Code: 

```c++
#include <Servo.h>

Servo esc3;   

int val = 0;

void setup() {
   pinMode(3, OUTPUT);

   esc3.attach(3, 1000, 2000); 
   esc3.writeMicroseconds(1000);
   delay(2000);

   }

void loop() {

   esc3.write(100);
   delay(15);

   }
```

---

### 🔹 2. Test with 4 Motors Simultaneously

Once the single motor test was validated, we connected all **4 motors** and ESCs to simulate the **vertical takeoff (VTOL) configuration**.

We implemented:
- **Synchronized PWM output** to 4 ESCs
- Gradual increase in speed
- Observation of **power draw and stability**

⚠️ The setup was very powerful and required secure mounting during testing.

📁 Code: [`/code/test_4_motors.ino`](final_prog/final_prog.ino)

---

## Conclusion of this project

> SolidWork simulation of takeoff mode (quadrotor) : [here](https://github.com/user-attachments/assets/cc8a4fbf-887d-470e-b178-39e1f3d946ab)

> SolidWork simulation of leveling mode (bimotor) : [here](https://github.com/user-attachments/assets/95568220-fe7e-48d8-a944-b3fb4c063d3b)

> 3d Plane Screenshot : <img width="1182" height="820" alt="image" src="https://github.com/user-attachments/assets/89b64557-a9aa-4211-951a-ced54fe134c6" />


### Problems encountered :

- When we did our first tests, the motors worked individually, but when we connected the second brushless motor afterwards, the program stopped working and the motors stayed still instead of rotating. So after hours and hours of research x) We found that the problem was only due to the calibration of the brushless motors, so we integrated it into our program and everything works perfectly.
- During the brushless motor study, a simple wiring error caused us to burn out two current sensors. Because we found that we couldn't measure current and voltage simultaneously during the test.
- Batteries are discharged quickly because powerful motors consume electricity quickly.

### Conclusion :

Despite the technical problems encountered, this was a very rewarding project, given that I'm a high-school student, and it enabled me to put into practice the knowledge I'd acquired in previous years. It also taught me that small tools can create something impressive, and can serve as a strong argument for innovative solutions. 

### What I learned :

- Dare to take on new projects as long as you've got the basics, even if it's difficult, as long as you keep looking and keep trying, you'll always learn something.
- For my next projects, especially personal and at university, I'll try to document my tests and research as best I can, because when I was synthesizing this project, I realized how little information I had.
- Research electronic components in detail (datasheets), as minor errors can destroy the component or put your safety at risk.

📦 All ressources are available in the `/code/` directory with comments.

---

## 🛡 License

This project is under the **MIT License**.  
Feel free to reuse, adapt, or contribute — for educational purposes only.

## 💬 Disclaimer

I would like to thank my teachers, Mrs Louis, Mrs Peche and Mrs Cossart for their help and encouragement.
I would also like to thank my two best friends and colleagues on this project, Saboué and Julyne, without whom I would probably never have done this project.

This repository is part of a **high school educational project only**.  
The information shared here **does not represent a certified or deployable flight system**.  
All materials were created for learning, testing, and personal experimentation.

---

## 💌 Contact

If you'd like to learn more or contribute to the software/Arduino side, feel free to open an issue or send a message.  
✨ Made with care by Yass
