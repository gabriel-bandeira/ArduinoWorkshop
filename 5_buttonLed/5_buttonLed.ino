/*
	Mudar o valor do estado do Led de acordo com o valor do botao
	Sugestoes de mudancas:
		O Led pode ser setado para blinkar quando o botao for pressionado
		ou pode fazer um Fade,
		ou modificar a velocidade da piscagem de acordo com a quantidade de vezes que o botao eh pressionado

	Circuito: https://www.tinkercad.com/things/fLbJJlb1iWt-4ledbutton/editel
*/

// Setando o pino digital para ser o ledPin
int ledPin = 10;

// Setando o pino digital para ser o buttonPin
int buttonPin = 7;


// Funcao setup, para inicializar alguns parametros
void setup()
{
	// Setando o pino do led como saida
	pinMode(ledPin, OUTPUT);
	// Setando o pino do botao como entrada
	pinMode(buttonPin, INPUT);
	// Liberando a comunicacao serial, para velocidade de 9600
	Serial.begin(9600);
}

// Funcao que fica rodando enquanto o arduino estiver ligado
void loop()
{
	// salvando o valor da porta A0, que esta o LDR na variavel ldrValue
	int buttonState = digitalRead(buttonPin);

	// imprime na tela serial o valor lido do LDR
	Serial.print("Estado do botao: ");
	Serial.println(buttonState);

	// Vendo se o ldrValue esta dentro ou nao do threshold para ativar o led
	if(buttonState == HIGH)
	{
		// Acender o LED
		digitalWrite(ledPin, HIGH);
	} 
	else
	{
		// Apagar o LED
		digitalWrite(ledPin, LOW);
	}
}
