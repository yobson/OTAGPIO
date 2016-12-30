#include "UserDefined.h"
#include <wiringPi.h>

void initUD() {
    atexit(&shutdownUD);
    numberOfUDActions = 0; //Change this to the number of UDActions you have
    actions = malloc(sizeof(UDAction) * numberOfUDActions);
    //Add them to the array here;
}

void shutdownUD() {
    free(actions);
}

Data doUD(int UDIndex, Data dataFromRequest) {
    if (UDIndex > numberOfUDActions) { Data ret = {.data = NULL, .dataSize = 0}; return ret; }
    return actions[UDIndex](dataFromRequest);
}