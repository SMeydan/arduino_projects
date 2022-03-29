#include <TimedAction.h>
void loop2();
TimedAction timedAction = TimedAction(10,loop2);

int ledPin = 2;
int potPin = A0;
int ldrPin = A1;
int relayPin = 8;
int ldrLedPin = 7;
int transPin = 11;
int ledPotPin = 13;
int buzzerPin = 10;
int buttonPin = 12;
int button2Pin = 9;
int led[]={3,4,5,6};
boolean onOff = false;
boolean onRelay = false;

void setup()
 {
    Serial.begin(9600);
    pinMode(potPin,INPUT);
    pinMode(ldrPin,INPUT);
    pinMode(ledPin,OUTPUT);
    pinMode(relayPin,OUTPUT);
    pinMode(transPin,OUTPUT);
    pinMode(buttonPin,INPUT);
    pinMode(button2Pin,INPUT);
    pinMode(buzzerPin,OUTPUT);
    pinMode(ledPotPin,OUTPUT);
    pinMode(ldrLedPin,OUTPUT);
    digitalWrite(relayPin,LOW);
    for(int i=0;i<4;i++) pinMode(led[i],OUTPUT);
    Serial.println("The Machine is Connected Now");
 }


void loop() 
 {
  timedAction.check();
  
  digitalWrite(ledPotPin,HIGH);
  int potValue=analogRead(potPin);
  float ldrValue=analogRead(ldrPin);
  
  int mapValue=map(potValue,0,1023,0,255);
  Serial.println("Pot:"+String(potValue)); 
  
  float voltage=potValue*(5.0/1023.0);
  Serial.println("Voltage:"+ String(voltage)); 
  analogWrite(ledPin,mapValue);
 
  Serial.println(ldrValue);
  if(ldrValue>500) digitalWrite(ldrLedPin,HIGH);
  else digitalWrite(ldrLedPin,LOW);
  
  for(int i=0;i<4;i++)
    {  
      digitalWrite(led[i],HIGH);
      delay(500);
      digitalWrite(led[i],LOW);
    }
  
  for(int i=2;i>=0;i--)
    {  
      digitalWrite(led[i],HIGH);
      delay(500);
      digitalWrite(led[i],LOW);
    }
 
  digitalWrite(buzzerPin,HIGH);
  delay(500);
  digitalWrite(buzzerPin,LOW);
  
  Serial.println("Another loop");
  delay(500);
 }


 void loop2(){
    if (digitalRead(buttonPin) == 1)
    {
     if (onOff == false)
     {
      digitalWrite(transPin, HIGH);
      onOff=true; 
     }
     else
     {
     digitalWrite(transPin, LOW);
     onOff=false;
     }
    }

if (digitalRead(button2Pin) == 1)
    {
     if (onRelay == false) digitalWrite(relayPin, HIGH); 
     else digitalWrite(relayPin, LOW);
     onRelay=not onRelay; 
    }
  
  }
