#include <SoftwareSerial.h>					/* Call Library */

SoftwareSerial ESP(3, 2);     		   			 /* Rx, Tx */

void setup() {
	Serial.begin(9600);					/* Serial Port, 9600 or 115200 */
	ESP.begin(9600);					/* Connect to ESP-01, 9600 or 115200 */
	Serial.begin("Serial is begin!");
}

void loop() {
	/* If received data from Serial Console, sent to ESP-01 */
	if (Serial.available()) {
		ESP.print(Serial.read());			/* If ESP has no response, change "print" to "write"
	}
	
	/* If received data from ESP-01, sent to Serial Console */
	if (ESP.available()) {
		Serial.print(ESP.read());
	}
}
