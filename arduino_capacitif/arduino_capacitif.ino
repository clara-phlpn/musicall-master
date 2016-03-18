
const int SIZE = 3;
bool values[SIZE];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i< SIZE; i++) values[i] = 0;
}

void printpin(int pin) {
  Serial.print(readCapacitivePin(pin));
  Serial.print("/");
}

void loop() {

  bool dirty = false;
  for (int i = 0; i< SIZE; i++) {
    bool bar1 = (readCapacitivePin(6+i) > 10);
    if (values[i] != bar1) {
      values[i] = bar1;
      if(values[i] == 1) {
        Serial.print(1);
        Serial.print(":");
        Serial.print(i+1);
        Serial.println("");
      }
      dirty = true;
    }
    
    bool bar2 = (readCapacitivePin(10+i) > 13);
    if (values[i] != bar2) {
      values[i] = bar2;
      if(values[i] == 1) {
        Serial.print(2);
        Serial.print(":");
        Serial.print(i+1);
        Serial.println("");
      }
      dirty = true;
    }
  }

 
  delay(50);
  
  //Serial.print("\t");
  //Serial.println(readCapacitivePin(7));

}
