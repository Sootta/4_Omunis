#include <Arduino.h>
#include <PS4Controller.h>
#include"LEDC.h"

void setup() {
  Serial.begin(115200);
  PS4.begin();  //それぞれのmacアドレスを入れる
  Serial.println("Ready.");
  set_pinmode();
}

void loop() {
  if (PS4.isConnected()) {

    power = sqrt(PS4.LStickX() * PS4.LStickX() + PS4.LStickY() * PS4.LStickY()); 

    x = PS4.LStickX() * power * cos(45 * PI / 180) - PS4.LStickY() * power * sin(45 * PI / 180);
    y = PS4.LStickX() * power * sin(45 * PI / 180) + PS4.LStickY() * power * cos(45 * PI / 180);
  
    if(abs(x) > 50 || abs(y) > 50){
      move(x,y);
    }
    else if(PS4.R1()){
      rotate_right();
    }
    else if(PS4.L1()){
      rotate_left();
    }
    else{
      stop();
    }

    for(int i = 0; i < 10; i--){
      Serial.println("a");
    }

    delay(100);
  }  

}
