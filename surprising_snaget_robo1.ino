const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5;
const int ledPin5 = 6;
const int ledPin6 = 7;
const int ledPin7 = 8;
const int ledPin8 = 9;

const int botaoIniciarPin = 10;
const int botaoPararPin = 11;

bool efeitoLigado = false;
int direcao = 0; // 0 = direita pra esquerda, 1 = esquerda pra direita

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);

  pinMode(botaoIniciarPin, INPUT_PULLUP);
  pinMode(botaoPararPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(botaoPararPin) == LOW) {
    efeitoLigado = false;
    desligarTodosOsLeds();
    delay(200); 
  }

  if (digitalRead(botaoIniciarPin) == LOW) {
    efeitoLigado = true;
    direcao = !direcao;  // alterna entre 0 e 1
    delay(200);
  }

  if (efeitoLigado) {
    if (direcao == 0) {
      piscarDireitaParaEsquerda();
    } else {
      piscarEsquerdaParaDireita();
    }
  }

  delay(50);
}

void piscarDireitaParaEsquerda() {
  int leds[] = {9, 8, 7, 6, 5, 4, 3, 2};
  for (int i = 0; i < 8; i++) {
    digitalWrite(leds[i], HIGH);
    delay(200);
    digitalWrite(leds[i], LOW);
    delay(200);
  }
}

void piscarEsquerdaParaDireita() {
  int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < 8; i++) {
    digitalWrite(leds[i], HIGH);
    delay(200);
    digitalWrite(leds[i], LOW);
    delay(200);
  }
}

void desligarTodosOsLeds() {
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  digitalWrite(ledPin6, LOW);
  digitalWrite(ledPin7, LOW);
  digitalWrite(ledPin8, LOW);
}
