#include <Servo.h>

int clockwise = A5;
int counterclockwise = A3;
int modeButtom = A4;
bool cwState = false;
bool ccwState = false;
bool modeState = false;
Servo contServo;
Servo angServo;
int pos1 = 22;
int pos2 = 160;;
int pos = pos1;


void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // Initializes pins to input/output and to needed values
  pinMode(clockwise, INPUT);
  pinMode(counterclockwise, INPUT);
  pinMode(modeButtom, INPUT);
  pinMode(A1,OUTPUT);
  digitalWrite(A1,HIGH);
  pinMode(A0,OUTPUT);
  digitalWrite(A0,LOW);

  // Initializes servo output pins (of the OSEPP Shield)
  contServo.attach(9);
  angServo.attach(10);

  //Initializes position of angular servo (watch your fingers!)
  angServo.write(pos1);
}

void loop() {
  
  // Read input pins
  for (int i=0; i<5; i++){
    cwState = cwState || (digitalRead(clockwise)==HIGH);
    ccwState = ccwState || (digitalRead(counterclockwise)==HIGH);
    modeState = modeState || (digitalRead(modeButtom)==HIGH);
    delay(5);
  }

  //Cont. Servo Values: Forward = 180, Reverse = 0, Stop = 90
  //Ang. Servo Values: 22 or 158 (only)
  
  if ((cwState && ccwState) || (!cwState && !ccwState)){
    // If both (or neither) directions, do nothing
    contServo.write(90); //Stops continuous servo

  } else if (!modeState) {
    //If the mode button is pressed, control angular servo
    contServo.write(90); //Stops continuous servo
    if (cwState && (pos < pos2)) {
      pos += 1;
      angServo.write(pos); 
      Serial.println("Rotating switcher cw");
    } 
    if (ccwState && (pos > pos1)) {
      pos -= 1;
      angServo.write(pos); 
      Serial.println("Rotating switcher ccw");
    } 
  } else if ((pos == pos1) || (pos == pos2)) {
    // If mode button isn't pressed, control the outer ring
    // ONLY IF ANGULAR SERVO IS IN CORRECT POSITION
    if (cwState) {
      contServo.write(180);
      Serial.println("Rotating ring cw");
    }
    if (ccwState) {
      contServo.write(0);
      Serial.println("Rotating ring ccw");
    }
  }
  
  // Reset pin states
  cwState = false;
  ccwState = false;
  modeState = false;

}
