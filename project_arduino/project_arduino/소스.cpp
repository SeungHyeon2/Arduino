#include <Servo.h>
#include <LiquidCrystal.h>
#include "LedControl.h"

int i = 0;
// 가위바위보 변수
int jan = 4;
int ken = 2;
int po = 3;
long randNumber;
//lcd모니터
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
LedControl lc = LedControl(A0, A1, A2, 1);
LedControl lc1 = LedControl(A3, A4, A5, 1);
//초음파센서
int trig = 5;
int echo = 6;
//서보
Servo myservo;
int angle = 0;
//가위바위보 함수
byte ledjan[] =
{
  B00000000,
  B00000010,
  B01100100,
  B01111000,
  B01111110,
  B01111000,
  B01111000,
  B00000000
};

byte ledken[] =
{
  B00000000,
  B00111100,
  B11111110,
  B11111110,
  B11111110,
  B11111110,
  B00111100,
  B00000000
};

byte ledpo[] =
{
  B00010000,
  B00110000,
  B01100000,
  B01111110,
  B01111110,
  B01111110,
  B01111110,
  B00000000
};

byte ledchoice[] =
{
  B00000000,
  B00000100,
  B00000010,
  B00000001,
  B10110001,
  B00001010,
  B00000100,
  B00000000
};
byte ledjan1[] =
{
  B00000000,
  B00000010,
  B01100100,
  B01111000,
  B01111110,
  B01111000,
  B01111000,
  B00000000
};

byte ledken1[] =
{
  B00000000,
  B00111100,
  B11111110,
  B11111110,
  B11111110,
  B11111110,
  B00111100,
  B00000000
};

byte ledpo1[] =
{
  B00010000,
  B00110000,
  B01100000,
  B01111110,
  B01111110,
  B01111110,
  B01111110,
  B00000000
};

