#include "SMSModule.h"
#include "StorageModule.h"
#include "PrinterModule.h"
// numero del modulo 611212746
// prueba 646491607
SMSModule *smsModule;
//StorageModule *storageModule;

void setup()
{

  Serial.begin(9600);

//  storageModule = new StorageModule(10);
//  delay(5000);
  smsModule = new SMSModule(2, 3, 4);
//  delay(5000);
}

void loop()
{
  
  //  if (storageModule->save("pepe.txt", "hola")) {
  //    Serial.println("ok");
  //  }else{
  //    Serial.println("nada");
  //  }
  if (smsModule->searching()) {

    char *usernum;
    char *sms;

    if (smsModule->getLastUserNumber()) {

      usernum = smsModule->getCallerIDbuffer();

      smsModule->readLastSMS();
      sms = smsModule->getReplybuffer();

      String numberPhone(usernum);
      String userSMS(sms);
//      String fileName = numberPhone + ".txt";

      if (smsModule->sendSMS(usernum, "Proximamente empezaras a recibir mensajes de  la bicicleta pirata... !!!!")) {
        String dato = "#" + numberPhone + "@" + userSMS;
        Serial.println(dato);
        delay(2000);
        smsModule->deleteLastSMS();
        delay(2000);
      }
      //delay(10000);
      //        Serial.println(numberPhone);
      //        Serial.println(userSMS);
      //        Serial.println(fileName);

      //        if (storageModule->save(usernum, userSMS)) {
      //          Serial.println("Grabado..");
      //        }
    }
    //    Serial.println("Recibio algo");
    //    smsModule->readLastSMS();
    //smsModule->deleteLastSMS();
    //    char usernum;
    //    char userSMS;
    //
    //    if (smsModule->getLastUserNumber()) {
    //
    //      usernum = smsModule->getReplybuffer();
    //      smsModule->readLastSMS();
    //      userSMS = smsModule->getReplybuffer();
    //
    //      if (storageModule->save(usernum, userSMS)) {
    //        smsModule->deleteLastSMS();
    //      }
    //
    //    }

    //  } else {
    //
    //Serial.println("Nada");
    //    char *usernum;
    //    char *sms;
    //
    //    if (smsModule->getLastUserNumber()) {
    //
    //      usernum = smsModule->getCallerIDbuffer();
    //
    //      smsModule->readLastSMS();
    //      sms = smsModule->getReplybuffer();
    //
    //      String numberPhone(usernum);
    //      String userSMS(sms);
    //      String fileName = numberPhone + ".txt";
    //
    //      Serial.println(numberPhone);
    //      Serial.println(userSMS);
    //      Serial.println(fileName);
    //      if (storageModule->save(usernum, userSMS)) {
    //        Serial.println("Grabado..");
    //      }
    //    }
    //  }
    //  smsModule->getUserNumber(9);
    //  if (smsModule->searching()) {
    ////    if (storageModule->save("foo.txt", "hola a todo el mundo")) {
    ////
    ////    }
    //  }else{
    //
    //  }
  } 
}

void eventos(int comando) {
  switch (comando) {
    case 1: {

        break;
      }
  }
}
