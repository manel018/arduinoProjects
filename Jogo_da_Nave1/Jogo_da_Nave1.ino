
void setup() {
  
  

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
