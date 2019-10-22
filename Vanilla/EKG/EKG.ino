int outputCounter = 2;
int amtpin = 54;
int del = 25;
void setup(){
  while(outputCounter < amtpin){
    pinMode(outputCounter, OUTPUT);
    outputCounter++;
  }
  pinMode(0,OUTPUT);
  pinMode(1, OUTPUT);
}

void loop(){ //26pth pin starts another straight
  for(int i = 2; i < amtpin + 3; i++){
    if(i == 47){
      i = 1;
    }
    if(i < 5){
      digitalWrite(i, HIGH);
      delay(del);
    }else if (i <= amtpin){
      digitalWrite(i, HIGH);
      digitalWrite(i - 3, LOW);
      delay(del);
    }else{
      digitalWrite(i-3, LOW);
      delay(del);
    }
    if(i==1){
      i = 47;
    }
  }


}
