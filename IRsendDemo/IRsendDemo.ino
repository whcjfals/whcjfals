
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

/*
5B038877 1번
5B0348B7 2번
 */
 
//적외선 송신 센서
const uint16_t kIrLed = D7;

//IRsend 초기화한 적외선 송신센서 값에대한 객체 생성
IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.

void setup() {
  //IRsend 객체 begin
  irsend.begin();
  Serial.begin(115200);
}

void loop() {

//시리얼모니터 사용 1일때 1에 해당하는 키코드 발사, 2..
  if(Serial.available()){
    char c = Serial.read();
    if(c=='1'){
      //매개값에 해당하는 키코드값 적외선 발사
      irsend.sendNEC(0x5B038877);
    }else if(c=='2'){
       irsend.sendNEC(0x5B0348B7);
    }
  }
}

