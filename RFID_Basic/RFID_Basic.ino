// (c) Michael Schoeffler 2014, http://www.mschoeffler.de
#include "SPI.h" // SPI library
#include "MFRC522.h" // RFID library (https://github.com/miguelbalboa/rfid)

const int pinRST = 9;
const int pinSDA = 10;
MFRC522 mfrc522(pinSDA, pinRST); // Set up mfrc522 on the Arduino
String card_id;
String card[2] = {"262217821","1028238129"} ;
String Name[2] = {"hasrul","nizam"};

void setup() {
  SPI.begin(); // open SPI connection
  mfrc522.PCD_Init(); // Initialize Proximity Coupling Device (PCD)
  Serial.begin(9600); // open serial connection
}
void loop() {
  
  if (mfrc522.PICC_IsNewCardPresent()) { // (true, if RFID tag/card is present ) PICC = Proximity Integrated Circuit Card
    for(int c = 0; c < sizeof(card); c++){
      if(card_id.indexOf(card[c]) != -1){
      Serial.print("Detected card name: ");
      Serial.println(Name[c]);
      }
    }
    if(mfrc522.PICC_ReadCardSerial()) { // true, if RFID tag/card was read
      Serial.print("RFID TAG ID:");
      card_id = "";
      for (byte i = 0; i < mfrc522.uid.size; ++i) { // read id (in parts)
//        Serial.print(mfrc522.uid.uidByte[i], HEX); // print id as hex values
//        Serial.print(" "); // add space between hex blocks to increase readability
          card_id += String(mfrc522.uid.uidByte[i]);
      }
      Serial.println(card_id); // Print out of id is complete.
    }
  }
}
