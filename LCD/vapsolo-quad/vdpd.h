#include "MatrixCharlieplex.h"
using namespace ArduinoMatrixCharlieplex;

class vpdp{
private:
  MatrixCharlieplex mch;
  uint8_t pins[5];
  uint8_t numPins;
  bool showPercentage;  
  bool showBattery;     
  bool showRaindrop;    
  
public:
    vpdp(int a, int b, int c, int d, int e) 
        : mch(pins, 5, MXCHARLIE_CA), 
          showPercentage(false),   
          showBattery(false), 
          showRaindrop(false) {
        pins[0] = a;
        pins[1] = b;
        pins[2] = c;
        pins[3] = d;
        pins[4] = e;
        numPins = 5;
    }
    
    void percentage(bool show){
      showPercentage = show;  
    }
    
    void battery(bool show){
      showBattery = show;
    }
    
    void raindrop(bool show){
      showRaindrop = show;
    }
    
    void numbers(int asd){
      uint8_t unitSeg[7]={4,3,13,2,9,1,5};
      uint8_t tenSeg[7]={16,12,8,7,11,6,10};
      uint8_t maskNos[10]={126,48,109,121,51,91,95,112,127,123};
      bool hundreds1=asd/100;
      uint8_t tens = (asd/10)%10;
      uint8_t units = asd % 10;
      uint8_t maskUnit=maskNos[units];
      uint8_t maskTen=maskNos[tens];
      long time_now = millis();
      
      while(millis() < time_now + 100){
        for (uint8_t k = 0; k <7 ; k=k+1 ){
          if (bitRead(maskUnit,k)){
             mch.turnOn(unitSeg[k]);
          }
          if (bitRead(maskTen,k)){
             mch.turnOn(tenSeg[k]);
          }
          if (hundreds1==1){
            mch.turnOn(14);
            mch.turnOn(15);
          }
          if (showPercentage){
            mch.turnOn(19);
          }
          if (showBattery){
            mch.turnOn(17);
          }
          if (showRaindrop){
            mch.turnOn(18);
          }
        }
      }
    }
};
