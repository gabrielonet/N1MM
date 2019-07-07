#include <TFT_HX8357.h> // Hardware-specific library
TFT_HX8357 tft = TFT_HX8357();       // Invoke custom library
int nw;
int ne;
int se ;
int sw ;
int temp = 0;
int value = 0;
char angle[20];
String incomingByte ;   // for incoming serial data


void setup(void) {
  Serial.begin(9600);
  Serial.setTimeout(20);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.drawLine(240, 160, 0, 0, TFT_GREEN);
  pinMode(0, OUTPUT) ; //   just to disable TX0
  digitalWrite (0, HIGH);  
  pinMode(1, OUTPUT) ; //   just to disable TX0
  digitalWrite (1, HIGH);  
  pinMode(2, OUTPUT) ; //   just to disable TX0
  digitalWrite (2, HIGH);  
  pinMode(3, OUTPUT) ; //   just to disable TX0
  digitalWrite (3, HIGH);
  background();
  //tft.drawLine(180, 160, 100, 50, TFT_GREEN);
  //tft.fillTriangle(73, 34, 10, 63, 73, 93, TFT_RED);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);


  
}
void background(){
  tft.fillScreen(TFT_BLACK);  tft.setTextColor(TFT_GREEN);
  tft.drawRect(0, 0, 100, 50, TFT_GREEN);
  tft.drawCentreString("VE", 50,15, 4);
  tft.drawRect(380, 0, 100, 50, TFT_GREEN);
  tft.drawCentreString("JA", 430,15, 4);
  
  tft.drawRect(380, 270, 100, 50, TFT_GREEN);
  tft.drawCentreString("VK", 430,285, 4);

  tft.drawRect(0, 270, 100, 50, TFT_GREEN);
  tft.drawCentreString("PY", 50,285, 4);

 tft.drawCircle(240,160, 60, TFT_YELLOW);
 tft.drawCentreString("YO8RXP", 240,150, 4);




 

    
  }



void north_west() {
   background();
   tft.drawLine(180, 160, 100, 50, TFT_GREEN);
  digitalWrite(4, LOW);  digitalWrite(5, LOW);
  digitalWrite(6, LOW);  digitalWrite(7, LOW);


   

}
void north_east() {
   background();
   tft.drawLine(300, 160, 380, 50, TFT_GREEN);  

  digitalWrite(4, LOW);  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);  digitalWrite(7, HIGH);   
}
void south_east() {
   background();
   tft.drawLine(300, 160, 380, 270, TFT_GREEN);
  digitalWrite(4, HIGH);  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);  digitalWrite(7, HIGH);    
}
void south_west() {
   background();
   tft.drawLine(180, 160, 100, 270, TFT_GREEN);
  digitalWrite(4, HIGH);  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);  digitalWrite(7, LOW); 
}

void loop() {
  if (Serial.available() > 0) {
                
                // read the incoming byte:
                incomingByte = Serial.readString();
                incomingByte.toCharArray(angle,20);
                background();
                tft.drawCentreString(angle+2, 240,250, 4);
  }

  int azimuth = atoi(angle);
  
  //nw = digitalRead(0); 
  //ne = digitalRead(3); 
  //se = digitalRead(2); 
  //sw = digitalRead(1); 

  if ( azimuth >= 270 && azimuth  <= 359 && temp != 1  ){ north_west(); temp = 1; }
  if ( azimuth >= 0   && azimuth  <= 90  && temp != 2  ){ north_east(); temp = 2; }
  if ( azimuth >= 91 && azimuth  <= 180 && temp != 3  ){ south_east(); temp = 3; }
  if ( azimuth >= 181 && azimuth  <= 269 && temp != 4  ){ south_west(); temp = 4; }

  //if (ne != 1 && temp != 2){ north_east(); temp = 2; }
  //if (se != 1 && temp != 3){ south_east(); temp = 3; }
  //if (sw != 1 && temp != 4){ south_west(); temp = 4; }
  
}

