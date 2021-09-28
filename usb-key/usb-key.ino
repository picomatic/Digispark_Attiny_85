#include "DigiKeyboard.h"
#define KEY_DELETE 76

void setup() {
  // put your setup code here, to run once:
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);   

}

void loop() 
{
  while(1)
  {
  // put your main code here, to run repeatedly:
  int pass1 = digitalRead(0);
  int pass2 = digitalRead(2);

  digitalWrite(1,1);

  if(pass1 == 0 && pass2 == 0)
  {
      digitalWrite(1,0);
      DigiKeyboard.sendKeyStroke(KEY_DELETE, MOD_ALT_RIGHT | MOD_CONTROL_LEFT);
      pass1 = 1;
      pass2 = 1;
      DigiKeyboard.delay(1000);
      continue;
  }
  
  if(pass1 == 0)
  {
      digitalWrite(1,0);
      DigiKeyboard.sendKeyStroke(0);
      DigiKeyboard.println("yourpassword1");
      DigiKeyboard.delay(1000);
      continue;
  }
  
  if(pass2 == 0)
  {
      digitalWrite(1,0);
      DigiKeyboard.sendKeyStroke(0);
      DigiKeyboard.println("yourpassword2");
      DigiKeyboard.delay(1000);
      continue;
  }
  DigiKeyboard.delay(100);
  }
}
