const int sensor_pin = A0;  /* Connect Soil moisture analog sensor pin to A0 of NodeMCU */

void setup() {
  Serial.begin(9600); /* Define baud rate for serial communication */
}

void loop() {
  float moisture_percentage;
  float moist;

  moist = ( ( (analogRead(sensor_pin)*100.00) / 1024.00 ) - 100.00 );
  moisture_percentage = (100 - (moist + 100));

  //Serial.print("Soil Moisture = ");
  Serial.print(moisture_percentage);
  //Serial.println("%");

  delay(5000);
}
