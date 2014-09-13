#include <SoftwareSerial.h>
#include <stdlib.h>
#define rxPin 19
#define txPin 19
SoftwareSerial MySerial = SoftwareSerial (rxPin,txPin);
const int numReadings= 10;
int gp2;
float distance;
int readings[numReadings];
int index = 0; 
int total = 0;                  
int average = 0;                

void setup()
{  
  pinMode(txPin,OUTPUT);
  MySerial.begin(9600);
  delay(1000);
}
 void LCD_CMD(int Command){
 MySerial.write(0xFE);
 MySerial.write(Command); 
}
void loop(){
  gp2=analogRead(2);
  distance=(2914/(gp2+5))-1;
  LCD_CMD(0x80);
  MySerial.print("Distance=    ");
  LCD_CMD(0x8A);
  MySerial.print(distance,DEC);
  
  LCD_CMD(0xC0);
  total= total + readings[index];       
  index = index + 1;                    
  if (index >= numReadings)              
    // ...wrap around to the beginning: 
    index = 0;                           
  // calculate the average:
  average = total / numReadings;         
  // send it to the computer as ASCII digits    
  MySerial.print("average=    ");
  LCD_CMD(0xCA);
  MySerial.print(average,DEC);
  LCD_CMD(0xCE);
  MySerial.print("CM");
  delay(200);
}
  
  
  
