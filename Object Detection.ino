/*
  Controls Subsystem Code
  by Mary Rose Farruggio
*/

// defines pins numbers
#define side_threshold 40
#define front_threshold 15
#define WAIT_TIME 1000
const int TRIG_1 = A0;
const int ECHO_1 = A1;
/*const int TRIG_2 = 10;
const int ECHO_2 = 11;
const int TRIG_3 = 6;
const int ECHO_3 = 7;
const int TRIG_4 = 4;
const int ECHO_4 = 5;
const int TRIG_5 = 2;
const int ECHO_5 = 3;
const int PANEL_1 = A0;
const int PANEL_2 = A1;
const int PANEL_3 = A2;*/

// defines variables
  double duration1;
  /*double duration2;
  double duration3;
  double duration4;
  double duration5;*/
  double distance1;
  /*double distance2;
  double distance3;
  double distance4;
  double distance5;
  bool intercept1 = false;
  bool intercept2 = false;
  bool intercept3 = false;
  bool intercept4 = false;
  bool intercept5 = false;
  bool bird_inside = false;
  int t1;
  int t2;
  int t3;
  int t4;
  int t5;*/

void setup() {
  pinMode(TRIG_1, OUTPUT); // Sets the tRIG_4 as an Output
  pinMode(ECHO_1, INPUT); // Sets the echoPin4 as an Input
  /*pinMode(TRIG_3, OUTPUT); // Sets the tRIG_4 as an Output
  pinMode(ECHO_3, INPUT); // Sets the echoPin4 as an Input
  pinMode(TRIG_4, OUTPUT); // Sets the tRIG_4 as an Output
  pinMode(ECHO_4, INPUT); // Sets the echoPin4 as an Input
  pinMode(TRIG_5, OUTPUT); // Sets the tRIG_5 as an Output
  pinMode(ECHO_5, INPUT); // Sets the echoPin5 as an Input
  pinMode(PANEL_1, OUTPUT);
  pinMode(PANEL_2, OUTPUT);
  pinMode(PANEL_3, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT); // For debugging
  Serial.begin(9600); // Starts the serial communication*/
}
void loop() {
 
  /*if((intercept5 == false) && ((millis() - t5) > WAIT_TIME)){
    digitalWrite(PANEL_1, HIGH);
  }
  if((intercept5 == false) && (intercept4 == false) && ((millis() - t5) > WAIT_TIME) && ((millis() - t4) > WAIT_TIME)){
    digitalWrite(PANEL_2, HIGH);
  }
  if(intercept4 == false && intercept3 == false /*&& ((millis() - t3) > WAIT_TIME) && ((millis() - t4) > WAIT_TIME)) {
    digitalWrite(PANEL_3, HIGH);
  } */
  /*{
   Serial.print("Value of current time - t3: "); Serial.print(millis()-t3); Serial.println(" milliseconds") ;
   Serial.print("Intercept 3:"); Serial.println(intercept3);
   
   if((intercept3 == false) && (intercept4 == false)){
     difitalWrite(Panel_3, HIGH)
   }
   if(intercept3 == false){
     digitalWrite(PANEL_4, HIGH)
   }
   }
  // Clears the TRIG_
  //int t1 = millis();*/

  digitalWrite(TRIG_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_1, LOW);
  distance1 = pulseIn(ECHO_1, HIGH) * 0.01715; // 0.0343/2
  Serial.print("Distance 1: ");
  Serial.println(distance1);
  delay(500);
  //if(distance1 < front_threshold){
    /*if(!bird_inside){
      digitalWrite(LED_BUILTIN, HIGH);
      bird_inside = 1;
      intercept1 = true;      
    }
    else if(bird_inside){
      digitalWrite(LED_BUILTIN, LOW); 
      bird_inside = false;      
      intercept1 = false;    
      intercept2 = false;  
      intercept3 = false;  
      intercept4 = false;  
      intercept5 = false;  
    }*/
    //intercept1 = true;        
    //digitalWrite(PANEL_3, LOW);
  /*  t1 = millis();
  }
  else{
    intercept1 = false;
  }*/

  /*digitalWrite(TRIG_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_2, LOW);
  distance2 = pulseIn(ECHO_2, HIGH) * 0.01715; // 0.0343/2
  Serial.print("Distance 2: ");
  Serial.println(distance2);
  if(distance2 < front_threshold){
    /*if(!bird_inside){
      digitalWrite(LED_BUILTIN, HIGH);
      bird_inside = 1;
      intercept2 = true;      
    }
    else if(bird_inside){
      digitalWrite(LED_BUILTIN, LOW); 
      bird_inside = false;      
      intercept1 = false;    
      intercept2 = false;  
      intercept3 = false;  
      intercept4 = false;  
      intercept5 = false;  
    }*/
  /*  intercept2 = true;        
    //digitalWrite(PANEL_3, LOW);
    t2 = millis();
  }
  else{
    intercept2 = false;
  }*/


  /*digitalWrite(TRIG_3, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_3, LOW);
  distance3 = pulseIn(ECHO_3, HIGH) * 0.01715; // 0.0343/2
  //Serial.print("Distance 3: ");
  //Serial.println(distance3);
  if(distance3 < side_threshold){
    /*if(!bird_inside){
      digitalWrite(LED_BUILTIN, HIGH);
      bird_inside = 1;
      intercept3 = true;      
    }
    else if(bird_inside){
      digitalWrite(LED_BUILTIN, LOW); 
      bird_inside = false;      
      intercept1 = false;    
      intercept2 = false;  
      intercept3 = false;  
      intercept4 = false;  
      intercept5 = false;  
    }*/
    /*intercept3 = true;        
    digitalWrite(PANEL_3, LOW);
    t3 = millis();
  }
  else{
    intercept3 = false;
  }

  digitalWrite(TRIG_4, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_4, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_4, LOW);
  distance4 = pulseIn(ECHO_4, HIGH) * 0.01715; // 0.0343/2
  //Serial.print("Distance 4: ");
  //Serial.println(distance4);
  if(distance4 < side_threshold){
    /*if(!bird_inside){
      digitalWrite(LED_BUILTIN, HIGH);
      bird_inside = 1;
      intercept4 = true;      
    }
    else if(bird_inside){
      digitalWrite(LED_BUILTIN, LOW); 
      bird_inside = false;      
      intercept1 = false;    
      intercept2 = false;  
      intercept3 = false;  
      intercept4 = false;  
      intercept5 = false;  
    }*/
    /*intercept4 = true;
    digitalWrite(PANEL_2, LOW);        
    digitalWrite(PANEL_3, LOW);
    t4 = millis();
  }
  else{
    intercept4 = false;

  }

  digitalWrite(TRIG_5, LOW);            // send out trigger pulse
  delayMicroseconds(2);
  digitalWrite(TRIG_5, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_5, LOW);
  distance5 = pulseIn(ECHO_5, HIGH) * 0.01715; // 0.0343/2      // read echo return and calculate distance
  //Serial.print("Distance 5: ");
  //Serial.println(distance5);
  if(distance5 < side_threshold){
    /*if(!bird_inside){
      digitalWrite(LED_BUILTIN, HIGH);
      bird_inside = 1;
      intercept5 = true;      
    }
    else if(bird_inside){
      //digitalWrite(LED_BUILTIN, LOW); 
      bird_inside = false;      
      intercept1 = false;    
      intercept2 = false;  
      intercept3 = false;  
      intercept4 = false;  
      intercept5 = false;  
    }*/
    /*intercept5 = true;
    digitalWrite(PANEL_1, LOW);
    digitalWrite(PANEL_2, LOW);
    t5 = millis();
  }
  else{
    intercept5 = false;
  }*/
}
/*
  Ultrasonic Sensor Code Version 1

  by Mary Rose Farruggio

*/
// defines pins numbers
#define side_threshold 40
#define front_threshold 15
#define WAIT_TIME 1000
const int TRIG_1 = A0;
const int ECHO_1 = A1;
/*const int TRIG_2 = 10;
const int ECHO_2 = 11;
const int TRIG_3 = 6;
const int ECHO_3 = 7;
const int TRIG_4 = 4;
const int ECHO_4 = 5;
const int TRIG_5 = 2;
const int ECHO_5 = 3;
const int PANEL_1 = A0;
const int PANEL_2 = A1;
const int PANEL_3 = A2;*/

