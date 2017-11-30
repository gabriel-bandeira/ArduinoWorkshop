/*
	Mudar o valor do estado do Led de acordo com o valor do botao
	Sugestoes de mudancas:
		Gerar sequencia aleatoria de leds e conferir se o usuario apertou a sequencia correta

	Circuito para um botao: https://www.tinkercad.com/things/fLbJJlb1iWt-4ledbutton/editel
*/

#define NUM_OF_LEDS 4

// Setando os pinos digitais para serem os ledPins
int ledPins[NUM_OF_LEDS] = {8, 9, 10, 11};

// Setando os pinos digitais para serem os buttonPins
int buttonPins[NUM_OF_LEDS] = {4, 5, 6, 7};


// Funcao setup, para inicializar alguns parametros
void setup()
{
	// Setando os pinos dos leds como saida
	for (int i = 0; i < NUM_OF_LEDS; i++)
		pinMode(ledPins[i], OUTPUT);
	
	// Setando os pinos dos botoes como entrada
	for (int i = 0; i < NUM_OF_LEDS; i++)
		pinMode(buttonPins[i], INPUT);

	// Liberando a comunicacao serial, para velocidade de 9600
	Serial.begin(9600);
}

// Funcao que fica rodando enquanto o arduino estiver ligado
void loop()
{
	for (int i = 0; i < NUM_OF_LEDS; i++)
	{
		// salvando o valor da porta buttonPin, que esta o botao, na variavel buttonState
		int buttonState = digitalRead(buttonPins[i]);

		// imprime na tela serial o valor lido do botao
		Serial.print("Estado do botao: ");
		Serial.println(buttonState);

		// Vendo se o botao esta pressionado para ativar o led
		if(buttonState == HIGH)
		{
			// Acender o LED
			digitalWrite(ledPins[i], HIGH);
		} 
		else
		{
			// Apagar o LED
			digitalWrite(ledPins[i], LOW);
		}
	}
}
