int steppin = 3;
int dirpin = 2;
int stepdelay;
int speed_value;
int direction_value;
int forward_led = 4;
int pause_led = 5;
int reverse_led = 12;

void setup() {
  pinMode(forward_led, OUTPUT);
  pinMode(pause_led, OUTPUT);
  pinMode(reverse_led, OUTPUT);
  pinMode(steppin, OUTPUT);
  pinMode(dirpin, OUTPUT);
  digitalWrite(dirpin, LOW); // direction pin either LOW or HIGH to move in either direction.
  digitalWrite(forward_led, LOW);
  digitalWrite(pause_led, LOW);
  digitalWrite(reverse_led, LOW);
  delay(400);
  digitalWrite(forward_led, HIGH);
  digitalWrite(pause_led, LOW);
  digitalWrite(reverse_led, LOW); 
  delay(400);
  digitalWrite(forward_led, LOW);
  digitalWrite(pause_led, HIGH);
  digitalWrite(reverse_led, LOW);
  delay(400);
  digitalWrite(forward_led, LOW);
  digitalWrite(pause_led, LOW);
  digitalWrite(reverse_led, HIGH); 
  delay(400);
  digitalWrite(forward_led, LOW);
  digitalWrite(pause_led, HIGH);
  digitalWrite(reverse_led, LOW); 
  delay(400);
  digitalWrite(forward_led, HIGH);
  digitalWrite(pause_led, LOW);
  digitalWrite(reverse_led, LOW);
  delay(400);
  digitalWrite(forward_led, LOW);
  digitalWrite(pause_led, HIGH);
  digitalWrite(reverse_led, LOW);
  delay(400);
  digitalWrite(forward_led, LOW);
  digitalWrite(pause_led, LOW);
  digitalWrite(reverse_led, HIGH); 
  delay(400);
  digitalWrite(forward_led, LOW);
  digitalWrite(pause_led, HIGH);
  digitalWrite(reverse_led, LOW); 
  delay(400);
  digitalWrite(forward_led, HIGH);
  digitalWrite(pause_led, LOW);
  digitalWrite(reverse_led, LOW);
  delay(400);
  digitalWrite(forward_led, LOW);
  digitalWrite(pause_led, LOW);
  digitalWrite(reverse_led, LOW);
  delay(100);
  digitalWrite(forward_led, HIGH);
  digitalWrite(pause_led, HIGH);
  digitalWrite(reverse_led, HIGH);
  delay(100);
    digitalWrite(forward_led, LOW);
  digitalWrite(pause_led, LOW);
  digitalWrite(reverse_led, LOW);
  delay(100);
  digitalWrite(forward_led, HIGH);
  digitalWrite(pause_led, HIGH);
  digitalWrite(reverse_led, HIGH);
  delay(100);
  digitalWrite(forward_led, LOW);
  digitalWrite(pause_led, LOW);
  digitalWrite(reverse_led, LOW);
  delay(100);
  digitalWrite(forward_led, HIGH);
  digitalWrite(pause_led, HIGH);
  digitalWrite(reverse_led, HIGH);
  delay(100);
  digitalWrite(forward_led, LOW);
  digitalWrite(pause_led, LOW);
  digitalWrite(reverse_led, LOW);
  delay(500);

}
 
void loop() {
  int val = analogRead(A7);
  speed_value = abs(val-511);
  direction_value = (val-511);
  stepdelay = map(speed_value,512,50,1,500);



  if ( direction_value > 0 && speed_value > 50) {
     digitalWrite(dirpin, LOW);
     digitalWrite(steppin, HIGH);
     delayMicroseconds(stepdelay);
     digitalWrite(steppin, LOW);
     digitalWrite(forward_led, HIGH);
     digitalWrite(pause_led, LOW);
     digitalWrite(reverse_led, LOW); 
  }
  else if (direction_value <= 0 && speed_value > 50) {
    digitalWrite(dirpin, HIGH);
    digitalWrite(steppin, HIGH);
    delayMicroseconds(stepdelay);
    digitalWrite(steppin, LOW);
    digitalWrite(forward_led, LOW);
    digitalWrite(pause_led, LOW);
    digitalWrite(reverse_led, HIGH); 
  }

  else {

    digitalWrite(forward_led, LOW);
    digitalWrite(pause_led, HIGH);
    digitalWrite(reverse_led, LOW); 
  }
 
}
 
