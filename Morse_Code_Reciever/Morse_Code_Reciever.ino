
int photocellPin = 0;     // LDR connected to pin 0
int photocellReading;     // the analog reading from LDR
long onmillis = 0;        // reset onmillis
long timeon = 0;          // reset timeon
  
void setup(void) {
  Serial.begin(9600);   
}

String morse;

void loop(void) {
  photocellReading = analogRead(photocellPin);  

  if (photocellReading < 300) {
    // off (no signal coming in)

    if (onmillis > 0) {
      // signal was coming in, we just lost it (count time spent and determine whether it's a S, L or space (end of letter))
      
      timeon = millis() - onmillis;
      if (timeon <= 500) {

        morse += ".";
        
      } else if (timeon > 500 && timeon <= 3000) {

        morse += "_";

      } else if (timeon > 3000) {

        morse += " ";
        
      }
        
      if (morse == "._ ") {
        
        Serial.println("A");
        morse = "";
         
      } else if (morse == "_... ") {
         
        Serial.println("B");
        morse = ""; //  Important to clear the string so the signals don't just continue to accumulate!

      } else if (morse == "_._. ") {

        Serial.println("C");
        morse = "";
         
      } else if (morse == "_.. ") {

        Serial.println("D");
        morse = "";
         
      } else if (morse == ". ") {

        Serial.println("E");
        morse = "";
         
      }  else if (morse == ".._. ") {

        Serial.println("F");
        morse = "";
         
      } else if (morse == "__. ") {

        Serial.println("G");
        morse = "";
         
      } else if (morse == ".... ") {

        Serial.println("H");
        morse = "";
         
      } else if (morse == ".. ") {

        Serial.println("I");
        morse = "";
         
      } else if (morse == ".___ ") {

        Serial.println("J");
        morse = "";
         
      } else if (morse == "_._ ") {

        Serial.println("K");
        morse = "";
         
      } else if (morse == "._.. ") {

        Serial.println("L");
        morse = "";
         
      } else if (morse == "__ ") {

        Serial.println("M");
        morse = "";
         
      } else if (morse == "_. ") {

        Serial.println("N");
        morse = "";
         
      } else if (morse == "___ ") {

        Serial.println("O");
        morse = "";
         
      } else if (morse == ".__. ") {

        Serial.println("P");
        morse = "";
         
      } else if (morse == "__._ ") {

        Serial.println("Q");
        morse = "";
         
      } else if (morse == "._. ") {

        Serial.println("R");
        morse = "";
         
      } else if (morse == "... ") {

        Serial.println("S");
        morse = "";
         
      } else if (morse == "_ ") {

        Serial.println("T");
        morse = "";
         
      } else if (morse == ".._ ") {

        Serial.println("U");
        morse = "";
         
      } else if (morse == "..._ ") {

        Serial.println("V");
        morse = "";
         
      } else if (morse == ".__ ") {

        Serial.println("W");
        morse = "";
         
      } else if (morse == "_.._ ") {

        Serial.println("X");
        morse = "";
         
      } else if (morse == "_.__ ") {

        Serial.println("Y");
        morse = "";
         
      } else if (morse == "__.. ") {

        Serial.println("Z");
        morse = "";
         
      }
      
      onmillis = 0;
      
    }
    
  } else {
    
    // on (receiving signal)
    if (onmillis == 0) {
      // we just started receiving signal
      onmillis = millis();
    }
    
  }
  
  delay(10); // read every 10 ms.
}
