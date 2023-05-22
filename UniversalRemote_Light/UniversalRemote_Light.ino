//IRsendDemo, mqtt_esp8266 각각의 코드에서 필요없는 부분은 빼고, 수정, 추가 좀 해서 
//두 코드를 버무려서 만듬  

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

//송신 센서초기화, 객체 생성
const uint16_t kIrLed = D7;

IRsend irsend(kIrLed); 

//wifi 아이디
const char* ssid = "FREE_U+zone";
//wifi 비번
const char* password = "";
//서버 주소
const char* mqtt_server = "broker.mqtt-dashboard.com";

//여기부터 셋업 와이파이 메소드까진 와이파이 관련 메소드, 정확히는 몰라도 됨
WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

//데이터를 이 함수를 통해 받아옴 
//여러개의 topic을 구독 등록해놨다면 topic별로 처리하는 부분을 분할해야됨 
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String cmd = "";
  for (int i = 0; i < length; i++) {
    char c = (char)payload[i];
    Serial.print(c);
    cmd+=c;
  }
  Serial.println();

  //여기까지 내가 구독하는 토픽으로 메시지가 도달했음
  //리모컨 신호를 발사한다.
  //이 4개의 키코드는 전원 키코드임 sendNEC라는 instance함수는 발사하는 함수
    
  if(cmd.equals("Tv on")){
    irsend.sendNEC(0x20DF10EF);
    irsend.sendNEC(0xCA0F1F87);
    irsend.sendNEC(0x5B0310EF);
    irsend.sendNEC(0xC181890F);
  }else if(cmd.equals("Tv off")){
    irsend.sendNEC(0x20DF10EF);
    irsend.sendNEC(0xCA0F1F87);
    irsend.sendNEC(0x5B0310EF);
    irsend.sendNEC(0xC181890F);
  }

  
 
}

// 구독 등록 해야됨 이보드 관점에서는 데이터를 받아와야하니깐 
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe

      //mqtt borker는 전세계 사람이 공유해서 사용하는 거기때문에 유니크한 닉네임으로
      client.subscribe("jcm/tvcontrol");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  irsend.begin(); //수신 객체 시작
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  //와이파이 연결이 끊어지면 다시 접속
  if (!client.connected()) {
    reconnect();
  }
  //반복
  client.loop(); 
}
