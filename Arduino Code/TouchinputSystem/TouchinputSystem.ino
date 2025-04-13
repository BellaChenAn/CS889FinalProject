#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>

// Touch
#define TOUCH_PIN1 4
#define TOUCH_PIN2 5
#define TOUCH_PIN3 6
#define TOUCH_PIN4 7
#define TOUCH_PIN5 8
#define TOUCH_PIN6 3
#define TOUCH_PIN7 9
#define TOUCH_PIN8 11
#define TOUCH_PIN9 12
#define TOUCH_PIN10 10
#define TOUCH_PIN11 1
#define TOUCH_PIN12 2

// Define WiFi objects
WiFiClient client;
WiFiUDP udp;

// char Rdata[255];
// String readUART = "";
// String readDATA = "";
unsigned int localPort = 41234;
unsigned int remotePort = 6666;

// Set WiFi setting
const char * udpAddress = "172.20.10.3";
const char * networkName = "Your WIFIname";
const char * networkPswd = "Your WIFI Password";

// Variables 
int32_t touchValue1, touchValueLast1;
int32_t touchValue2, touchValueLast2;
int32_t touchValue3, touchValueLast3;
int32_t touchValue4, touchValueLast4;
int32_t touchValue5, touchValueLast5;
int32_t touchValue6, touchValueLast6;
int32_t touchValue7, touchValueLast7;
int32_t touchValue8, touchValueLast8;
int32_t touchValue9, touchValueLast9;
int32_t touchValue10, touchValueLast10;
int32_t touchValue11, touchValueLast11;
int32_t touchValue12, touchValueLast12;
int32_t threshold = 100;
int touchFlag = 0;

void wifi_init(){
    // initialise - WIFI_STA = Station Mode, WIFI_AP = Access Point Mode 
  WiFi.mode(WIFI_STA);
  WiFi.begin(networkName, networkPswd);

  unsigned long startAttemptTime = millis();
  // while not connected to WiFi AND before timeout
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 20000) {
    Serial.print(".");
    delay(400);
  }

  // WiFi status
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Connected!");
  }
  else
  {
    Serial.println("Failed!");
  }

  if(udp.begin(localPort)) {
  Serial.println("GetPort");
  Serial.println(localPort);
  }
  else {
    Serial.println("NoPort");
  }

  // Print address
  Serial.print("IP address is:");
  Serial.println(WiFi.localIP());
}


void sendMessage(String str, int index, int data, int port){
  String newStr = str + index;
  OSCMessage msg(newStr.c_str());
  msg.add((int32_t)data);
  udp.beginPacket(udpAddress,port);
  msg.send(udp);
  udp.endPacket();
  msg.empty();
}

void setup() {
  // Serial
  Serial.begin(115200);
  
  // touch
  touchValue1 = 50;
  touchValueLast1 = 50;

  wifi_init();
}

void loop() {

  touchValueLast1 = touchValue1;
  touchValue1 = touchRead(TOUCH_PIN1) / 1000;
  Serial.print(touchValue1);Serial.print(",");
  if(touchValueLast1 < threshold && touchValue1 >= threshold ){
    sendMessage("/TouchValue",1,0,remotePort);
  }


  touchValueLast2 = touchValue2;
  touchValue2 = touchRead(TOUCH_PIN2) / 1000;
  Serial.print(touchValue2);Serial.print(",");
  if(touchValueLast2 < threshold && touchValue2 >= threshold ){
    sendMessage("/TouchValue",2,0,remotePort);
  }
  touchValueLast3 = touchValue3;
  touchValue3 = touchRead(TOUCH_PIN3) / 1000;
  Serial.print(touchValue3);Serial.print(",");
  if(touchValueLast3 < threshold && touchValue3 >= threshold ){
    sendMessage("/TouchValue",3,0,remotePort);
  }

  touchValueLast4 = touchValue4;
  touchValue4 = touchRead(TOUCH_PIN4) / 1000;
  Serial.print(touchValue4);Serial.print(",");
  if(touchValueLast4 < threshold && touchValue4 >= threshold ){
    sendMessage("/TouchValue",4,0,remotePort);
  }


  touchValueLast5 = touchValue5;
  touchValue5 = touchRead(TOUCH_PIN5) / 1000;
  Serial.print(touchValue5);Serial.print(",");
  if(touchValueLast5 < threshold && touchValue5 >= threshold ){
    sendMessage("/TouchValue",5,0,remotePort);
  }

  touchValueLast6 = touchValue6;
  touchValue6 = touchRead(TOUCH_PIN6) / 1000;
  Serial.print(touchValue6);Serial.print(",");
  if(touchValueLast6 < threshold && touchValue6 >= threshold ){
    sendMessage("/TouchValue",6,0,remotePort);
  }

  touchValueLast7 = touchValue7;
  touchValue7 = touchRead(TOUCH_PIN7) / 1000;
  Serial.print(touchValue7);Serial.print(",");
  if(touchValueLast7 < threshold && touchValue7 >= threshold ){
    sendMessage("/TouchValue",7,0,remotePort);
  }

  touchValueLast8 = touchValue8;
  touchValue8 = touchRead(TOUCH_PIN8) / 1000;
  Serial.print(touchValue8);Serial.print(",");
  if(touchValueLast8 < threshold && touchValue8 >= threshold ){
    sendMessage("/TouchValue",8,0,remotePort);
  }
  touchValueLast9 = touchValue9;
  touchValue9 = touchRead(TOUCH_PIN9) / 1000;
  Serial.print(touchValue9);Serial.print(",");
  if(touchValueLast9 < threshold && touchValue9 >= threshold ){
    sendMessage("/TouchValue",9,0,remotePort);
  }


  touchValueLast10 = touchValue10;
  touchValue10 = touchRead(TOUCH_PIN10) / 1000;
  Serial.print(touchValue10);Serial.print(",");
  if(touchValueLast10 < threshold && touchValue10 >= threshold ){
    sendMessage("/TouchValue",10,0,remotePort);
  }

  touchValueLast11 = touchValue11;
  touchValue11 = touchRead(TOUCH_PIN11) / 1000;
  Serial.print(touchValue11);Serial.print(",");
  if(touchValueLast11 < threshold && touchValue11 >= threshold ){
    sendMessage("/TouchValue",11,0,remotePort);
  }

  touchValueLast12 = touchValue12;
  touchValue12 = touchRead(TOUCH_PIN12) / 1000;
  Serial.print(touchValue12);Serial.print(",");
  if(touchValueLast12 < threshold && touchValue12 >= threshold ){
    sendMessage("/TouchValue",12,0,remotePort);
  }

  Serial.println();


}
