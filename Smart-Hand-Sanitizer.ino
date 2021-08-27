#include<LiquidCrystal.h>
LiquidCrystal lcd (12,11,5,4,3,2);
float pm=A0;
int l1=13;
int count=0,b=0;
int m=10;



void setup(){
  pinMode(A0,OUTPUT);
  pinMode(13,INPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);

String str = "WELCOME TO SANITIZATION MACHINE";
lcd.print(str);
Serial.println(str);
delay(100);
for(int i=0; i<str.length(); i++)
{
  lcd.scrollDisplayLeft();
  delay(100);
  
}
lcd.clear();

  
}

void loop(){
b=digitalRead(l1);
if(b==HIGH){
  count++;
    lcd.print(count);
    Serial.print(count);
    delay(1500);
lcd.clear();
pm = analogRead(A0);
//pm=pm/10;
m=pm;
lcd.setCursor(0,0);
lcd.print("TEMPERATURE:");
lcd.print(pm);
Serial.print(pm);
delay(1500);
lcd.clear();
if(pm>=95 && pm<=100){
//lcd.setCursor(0,1);
//lcd.print("SANITIZATION POSSIBLE");
analogWrite(10,m);
String str = "SANITIZATION CAN BE DONE";
lcd.print(str);
Serial.println(str);
delay(100);
for(int i=0; i<str.length(); i++)
{
  lcd.scrollDisplayLeft();
  delay(100);

 }
 analogWrite(10,0);
lcd.clear();
}
else{
  analogWrite(10,0);
  String str = "SANITIZATION CAN'T BE DONE";
lcd.print(str);
Serial.println(str);
delay(100);
for(int i=0; i<str.length(); i++)
{
  lcd.scrollDisplayLeft();
  delay(100);
  
}
lcd.clear();
}
}
}
