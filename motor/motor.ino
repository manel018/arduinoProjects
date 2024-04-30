#define START A0
#define BREAK A1
#define DIRECTION A2
#define PWM 8

#define HORARIO true
#define ANTI_HORARIO false

#define VELOCIDADE 18000  //Velocidade do motor: 18KHz = 2700 rpm

void setup() {
  pinMode(PWM, OUTPUT);
  pinMode(START, OUTPUT);
  pinMode(BREAK, OUTPUT);
  pinMode(DIRECTION, OUTPUT); 

  start(false);
}

void loop() {
  gira(500, HORARIO);  //Motor gira durante 500ms no sentido horário

  gira(2000, ANTI_HORARIO);  //Motor gira durante 200ms no sentido anti-horário
}

// Faz o eixo do motor girar durante o tempo (em milisegundos) e no sentido especificados
void gira(int tempoMili, bool sentido){
  tone(PWM,VELOCIDADE);  // Define a velocidade de giro
  rotacao(sentido);
  freia(false); // Libera o freio
  start(true);  // Começa a girar

  delay(tempoMili);

  start(false);
      //TODO: Nessa linha, testar um delay() para suavizar a frenagem e desaceleração
  freia(true);

  tone(PWM, 0);  // Zera a velocidade de giro
}

// Controla o terminal BREAK de acordo com o argumento
void freia(bool estado){
  // Freia quando o argumento é TRUE e Libera o freio quando o argumento é FALSE
  estado ? digitalWrite(BREAK, LOW) : digitalWrite(START, HIGH);
}

// Controla o terminal START de acordo com o argumento
void start(bool estado){
  estado ? digitalWrite(START, HIGH) : digitalWrite(START, LOW);
}

// Controla o terminal DIRECTION de acordo com o sentido de rotação fornecido
void rotacao(bool sentido){
  // Se sentido for true, gira no sentido HORÁRIO, se não, gira no sentido ANTI-HORÁRIO
  sentido ? digitalWrite(DIRECTION, LOW) : digitalWrite(DIRECTION, HIGH);
}