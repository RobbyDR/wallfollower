#include <Servo.h>

// Pin untuk sensor ultrasonik
const int pingPinFront = 9; // Pin untuk sensor depan
const int pingPinBack = 10;  // Pin untuk sensor belakang

// Pin untuk servo
const int servoPin = 6;

// Objek servo
Servo myServo;

// Fungsi untuk mengukur jarak menggunakan sensor Ping
long measureDistance(int pingPin) {
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  
  pinMode(pingPin, INPUT);
  long duration = pulseIn(pingPin, HIGH);
  long distance = (duration * 0.034) / 2; // Menghitung jarak dalam cm
  return distance;
}

// Fungsi fuzzy logic untuk menentukan sudut servo
int fuzzyLogic(long distanceFront, long distanceBack) {
  int angle = 90; // Sudut default

    // Aturan fuzzy
  if (distanceFront < 150) { // Jika terlalu dekat dengan dinding di depan
    angle = 110; // Belok kanan
  } else if (distanceBack < 150) { // Jika terlalu dekat dengan dinding di belakang
    angle = 70; // Belok kiri
  } else if (distanceFront > 200) { // Jika terlalu jauh dengan dinding di depan
  	angle = 70; // Belok kiri
  } else if (distanceBack > 200) { // Jika terlalu jauh dengan dinding di belakang
  	angle = 110; // Belok kanan
  } else {
    angle = 90; // Lurus
  }

  return angle;
}

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  long distanceFront = measureDistance(pingPinFront);
  long distanceBack = measureDistance(pingPinBack);
  
  Serial.print("Distance Front: ");
  Serial.print(distanceFront);
  Serial.print(" cm, Distance Back: ");
  Serial.print(distanceBack);
  
  int angle = fuzzyLogic(distanceFront, distanceBack);
  myServo.write(angle); // Mengatur sudut servo
  
  Serial.print(", Servo Angle: ");
  Serial.println(angle); // Tampilkan sudut servo di Serial Monitor
  
  delay(100); // Delay untuk stabilitas
}
