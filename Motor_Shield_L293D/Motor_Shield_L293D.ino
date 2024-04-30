#include <AFMotor.h>

AF_DCMotor motor1(1);

void setup() {
  motor1.setSpeed(0); //Define a velocidade do motor entre 0 a 255 
  

}

void loop() {
  motor1.setSpeed(255);
  motor1.run(FORWARD);  //Define o sentido de rotação horário
  delay(5000);

  motor1.setSpeed(0);
  motor1.run(RELEASE); //Para o motor
  delay(200);

  motor1.setSpeed(255);
  motor1.run(BACKWARD);  //Define o sentido de rotação horário
  delay(5000);

  motor1.setSpeed(0);
  motor1.run(RELEASE); //Para o motor
  delay(200);
}
