// introduce una libreria che ci permette di trasformare
//il segnale triggher in un output in cui è espressa la distanza in centimetri
#include<NewPing.h>
// introduce un libreria per filtrare i valori
#include <SignalFilter.h>
// libreria che ci permette di inizializzare la BLuetooth seriale
#include <SoftwareSerial.h>

// definisco il tx e rx per il segnali bluetooth
#define BT_TX_PIN 19
#define BT_RX_PIN 18

// definisco i segnali del sensore di distanza
#define PIN_TRIGGER 2
#define PIN_ECHO 3
#define PIN_TRIGGER01 4
#define PIN_ECHO01 5
#define PIN_TRIGGER02 6
#define PIN_ECHO02 7
#define PIN_TRIGGER03 8
#define PIN_ECHO03 9
#define PIN_TRIGGER04 10
#define PIN_ECHO04 11
#define PIN_TRIGGER05 12
#define PIN_ECHO05 13
#define PIN_TRIGGER06 22
#define PIN_ECHO06 23
#define PIN_TRIGGER07 24
#define PIN_ECHO07 25
#define PIN_TRIGGER08 26
#define PIN_ECHO08 27

// defenisco la distanza di ogni sensore
float distanza = 0.0;
float distanza01 = 0.0;
float distanza02 = 0.0;
float distanza03 = 0.0;
float distanza04 = 0.0;
float distanza05 = 0.0;
float distanza06 = 0.0;
float distanza07 = 0.0;
float distanza08 = 0.0;

// definisco la distanza massima
#define DISTANZA_MASSIMA 400 

// NewPing è una funzione importata che permette di trasformare
//il segnale triggher in un output in cui è espressa la distanza in centimetri
NewPing ultrasuoni(PIN_TRIGGER, PIN_ECHO, DISTANZA_MASSIMA); //oggetto sensore ultrasuoni
int sensorValue = 0;  // variabile in cui memorizzare i valori provenienti dal sensore
int sensorValueOld = -1; // variabile in cui memorizzare i valori precedenti provenienti dal sensore
int sensorValueFiltered = 0; // variabile in cui memorizzare i valori filtrati

NewPing ultrasuoni01(PIN_TRIGGER01, PIN_ECHO01, DISTANZA_MASSIMA);
int sensorValue2 = 0;  // variabile in cui memorizzare i valori provenienti dal sensore
int sensorValueOld2 = -1;
int sensorValueFiltered2 = 0;

NewPing ultrasuoni02(PIN_TRIGGER02, PIN_ECHO02, DISTANZA_MASSIMA);
int sensorValue3 = 0;  // variabile in cui memorizzare i valori provenienti dal sensore
int sensorValueOld3 = -1;
int sensorValueFiltered3 = 0;

NewPing ultrasuoni03(PIN_TRIGGER03, PIN_ECHO03, DISTANZA_MASSIMA);
int sensorValue4 = 0;  // variabile in cui memorizzare i valori provenienti dal sensore
int sensorValueOld4 = -1;
int sensorValueFiltered4 = 0;

NewPing ultrasuoni04(PIN_TRIGGER04, PIN_ECHO04, DISTANZA_MASSIMA);
int sensorValue5 = 0;  // variabile in cui memorizzare i valori provenienti dal sensore
int sensorValueOld5 = -1;
int sensorValueFiltered5 = 0;

NewPing ultrasuoni05(PIN_TRIGGER05, PIN_ECHO05, DISTANZA_MASSIMA);
int sensorValue6 = 0;  // variabile in cui memorizzare i valori provenienti dal sensore
int sensorValueOld6 = -1;
int sensorValueFiltered6 = 0;

NewPing ultrasuoni06(PIN_TRIGGER06, PIN_ECHO06 , DISTANZA_MASSIMA);
int sensorValue7 = 0;  // variabile in cui memorizzare i valori provenienti dal sensore
int sensorValueOld7 = -1;
int sensorValueFiltered7 = 0;

NewPing ultrasuoni07(PIN_TRIGGER07, PIN_ECHO07 , DISTANZA_MASSIMA);
int sensorValue8 = 0;  // variabile in cui memorizzare i valori provenienti dal sensore
int sensorValueOld8 = -1;
int sensorValueFiltered8= 0;

NewPing ultrasuoni08(PIN_TRIGGER08, PIN_ECHO08 , DISTANZA_MASSIMA);
int sensorValue9 = 0;  // variabile in cui memorizzare i valori provenienti dal sensore
int sensorValueOld9 = -1;
int sensorValueFiltered9= 0;
long previousTime = 0;

