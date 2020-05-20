  
int insole_type = 0; //left insole
//int insole_type = 1; //right insole

#include "BluetoothSerial.h"
#include <ArduinoJson.h>
using namespace std;
int col_s[4] = {8,9,10,11};

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)

#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it

#endif

 
void Select(int ch_num){
  for (int i = 0; i < 4; i++) {
    digitalWrite(col_s[i], bitRead(ch_num, i));
  }
}

int getMuxData(int ch){
  Select(ch);
  return analogRead(A0);
}

BluetoothSerial SerialBT;

  float test[9];
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
    
    JsonObject Pressure = doc.createNestedObject("Pressure");
    JsonObject Cop =doc.createNestedObject("Cop");
    JsonObject Temper =doc.createNestedObject("Temper");

void setup() {

  Serial.begin(115200);
  
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
  if(insole_type== 0){
    doc["type"] ="left";
  }
  else if(insole_type== 1){
    doc["type"] ="right";
  }
        //  값 삽입
  for(int i=0; i<9;i++  ){

    Select(i);
    if(i==0){
      Cop["x"]=C[i];

    }
    if(i==1){
      Cop["y"]=C[i];

    }
    if(i<5){
      String T_;
      if(insole_type == 0){
        T_ = "TL";
        T_+=i;
      }
      else if (insole_type == 1){
        T_ = "TR";
        T_+=i;
      }
      Temper[T_]=T[i];

    }
    String P_;
    if(insole_type == 0){
      P_ = "PL";
      P_+=i;
    }
    else if (insole_type == 1){
      P_ = "PR";
      P_+=i;
    }
    
    
    Pressure[P_]=P[i];
    //Serial.println(i);
  }

//      serializeJsonPretty(doc, jsondata); //JSON 이쁘게 보이는거
      // serializeJson(doc, jsondata); // JSON 노말하게 보이는것
      
  
  serializeJsonPretty(doc, Serial);
  Serial.println(" ");


  if (SerialBT.available()) {
    serializeJson(doc, SerialBT);
    Serial.println("send");
//    SerialBT.write(String(jsondata));

  

 

 

  }

  delay(1000);

}
