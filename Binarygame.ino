//Project 17 Binary Game
#define DATA 6    //pin 14 on chip
#define LATCH 8   //pin 12 on chip
#define CLOCK 10  //pin 11 on chip
//these are digital 10, 8, and 6 PWM

int number = 0;
int answer = 0;

void setup() {
  pinMode(LATCH, OUTPUT);       //set up pin output on chips
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));    //starts rand # generator
  displayNumber(0);             //clears LED's
}

void displayNumber(byte a){
  digitalWrite(LATCH, LOW);     //send byte to displayed LED
  shiftOut(DATA, CLOCK, MSBFIRST, a);
  digitalWrite(LATCH, HIGH);
}

void getAnswer(){
  int z = 0;
  Serial.flush();
  while (Serial.available() == 0){
    //does nothing until serail number comes in.
  }
  while (Serial.available() > 0)
  {
    //move digit to the next coloumn. (1 become 10)
    answer = answer * 10;
    //read next number enterd in serial, subtracting 0 for an int value
    z = Serial.read() - '0';
    //add digit to current value
    answer = answer + z;
    delay(5);         //Short delay for Serial.available
  }
  Serial.print("You entered: ");
  Serial.println(answer);
}

void checkAnswer()
{
  //checks answer displaying result
  if (answer == number){
    Serial.print("correct! ");
    Serial.print(answer, BIN);
    Serial.print(" equals ");
    Serial.println(number);
    Serial.println();
  }
  else{
    Serial.print("Incorrect, ");
    Serial.print(number, BIN);
    Serial.print(" equals ");
    Serial.println(number);
    Serial.println();
  }
answer = 0;
//delay(10000);  
}

void loop() {
  number =random(256);
  displayNumber(number);
  Serial.println("What is the binary number in base 10? ");
  getAnswer();
  checkAnswer();
}
