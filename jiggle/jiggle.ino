#include <DigiMouse.h>
void setup(){
  DigiMouse.begin();
  pinMode(1, OUTPUT);
}
 
void loop() 
{
    digitalWrite(1, HIGH);  
    DigiMouse.move(1,0,0);  // 1px right
    DigiMouse.delay(50);
    DigiMouse.move(-1,0,0); // 1px left
    digitalWrite(1, LOW);
    DigiMouse.delay(60000); //once a minute
}
