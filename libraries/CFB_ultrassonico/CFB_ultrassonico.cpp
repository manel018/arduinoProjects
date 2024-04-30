#include <iostream>
#include <CFB_ultrassonico.h>
 
 CFB_ultrassonico::CFB_ultrassonico(int pt, int pe){
    this-> pino_trigger = pt;
    this-> pino_echo = pe;
    pinMode(pino_trigger, OUTPUT);
    pinMode(pino_echo, OUTPUT);
 }

 CFB_ultrassonico::distancia_cm(){
    digitalWrite(pino_trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(pino_trigger, HIGH);   
    delayMicroseconds(10);      //Emite o sinal por 10micro segundos
    digitalWrite(pino_triǵger, LOW);
    delayMicroseconds(2);
    return pulseIn(pino_echo, HIGH)*0.0343/2;
 }