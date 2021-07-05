#include <Arduino.h>

int incoming = 0;
int a[100] = {0};
int i = 0;
int max_a = 0;
bool incoming_data = false;
bool data_end = true;

int incomingbyte = 0;

void setup() {
	Serial.begin(115200);
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	int value = 0;
	String value_str = "";

  	while (Serial.available() > 0 || !data_end) {   
		data_end = false; 
    	incoming_data = true;
    	value_str = Serial.readStringUntil('\n');

    	value = value_str.toInt();
		Serial.print("value ");
		Serial.println(value_str);
    	if (value_str[0] != 'e') {
      		a[i] = value;
      		++i;
    	}
    	else {
      		data_end = true; //end of data
    	} 
  	}
  	max_a = i;

	if (incoming_data) {
    	for(i = 0; i < max_a; i++) {
      		if (a[i] == 10) {
				Serial.println(a[i]);
				digitalWrite(LED_BUILTIN, HIGH);
				delay(500);
				digitalWrite(LED_BUILTIN, LOW);
				delay(500);
    		}
    	}
    	incoming_data = false;
    	i = 0;
  	}
}
