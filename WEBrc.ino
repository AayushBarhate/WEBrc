#include <WiFi.h>
#include <WebServer.h>
#include <WebSocketsServer.h>
#include <ESP32Servo.h>
#include <WiFiAP.h>
//-----------------------------------------------
const char *ssid = "WEBrc";
const char *password = "letmeinplz";
//-----------------------------------------------
//-----------------------------------------------
WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);
//-----------------------------------------------

int front=0;
int Steer=0;
Servo myservo; 
int servoPin = 13;
#include "html_page.h"
#include "functions.h"

void setup()
{
  pinMode(25, OUTPUT);    
  pinMode(26, OUTPUT);
  myservo.attach(servoPin);
  myservo.write(87);
  myservo.setPeriodHertz(50);
  //-----------------------------------------------
  WiFi.softAP(ssid, password);
  Serial.println();
  Serial.print("Local IP: ");
  Serial.println(WiFi.softAPIP());
  //-----------------------------------------------
  server.on("/", webpage);
  //-----------------------------------------------
  server.begin(); webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void loop()
{
  webSocket.loop(); server.handleClient();
  //-----------------------------------------------
  if(front == 1) {
    digitalWrite(25,HIGH);
    digitalWrite(26,LOW);
  }
  if(front == 2) {
    digitalWrite(25,LOW);
    digitalWrite(26,HIGH);
  }
  if(front == 0) {
    digitalWrite(25,LOW);
    digitalWrite(26,LOW);
  }
  if(Steer == 1) {
   myservo.write(100);
  }
  if(Steer == 2) {
    myservo.write(60);
  }
  if(Steer == 0) {
   myservo.write(87);
  }
 
}
