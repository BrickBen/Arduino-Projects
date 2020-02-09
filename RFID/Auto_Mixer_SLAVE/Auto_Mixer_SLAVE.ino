int counter = 0;
bool first1 = true;
bool first2 = true;
bool first3 = true;

bool testCase = true;
bool runMain = true;
void setup() {
  // put your setup code here, to run once:
  for(int i = 5; i <=10; i++){
    pinMode(i, INPUT_PULLUP);
  }
  pinMode(11, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 if(runMain){
  if((digitalRead(5) == HIGH && first1) || testCase){
    counter++;
    first1 = false;
    digitalWrite(8, HIGH);

  }
  if((digitalRead(6) == HIGH && first2) || testCase){
    counter++;
    first2 = false;
    digitalWrite(9, HIGH);
  }
  if((digitalRead(7) == HIGH && first3) || testCase){
    counter++;
    first3 = false;
    digitalWrite(10, HIGH);
  }
  if(counter >= 3){
    for(int i = 8; i <=10; i++){
      digitalWrite(i, HIGH);
    } 
    digitalWrite(11, LOW);
    delay(10000);
    digitalWrite(11,HIGH);
    runMain = false;
    }
  }

}
