void setup() {
  pinMode(13, OUTPUT);

}

void loop() {
  DigitalWrite(13, HIGH);
  delay(2000); 
  DigitalWrite(13, LOW);
  delay(2000); 

}
