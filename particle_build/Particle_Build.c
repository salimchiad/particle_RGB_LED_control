/*
This program light a 3 colors led from a html web page or Cpp controleur program.
*/

int led0 = D2; // RED pin LED (with 300 ohms resistor)
int led1 = D3; // GREEN pin LED (with 300 ohms resistor)
int led2 = D7; // BLUE pin LED (with 300 ohms resistor)

void setup()
{
	pinMode(led0, OUTPUT); // Pins in output mode
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);

	Spark.function("led",ledColor); // declaration of fonction ledColor on particle serveur with name led.

	digitalWrite(led0, LOW); // Turn OFF all leds.
	digitalWrite(led1, LOW);
	digitalWrite(led2, LOW);
}

void loop()
{
	// nothing to do here.
}

int ledColor(String command)			// Fonction called when you change the color.
{
	if (command=="RED") {				// RED called.
		digitalWrite(led0,HIGH);
		digitalWrite(led1,LOW);
		digitalWrite(led2,LOW);
		return 0;
	}
	else if (command=="GREEN") {		// GREEN called.
		digitalWrite(led0,LOW);
		digitalWrite(led1,HIGH);
		digitalWrite(led2,LOW);
		return 1;
	}
	else if (command=="BLUE") {			// BLUE called.
		digitalWrite(led0,LOW);
		digitalWrite(led1,LOW);
		digitalWrite(led2,HIGH);
		return 2;
	}
	else if (command=="YELLOW") {		// YELLOW called.
		digitalWrite(led0,HIGH);
		digitalWrite(led1,HIGH);
		digitalWrite(led2,LOW);
		return 3;
	}
	else if (command=="CYAN") {			// CYAN called.
		digitalWrite(led0,LOW);
		digitalWrite(led1,HIGH);
		digitalWrite(led2,HIGH);
	}
	else if (command=="VIOLET") {		// VIOLET called.
		digitalWrite(led0,HIGH);
		digitalWrite(led1,LOW);
		digitalWrite(led2,HIGH);
		return 5;
	}
	else if (command=="WHITE") {		// WHITE called.
		digitalWrite(led0,HIGH);
		digitalWrite(led1,HIGH);
		digitalWrite(led2,HIGH);
		return 6;
	}
	else if (command=="OFF") {			// OFF led called.
		digitalWrite(led0,LOW);
		digitalWrite(led1,LOW);
		digitalWrite(led2,LOW);
		return 7;
	}
	else {
		return -1;
	}
}
