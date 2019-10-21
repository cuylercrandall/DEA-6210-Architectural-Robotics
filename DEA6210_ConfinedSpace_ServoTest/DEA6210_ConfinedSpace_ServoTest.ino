#include <Servo.h>

int contServoPin = 10;
int angServoPin = 9;
Servo contServo;
Servo angServo;
int pos = 0;

void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // Initializes servo output pins
  contServo.attach(contServoPin);
  angServo.attach(angServoPin);

}


void loop() {

  // Angular servo positions: 22 and 158
  for (pos = 22; pos <= 158; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    angServo.write(pos);            // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(2000);
  for (pos = 158; pos >= 22; pos -= 1) { // goes from 180 degrees to 0 degrees
    angServo.write(pos);             // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(2000);
  
}
