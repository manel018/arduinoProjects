#include <Servo.h>

#define pot A0


Servo servo1, servo2;
int angS1;  //Angulo do servo 1


void setup() {
  servo1.attach(2); //Relaciona a porta ao servo;
  servo2.attach(3);
  angS1 = 0;
  servo1.write(angS1);  //Posiciona o servo no angulo definido
  servo2.write(angS1);
  pinMode(pot, INPUT);

}

void loop() {
  angS1 = map(analogRead(pot), 0, 1023, 0, 180);
  servo1.write(angS1);
  servo2.write(0);
  delay(2000);

  angS1 = map(analogRead(pot), 0, 1023, 0, 180);
  servo1.write(angS1);
  servo2.write(90);
  delay(2000);

  angS1 = map(analogRead(pot), 0, 1023, 0, 180);
  servo1.write(angS1);
  servo2.write(180);
  delay(2000);

  angS1 = map(analogRead(pot), 0, 1023, 0, 180);
  servo1.write(angS1);
  servo2.write(90);
  delay(2000);

}
