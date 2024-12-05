#include <SPI.h>
#include <Servo.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9

Servo s;  int pos=0;
int card_pin = 6;
int ring_pin = 7;
#define card "6A 3C 6E BE"
#define tag "F0 58 C0 80"
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

void setup(){
  s.attach(5);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();          // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  pinMode(card_pin,OUTPUT);
  pinMode(ring_pin,OUTPUT);
}

void loop(){
  // Look for new cards
  if(!mfrc522.PICC_IsNewCardPresent()) {return;}
  // Select one of the cards
  if(!mfrc522.PICC_ReadCardSerial()) {return;}
   //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for(byte i=0; i<mfrc522.uid.size; i++) {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  //change here the UID of the card/cards that you want to give access
  if(content.substring(1)==card){
    Serial.println("Authorized access to this card");
    Serial.println();
    delay(500);
    if(digitalRead(5)==HIGH){ s.write(180); delay(1000);}
    else{s.write(0); delay(1000);}
  }
  else if(content.substring(1)==tag){
    Serial.println("Authorized access to this tag");
    Serial.println();
    s.write(180); delay(1000);
    delay(9000);
    s.write(0); delay(1000);
  }
  else{
    Serial.println(" Access denied");
    delay(3000);
  }
} 
void Accessing_Decision(){}
