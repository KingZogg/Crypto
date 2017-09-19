/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
// Allow for receiving messages up to 512 bytes long
#define BLYNK_MAX_READBYTES 512

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "aaa03396e349483c90b4b84049db47a8";                                       // Your Blynk authentication string

char ssid[] = "GamerShrimp-25G";
char pass[] = "combatwombat$$$###combatwombat";
char server[] = "blynk-cloud.com";

//String tosendtoWebhook = "/json?lat=31.9505269&lng=115.8604572&date=2017-09-19";
String tosendtoWebhook = "/json?lat=51.5073509&lng=0&date=2017-09-19";

BLYNK_WRITE(V0)
{
	Serial.println("WebHook data:");
	Serial.println(param.asStr());
}

void setup()
{
	Serial.begin(115200);
	Serial.println();
	Blynk.begin(auth, ssid, pass, server);
	Blynk.virtualWrite(V0, tosendtoWebhook);
}

void loop()
{
	Blynk.run();
}
