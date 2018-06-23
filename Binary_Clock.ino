
int seconds;
int minutes;
int hours;

void setup() {
  Serial.begin(9600);
  seconds = 0;
  minutes = 0;
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  

}

void loop() {
  
  update_clock();
  Serial.print(hours);
  Serial.print(":");
  Serial.print(minutes);
  Serial.print(":");
  Serial.println(seconds);
  seconds++;
  delay(1000);
  if(seconds == 60){
    minutes++;
    seconds = 0;
  }
  if(minutes == 60){
    hours++;
    minutes = 0;
  }

}

void update_clock(){
  //for seconds only right now
  if(seconds % 2 == 1){
    analogWrite(3, 100);
  } else {
    analogWrite(3, 0);
  }

  if(seconds % 4 == 3 || seconds % 4 == 2){
    analogWrite(5, 100);
  } else {
    analogWrite(5, 0);
  }

  if(seconds % 8 >= 4 && seconds % 8 <= 7){
    analogWrite(6, 100);
  } else {
    analogWrite(6, 0);
  }

  if(seconds % 16 >= 8 && seconds % 16 <= 15){
    analogWrite(9, 100);
  } else {
    analogWrite(9, 0);
  }

  if(seconds % 32 >= 16 && seconds % 32 <= 31){
    analogWrite(10, 100);
  } else {
    analogWrite(10, 0);
  }

  if(seconds % 64 >= 32 && seconds % 64 <= 59){
    analogWrite(11, 100);
  } else {
    analogWrite(11, 0);
  }

}




