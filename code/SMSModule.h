#ifndef SMSModule_h
#define SMSModule_h

#include "Adafruit_FONA.h"
#include <SoftwareSerial.h>

class SMSModule {
  private:
    int FONA_RX;
    int FONA_TX;
    int FONA_RST;
    Adafruit_FONA *fona;
    SoftwareSerial *fonaSS;
    SoftwareSerial *fonaSerial;
    char fonaInBuffer[64];
    char callerIDbuffer[32];  //we'll store the SMS sender number in here
    setupFona();
    char replybuffer[255];
    uint8_t type;
    
  public:
    SMSModule();
    SMSModule(int FONA_RX, int FONA_TX, int FONA_RST);
    ~SMSModule();
    bool searching();
    bool sendSMS(char *callerIDbuffer, char sms[141]);
//    bool readSMS(uint8_t i);
    bool readLastSMS();
    bool getUserNumber(uint8_t i);
    bool getLastUserNumber();
    char* getReplybuffer();
    char* getCallerIDbuffer();
    bool deleteLastSMS();
};
#endif