byte ledchoice1[] =
{
  B00000000,
  B00000100,
  B00000010,
  B00000001,
  B10110001,
  B00001010,
  B00000100,
  B00000000
};
void function1() {
    randNumber = random(1, 4);
    Serial.println(randNumber);
    Serial.println(digitalRead(jan)); //3은 보재기 1은 가위 2는 돌멩이
    Serial.println(digitalRead(ken)); //3은 보재기 1은 가위 2는 돌멩이
    Serial.println(digitalRead(po)); //3은 보재기 1은 가위 2는 돌멩이
    if (digitalRead(jan) == LOW) {
        display_ledjan(0);
        if (randNumber == 3) {
            display_ledpo1(0);
            lcd.clear();
            lcd.setCursor(0, 0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
            lcd.print("***you  win***");      // 문구를 출력합니다.
            lcd.setCursor(0, 1);
            lcd.print("congratulations!");
            Serial.println("가위로 이겼다");
            i = 10;
            myservo.write(180);
            delay(1000);
            myservo.write(0);
            delay(1000);
            myservo.write(180);
            delay(1000);
            myservo.write(0);
            delay(1000);
        }
        else if (randNumber == 2) {
            display_ledken1(0);
            lcd.clear();
            lcd.setCursor(0, 0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
            lcd.print("***you lose***");       // 문구를 출력합니다.
            lcd.setCursor(0, 1);
            lcd.print("that's too bad");
            Serial.println("가위로 졌다");
            i = 10;
        }
        else {
            display_ledjan1(0);
            lcd.clear();
            lcd.setCursor(0, 0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
            lcd.print("***you draw***");       // 문구를 출력합니다.
            lcd.setCursor(0, 1);
            lcd.print("Keep trying!");
            Serial.println("가위로 비겼다");
            i = 10;
        }
        delay(5000);
        lcd.clear();
    }
    else if (digitalRead(ken) == LOW) {
        display_ledken(0);
        if (randNumber == 1) {
            display_ledjan1(0);
            lcd.clear();
            lcd.setCursor(0, 0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
            lcd.print("***you  win***");       // 문구를 출력합니다.
            lcd.setCursor(0, 1);
            lcd.print("congratulations!");
            Serial.println("바위로 이겼다");
            i = 10;
            myservo.write(180);
            delay(1000);
            myservo.write(0);
            delay(1000);
            myservo.write(180);
            delay(1000);
            myservo.write(0);
            delay(1000);

        }
        else if (randNumber == 3) {
            display_ledpo1(0);
            lcd.clear();
            lcd.setCursor(0, 0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
            lcd.print("***you lose***");       // 문구를 출력합니다.
            lcd.setCursor(0, 1);
            lcd.print("that's too bad");
            Serial.println("바위로 졌다");
            i = 10;
        }
        else {
            display_ledken1(0);
            lcd.clear();
            lcd.setCursor(0, 0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
            lcd.print("***you draw***");       // 문구를 출력합니다.
            lcd.setCursor(0, 1);
            lcd.print("Keep trying!");
            Serial.println("바위로 비겼다");
            i = 10;
        }
        delay(5000);
        lcd.clear();
    }

    else if (digitalRead(po) == LOW) {
        display_ledpo(0);

        if (randNumber == 2) {
            display_ledken1(0);
            lcd.clear();
            lcd.setCursor(0, 0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
            lcd.print("***you  win***");       // 문구를 출력합니다.
            Serial.println("보로 이겼다");
            lcd.setCursor(0, 1);
            lcd.print("congratulations!");
            i = 10;
            myservo.write(180);
            delay(1000);
            myservo.write(0);
            delay(1000);
            myservo.write(180);
            delay(1000);
            myservo.write(0);
            delay(1000);

        }
        else if (randNumber == 1) {
            display_ledjan1(0);
            lcd.clear();
            lcd.setCursor(0, 0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
            lcd.print("***you lose***");       // 문구를 출력합니다.
            lcd.setCursor(0, 1);
            lcd.print("that's too bad");
            Serial.println("보로 졌다");
            i = 10;
        }
        else {
            display_ledpo1(0);
            lcd.clear();
            lcd.setCursor(0, 0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
            lcd.print("***you draw***");       // 문구를 출력합니다.
            lcd.setCursor(0, 1);
            lcd.print("Keep trying!");
            Serial.println("보로 비겼다");
            i = 10;
        }
        delay(5000);
        lcd.clear();
    }
    else {
        // 0번째 줄 0번째 셀부터 입력하게 합니다.
        lcd.clear();
        lcd.setCursor(0, 0);
        display_ledchoice(0);
        display_ledchoice1(0);
        lcd.print("push the button" + String(int(10) - int(i)));
        Serial.println("버튼을 눌러주세요.");
    }
}
void setup() {
    Serial.begin(9600);
    pinMode(jan, INPUT_PULLUP);
    pinMode(ken, INPUT_PULLUP);
    pinMode(po, INPUT_PULLUP);
    //lcd모니터
    lcd.begin(16, 2);
    lcd.clear();
    //초음파센서
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    //서보
    myservo.attach(7);
    //도트 매트릭스
    lc.shutdown(0, false);
    lc.setIntensity(0, 3);
    lc.clearDisplay(0);
    lc1.shutdown(0, false);
    lc1.setIntensity(0, 3);
    lc1.clearDisplay(0);
}
void loop() {
    //초음파센서
    digitalWrite(trig, LOW);
    digitalWrite(echo, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    unsigned long duration = pulseIn(echo, HIGH);
    float distance = duration / 29.0 / 2.0;
    Serial.print(distance);
    Serial.println("cm");
    if (distance < 5) {
        while (i < 10) {
            lcd.clear();
            lcd.setCursor(0, 0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
            Serial.println("코인을 넣어주세요.");
            function1();
            Serial.println(String(int(10) - int(i)) + "초 남았습니다");
            i++;
            delay(1000);

        }

    }
    else {
        lcd.clear();
        lcd.setCursor(0, 0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
        lcd.print("Insert Coin 0/1");
        Serial.println("코인을 넣어주세요.");
        i = 0;
        display_ledjan(0);
        delay(30);
        display_ledken(0);
        delay(30);
        display_ledpo(0);

        display_ledjan1(0);
        delay(30);
        display_ledken1(0);
        delay(30);
        display_ledpo1(0);

    }
}
void display_ledjan(int a)
{
    if (a == 0) {
        for (int i = 0; i < 8; i++)
        {
            lc.setRow(0, i, ledjan[i]);
        }
    }
    else {
        for (int i = 0; i < 8; i++)
        {
            lc.setRow(0, i, B01010101);
        }
    }
}


void display_ledken(int a)
{
    if (a == 0) {
        for (int i = 0; i < 8; i++)
        {
            lc.setRow(0, i, ledken[i]);
        }
    }
    else {
        for (int i = 0; i < 8; i++)
        {
            lc.setRow(0, i, B01010101);
        }
    }
}


void display_ledpo(int a)
{
    if (a == 0) {
        for (int i = 0; i < 8; i++)
        {
            lc.setRow(0, i, ledpo[i]);
        }
    }
    else {
        for (int i = 0; i < 8; i++)
        {
            lc.setRow(0, i, B01010101);
        }
    }
}

void display_ledchoice(int a)
{
    if (a == 0) {
        for (int i = 0; i < 8; i++)
        {
            lc.setRow(0, i, ledchoice[i]);
        }
    }
    else {
        for (int i = 0; i < 8; i++)
        {
            lc.setRow(0, i, B01010101);
        }
    }
}
void display_ledjan1(int a)
{
    if (a == 0) {
        for (int i = 0; i < 8; i++)
        {
            lc1.setRow(0, i, ledjan1[i]);
        }
    }
    else {
        for (int i = 0; i < 8; i++)
        {
            lc1.setRow(0, i, B01010101);
        }
    }
}


void display_ledken1(int a)
{
    if (a == 0) {
        for (int i = 0; i < 8; i++)
        {
            lc1.setRow(0, i, ledken1[i]);
        }
    }
    else {
        for (int i = 0; i < 8; i++)
        {
            lc1.setRow(0, i, B01010101);
        }
    }
}


void display_ledpo1(int a)
{
    if (a == 0) {
        for (int i = 0; i < 8; i++)
        {
            lc1.setRow(0, i, ledpo1[i]);
        }
    }
    else {
        for (int i = 0; i < 8; i++)
        {
            lc1.setRow(0, i, B01010101);
        }
    }
}

void display_ledchoice1(int a)
{
    if (a == 0) {
        for (int i = 0; i < 8; i++)
        {
            lc1.setRow(0, i, ledchoice1[i]);
        }
    }
    else {
        for (int i = 0; i < 8; i++)
        {
            lc1.setRow(0, i, B01010101);
        }
    }
}