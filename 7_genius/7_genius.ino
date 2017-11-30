/*
	Genius game

	Circuito para um botao: https://www.tinkercad.com/things/fLbJJlb1iWt-4ledbutton/editel
*/

#define NUM_OF_LEDS 4
#define MAX_GENIUS_SEQUENCY 50


// Setando os pinos digitais para serem os ledPins
int ledPins[NUM_OF_LEDS] = {8, 9, 10, 11};

// Setando os pinos digitais para serem os buttonPins
int buttonPins[NUM_OF_LEDS] = {4, 5, 6, 7};

int buzzerPin = 13;

// Sequencia para jogo genius
int gameSeq[MAX_GENIUS_SEQUENCY] = {0};
int currentButtonIndex = 0;


void startOver() {
	currentButtonIndex = 0;
	for(int i = 0; i < MAX_GENIUS_SEQUENCY; i++) {
		gameSeq[i] = (int)random(0, 4);
	}
}


void blink(int rep, int delay_time = 500) {
	for(int r = 0; r < rep; r++) {
		digitalWrite(buzzerPin, HIGH);
		for(int i = 0; i < NUM_OF_LEDS; i++)
			digitalWrite(ledPins[i], HIGH);
		delay(delay_time);
		digitalWrite(buzzerPin, LOW);
		for(int i = 0; i < NUM_OF_LEDS; i++)
			digitalWrite(ledPins[i], LOW);
		delay(delay_time);
	}
}

void game_over() {
	blink(3);
	startOver();
}

void win_game() {
	blink(5, 100);
	delay(500);
	blink(5, 100);
	delay(2000);
	startOver();
}


// Funcao setup, para inicializar alguns parametros
void setup() {
	// Setando os pinos dos leds como saida
	for (int i = 0; i < NUM_OF_LEDS; i++)
		pinMode(ledPins[i], OUTPUT);
	
	// Setando os pinos dos botoes como entrada
	for (int i = 0; i < NUM_OF_LEDS; i++)
		pinMode(buttonPins[i], INPUT);

	// Setando o pino do buzzer como saida
	pinMode(buzzerPin, OUTPUT);

	// Liberando a comunicacao serial, para velocidade de 9600
	Serial.begin(9600);

	// Se nao ha nada conectado a porta A0, o ruido de analogRead
	// vai fazer randomSeed ter diferentes sementes sempre que o
	// rodar novamente. randomSeed() ira entao reorganizar a funcao
	// random
	randomSeed(analogRead(A0));

	// Inicia o jogo
	startOver();
}


int getGeniusIndex() {
	int ret = 0;
	int read[NUM_OF_LEDS] = {0};
	int index = -1;
	while(ret == 0) {
		for (int i = 0; i < NUM_OF_LEDS; i++) {
			read[i] = digitalRead(buttonPins[i]);
			ret += read[i];
			if (read[i] == 1)
				index = i;
		}
		delay(50);
	}
	if (ret > 1)
		return -1;
	return index;
}

// Funcao que fica rodando enquanto o arduino estiver ligado
void loop() {
}
