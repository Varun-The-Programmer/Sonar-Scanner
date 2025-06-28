#include <Servo.h>

Servo myservo;

int trig = 10;
int echo = 11;

long duration;
float distance;

int buzzer = 9;
int red = 4;
int green = 5;
int blue = 6;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(3);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int deg = 0; deg <= 180; deg++){
    myservo.write(deg);
    delay(10);

    digitalWrite(trig, LOW);
    delay(10);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = duration * 0.017;

    if (distance > 40){
      digitalWrite(green, HIGH);
      digitalWrite(blue, LOW);
      digitalWrite(red, LOW);
      noTone(buzzer);
    } else if (distance > 10){
      digitalWrite(green, HIGH);
      digitalWrite(blue, LOW);
      digitalWrite(red, HIGH);
      tone(buzzer, 100);
    } else{
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
      digitalWrite(red, HIGH);
      tone(buzzer, 450); 
    }
  }
  for (int deg = 180; deg >= 0; deg--){
    myservo.write(deg);
    delay(10);

    digitalWrite(trig, LOW);
    delay(10);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = duration * 0.017;

    if (distance > 40){
      digitalWrite(green, HIGH);
      digitalWrite(blue, LOW);
      digitalWrite(red, LOW);
      noTone(buzzer);
    } else if (distance > 10){
      digitalWrite(green, HIGH);
      digitalWrite(blue, LOW);
      digitalWrite(red, HIGH);
      tone(buzzer, 100);
    } else{
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
      digitalWrite(red, HIGH);
      tone(buzzer, 450); 
    }
  }
}
