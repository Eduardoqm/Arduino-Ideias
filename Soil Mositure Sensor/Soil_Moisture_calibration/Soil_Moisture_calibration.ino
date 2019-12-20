const int sensor_pin = A0;  /* Connect Soil moisture analog sensor pin to A0 of NodeMCU */

void setup() {
  Serial.begin(9600); /* Define baud rate for serial communication */
}

void loop() {
  float calib;

  calib = analogRead(sensor_pin);
  
  Serial.print(calib);

  delay(5000);
}
