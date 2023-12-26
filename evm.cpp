#include <LiquidCrystal.h>

LiquidCrystal lcd(11, 10, 9, 8, 7, 6);

#define sw1 A0
#define sw2 A1 
#define sw3 A2 
#define sw4 A3 
#define sw5 A4
#define sw6 A5
#define led3 3  


int vote1 = 0;
int vote2 = 0;
int vote3 = 0;
int vote4 = 0;
bool cb = false;

void setup() {
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
  pinMode(sw5, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(led3, OUTPUT);


lcd.begin(16, 2);
lcd.setCursor(0,0);
lcd.print(" EVERY VOTE ");
lcd.setCursor(0,1);
lcd.print("   MATTERS :) ");
lcd.setCursor(0,0);
delay(2500);
lcd.print(" Please do cast ");
lcd.setCursor(0,1);
lcd.print("  Your Vote  ");
lcd.setCursor(0,0);
delay(3000);
lcd.print(" VOTING MACHINE ");
lcd.setCursor(0,1);
lcd.print("  IIT INDORE ");
delay(3000);
  digitalWrite(sw1, HIGH);
  digitalWrite(sw2, HIGH);
  digitalWrite(sw3, HIGH);
  digitalWrite(sw4, HIGH);
  digitalWrite(sw5, HIGH);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("1)P1");
  lcd.setCursor(2, 1);
  lcd.print("2)P2");
  lcd.setCursor(8, 0);
  lcd.print("3)P3");
  lcd.setCursor(8, 1);
  lcd.print("4)NOTA");
}

void loop() {
  if(cb == true){
  if (digitalRead(sw1) == LOW) {
    
    lcd.clear();
    lcd.print("Thanks for");
    lcd.setCursor(0, 1);
    lcd.print("voting ");
    digitalWrite(12, HIGH);
    unsigned long startMillis = millis();
    while (millis() - startMillis < 10000) {
        if (digitalRead(sw1) == LOW) {
            digitalWrite(led3, HIGH); 
            delay(500);               
            digitalWrite(led3, LOW);  
            delay(500);               
        }
        
    }

    vote1++;
    cb=false;
    digitalWrite(12, LOW);
    showPartyOptions();
}


  if (digitalRead(sw2) == LOW) {
    lcd.clear();
    lcd.print("Thanks for");
    lcd.setCursor(0, 1);
    lcd.print("voting ");
    digitalWrite(12, HIGH);
    unsigned long startMillis = millis();
    while (millis() - startMillis < 10000) {
        if (digitalRead(sw2) == LOW) {
            digitalWrite(led3, HIGH); 
            delay(500);               
            digitalWrite(led3, LOW);  
            delay(500);               
        }
    }

    vote2++;
    cb=false;
    digitalWrite(12, LOW);
    showPartyOptions();
  }

  if (digitalRead(sw3) == LOW) {
    lcd.clear();
    lcd.print("Thanks for");
    lcd.setCursor(0, 1);
    lcd.print("voting ");
    digitalWrite(12, HIGH);
    unsigned long startMillis = millis();
    while (millis() - startMillis < 10000) {
        if (digitalRead(sw3) == LOW) {
            digitalWrite(led3, HIGH); 
            delay(500);              
            digitalWrite(led3, LOW);  
            delay(500);               
        }
    }

    vote3++;
    cb=false;
    digitalWrite(12, LOW);
    showPartyOptions();
  }

  if (digitalRead(sw4) == LOW) {
    lcd.clear();
    lcd.print("Thanks for ");
    lcd.setCursor(0, 1);
    lcd.print("voting ");
    digitalWrite(12, HIGH);
    unsigned long startMillis = millis();
    while (millis() - startMillis < 10000) {
        if (digitalRead(sw4) == LOW) {
            digitalWrite(led3, HIGH); 
            delay(500);               
            digitalWrite(led3, LOW);  
            delay(500);               
        }
    }

    vote4++;
    cb=false;
    digitalWrite(12, LOW);
    showPartyOptions();
  }

  if (digitalRead(sw5) == LOW) {
    digitalWrite(13, HIGH);
    lcd.clear();
    determineWinner();
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("P1");
    lcd.setCursor(1, 1);
    lcd.print(vote1);
    lcd.setCursor(3, 0);
    lcd.print(" P2");
    lcd.setCursor(5, 1);
    lcd.print(vote2);
    lcd.setCursor(7, 0);
    lcd.print(" P3");
    lcd.setCursor(9,1);
    lcd.print(vote3);
    lcd.setCursor(11, 0);
    lcd.print(" NOTA ");
    lcd.setCursor(13, 1);
    lcd.print(vote4);
    delay(4000);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Thanks for");
    lcd.setCursor(5,1);
    lcd.print("Voting!");
    delay(4000);
    resetVotes();
    showPartyOptions();
  }
}
}

void showPartyOptions() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("1)P1");
  lcd.setCursor(2, 1);
  lcd.print("2)P2");
  lcd.setCursor(8, 0);
  lcd.print("3)P3");
  lcd.setCursor(8, 1);
  lcd.print("4)NOTA");
}

void determineWinner() {
  int totalVotes = vote1 + vote2 + vote3 + vote4;
  lcd.clear();
  if (totalVotes > 0) {
    if (vote1 > vote2 && vote1 > vote3 && vote1 > vote4) {
      lcd.print("P1 Wins!");
    } else if (vote2 > vote1 && vote2 > vote3 && vote2 >vote4) {
      lcd.print("P2 Wins!");
    } else if (vote3 > vote1 && vote3 > vote2 && vote3 > vote4) {
      lcd.print("P3 Wins!");
    } else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3) {
      lcd.print("No One Won!");
    }
     else {
        lcd.print("Tie Up Or");
        lcd.setCursor(0, 1);
        lcd.print("No Result");
      }
    }else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("No Voting....");
    }
}

void resetVotes() {
  vote1 = 0;
  vote2 = 0;
  vote3 = 0;
  vote4 = 0;
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}