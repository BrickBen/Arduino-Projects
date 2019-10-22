int timer = 300;
int x = 0;
int count = 0;
void setup() {
  for(int i = 2; i<6; i++){
    pinMode(i, OUTPUT);
  }
pinMode(6, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);
}

void loop() {
 if((digitalRead(6) == LOW || digitalRead(7) == LOW || x == 1) && count != 66){
  for(int u = 2;u<6;u++){
    if(u%2 ==0){
    digitalWrite(u, HIGH);
    }else{
      digitalWrite(u,LOW);
    }
  }
  delay(timer);
 for(int v =2; v<6;v++){
  if(v%2 != 0){
  digitalWrite(v, HIGH);
  }else{
    digitalWrite(v, LOW);
  }
 }
 delay(timer);
 x = 1;
 count++;
 if(count == 66){
  for(int k = 2;k<6;k++){
    digitalWrite(k, LOW);
        }
      }
    }

  }
