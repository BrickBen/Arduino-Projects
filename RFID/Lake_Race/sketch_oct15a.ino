#include <Time.h>
#include <EEPROM.h>
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
int nums[]={1,2,3,4,5,6};
String uids[] = {"FB 27 44 1C","AB DF 56 1C","CB 87 4A 1C","s","s","s"};
int questionNumberArray[] ={1,2,3,4,5,6};
void reseedRandom( void )
{
  static const uint32_t HappyPrime = 937;
  union
  {
    uint32_t i;
    uint8_t b[4];
  }
  raw;
  int8_t i;
  unsigned int seed;
 
  for ( i=0; i < sizeof(raw.b); ++i )
  {
    raw.b[i] = EEPROM.read( i );
  }

  do
  {
    raw.i += HappyPrime;
    seed = raw.i & 0x7FFFFFFF;
  }
  while ( (seed < 1) || (seed > 2147483646) );

  randomSeed( seed ); 

  for ( i=0; i < sizeof(raw.b); ++i )
  {
    EEPROM.write( i, raw.b[i] );
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  reseedRandom();
   

const int questionCount = sizeof questionNumberArray / sizeof questionNumberArray[0];
for (int i=0; i < questionCount; i++) {
   int n = random(0, questionCount);  // Integer from 0 to questionCount-1
   int temp = questionNumberArray[n];
   questionNumberArray[n] =  questionNumberArray[i];
   questionNumberArray[i] = temp;
  }
 for(int j =0; j < sizeof questionNumberArray / sizeof questionNumberArray[0]; j++){
 Serial.println(questionNumberArray[j]);
 }
}

int loopCounter = 0;
void loop() {
if(loopCounter != 6){
  int first = questionNumberArray[0];
  int second = questionNumberArray[1];
  int third = questionNumberArray[2];
  int fourth = questionNumberArray[3];
  int fifth = questionNumberArray[4];
  int sixth = questionNumberArray[5];
  int loopingProgress[] = {first,second,third,fourth,fifth,sixth};
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
    {
      return;
    }
    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) 
    {
      return;
    }
    //Show UID on serial monitor
    Serial.print("UID tag :");
    String content= "";
    byte letter;
    for (byte i = 0; i < mfrc522.uid.size; i++) 
    {
       Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
       Serial.print(mfrc522.uid.uidByte[i], HEX);
       content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
       content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    Serial.println();
    Serial.print("Message : ");
    content.toUpperCase();
  
  int lp = loopingProgress[loopCounter];
    if(content.substring(1) == uids[lp-1]){
       Serial.println("Authorized access");
       Serial.println();
       delay(1000);
       loopCounter++;
    }
   
   else   {
      Serial.println(" Access denied");
      delay(1000);
    }
    
  }else{
    Serial.println("Finished");
  }

}
