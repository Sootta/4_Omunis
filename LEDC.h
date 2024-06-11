#include <Arduino.h>

const int D_Pin1 = 25;
const int D_Pin2 = 26;
const int D_Pin3 = 23;
const int D_Pin4 = 5;

int x, y;
int power;

void set_pinmode(){
  ledcSetup(1,24000,8);
  ledcSetup(2,24000,8);
  ledcSetup(3,24000,8);
  ledcSetup(4,24000,8);
  
  ledcAttachPin(0,1);
  ledcAttachPin(2,2);
  ledcAttachPin(4,3);
  ledcAttachPin(27,4);

  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(5,OUTPUT);
  
}

void move(int x, int y){
  ledcWrite(1,abs(x));
  digitalWrite(D_Pin1, x > 0 ? LOW:HIGH);

  ledcWrite(2,abs(y));
  digitalWrite(D_Pin2, y > 0 ? LOW:HIGH);

  ledcWrite(3,abs(x));
  digitalWrite(D_Pin3, x > 0 ? LOW:HIGH);

  ledcWrite(4,abs(y));
  digitalWrite(D_Pin4, y > 0 ? HIGH:LOW);
}

void rotate_right(){
  ledcWrite(1,255); // hogeHoge hoge_hoge HogeHoge HOGE_HOGE
  ledcWrite(2,255);
  ledcWrite(3,255);
  ledcWrite(4,255);

  digitalWrite(D_Pin1,LOW);
  digitalWrite(D_Pin2,HIGH);
  digitalWrite(D_Pin3,HIGH);
  digitalWrite(D_Pin4,HIGH);

}

void rotate_left(){
  ledcWrite(1,255);
  ledcWrite(2,255);
  ledcWrite(3,255);
  ledcWrite(4,255);

  digitalWrite(D_Pin1,HIGH);
  digitalWrite(D_Pin2,LOW);
  digitalWrite(D_Pin3,LOW);
  digitalWrite(D_Pin4,LOW);

}


void stop(){
  ledcWrite(1,0);
  ledcWrite(2,0);
  ledcWrite(3,0);
  ledcWrite(4,0);
}
