//초음파 센서 만들기 
int trig = 5;
int echo = 6;
int led = 3;

void setup(){
  pinMode(trig,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(echo,INPUT);
}

void loop(){
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);
  float distance = duration/24.0/2.0;

  if(distance>20){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }

}
