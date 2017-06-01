#include "PrinterModule.h"
PrinterModule::PrinterModule(int RX_PIN, int TX_PIN, int pin) {
  RX_PIN = RX_PIN;
  TX_PIN = TX_PIN;
  mySerial = new SoftwareSerial(RX_PIN, TX_PIN);
  printer = new Adafruit_Thermal(mySerial);

  // This line is for compatibility with the Adafruit IotP project pack,
  // which uses pin 7 as a spare grounding point.  You only need this if
  // wired up the same way (w/3-pin header into pins 5/6/7):
  pinMode(pin, OUTPUT); 
  digitalWrite(pin, LOW);

  // NOTE: SOME PRINTERS NEED 9600 BAUD instead of 19200, check test page.
  mySerial->begin(19200);  // Initialize SoftwareSerial
  //Serial1.begin(19200); // Use this instead if using hardware serial
  printer->begin();        // Init printer (same regardless of serial type)
}

bool PrinterModule::printText(String data){
  printer->println(data);
  printer->wake();
}

