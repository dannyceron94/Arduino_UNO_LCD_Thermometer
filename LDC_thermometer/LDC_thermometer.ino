#include <LiquidCrystal.h>

// We'll use analog input 0 to measure the temperature sensor's
// signal pin.
const int temperaturePin = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // In this sketch, we'll use the Arduino's serial port
  // to send text back to the main computer. For both sides to
  // communicate properly, they need to be set to the same speed.
  // We use the Serial.begin() function to initialize the port
  // and set the communications speed.
  
  // The speed is measured in bits per second, also known as
  // "baud rate". 9600 is a very commonly used baud rate,
  // and will transfer about 10 characters per second.
  Serial.begin(9600);
   
  lcd.begin(16, 2);
  lcd.print("Temp sensor on");
  lcd.setCursor(0 ,1);
  lcd.print("By dcNetworks");
   delay(4000);
}

void loop() {
  float voltage, degreesC, degreesF;

  // First we'll measure the voltage at the analog pin. Normally
  // we'd use analogRead(), which returns a number from 0 to 1023.
  // Here we've written a function (further down) called
  // getVoltage() that returns the true voltage (0 to 5 Volts)
  // present on an analog input pin.
  voltage = getVoltage(temperaturePin);

  // Now we'll convert the voltage to degrees Celsius.
  // This formula comes from the temperature sensor datasheet:
  degreesC = (voltage - 0.5) * 100.0;

  degreesF = degreesC * (9.0/5.0) + 32.0;

  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);

  lcd.print("deg C: ");
  lcd.print(degreesC);
  lcd.setCursor(0,1);
  lcd.print("deg F: ");
  lcd.print(degreesF);
  
  delay(1000);
  lcd.clear();
}

float getVoltage(int pin)
{
  // This equation converts the 0 to 1023 value that analogRead()
  // returns, into a 0.0 to 5.0 value that is the true voltage
  // being read at that pin.
  
  // Here's the return statement for this function. We're doing
  // all the math we need to do within this statement:
  
  return (analogRead(pin) * 0.004882814);


}
