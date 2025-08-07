#include <Servo.h>

Servo escGA; //Front Left
Servo escDA; //Front Right
Servo escGD; //Rear Left
Servo escDD; //Rear Right

Servo servoG; //Left Servo
Servo servoD; //Right Servo

String command;

void setup() {
  Serial.begin(9600);
  escGA.attach(3);
  escGA.attach(9);
  escGA.attach(5);
  escGA.attach(10);

  servoG.attach(6);
  servoD.attach(11);

  delay(15);
  // Initialization of servos' positions
  servoG.write(90);
  servoD.write(90);

  Serial.println("Enter desired operating mode");
  Serial.println("'depart' or 'vol'");
}

void loop() {
  delay(3000);
  calibrage();
  {
    if (Serial.available())
    {
      command = Serial.readStringUntil('\n');
    }
    if (command == "depart")
    {
      depart();
    }
    else if (command == "vol")
    {
      vol();
    }
    command = "";
  }
}

void calibrage() {
  //Calibration of Front Left (GA)
  escGA.write(0);
  delay(1000);
  escGA.write(180);
  delay(1000);
  escGA.write(0);

  //Calibration of Front Right (DA)
  escDA.write(0);
  delay(1000);
  escDA.write(180);
  delay(1000);
  escDA.write(0);

  //Calibration of Rear Left (GD)
  escGD.write(0);
  delay(1000);
  escGD.write(180);
  delay(1000);
  escGD.write(0);

  //Calibration of Rear Right (DD)
  escDD.write(0);
  delay(1000);
  escDD.write(180);
  delay(1000);
  escDD.write(0);
  
  Serial.println("Calibration complete!");
}

void depart() {
  //Position of servos (takeoff mode)
  servoG.write(45);
  servoD.write(45);
  //All four motors stay on
  escGA.write(135);
  escDA.write(135);
  escGD.write(135);
  escDD.write(135);
}

void vol() {
  //Position of servos (flight mode)
  servoG.write(90);
  servoD.write(90);
  //Only front motors stay on
  escGA.write(135);
  escDA.write(135);
  //Rear motors are turned off
  escGD.write(0);
  escDD.write(0);
}
