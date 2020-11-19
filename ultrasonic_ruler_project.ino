#define trigPin 7
#define echoPin 6
#define led 13
#define led2 12
#define led3 11
#define led4 10
#define led5 9
#define led6 8
#define buzzer 3

int sound = 250;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;


  if (distance > 30 || distance <= 0) {
    Serial.println("You're not close to object");
    Serial.print(distance);
    Serial.println(" cm");
    tone(buzzer, sound);

    noTone(buzzer);
  }
  else {

    if (distance <= 30 && distance > 25) {
      Serial.println("You're approaching the object");
      Serial.print(distance);
      Serial.println(" cm");
      tone(buzzer, sound);

      digitalWrite(led, HIGH);
      sound = 250;
    }
    else {
      digitalWrite(led, LOW);
    }

    if (distance <= 25 && distance > 20) {
      Serial.println("Getting close");
      Serial.print(distance);
      Serial.println(" cm");
      tone(buzzer, sound);

      digitalWrite(led2, HIGH);
      sound = 260;
    }
    else {
      digitalWrite(led2, LOW);
    }
    if (distance <= 20 && distance > 15) {
      Serial.println("Almost close");
      Serial.print(distance);
      Serial.println(" cm");
      tone(buzzer, sound);

      digitalWrite(led3, HIGH);
      sound = 270;
    }
    else {
      digitalWrite(led3, LOW);
    }
    if (distance <= 15 && distance > 10) {
      Serial.println("Very close to object");
      Serial.print(distance);
      Serial.println(" cm");
      tone(buzzer, sound);

      digitalWrite(led4, HIGH);
      sound = 280;
    }
    else {
      digitalWrite(led4, LOW);
    }
    if (distance <= 10 && distance > 5) {
      Serial.println("Very very close to object");
      Serial.print(distance);
      Serial.println(" cm");
      tone(buzzer, sound);

      digitalWrite(led5, HIGH);
      sound = 290;
    }
    else {
      digitalWrite(led5, LOW);
    }
    if (distance <= 5 && distance > 0) {
      Serial.println("You're extremely close to object");
      Serial.println("Keep a safe distance. Object might be harmful");
      Serial.print(distance);
      Serial.println(" cm");
      tone(buzzer, sound);

      digitalWrite(led6, HIGH);
      sound = 300;
    }
    else {
      digitalWrite(led6, LOW);
    }
  }
  delay(500);
}