// defines variables
  double duration1;
  /*double duration2;
  double duration3;
  double duration4;
  double duration5;*/
  double distance1;
  /*double distance2;
  double distance3;
  double distance4;
  double distance5;
  bool intercept1 = false;
  bool intercept2 = false;
  bool intercept3 = false;
  bool intercept4 = false;
  bool intercept5 = false;
  bool bird_inside = false;
  int t1;
  int t2;
  int t3;
  int t4;
  int t5;*/

void setup() {
  pinMode(TRIG_1, OUTPUT); // Sets the tRIG_4 as an Output
  pinMode(ECHO_1, INPUT); // Sets the echoPin4 as an Input
  /*pinMode(TRIG_3, OUTPUT); // Sets the tRIG_4 as an Output
  pinMode(ECHO_3, INPUT); // Sets the echoPin4 as an Input
  pinMode(TRIG_4, OUTPUT); // Sets the tRIG_4 as an Output
  pinMode(ECHO_4, INPUT); // Sets the echoPin4 as an Input
  pinMode(TRIG_5, OUTPUT); // Sets the tRIG_5 as an Output
  pinMode(ECHO_5, INPUT); // Sets the echoPin5 as an Input
  pinMode(PANEL_1, OUTPUT);
  pinMode(PANEL_2, OUTPUT);
  pinMode(PANEL_3, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT); // For debugging
  Serial.begin(9600); // Starts the serial communication*/
}
void loop() {
 
  /*if((intercept5 == false) && ((millis() - t5) > WAIT_TIME)){
    digitalWrite(PANEL_1, HIGH);
  }
  if((intercept5 == false) && (intercept4 == false) && ((millis() - t5) > WAIT_TIME) && ((millis() - t4) > WAIT_TIME)){
    digitalWrite(PANEL_2, HIGH);
  }
  if(intercept4 == false && intercept3 == false /*&& ((millis() - t3) > WAIT_TIME) && ((millis() - t4) > WAIT_TIME)) {
    digitalWrite(PANEL_3, HIGH);
  } */
  /*{
   Serial.print("Value of current time - t3: "); Serial.print(millis()-t3); Serial.println(" milliseconds") ;
   Serial.print("Intercept 3:"); Serial.println(intercept3);
   
   if((intercept3 == false) && (intercept4 == false)){
     difitalWrite(Panel_3, HIGH)
   }
   if(intercept3 == false){
     digitalWrite(PANEL_4, HIGH)
   }
   }
  // Clears the TRIG_
  //int t1 = millis();*/

  digitalWrite(TRIG_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_1, LOW);
  distance1 = pulseIn(ECHO_1, HIGH) * 0.01715; // 0.0343/2
  Serial.print("Distance 1: ");
  Serial.println(distance1);
  delay(500);
  //if(distance1 < front_threshold){
    /*if(!bird_inside){
      digitalWrite(LED_BUILTIN, HIGH);
      bird_inside = 1;
      intercept1 = true;      
    }
    else if(bird_inside){
      digitalWrite(LED_BUILTIN, LOW); 
      bird_inside = false;      
      intercept1 = false;    
      intercept2 = false;  
      intercept3 = false;  
      intercept4 = false;  
      intercept5 = false;  
    }*/
    //intercept1 = true;        
    //digitalWrite(PANEL_3, LOW);
  /*  t1 = millis();
  }
  else{
    intercept1 = false;
  }*/

  /*digitalWrite(TRIG_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_2, LOW);
  distance2 = pulseIn(ECHO_2, HIGH) * 0.01715; // 0.0343/2
  Serial.print("Distance 2: ");
  Serial.println(distance2);
  if(distance2 < front_threshold){
    /*if(!bird_inside){
      digitalWrite(LED_BUILTIN, HIGH);
      bird_inside = 1;
      intercept2 = true;      
    }
    else if(bird_inside){
      digitalWrite(LED_BUILTIN, LOW); 
      bird_inside = false;      
      intercept1 = false;    
      intercept2 = false;  
      intercept3 = false;  
      intercept4 = false;  
      intercept5 = false;  
    }*/
  /*  intercept2 = true;        
    //digitalWrite(PANEL_3, LOW);
    t2 = millis();
  }
  else{
    intercept2 = false;
  }*/


  /*digitalWrite(TRIG_3, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_3, LOW);
  distance3 = pulseIn(ECHO_3, HIGH) * 0.01715; // 0.0343/2
  //Serial.print("Distance 3: ");
  //Serial.println(distance3);
  if(distance3 < side_threshold){
    /*if(!bird_inside){
      digitalWrite(LED_BUILTIN, HIGH);
      bird_inside = 1;
      intercept3 = true;      
    }
    else if(bird_inside){
      digitalWrite(LED_BUILTIN, LOW); 
      bird_inside = false;      
      intercept1 = false;    
      intercept2 = false;  
      intercept3 = false;  
      intercept4 = false;  
      intercept5 = false;  
    }*/
    /*intercept3 = true;        
    digitalWrite(PANEL_3, LOW);
    t3 = millis();
  }
  else{
    intercept3 = false;
  }

  digitalWrite(TRIG_4, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_4, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_4, LOW);
  distance4 = pulseIn(ECHO_4, HIGH) * 0.01715; // 0.0343/2
  //Serial.print("Distance 4: ");
  //Serial.println(distance4);
  if(distance4 < side_threshold){
    /*if(!bird_inside){
      digitalWrite(LED_BUILTIN, HIGH);
      bird_inside = 1;
      intercept4 = true;      
    }
    else if(bird_inside){
      digitalWrite(LED_BUILTIN, LOW); 
      bird_inside = false;      
      intercept1 = false;    
      intercept2 = false;  
      intercept3 = false;  
      intercept4 = false;  
      intercept5 = false;  
    }*/
    /*intercept4 = true;
    digitalWrite(PANEL_2, LOW);        
    digitalWrite(PANEL_3, LOW);
    t4 = millis();
  }
  else{
    intercept4 = false;

  }

  digitalWrite(TRIG_5, LOW);            // send out trigger pulse
  delayMicroseconds(2);
  digitalWrite(TRIG_5, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_5, LOW);
  distance5 = pulseIn(ECHO_5, HIGH) * 0.01715; // 0.0343/2      // read echo return and calculate distance
  //Serial.print("Distance 5: ");
  //Serial.println(distance5);
  if(distance5 < side_threshold){
    /*if(!bird_inside){
      digitalWrite(LED_BUILTIN, HIGH);
      bird_inside = 1;
      intercept5 = true;      
    }
    else if(bird_inside){
      //digitalWrite(LED_BUILTIN, LOW); 
      bird_inside = false;      
      intercept1 = false;    
      intercept2 = false;  
      intercept3 = false;  
      intercept4 = false;  
      intercept5 = false;  
    }*/
    /*intercept5 = true;
    digitalWrite(PANEL_1, LOW);
    digitalWrite(PANEL_2, LOW);
    t5 = millis();
  }
  else{
    intercept5 = false;
  }*/
}
