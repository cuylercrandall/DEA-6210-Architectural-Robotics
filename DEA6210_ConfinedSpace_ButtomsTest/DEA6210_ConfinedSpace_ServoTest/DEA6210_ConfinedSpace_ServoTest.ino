int contServoPin = 10;
int angServoPin = 9;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  //pinMode(contServoPin,OUTPUT);
  //pinMode(angServoPin,OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13,HIGH);
}


void loop() {
  analogWrite(contServoPin,0);
  analogWrite(angServoPin,0);
  delay(1000);
  analogWrite(contServoPin,30);
  analogWrite(angServoPin,30);
  delay(1000);
  analogWrite(contServoPin,60);
  analogWrite(angServoPin,60);
  delay(1000);
  analogWrite(contServoPin,90);
  analogWrite(angServoPin,90);
  delay(1000);
  analogWrite(contServoPin,120);
  analogWrite(angServoPin,120);
  delay(1000);
  analogWrite(contServoPin,150);
  analogWrite(angServoPin,150);
  delay(1000);
  analogWrite(contServoPin,180);
  analogWrite(angServoPin,180);
  delay(1000);
  analogWrite(contServoPin,210);
  analogWrite(angServoPin,210);
  delay(1000);
  analogWrite(contServoPin,240);
  analogWrite(angServoPin,240);
  delay(5000);
}