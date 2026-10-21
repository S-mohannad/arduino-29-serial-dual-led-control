int v;
void setup() {
Serial.begin(9600);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);

}

void loop() {
Serial.print("enter 1 to turn off led1 \n enter 2 to turn on led1 \n enter 3 to turn off led2 \n enter 4 to turn on led2");
while(Serial.available()==0)
{}
v=Serial.parseInt();
if(v==1){digitalWrite(10,LOW);}
if(v==2){digitalWrite(10,HIGH);}
if(v==3){digitalWrite(11,LOW);}
if(v==4){digitalWrite(11,HIGH);}
Serial.print("\n v:");
Serial.print(v);

}