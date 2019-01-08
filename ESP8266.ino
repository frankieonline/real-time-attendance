#include <SoftwareSerial.h>						/* Call Library */

SoftwareSerial ESP(3, 2);     		   			 /* Rx, Tx */

void sendATcmd(String cmd, unsigned int time) {
	/* cmd: Receive AT command String; time: Waiting Time */
	String response = "";						/* Receive ESP returned value */
	ESP.print(cmd);								/* Send AT Command to ESP */
	
	unsigned long timeout = time + millis();	/* Waiting Time */
	
	while (ESP.available() || millis() < timeout) {
		/* Wait until there is response or waiting time passed */
		while (ESP.available()) {
			char c = ESP.read();				/* Receive ESP response */
			response += c;
		}
	}
	
	Serial.print(response);						/* Show ESP response */
}

void setup() {
	Serial.begin(9600);							/* Serial Port, 9600 or 115200 */
	ESP.begin(9600);							/* Connect to ESP-01, 9600 or 115200 */
	Serial.begin("Serial is begin!");
}

void loop() {
	/* If received data from Serial Console, sent to ESP-01 */
	if (Serial.available()) {
		ESP.print(Serial.read());				/* If ESP has no response, change "print" to "write"
	}
	
	/* If received data from ESP-01, sent to Serial Console */
	if (ESP.available()) {
		Serial.print(ESP.read());
	}
}
