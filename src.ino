#include <Servo.h>          //Servo motor library. This is standard library
#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library

//our L298N control pins
const int LeftMotorForward = 7;
const int LeftMotorBackward = 6;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;

//sensor pins
#define trig_pin A3 //analog input 1
#define echo_pin A4 //analog input 2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor; //our servo name

int lookRight(){
  Serial.println("Look right!");  
  servo_motor.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}

int lookLeft(){
  Serial.println("Look left!");
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  Serial.println("STop!");
  digitalWrite(RightMotorForward, 0);
  digitalWrite(LeftMotorForward, 0);
  digitalWrite(RightMotorBackward, 0);
  digitalWrite(LeftMotorBackward, 0);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;

    Serial.println("Move forward!");
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorBackward, LOW);
    digitalWrite(LeftMotorBackward, LOW);
    delay(10);
}}

void moveBackward(){

  goesForward=false;

  Serial.println("Move backward!");
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
	digitalWrite(RightMotorForward, LOW);

}

void turnRight(){

  Serial.println("Turn right!");
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);

//  analogWrite(RightMotorForward, 0);
//  analogWrite(LeftMotorForward, 200);
//  analogWrite(RightMotorBackward, 0);
//  analogWrite(LeftMotorBackward, 0);
  
  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);

//analogWrite(RightMotorForward, 200);
//analogWrite(LeftMotorForward, 200);
//analogWrite(RightMotorBackward, 0);
//analogWrite(LeftMotorBackward, 0);
 
  
  
}

void turnLeft(){

  Serial.println("Turn left!");
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

//  analogWrite(RightMotorForward, 200);
//  analogWrite(LeftMotorForward, 0);
//  analogWrite(RightMotorBackward, 0);
//  analogWrite(LeftMotorBackward, 0);

  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);

//analogWrite(RightMotorForward, 200);
//analogWrite(LeftMotorForward, 200);
//analogWrite(RightMotorBackward, 0);
//analogWrite(LeftMotorBackward, 0);
}

void setup(){
  Serial.begin(9600);
  
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  servo_motor.attach(9); //our servo pin

  servo_motor.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
	distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop(){

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  Serial.println("Distance: "); Serial.println(distance);
  
  
  if (distance <= 20){
    moveStop();
    delay(100);
    moveBackward();
    delay(100);
    moveStop();
    delay(100);
    distanceRight = lookRight();
    Serial.println("Right distance: "); Serial.print(distanceRight);
    delay(100);
    distanceLeft = lookLeft();
    Serial.println("Distance left: "); Serial.print(distanceLeft);
    delay(100);

    if (distance >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
  }
    distance = readPing();
}
```
