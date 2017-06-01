#include "StorageModule.h"

//StorageModule::StorageModule(int _powerPin, int _outPin) {
StorageModule::StorageModule(int _outPin) {
  //  powerPin = _powerPin;
  outPin = _outPin;
  //  pinMode(powerPin, OUTPUT);
  //  digitalWrite(powerPin, HIGH);
  pinMode(outPin, OUTPUT);

  
    Serial.println("Initializing SD card...");

  //  bool is = true;
  //  while (is) {
  //
Serial.begin(9600);
  if (SD.begin(outPin)) {

    Serial.println("initialization SD good!");
  } else {
    Serial.println("initialization failed!");

  }
  //  }
}

StorageModule::StorageModule() {

}
bool StorageModule::save(String fileName, String dato) {

  if (SD.exists(fileName)) {
    Serial.println("file dont exists.");
  }

  File file = SD.open(fileName, FILE_WRITE);
  if (file) {
    file.println(dato);
    file.close();
    Serial.println("file wrote.");
    return true;
  } else {
    Serial.println("file don't wrote.");
    return false;
  }
  //  delay(10000);
}

int StorageModule::countFile() {
  int counter = 0;
  bool isFile();
  File root;
  root = SD.open("/");
  while (isFile) {

  }

}

StorageModule::~StorageModule() {

}


