#ifndef VALIDATOR_H_INCLUDED
#define VALIDATOR_H_INCLUDED


int validator_StringFloatEsValido (char* pArray, int limiteArray);
int validator_StringCodigoProductoEsValido (char* pArray, int limiteArray);
char validator_StringTelefonoEsValido (char* pArray, int limiteArray);
int validator_StringIntEsValido(char* pArray, int limiteArray);
int validator_isValidCuilOrCuit(char *pBuffer, int limite);
int validator_StringCharEsValidoDos(char* array,int size);
int validator_isValidEntero(char *pBuffer, int limite);
int validator_StringCharEsValido (char* pArray, int limiteArray);
int validator_isValidFecha(char* pArray);

#endif // VALIDATOR_H_INCLUDED
