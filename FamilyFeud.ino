int P1Light = 3;    //Player 1 light
int P1BuzzInPin = 5 //P1 Button Pin
int P1BuzzVal;      //Store high/low trigger
int P2Light = 4;    //Player 2 light
int P2BuzzInPin = 6 //P2 Button Pin
int P2BuzzVal;      //Store high/low trigger
int Reset = 2;      //Reset Player Buzz-In
int resetPinVal;    //To read high/low trigger
bool isBuzzed;      //When pressed, to block other player light

int S1 = A1;        //Strike 1 Light
int S2 = A2;        //Strike 2 Light
int S3 = A3;        //Strike 3 Light
int strikePin = A4; //Cycle strikes
int strikes;        //Number of strikes
int strikePinVal;   //Read high/low trigger

int timeStrike;     //time of previous strike (debounce)
int timePlayerReset;//time of previous player reset (debounce)
//EDIT DATA TYPE SO THAT IT WILL NOT REACH MAX.
//IF MAX REACHED, THEN NEXT TIME MAY NOT BE GREATER THAN PREVIOUS TIME
// AND NO CYCLE OR RESET (WITH DEBOUNCE)

void buzzIn(int player)
{
  digitalWrite(player, HIGH);
  if (player == P1)

  isBuzzed = true;
}

void resetBuzzer()
{
  
}

void strike()
{
  strikes = (strikes + 1) % 4;
  if (0 == strikes)
  {
    digitalWrite(S1, LOW);
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
  }
  if (strikes > 0)
  {
    //call strike sound
    digitalWrite(S1, HIGH);
  }
  if (strikes > 1)
  {
    //call strike sound
    digitalWrite(S2, HIGH);
  }
  if (strikes > 2)
  {
    //call strike sound
    digitalWrite(S3, HIGH);
  }
}

void setup() {
  Serial.begin(9600);

  isBuzzed = false;
  
  pinMode(P1, OUTPUT); //Player 1a
  pinMode(P2, OUTPUT); //Player 2
  pinMode(Reset, INPUT); //Button: Reset Player. Initialize LOW

  pinMode(S1, OUTPUT); //First Strike
  pinMode(S2, OUTPUT); //Second Strike
  pinMode(S3, OUTPUT); //Third Strike
  pinMode(strikePin, INPUT_PULLUP); //Button: Cycle Strikes

  pinMode(2, OUTPUT); //White LED

  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  digitalWrite(P1, LOW);
  digitalWrite(P2, LOW);  

  timeStrike = 0;
  timePlayerReset = 0;
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(P2, HIGH);
  digitalWrite(P1, LOW);
  delay(500);
  digitalWrite(P2, LOW);
  digitalWrite(P1, HIGH);
  delay(500);

  //if player1Pin set high and player1Pin low, then light and lock
  
  if (
  //if player2Pin set high and player2Pin low, then light and lock

  //if playerResetPin high, then turn off player lights and unlock

  if(LOW == Reset)
    Serial.print("Strike!");

  strikePinVal = digitalRead(strikePin);

  //Hold Button for 1 sec to engage trigger
  if (strikePinVal == LOW && (millis()>(timeStrike+30)))
  {
    timeStrike = millis();
    Serial.print("Time strike is ");
    Serial.println(timeStrike);
    strike();   //Cycle through strikes
    
  }
}
