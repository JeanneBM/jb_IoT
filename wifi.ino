#include <SPI.h>
#include <ESP8266WiFi.h>

#include <ESP8266WebServer.h>
#ifndef APSSID
#define APSSID "espjb"
#define APPSK "maja"
#endif

const char *ssid = APSSID;
const char *pwd = APPSK;

ESP8266WebServer server(80);
WiFiClient client;

char html_template[] PROGMEM = R"=====(
  <!DOCTYPE html>
  <head>
    <script>
      window.onload = () => {
        var on_button = document.getElementById('on_button'); 
        var off_button = document.getElementById('off_button'); 
        on_button.addEventListener('click', () => {fetch('on')}); 
        off_button.addEventListener('click', () => {fetch('off')}); 
      }
    </script>
  </head>
  <html>
    <body style='display: flex; align-items: center; flex-direction: column'> 
      <h1>Hello from ESP8266! :)</h1> 
      <button id='on_button' style='width: 80%; height:8vh'>On</button>
      <button id='off_button' style='width: 80%; height:8vh'>Off</button>
    </body>
  </html>
)=====";

void handleRootRoute() {
  Serial.println("[GET] Route '/' called");
  server.send(200, "text/html", html_template);
}

void handleOnRoute(){
  Serial.println("[GET] Route '/on' called");
  digitalWrite(2, LOW);
  digitalWrite(14, LOW);
}

void handleOffRoute(){
  Serial.println("[GET] Route '/off' called");
  digitalWrite(2, HIGH);
  digitalWrite(14, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  Serial.println("Serial initialized!");
  Serial.println();
  pinMode(2, OUTPUT);
  pinMode(14, OUTPUT);
  Serial.println("Configuring AP...");

  WiFi.softAP(ssid, pwd);
  Serial.println("\nAP IP Address: ");
  Serial.print(WiFi.softAPIP());
  server.on("/", handleRootRoute);
  server.on("/on", handleOnRoute);
  server.on("/off", handleOffRoute);
  server.begin();
  Serial.println("\nWeb server listetning...");
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

