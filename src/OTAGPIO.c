#include "OTAGPIO.h"
#include "UserDefined.h"
#include <wiringPi.h>

void initApp(){
	atexit(&shutdownApp);
	wiringPiSetup();
}

void shutdownApp() {
	
}

int indexPage(struct http_request *req) {
	http_response_header(req, "content-type", "text/html");
	http_response(req, 200, "Hello World", 12);
	return KORE_RESULT_OK;
}

int setPinMode(struct http_request *req)
{
	http_populate_get(req);
	int pinNumber;
	char *mode;
	http_argument_get_int32(req, "num", &pinNumber);
	http_argument_get_string(req, "mode", &mode);

	if (strncmp(mode, "READ", 4)) {
		pinMode(pinNumber, OUTPUT);
	} else {
		pinMode(pinNumber, INPUT);
	}

	http_response(req, 200, NULL, 0);
	return KORE_RESULT_OK;
}

int pinWrite(struct http_request *req)
{
	http_populate_get(req);
	int pinNumber, state;
	http_argument_get_int32(req, "num", &pinNumber);
	http_argument_get_int32(req, "state", &state);

	digitalWrite(pinNumber, (state == 1) ? HIGH : LOW);

	http_response(req, 200, NULL, 0);
	return KORE_RESULT_OK;
}

int pinRead(struct http_request *req) {
	http_populate_get(req);
	int pinNumber, state;
	http_argument_get_int32(req, "num", &pinNumber);

	state = digitalRead(pinNumber);

	http_response(req, 200, (void *) &state, sizeof(int));
	return KORE_RESULT_OK;
}

int udaction(struct http_request *req) 
{
	http_populate_get(req);
	Data data, ret;
	int act;
	http_argument_get_string(req, "num", (char *)data.data);
	http_argument_get_int32(req, "length", &data.dataSize);
	http_argument_get_int32(req, "action", &act);

	if (act < numberOfActions) {ret = actions[act](data);}
	else {
		http_response(req, 400, NULL, 0);
	}

	http_response(req, 200, ret.data, ret.dataSize);
	return KORE_RESULT_OK;
}
