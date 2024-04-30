#define START A0
#define BREAK A1
#define DIRECTION A2
#define PWM 8

#define HORARIO true
#define ANTI_HORARIO false

#define VELOCIDADE 18000  // Velocidade do motor: 18KHz = 2700 rpm
#define INTERVALO 50    // Intervalo (em milisegundos) entre as leituras

#define TOLERANCIA 10

#define AUMENTANDO 1
#define DIMINUINDO -1

void setup() {
  pinMode(PWM, OUTPUT);
  pinMode(START, OUTPUT);
  pinMode(BREAK, OUTPUT);
  pinMode(DIRECTION, OUTPUT); 

  start(false);

  int estado = PROCURA;
  int ultimoEstado = 0;
  double leitura = 0;
  double ultimaLeitura = 0;
  double diferenca;

  bool coletado = false;

  
}

void loop() {
  leitura = read();

  switch (estado)
  {
  case PRONTO:
    gira(HORARIO);  //Motor gira no sentido horário
    leituraAnterior = leitura;

    estado = PROCURANDO;
    break;

    case PROCURANDO:
      diferenca = leitura - leituraAnterior;
      if(mod(diferenca) > TOLERANCIA){
        estado = diferenca > 0 ? AUMENTANDO : DIMINUINDO;
      }
      break;

    case AUMENTANDO:
      
      break;
  
  default:
    break;
  }

  delay(INTERVALO);

  leitura = read();
  leitura_2 = read();

  


    

  ultimaLeitura = leituraAtual;

  }
  estado = (diferenca > TOLERANCIA) ? AUMENTANDO : DIMINUINDO;

  



  ultimoEstado = estadoAtual;
  

  if(estadoAtual != ultimoEstado){
    pararMotor();
    gira(ANTI_HORARIO, INTERVALO);
  }


  gira(2000, ANTI_HORARIO);  //Motor gira durante 200ms no sentido anti-horário
}

// Faz o eixo do motor girar no sentido especificado
void gira(bool sentido){
  tone(PWM,VELOCIDADE);  // Define a velocidade de giro
  rotacao(sentido);
  acionarMotor();
}

// Faz o eixo do motor girar no sentido e durante o tempo especificados
void gira(bool sentido, int tempoMili){
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

void acionarMotor(){
  freia(false); // Libera o freio
  start(true);  // Começa a girar
}

void pararMotor(){
  start(false);  // Para de girar
  freia(true);   // Aciona o freio
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