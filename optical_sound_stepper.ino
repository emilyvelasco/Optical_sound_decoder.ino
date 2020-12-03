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
  int val = analogRead(A0); //reads pot value
  speed_value = abs(val-511); //sets the center position of the pot as 0 speed and the endstops as max speed
  direction_value = (val-511); //sets center position of pot as divider between positive and negative direction
  stepdelay = map(speed_value,512,0,1,500); //maps max speed_value to shortest step delay


  if ( direction_value > 0 && speed_value > 50) { //turns motor forward if direction_value is positive and speed_value is above 50
     digitalWrite(dirpin, HIGH);
     digitalWrite(steppin, HIGH);
     delayMicroseconds(stepdelay);
     digitalWrite(steppin, LOW);
  }
  else if (direction_value <= 0 && speed_value > 50) { //turns motor backward if direction_value is negative and speed_value is above 50
    digitalWrite(dirpin, LOW);
    digitalWrite(steppin, HIGH);
    delayMicroseconds(stepdelay);
    digitalWrite(steppin, LOW);
  }
 
}
 
