#include "OTAGPIO.h"
#include "UserDefined.h"

void initApp(){
	atexit(&shutdownApp);
}

void shutdownApp() {
	
}

int indexPage(struct http_request *req) {
	http_response_header(req, "content-type", "text/html");
	http_response(req, 200, "Hello World", 12);
	return KORE_RESULT_OK;
}

int pinMode(struct http_request *req)
{
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
