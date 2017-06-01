#include "SMSModule.h"

SMSModule::SMSModule(int FONA_RX, int FONA_TX, int FONA_RST) {
  FONA_RX = FONA_RX;
  FONA_TX = FONA_TX;
  FONA_RST = FONA_RST;
  fonaSS = new SoftwareSerial(FONA_TX, FONA_RX);
  fonaSerial = fonaSS;
  fona = new Adafruit_FONA(FONA_RST);
  setupFona();
}

SMSModule::setupFona() {
  while (!Serial);

//  Serial.begin(115200);
  Serial.println(F("FONA basic test"));
  Serial.println(F("Initializing....(May take 3 seconds)"));
  // start at 115200 baud
  fonaSerial->begin(115200);
  fona->begin(*fonaSerial);
  
  // send the command to reset the baud rate to 4800
  fona->setBaudrate(9600); 
  fonaSerial->begin(4800);
  if (! fona->begin(*fonaSerial)) {
    Serial.println(F("Couldn't find FONA"));
    while (1);
  }
  type = fona->type();
  Serial.println(F("FONA is OK"));
  Serial.print(F("Found "));
  switch (type) {
    case FONA800L:
      Serial.println(F("FONA 800L")); break;
    case FONA800H:
      Serial.println(F("FONA 800H")); break;
    case FONA808_V1:
      Serial.println(F("FONA 808 (v1)")); break;
    case FONA808_V2:
      Serial.println(F("FONA 808 (v2)")); break;
    case FONA3G_A:
      Serial.println(F("FONA 3G (American)")); break;
    case FONA3G_E:
      Serial.println(F("FONA 3G (European)")); break;
    default:
      Serial.println(F("???")); break;
  }
  // Print module IMEI number.
  char imei[16] = {0}; // MUST use a 16 character buffer for IMEI!
  uint8_t imeiLen = fona->getIMEI(imei);
  if (imeiLen > 0) {
    Serial.print("Module IMEI: "); Serial.println(imei);
  }

}


bool SMSModule::searching() {
  //  int slot = 0;            //this will be the slot number of the SMS
  //  int charCount = 0;
  //  char* bufPtr = fonaInBuffer;
  if (fona->available()) {
    //    do  {
    //      *bufPtr = fona->read();
    //      Serial.write(bufPtr);
    //    } while ((*bufPtr++ != '\n') && (fona->available()) && (++charCount < (sizeof(fonaInBuffer) - 1)));
    //
    //    // Retrieve SMS sender address/phone number.
    //    if (fona->getSMSSender(slot, callerIDbuffer, 31)) {
    //    } else {
    //      Serial.println("Didn't find SMS message in slot!");
    //    }

    return true;
  }
  return false;
}

bool SMSModule::getUserNumber(uint8_t i) {

  if (fona->getSMSSender(i, replybuffer, 31)) {
    Serial.println(replybuffer);
    return true;
  } else {
    Serial.println("Didn't find SMS message in slot!");
    return false;
  }
}

bool SMSModule::getLastUserNumber() {

  int8_t smsnum = fona->getNumSMS();

  if ( (type == FONA3G_A) || (type == FONA3G_E) ) {
    smsnum--;
  }

  if (fona->getSMSSender(smsnum, callerIDbuffer, 31)) {
    //    Serial.println(callerIDbuffer);
    return true;
  } else {
    Serial.println("Didn't find SMS message in slot!");
    return false;
  }
}


bool SMSModule::sendSMS(char *callerIDbuffer, char sms[141]) {

  while (1) {
    if (fona->sendSMS(callerIDbuffer, sms)) {
      break;
    }
  }
  return true;
  
  //  do{
  //
  //  }while(!fona->sendSMS(callerIDbuffer, sms));

  //  if (fona->sendSMS(callerIDbuffer, sms)) {
  //    Serial.println(F("Sent!"));
  //    return true;
  //  } else {
  //    Serial.println(F("send message failed "));
  //    return false;
  //  }
}

bool SMSModule::readLastSMS() {
  int8_t smsnum = fona->getNumSMS();

  if ( (type == FONA3G_A) || (type == FONA3G_E) ) {
    smsnum--;
  }
  uint16_t smslen;
  if (fona->readSMS(smsnum, replybuffer, 250, &smslen)) {
    //    Serial.println(replybuffer);
    return true;

  } else {
    Serial.println("Didn't find SMS message in slot!");
    return false;
  }
}

bool SMSModule::deleteLastSMS() {
  int8_t smsnum = fona->getNumSMS();

  if ( (type == FONA3G_A) || (type == FONA3G_E) ) {
    smsnum--;
  }
  if (fona->deleteSMS(smsnum)) {
    Serial.println("Deleted");
    return true;
  } else {
    Serial.println("Didn't delete");
    return false;
  }
}

char* SMSModule::getReplybuffer() {
  return replybuffer;
}
char* SMSModule::getCallerIDbuffer() {
  return callerIDbuffer;
}

SMSModule::~SMSModule() {

}
