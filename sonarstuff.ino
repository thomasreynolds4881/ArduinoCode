#include "NewPing.h"

#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define MAX_DISTANCE 400
#define LED1 7
#define LED2 6
#define LED3 5
#define LED4 4

float distance, duration;
float limit = 50 ;
int iterations = 5;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  // set LEDs as outputs
  for(int i=4; i<=7; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // get data from sonar
  /*
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin, HIGH);
  // distance is the time it took sound for sonar to return (divided by two since it went there and back) times speed of sound
  */
  duration = sonar.ping_median(iterations);
  distance = (duration/2)*0.0343;

  if (distance > limit){
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);
  }else if (distance > limit*.75){
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
  }else if (distance > limit*.5){
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, LOW);
  }else if (distance > limit*.25){
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, LOW);
  }else{
    digitalWrite(LED4, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, LOW);
  }

  Serial.print("Distance = ");
  Serial.println(distance);
  delay(100);
}
