#include <ESP8266WiFi.h>


const char* ssid = "ESP_PIRATA!!";
const char* password = "12345678";
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  
  IPAddress staticIP(192, 168, 4, 2); // IP set to Static
  IPAddress gateway(192, 168, 4, 1);// gateway set to Static
  IPAddress subnet(255, 255, 255, 0);// subnet set to Static

  WiFi.mode(WIFI_AP);// Working mode only as Acess Point 

  WiFi.softAP(ssid, password, 2, 0);
  WiFi.config(staticIP, gateway, subnet);

  server.begin();

  Serial.println("Server started"); 
  Serial.println(WiFi.softAPIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  while (!client.available()) {
    delay(1);
  }

  String req = client.readStringUntil('\r');
  req = req.substring(req.indexOf("/") + 1, req.indexOf("HTTP") - 1);
  Serial.println(req);
  client.flush();

  // Match the request

  if (req.indexOf("D") != -1)
  {
    client.print("REcebido seu dado D   ");
  }
  else if (req.indexOf("R") != -1)
  {
    client.print("REcebido seu dado R   ");
  }  
  else if (req.indexOf("b") != -1)
  {
    client.print("Oi Bia!  ");
  } 
  else {
    client.print("Invalid Request");
    client.flush();
    client.stop();
    return;
  }

  //client.print("HTTP/1.1 200 OK\n\n");
  client.flush();

}
