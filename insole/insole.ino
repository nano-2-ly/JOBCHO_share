//int insole_type = 0; //left insole
int insole_type = 1; //right insole


#include "BluetoothSerial.h"
#include <ArduinoJson.h>
using namespace std;
 

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)

#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it

#endif

 

BluetoothSerial SerialBT;

  float P[9];
  float C[2];
  float T[5];

//덤프 데이터 생성
void dump(){
for(int i=0; i<9;i++  ){
if(i<2){
  C[i]=i;

}
if(i<5){
  T[i]=i;

}
P[i]=i;

}
}
 String jsondata = "";
    
    StaticJsonDocument <1500> doc;
    // DynamicJsonDocument doc(1024); 동적json 생성
    JsonObject root = doc.to<JsonObject>();

    JsonArray Type = root.createNestedArray("Type");
    JsonArray Pressure = root.createNestedArray("Pressure");
    JsonArray Temper =root.createNestedArray("Temper");
    JsonArray Cop =root.createNestedArray("Cop");


void setup() {
  
  

   

  Serial.begin(9600);

  if(insole_type == 0){
    SerialBT.begin("left insole"); //Bluetooth device name
  }
  
  else if (insole_type == 1){
    SerialBT.begin("right insole"); //Bluetooth device name
  }

  Serial.println("The device started, now you can pair it with bluetooth!");

  dump();
  

}

 

boolean bToogle = 0;

void loop() {

        //  값 삽입
      for(int i=0; i<9;i++  ){
      if(i<2){
        Cop[i]=C[i];

      }
      if(i<5){
        Temper[i]=T[i];

      }
      Pressure[i]=P[i];

      }
      Type[0] = insole_type;


//      serializeJsonPretty(doc, jsondata); //JSON 이쁘게 보이는거
      // serializeJson(doc, jsondata); // JSON 노말하게 보이는것
      
  serializeJson(doc, Serial);
  Serial.println(" ");

      


  if (SerialBT.available()) {
    serializeJson(doc, SerialBT);
    Serial.println("send");
//    SerialBT.write(String(jsondata));

  }

 

 

  

  delay(1000);

}
