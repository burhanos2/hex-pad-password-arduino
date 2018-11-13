#include <Keypad.h>
//needs library called "keypad" by Mark Stanley, Alexander Brevig
//to download go to Tools > Manage libraries

const byte ROWS = 4;
const byte COLS = 3;

int led1 = 12;
int led2 = 13;
int led3 = 4;
int counter = 0;

String codeString;
String correctString = "0238933";

char code[5];

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {5,6,7,8};
byte colPins[COLS] = {9,10,11};


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);  
   pinMode(led1, OUTPUT);  
   pinMode(led2, OUTPUT);  
   pinMode(led3, OUTPUT);  
}
  
void loop(){
  char key = keypad.getKey();
    // just print the pressed key
   if (key){
    Serial.println(key);
    counter++;
    code[counter] = key;
    codeString = codeString + code[counter];
    Serial.println(codeString);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);  
    digitalWrite(led3, LOW);  
  } 
  
  if (codeString == correctString){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);    
    digitalWrite(led3, LOW);
    Serial.println("CORRECT!");   
  }

  if(codeString.length() >= correctString.length() && codeString != correctString){    
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);    
    digitalWrite(led3, LOW);  
    Serial.println("error!");   
    codeString = "";
    }

    else{      
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);    
    digitalWrite(led3, HIGH);  
      }


   

}
