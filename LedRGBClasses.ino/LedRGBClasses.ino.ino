#define ledR 2
#define ledG 4
#define ledB 3
#define botao 7
#define maximo 3

//Classe botão
class Btn{
  //Membros publicos da classe
  public:
    int btnclicado, btnliberado, pino;  //Atributos
    //Construtor da classe
    Btn(int p){
      pino = p; //Inicialização dos atributos da classe
      btnclicado = btnliberado = 0;
    }
    //Método de verificação do evento de clique do botão
    bool verificaBotao (){
      if (digitalRead(pino) == HIGH){
        btnclicado =1;    //O botão está pressionado
        btnliberado = 0;
      }
      else{
        btnliberado = 1;  //O botão foi liberado
      }

      //Se o botão foi pressionado e depois liberado, então..
      if((btnclicado == 1) && (btnliberado == 1)){
        btnclicado = 0;   //Reinicie o estado das variáveis
        btnliberado = 0;
        
        return true;  //Retorne verdadeiro para clique do botão
      }
      
      else  //Se não, retorne falso para clique do botão
        return false;
    }
}; //ponto e virgula para finalizar a declaração da classe

//Classe cor
class Cor{
  //Membros publicos da classe
  public:
    int pinoR, pinoG, pinoB, cliclo, maximo;
    //Construtor da classe
    Cor(int pr, int pg, int pb):pinoR(pr), pinoG(pg), pinoB(pb){ //Lista de inicialização
      ciclo = 0;  //Inicialização dos atributos da classe
      maximo = 3;
    }
    //Método de verificação da entrada e alteração da cor do led
    void trocaLed(){
      switch (ciclo){
        case 0:
          corLed(1,0,0);  //vermelho
          break;
        case 1:
          corLed(0,1,0);  //verde
          break;
        case 2:
          corLed(0,0,1);  //azul
          break;
      }
      ciclo++;  //Incrementa o ciclo
      if(ciclo>maximo-1)
        ciclo=0;  //reinicia o ciclo
    }
  //Membros privados da classe
  private:
    //Método de alteração da cor do led
    void corLed(int r, int g, int b){
      digitalWrite(pinoR, r);
      digitalWrite(pinoG, g);
      digitalWrite(pinoB, b);
    }
};  //ponto e virgula para finalizar a declaração da classe

Btn btn(botao); //Instancia um botao com no pino definido
Cor cor(ledR, ledG, ledB); //Instancia um objeto Cor

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(botao, INPUT);

}

void loop() {
  if(verificaBotao()){
    cor.trocaLed();
  }
}
