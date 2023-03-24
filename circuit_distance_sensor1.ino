


const int pingPin = 7;
const int ledPin = 13;

void setup() {
  
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  long duration, cm;

  
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(3);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(6);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  
  cm = microsecondsToCentimeters(duration);

  
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  
  if(cm < 100) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(100);
}


long microsecondsToCentimeters(long microseconds) {

  return microseconds / 28 / 2;
}