

// constants won't change. They're used here to set pin numbers:
const int buttonPinup = 4;     // the number of the pushbutton pin
const int buttonPinright = 3;     // the number of the pushbutton pin
const int buttonPinleft = 5;
const int buttonPinclick = 2;
const int buttonPinclick2 = 6;
const int buttonPindown = 7;

//const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0; 
int buttonState3 = 0; 
int buttonState4 = 0; 
int buttonState5 = 0; 
int buttonState6 = 0; 

void setup() {
   pinMode(buttonPinup, INPUT);
   pinMode(buttonPinright, INPUT);
   pinMode(buttonPinleft, INPUT);
   pinMode(buttonPinclick, INPUT);
   pinMode(buttonPinclick2, INPUT);
   pinMode(buttonPindown, INPUT);

    Serial.begin(115200);
}

void loop() {
  
  buttonState1 = digitalRead(buttonPinup);
  buttonState2 = digitalRead(buttonPinright);
  buttonState3 = digitalRead(buttonPinleft);
  buttonState4 = digitalRead(buttonPinclick);
  buttonState5 = digitalRead(buttonPinclick2);
  buttonState6 = digitalRead(buttonPindown);

  if (buttonState1 == HIGH) 
      {Serial.println("up"); }
       
  if (buttonState2 == HIGH) 
      {Serial.println("right"); }
              
  if (buttonState3 == HIGH) 
      {Serial.println("left"); }
             
  if (buttonState4 == HIGH) 
      {Serial.println("click"); }
            
 // if (buttonState5 == HIGH) 
   //   {Serial.println("click2"); }
             
  //if (buttonState6 == HIGH) 
    //  {Serial.println("down"); }
      



//  Serial.println(buttonState); 
  
  
  
  }
