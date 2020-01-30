#define ledR 2
#define ledY 3
#define ledG 4
#define trigPin 10
#define echoPin 13

float duration, distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)*0.0343;

  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2){
    Serial.println("Out of range");
    digitalWrite(ledR, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledG, HIGH);
  }else{
    if(distance > 20){
      digitalWrite(ledR, HIGH);
      digitalWrite(ledY, LOW);
      digitalWrite(ledG, LOW);
    }else if(distance > 10){
      digitalWrite(ledR, LOW);
      digitalWrite(ledY, HIGH);
      digitalWrite(ledG, LOW);
    }else{
      digitalWrite(ledR, LOW);
      digitalWrite(ledY, LOW);
      digitalWrite(ledG, HIGH);
    }
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(50);
}
