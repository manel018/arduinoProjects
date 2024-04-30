#include <HCSR04.h>

#define p_trigger 4
#define p_echo 5

UltraSonicDistanceSensor distanceSensor (p_trigger, p_echo);

int distance;

void setup() {
  Serial.begin(9600);
}

void loop() {
  distance = distanceSensor.measureDistanceCm();
  Serial.println("Distancia: " + distance);
  delay(500);
}
