#include "LinkedList.h"
#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
int controller_generarInforme (LinkedList* pArrayListEmployee);


#endif //controller_H_INCLUDED
