// Motor City Swim Timer
// Marvin Curlee - mcurlee.com

const int ledPin =  13;
const int ledRunningPin = 5;

const int buttonStart = 12;
int buttonStartState = 0;

const int buttonLane1 = 11;
int buttonLane1State = 0;

const int buttonLane2 = 10;
int buttonLane2State = 0;

const int buttonLane3 = 9;
int buttonLane3State = 0;

const int buttonLane4 = 8;
int buttonLane4State = 0;

const int buttonLane5 = 7;
int buttonLane5State = 0;

const int buttonLane6 = 6;
int buttonLane6State = 0;







// init start time
float startTime;


// button press booleans
int heatStarted = 0;
int lane1Finish = 0;
int lane2Finish = 0;
int lane3Finish = 0;
int lane4Finish = 0;
int lane5Finish = 0;
int lane6Finish = 0;


 //place var
 int heatPlace = 0;



void setup() {
  
  
  Serial.begin(9600);           // set up Serial library at 9600 bps
  
  // Clear screen 
  
  for (int x = 1; x < 80; x++) { 
    Serial.println("");
    }
  
  
  // Print start text
  
  Serial.println("");

  Serial.println("================================================="); 
  Serial.println("=================================================");  
  Serial.println("               Motor City Swimming");   
  Serial.println("               Ready to Start Heat.......");   
  Serial.println("=================================================");   
  Serial.println("=================================================");  
  Serial.println("");
  Serial.println("");
  Serial.println("");
  
  
  // set pin modes
  pinMode(ledPin, OUTPUT);  // LED
  pinMode(buttonStart, INPUT); // Start
  pinMode(buttonLane1, INPUT); // Lane 1
  pinMode(buttonLane2, INPUT); // Lane 2
  pinMode(buttonLane3, INPUT);  // Lane 3
  pinMode(buttonLane4, INPUT); //  Lane 4
  pinMode(buttonLane5, INPUT); //  Lane 5
  pinMode(buttonLane6, INPUT); //  Lane 6
  
  
  //  Turn on LED to indicate ready to start.
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledRunningPin, LOW);
}



void loop() {

  
  
  
  
//  Check the state of all buttons at the start of the loop

  buttonStartState = digitalRead(buttonStart);
  buttonLane1State = digitalRead(buttonLane1);
  buttonLane2State = digitalRead(buttonLane2);
  buttonLane3State = digitalRead(buttonLane3);
  buttonLane4State = digitalRead(buttonLane4);
  buttonLane5State = digitalRead(buttonLane5);
  buttonLane6State = digitalRead(buttonLane6);
  
  
// If start is pressed, record start time-stamp and print starting info to Serial

 if (buttonStartState == HIGH && heatStarted == 0 ) {   
    startTime  = millis();
    heatStarted = 1;
    digitalWrite(ledPin, LOW);
    digitalWrite(ledRunningPin, HIGH);  
    Serial.println(" ########  HEAT START! ##########");
    Serial.println("");
   
     
  } 


//  Check and see if any of the lanes are finished.  If so, print the time.

    if (buttonLane1State == HIGH && lane1Finish == 0 && heatStarted == 1) {
   
      lane1Finish = 1;
      printTime(1);
  }
 
 
 
  if (buttonLane2State == HIGH && lane2Finish == 0 && heatStarted == 1) {
   
      lane2Finish = 1;
      printTime(2);
  }
 
 
  if (buttonLane3State == HIGH && lane3Finish == 0  && heatStarted == 1) {
   
      lane3Finish = 1;
      printTime(3);
  }
 
 
  if (buttonLane4State == HIGH && lane4Finish == 0 && heatStarted == 1) {
   
      lane4Finish = 1;
      printTime(4);

  }
  
  
   if (buttonLane5State == HIGH && lane5Finish == 0 && heatStarted == 1) {
   
      lane5Finish = 1;
      printTime(5);

  }
  
  
   if (buttonLane6State == HIGH && lane6Finish == 0  && heatStarted == 1) {
  
      lane6Finish = 1;
      printTime(6);

  }
  
 // Done with lane checks 
   
  
  
}


// printTime function


void printTime(int laneNumber) {
  
  int wholeMin = 0; 
  float stopTime = millis();
  heatPlace = heatPlace + 1;
  
  float stopTimeSeconds = (stopTime - startTime) / 1000;
      if (stopTimeSeconds >= 60) {
        wholeMin = stopTimeSeconds / 60;
        stopTimeSeconds = stopTimeSeconds - (wholeMin * 60);
      }
      
     Serial.print("PLACE ");
     Serial.print(heatPlace);
     Serial.print(" -- ");
     Serial.print("LANE ");
     Serial.print(laneNumber);
     Serial.print(" -- TIME (SCM) =  ");
     if (wholeMin < 10) { Serial.print("0"); }
     Serial.print(wholeMin);
     Serial.print(":");
     if (stopTimeSeconds < 10) { Serial.print("0"); }
     Serial.println(stopTimeSeconds);
     Serial.println("");
     
}
     
     
