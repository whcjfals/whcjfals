#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

// An IR detector/demodulator is connected to GPIO pin 14(D5 on a NodeMCU
// board).
// Note: GPIO 16 won't work on the ESP8266 as it does not have interrupts.
const uint16_t kRecvPin = D7;

IRrecv irrecv(kRecvPin);

decode_results results;

void setup() {
  Serial.begin(115200);
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
    }
    irrecv.resume();  // Receive the next value
  }
  delay(100);
}