#include <Arduino.h>

#define e1 8    //enable pins for 7 segment
#define e2 9

void setup()
{
  for(int i=0;i<11;i++)
    pinMode(i,OUTPUT);
}

int seg_code[10]={0x3F,0X06,0x5B,0X4F,0X66,0X6D,0x7D,0X07,0X7F,0X6F};

void loop()
{
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      for(int k=0;k<10;k++)
      {
      	digitalWrite(e1,LOW);
        digitalWrite(e2,HIGH);
        PORTD=seg_code[j];
        digitalWrite(e1,HIGH);
        digitalWrite(e2,LOW);
        delay(50);
        
        digitalWrite(e2,LOW);
        digitalWrite(e1,HIGH);
        PORTD=seg_code[i];
        digitalWrite(e2,HIGH);
        digitalWrite(e1,LOW);
        delay(50);
      }
    }
  }      
}
