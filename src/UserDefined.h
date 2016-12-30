#include <stdlib.h>

//Types
typedef struct {
    int dataSize;
    void *data;
} Data;

typedef Data (*UDAction)(Data dataFromRequest);

//Variables
int numberOfUDActions;
UDAction *actions;

//Functions
void initUD(void);
void shutdownUD(void);
Data doUD(int UDIndex, Data dataFromRequest);