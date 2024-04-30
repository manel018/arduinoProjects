#ifndef CFB_ULTRASSONICO_H_INCLUDED
#define CFB_ULTRASSONICO_H_INCLUDED

#include <Arduino.h>

class CFB_ultrassonico{
public:
    CFB_ultrassonico(int pt, int pe);   //Construtor da classe
    double distancia_cm();
private:
    int pino_trigger, pino_echo;
};


#endif  //CFB_ULTRASSONICO_INCLUDED