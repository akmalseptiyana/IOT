#define m1a 3
#define m1b 5

#define m2a 9
#define m2b 10

int arrow =0;
void setup() {


pinMode(m1a,OUTPUT);
pinMode(m1b,OUTPUT);
pinMode(m2a,OUTPUT);
pinMode(m2b,OUTPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);

}

void loop() {

// pembacaan sensor pada pin 12 dan 13

int rsensor=digitalRead(7);
int lsensor=digitalRead(8);

//logika robot menggunakan prinsip  AND
if((lsensor == LOW)&&(rsensor== HIGH)) {kiri();}
if((lsensor== HIGH)&&(rsensor== LOW))  {kanan();}
if((lsensor==HIGH)&&(rsensor== HIGH))  {berhenti();}
if((lsensor== LOW)&&(rsensor==LOW))    {maju();}
}
void maju(){
digitalWrite(m2a,LOW);   // kiri CCW
digitalWrite(m2b,HIGH);

digitalWrite(m1a,HIGH);  // kanan CW
digitalWrite(m1b,LOW);
}

void berhenti(){
  
digitalWrite(m1a,HIGH);   // CCW
digitalWrite(m1b,HIGH);

digitalWrite(m2a,HIGH);  //CW
digitalWrite(m2b,HIGH);
}

void kanan()
{
  
digitalWrite(m2a,LOW);   //kiri CCW
digitalWrite(m2b,HIGH);

digitalWrite(m1a,HIGH);  //kanan CW
digitalWrite(m1b,HIGH);
}
void kiri(){
  
digitalWrite(m2a,HIGH);   //kiri CCW
digitalWrite(m2b,HIGH);

digitalWrite(m1a,HIGH);  //kanan CW
digitalWrite(m1b,LOW);
}

