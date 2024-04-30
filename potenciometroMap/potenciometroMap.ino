#define led 3
#define pot A0

void setup(){
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
}

void loop(){
  /*  Intervalo dos valores das portas
      (1) da porta analógica: 0 a 1023 (entrada)
      (2) da porta PWM: 0 a 255 (saida) 
  */ 
  //analogWrite(led, analogRead(pot)/4);  //Conversão por proporcionalidade
  
  //Sintaxe: map(leitura, min_valor_entrada, max_valor_entrada, min_valor_saida, max_valor_saida)
  analogWrite(led, map(analogRead(pot), 0, 1023, 0, 255)); //Conversão pelo método 'map'
}
