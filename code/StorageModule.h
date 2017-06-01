#ifndef StorageModule_h
#define StorageModule_h

#include <SD.h>

class StorageModule {
  private:
    int powerPin;
    int outPin;
  public:
//    StorageModule(int _powerPin, int _outPin);
    StorageModule(int _outPin);
    StorageModule();
    ~StorageModule();
    bool save(String fileName, String dato);
    int countFile();
//    bool isOn = false;
};
#endif

