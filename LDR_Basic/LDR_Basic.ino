/* Photocell reading program */
// Constants
#define DELAY 500 // Delay between two measurements in ms
#define VIN 5 // V power voltage
#define R 10000 //ohm resistance value

// Parameters
const int sensorPin = A0; // Pin connected to sensor

//Variables
int sensorVal; // Analog value from the sensor
int lux; //Lux value

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  sensorVal = analogRead(sensorPin);
  lux=sensorRawToPhys(sensorVal);
  Serial.print("Raw value from sensor= ");
  Serial.println(sensorVal); // the analog reading
  Serial.print("Physical value from sensor = ");
  Serial.print(lux); // the analog reading
  Serial.println(" lumen"); // the analog reading
  delay(DELAY);
}

int sensorRawToPhys(int raw){
  // Conversion rule
  float Vout = float(raw) * (VIN / float(1023));// Conversion analog to voltage
  float RLDR = (R * (VIN - Vout))/Vout; // Conversion voltage to resistance
  int phys=500/(RLDR/1000); // Conversion resitance to lumen
  return phys;
}
