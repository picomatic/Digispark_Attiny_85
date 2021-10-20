#include "DigiKeyboard.h"
#define KEY_DELETE            76
#define BUTTON0               0
#define BUTTON2               2
#define TWOBUTTONDETECTDELAY  100
#define LOOPDELAY             100
#define KEYPRESSEDDELAY       500
#define BTNPRESSED            0

#define PASS1 "password1"
#define PASS2 "password2"

void setup() {
  // put your setup code here, to run once:
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);   
}

void loop() 
{
  char loopCount;
  while(1)
  {
    loopCount ++;
    digitalWrite(1,1);
    
    int button1Pressed = digitalRead(BUTTON0);
    int button2Pressed = digitalRead(BUTTON2);

    if(button1Pressed == BTNPRESSED)
    {
      DigiKeyboard.delay(TWOBUTTONDETECTDELAY);
      button2Pressed = digitalRead(BUTTON2);
    }
    else if(button2Pressed == BTNPRESSED)
    {
      DigiKeyboard.delay(TWOBUTTONDETECTDELAY);
      button1Pressed = digitalRead(BUTTON0);
    }
      

    if(button1Pressed == BTNPRESSED && button2Pressed == BTNPRESSED)
    {
      DigiKeyboard.sendKeyStroke(KEY_DELETE, MOD_ALT_RIGHT | MOD_CONTROL_LEFT);
      KeyPressed();
      continue;
    } 
    else if(button1Pressed == BTNPRESSED)
    {   
      SendPass(PASS1);   
    } 
    else if(button2Pressed == BTNPRESSED)
    {
      SendPass(PASS2);
    } 
    else
    {
      DigiKeyboard.delay(LOOPDELAY);
    }
    
    if(loopCount == 0)
    {
      DigiKeyboard.sendKeyStroke(0);
    }
  }
}

void KeyPressed()
{
  digitalWrite(1,0);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(KEYPRESSEDDELAY);
}

void SendPass(char* pass)
{
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.println(pass);
  KeyPressed();
}
