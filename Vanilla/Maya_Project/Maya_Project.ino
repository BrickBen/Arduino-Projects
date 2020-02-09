void setup() {
  // put your setup code here, to run once:
  for(int i = 5; i <= 20; i++){
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 5; i <= 20; i++){
    digitalWrite(i, HIGH);
    delay(1000);
  }
  delay(500);
  for(int i = 20; i >= 5; i--){
    digitalWrite(i, LOW);
    delay(1000);
  }
  delay(500);
}
