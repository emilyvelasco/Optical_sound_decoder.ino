int steppin = 3;
int dirpin = 2;
int stepdelay;
int speed_value;
int direction_value;
void setup() {
  pinMode(steppin, OUTPUT);
  pinMode(dirpin, OUTPUT);
  digitalWrite(dirpin, LOW); // direction pin either LOW or HIGH to move in either direction.
  Serial.begin(115200);
}
 
void loop() {
  int val = analogRead(A0);
  speed_value = abs(val-511);
  direction_value = (val-511);
  stepdelay = map(speed_value,512,0,1,500);


  if ( direction_value > 0 && speed_value > 50) {
     digitalWrite(dirpin, HIGH);
     digitalWrite(steppin, HIGH);
     delayMicroseconds(stepdelay);
     digitalWrite(steppin, LOW);
  }
  else if (direction_value <= 0 && speed_value > 50) {
    digitalWrite(dirpin, LOW);
    digitalWrite(steppin, HIGH);
    delayMicroseconds(stepdelay);
    digitalWrite(steppin, LOW);
  }
 
}
 
