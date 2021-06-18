
//=======================================
//handle function: send webpage to client
//=======================================
void webpage()
{
  server.send(200,"text/html", webpageCode);
}
//=====================================================
//function process event: new data received from client
//=====================================================
void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t welength)
{
  String payloadString = (const char *)payload;
  Serial.print("payloadString= ");
  Serial.println(payloadString);

  if(type == WStype_TEXT) //receive text from client
  {
    byte separator=payloadString.indexOf('=');
    String var = payloadString.substring(0,separator);
    Serial.print("var= ");
    Serial.println(var);
    String val = payloadString.substring(separator+1);
    int value = val.toInt();
    Serial.print("val= ");
    Serial.println(val);
    Serial.println(" ");
    if(var == "Front")
    {
      if(value == 1) front = 1;
      if(value == 2) front = 2;
      if(value == 0) front = 0;
    }
     if(var == "Steer")
    {
      if(value == 1) Steer = 1;
      if(value == 2) Steer = 2;
      if(value == 0) Steer = 0;
    }
  }
}
