#include <Servo.h>
#include <LiquidCrystal.h>

Servo servo; // Cria um objeto Servo
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Configura os pinos do LCD

// Leds
const int verde = 12;
const int vermelho = 13;
// Sensor de presença
const int trigger = 9;
const int echo = 8;
// Servo
const int servoPin = 10;
// Buzzer
const int buzzer = 11;

void setup() {
    // Leds
    pinMode(verde, OUTPUT);
    pinMode(vermelho, OUTPUT);
    digitalWrite(verde, LOW);
    digitalWrite(vermelho, HIGH);
    // Sensor de presença
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    // Servo
    servo.attach(servoPin);
    servo.write(0); // Posição inicial do servo
    // Serial
    Serial.begin(9600);
    // LCD
    lcd.begin(16, 2);
}

void loop() {
    // Limpa o Gatilho
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    // Dispara o pulso
    digitalWrite(trigger, HIGH);  
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    // Calcula o tempo de resposta
    long duracao = pulseIn(echo, HIGH);
    // Calcula a distância
    long distancia = duracao * 0.034 / 2;

    // Abertura
    if (distancia < 120) {
        servo.write(90); // Abre a porta
        digitalWrite(verde, HIGH);
        digitalWrite(vermelho, LOW);
        tone(buzzer, 1000); // Emite um som
        delay(200);
        noTone(buzzer); // Para o som
        delay(500);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Cancela Aberta");

    
    // Fechamento
    } else {
        servo.write(0); // Fecha a porta
        digitalWrite(verde, LOW);
        digitalWrite(vermelho, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Cancela Fechada");
    }
    delay(300); // Aguarda 
}