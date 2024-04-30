#define pot A0
int leds[] = {2,3,4,5,6,7};

void setup(){
  pinMode(pot, INPUT);
  for(int i=0; i<6; i++){
    pinMode(leds[i], OUTPUT); //Iteração de declaração das portas de saída
  }
}

//Método para acender do 1° ao x-ésimo led e apagar os demais
void acender(int x){
  for(int i=0; i<x; i++){
    digitalWrite(leds[i], HIGH);  //Acende todos os x-ésimos primeiros leds
  }
  for(int i=x; i<6; i++){
    digitalWrite(leds[i], LOW); //Apaga os leds em diante
  }
}

void loop(){
  /*  Intervalo dos valores das portas
      (1) da porta analógica: 0 a 1023 (entrada)
      (2) da porta PWM: 0 a 255 (saida) 
  */ 
  
  //Sintaxe: map(leitura, min_valor_entrada, max_valor_entrada, min_valor_saida, max_valor_saida)
  int valAnalogico = analogRead(pot); //Lê o valor analógico do potenciômetro

  //Conversão dos intervalos do potenciômetro em (0 a 6) 7 valores/estados possíveis
  int x = map(valAnalogico, 0, 1023, 0, 6);
  acender(x);
}
