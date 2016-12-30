#include "UserDefined.h"
#include <wiringPi.h>

void initUD() {
    atexit(&shutdownUD);
    numberOfUDActions = 0;
    actions = malloc(sizeof(action) * numberOfUDActions);
}

void shutdownUD() {
    free(actions);
}

Data doUD(int UDIndex, Data dataFromRequest) {
    if (UDIndex > numberOfUDActions) { Data ret = {.data = NULL, .dataSize = 0}; return ret; }
    return actions[UDIndex](dataFromRequest);
}