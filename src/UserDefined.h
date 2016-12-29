#include <stdlib.h>

//Types
typedef struct {
    int dataSize;
    void *data;
} Data;

typedef Data (*action)(Data dataFromRequest);

//Variables
int numberOfUDActions;
action *actions;

//Functions
void initUD(void);
void shutdownUD(void);
Data doUD(int UDIndex, Data dataFromRequest);