SignalFilter Filter;
SignalFilter Filter2;
SignalFilter Filter3;
SignalFilter Filter4;
SignalFilter Filter5;
SignalFilter Filter6;
SignalFilter Filter7;
SignalFilter Filter8;
SignalFilter Filter9;

SoftwareSerial bt =  SoftwareSerial(BT_RX_PIN, BT_TX_PIN);


void setup() {
  Serial.begin(115200);
  //Serial.begin(57600);

  Filter.begin();
  Filter.setFilter('c');
  Filter.setOrder(2);

  Filter2.begin();
  Filter2.setFilter('c');
  Filter2.setOrder(2); 

   Filter3.begin();
  Filter3.setFilter('c');
  Filter3.setOrder(2);

    Filter4.begin();
  Filter4.setFilter('c');
  Filter4.setOrder(2);

   Filter5.begin();
  Filter5.setFilter('c');
  Filter5.setOrder(2);

 Filter6.begin();
  Filter6.setFilter('c');
  Filter6.setOrder(2);

  Filter7.begin();
  Filter7.setFilter('c');
  Filter7.setOrder(2);

  Filter8.begin();
  Filter8.setFilter('c');
  Filter8.setOrder(2);

  Filter9.begin();
  Filter9.setFilter('c');
  Filter9.setOrder(2);

  pinMode(BT_RX_PIN, INPUT);
  pinMode(BT_TX_PIN, OUTPUT);
 
  bt.begin(115200);
  
}

void loop() {

  distanza = ultrasuoni.ping_cm();
  distanza01 = ultrasuoni01.ping_cm();
  distanza02 = ultrasuoni02.ping_cm();
  distanza03 = ultrasuoni03.ping_cm();
  distanza04 = ultrasuoni04.ping_cm();
  distanza05 = ultrasuoni05.ping_cm();
  distanza06 = ultrasuoni06.ping_cm();
  distanza07 = ultrasuoni07.ping_cm();
   distanza08 = ultrasuoni08.ping_cm();
 
  sensorValueFiltered = Filter.run(distanza);
  sensorValueFiltered2 = Filter2.run(distanza01);
  sensorValueFiltered3 = Filter3.run(distanza02);
  sensorValueFiltered4 = Filter4.run(distanza03);
  sensorValueFiltered5 = Filter5.run(distanza04);
  sensorValueFiltered6 = Filter6.run(distanza05);
  sensorValueFiltered7 = Filter7.run(distanza06);
  sensorValueFiltered8 = Filter8.run(distanza07);
  sensorValueFiltered9 = Filter9.run(distanza08);



  if ((sensorValueFiltered != sensorValueOld ) || (sensorValueFiltered2 != sensorValueOld2) 
 || (sensorValueFiltered3 != sensorValueOld3) || (sensorValueFiltered4 != sensorValueOld4)  
 || (sensorValueFiltered5 != sensorValueOld5)|| (sensorValueFiltered6 != sensorValueOld6)||
 (sensorValueFiltered7 != sensorValueOld7) || (sensorValueFiltered8 != sensorValueOld8)|| (sensorValueFiltered9 != sensorValueOld9)){
  
  Serial.print("distanza");
  Serial.print(" ");
  Serial.print(distanza);
  Serial.print(" ");
  Serial.print(distanza01);
  Serial.print(" ");
  Serial.print(distanza02);
  Serial.print(" ");
  Serial.print(distanza03);
  Serial.print(" ");
  Serial.print(distanza04);
  Serial.print(" ");
  Serial.print(distanza05);
  Serial.print(" ");
  Serial.print(distanza06);
  Serial.print(" ");
  Serial.print(distanza07);
  Serial.print(" ");
  Serial.println(distanza08);

  bt.print("distanza");
  bt.print(" ");
  bt.print(distanza);
  bt.print(" ");
  bt.print(distanza01);
  bt.print(" ");
  bt.print(distanza02);
  bt.print(" ");
  bt.print(distanza03);
  bt.print(" ");
  bt.print(distanza04);
  bt.print(" ");
  bt.print(distanza05);
  bt.print(" ");
  bt.print(distanza06);
  bt.print(" ");
  bt.print(distanza07);
  bt.print(" ");
  bt.println(distanza08);
 
  
}
long currentTime = millis();
  if (currentTime-previousTime > 500) {
    Serial.println ("check");
    bt.println ("check");
    previousTime = currentTime;
  }
  }
