#ifndef PrinterModule_h
#define PrinterModule_h

#include "Adafruit_Thermal.h"
//#include "adalogo.h"
//#include "adaqrcode.h"
#include "SoftwareSerial.h"

class PrinterModule {
  private:
    int TX_PIN;
    int RX_PIN;
    int pin;
    SoftwareSerial *mySerial;//(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
    Adafruit_Thermal *printer;
  public:
    PrinterModule();
    //    PrinterModule(int fonaRx, int fonaTx, int fonaRst);
//    PrinterModule(int RX_PIN, int TX_PIN, int pin);
    PrinterModule(int RX_PIN, int TX_PIN, int pin);

    ~PrinterModule();
    bool printText(String data);
};
#endif


