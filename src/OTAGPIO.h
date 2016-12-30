#include <kore/kore.h>
#include <kore/http.h>
#include <stdio.h>
#include <stdlib.h>

void initApp(void);
void shutdownApp(void);

int indexPage(struct http_request *);
int	setPinMode(struct http_request *);
int pinWrite(struct http_request *);
int pinRead(struct http_request *);

int udaction(struct http_request *);