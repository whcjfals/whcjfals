#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

#define led1 D6
#define led2 D5

/*
5B038877 1번
5B0348B7 2번
 */

const uint16_t kRecvPin = D7;

IRrecv irrecv(kRecvPin);

decode_results results;

void setup() {
  Serial.begin(115200);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  irrecv.enableIRIn();  // Start the receiver
  while (!Serial)  // Wait for the serial connection to be establised.
    delay(50);
  Serial.println();
  Serial.print("IRrecvDemo is now running and waiting for IR message on Pin ");
  Serial.println(kRecvPin);
}

void loop() {
  if (irrecv.decode(&results)) {
    // print() & println() can't handle printing long longs. (uint64_t)

    //내가 원하는 리모컨 신호는 하위 4바이트만 차지하는 신호인데 그 이상의 신호는 무시한다!
    if( (results.value & 0xFF00000000000000) != 0xFF00000000000000){
      
      serialPrintUint64(results.value, HEX);
      Serial.println("");
      if(results.value == 0x5B038877){
        Serial.println("1번 눌렀다!");
        digitalWrite(led1,!digitalRead(led1));
      }else if(results.value == 0x5B0348B7){
        Serial.println("2번 눌렀다!");
        digitalWrite(led2,!digitalRead(led2));
      }
    }
    irrecv.resume();  // Receive the next value
  }
  delay(100);
}