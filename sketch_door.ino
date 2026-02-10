int IRsensor1=2;
int IRsensor2=8;
int led1=3;
int led2=1;
int buzzer1=4;
int buzzer2=6;
void setup() 
{
  // put your setup code here, to run once:
pinMode(IRsensor1,INPUT);
pinMode(IRsensor2,INPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(buzzer1,OUTPUT);  
pinMode(buzzer2,OUTPUT);
}
void loop()
{
  int status_IR1=digitalRead(IRsensor1);
 if(status_IR1==HIGH)   // put your main code here, to run repeatedly:
{
digitalWrite( led1,LOW);
digitalWrite( led2,LOW);
digitalWrite( buzzer1,LOW);

}
else
{
 digitalWrite( led1,HIGH);
 digitalWrite( led2,HIGH);
digitalWrite( buzzer1,HIGH);

}
int status_IR2=digitalRead(IRsensor2);
 if(status_IR2==HIGH)
 {
  digitalWrite( buzzer2,LOW);
 }
 else
 {
 digitalWrite( buzzer2,HIGH);
}
}
