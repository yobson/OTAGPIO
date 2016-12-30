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


	http_response(req, 200, NULL, 0);
	return KORE_RESULT_OK;
}

int pinWrite(struct http_request *req)
{
	http_response(req, 200, NULL, 0);
	return KORE_RESULT_OK;
}

int pinRead(struct http_request *req) {
	http_response(req, 200, NULL, 0);
	return KORE_RESULT_OK;
}

int udaction(struct http_request *req) 
{
	http_response(req, 200, NULL, 0);
	return KORE_RESULT_OK;
}
