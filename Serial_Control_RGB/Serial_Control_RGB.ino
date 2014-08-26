  char Read[18];
  char buf1[3];
  char buf2[3];
  char buf3[3]; 
  String str;
  String R;
  String G;
  String B;
  int red, green, blue;
  int RedPin = 10;
  int GreenPin = 11;
  int BluePin = 9;
  
  void setup() 
  { 
    Serial.begin(9600);
    Serial.flush();
    pinMode(RedPin, OUTPUT);
    pinMode(GreenPin, OUTPUT);
    pinMode(BluePin, OUTPUT);
  } 
  
  void loop() 
  { 
    if (Serial.available() > 0) 
    {
      int index=0;
      delay(100); 
      int numChar = Serial.available();
      if (numChar>15) 
      {
        numChar=15;
      }
      while (numChar--) 
      {
        Read[index++] = Serial.read();
      }
      
      str = String(Read);
      R = str.substring(0, 2);
      G = str.substring(2, 4);  
      B = str.substring(4, 6);   
      
      R.toCharArray(buf1, 3);
      G.toCharArray(buf2, 3);
      B.toCharArray(buf3, 3);
      
      int RED = strtol(buf1, 0, 16);
      int GREEN = strtol(buf2, 0, 16);
      int BLUE = strtol(buf3, 0, 16);
      
      analogWrite(RedPin, RED);
      analogWrite(GreenPin, GREEN);
      analogWrite(BluePin, BLUE);           
     }
   }
   
   /**********************************************
    char text[10];
    char buf[3];
     
    String str;
     
    String r;
    String g;
    String b;
     
    void setup() {
      // put your setup code here, to run once:
      strcpy(text, "FFF00");
      Serial.begin(9600);
    }
     
    void loop() {
      str = String(text);
      
      char rr[3];
      
     
      r = str.substring(0, 2);
      g = str.substring(2, 4);  
      b = str.substring(4, 6);    
      
      r.toCharArray(buf, 3);
      Serial.println(strtol(buf, 0, 16) );
     
      g.toCharArray(buf, 3);  
      Serial.println(strtol(buf, 0, 16) );  
     
      b.toCharArray(buf, 3);  
      Serial.println(strtol(buf, 0, 16) );  
      
      delay(1000);
    }
   ***********************************************/
     /*    
      if ((Read[0] == '0') || (Read[1] == '0')) 
      {
        analogWrite(RedPin, 0);
      }
      if ((Read[0] == 'F') || (Read[1] == 'F')) 
      {
        analogWrite(RedPin, 255);
      }
         
      if ((Read[2] == '0') || (Read[3] == '0')) 
      {
        analogWrite(GreenPin, 0);
      }
      if ((Read[2] == 'F') || (Read[3] == 'F')) 
      {
        analogWrite(GreenPin, 255);
      }
        
      if ((Read[4] == '0') || (Read[5] == '0')) 
      {
        analogWrite(BluePin, 0);
      }
      if ((Read[4] == 'F') || (Read[5] == 'F')) 
      {
        analogWrite(BluePin, 255);
      }         
      */
  
  
