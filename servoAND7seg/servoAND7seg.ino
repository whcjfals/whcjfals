
//1.Servo init
#include <Servo.h>
Servo servo;
int btn = 13;
int direction = 1;
int angle = 0;
//2. 7Segment init
int leds[] = {2,3,4,5,6,7,8,9};
int delight[4][8]{
  {1,0,0,1,1,1,1,1},
  {0,0,1,0,0,1,0,1},
  {0,0,0,0,1,1,0,1},
  {1,0,0,1,1,0,0,1}
};
int n =0;
void setup()
{
  for(int i =0; i<8; i++){
  	pinMode(leds[i], OUTPUT);
  }
  pinMode(btn, INPUT_PULLUP);
  servo.attach(12);
}

void loop()
{
  
  if(digitalRead(btn)==LOW){
    //Servo control
 	angle+=60*direction;
    if(angle>=180 || angle<=0){
    	direction*=-1;
    }
    servo.write(angle);
    
    //7Segment Control
    if(angle==0){
      n=0;
    }else if(angle==60){
      n=1;
    }else if(angle==120){
      n=2;
    }else if(angle==180){
      n=3;
    }
    for(int i =0; i<8; i++){
    	digitalWrite(leds[i],delight[n][i]);
    }
    
    
    delay(500);
  }
}