/*
  Mudar o valor do estado do Led de acordo com o valor do botao
  Sugestoes de mudancas:
    Gerar sequencia aleatoria de leds e conferir se o usuario apertou a sequencia correta

  Circuito para um botao: https://www.tinkercad.com/things/fLbJJlb1iWt-4ledbutton/editel
*/

#define NUM_OF_LEDS 4
#define MAXIMO 10

// Setando os pinos digitais para serem os ledPins
int ledPins[NUM_OF_LEDS] = {10, 11, 12, 13};

// Setando os pinos digitais para serem os buttonPins
int buttonPins[NUM_OF_LEDS] = {2, 3, 4, 5};

int freq[NUM_OF_LEDS] = {300, 500, 700, 900};
int buzerPin = 6;

int resposta[MAXIMO] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int sequencia[MAXIMO] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int i = 0;

bool gerou = false;
bool pressionado[NUM_OF_LEDS] = {false, false, false, false};

// Funcao setup, para inicializar alguns parametros
void setup()
{
  // Setando os pinos dos leds como saida
  for (int i = 0; i < NUM_OF_LEDS; i++)
    pinMode(ledPins[i], OUTPUT);

  // Setando os pinos dos botoes como entrada
  for (int i = 0; i < NUM_OF_LEDS; i++)
    pinMode(buttonPins[i], INPUT_PULLUP);

  pinMode(buzerPin, OUTPUT);

  // Liberando a comunicacao serial, para velocidade de 9600
  Serial.begin(9600);

  // Dá a semente do random
  randomSeed(analogRead(0));
}

// Funcao que fica rodando enquanto o arduino estiver ligado
void loop()
{
  if (gerou == false)
    geraOrdem(5);


}

void geraOrdem(int qtd) {
  for (i = 0; i < qtd; i++) {
    sequencia[i] = random(1, 5);
    Serial.println(sequencia[i]);
  }

  i = 0;
  while (sequencia[i] > 0) {

    // Acender o LED
    digitalWrite(ledPins[sequencia[i] - 1], HIGH);
    // Toca o buzzer
    tone(buzerPin, freq[sequencia[i] - 1]);
    delay(500);

    // Apagar o LED
    digitalWrite(ledPins[sequencia[i] - 1], LOW);
    // Silencia o buzzer
    noTone(buzerPin);
    delay(500);
    i++;
  }

  gerou = true;
}

void leSequencia() {
  i = 0;
  while (sequencia[i] > 0) {

    for (int i = 0; i < NUM_OF_LEDS; i++)
    {
      // salvando o valor da porta buttonPin, que esta o botao, na variavel buttonState
      int buttonState = digitalRead(buttonPins[i]);

      // imprime na tela serial o valor lido do botao
      Serial.print("Estado do botao: ");
      Serial.println(buttonState);

      // Vendo se o botao esta pressionado para ativar o led
      if (buttonState == LOW)
      {
        // Acender o LED
        digitalWrite(ledPins[i], HIGH);

        // Toca o buzzer
        tone(buzerPin, freq[i]);

        resposta[i] = 
        pressionado[i] = true;
      }
      else
      {
        // Apagar o LED
        digitalWrite(ledPins[i], LOW);

        // Silencia o buzzer
        noTone(buzerPin);
      }
      if (pressionado[i] == true) {
        i++;
      }
    }

  }
}