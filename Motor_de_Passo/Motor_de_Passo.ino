#include <Stepper.h>
#define entrada1 8
#define entrada2 9
#define entrada3 10
#define entrada4 11

//Verificar o n° de passos por giro do motor no datasheet
const int passosPgiro 64  


Stepper mp(passosPgiro, e1, e3, e2, e4);

void setup() {
  mp.setSpeed(500); //Rotações por minuto
  

}

void loop() {
  //Loop para dar 1 volta completa
  for(int i; i < passosPgiro; i++){
    //grau do passo: 360°/passosPgiro
    mp.step(passosPgiro); //dá um passo no sentido horário
    delay(1000);  
  }

  mp.step(-passosPgiro); //Sentido anti-horário 
  delay(1000); 
}
