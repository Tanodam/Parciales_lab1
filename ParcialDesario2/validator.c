#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
*\brief [Funcion interna de GetStringFloat] Valida que el usuario solo haya ingresado caracteres del 0 al 9
*\param pArray Puntero a la direccion de memoria donde esta almacenada el string a validar
*\param limiteArray tamaño del array
*\return Exito=0 y Error=-1
*/
int validator_StringFloatEsValido (char* pArray, int limiteArray)
{
    int i=0;
    int retorno = 0;
    int contadorPuntos = 0;


    if(pArray != NULL && limiteArray > 0)
    {
        retorno = 1;
        for(i=0; i < limiteArray && pArray[i] != '\0'; i++)
        {
            switch(pArray[i])
            {
            case 46: //Punto
                if(i==0 || i==(strlen(pArray)-1))
                {
                    retorno = 0;
                    break;
                }
                contadorPuntos++;
                break;
            default:          ///0                 9
                if((pArray[i] < 48 || pArray[i] > 57) || contadorPuntos > 1)
                {
                    retorno = 0;
                }
                break;
            }
        }
    }

    return retorno;
}
/**
*\brief [Funcion interna de GetStringInt] Valida que el usuario solo haya ingresado caracteres del 0 al 9
*\param pArray Puntero a la direccion de memoria donde esta almacenada el string a validar
*\param limiteArray tamaño del array
*\return Exito=0 y Error=-1
*/
int validator_StringIntEsValido(char* array, int size)
{
    int retorno = 0;
    int i;

    if(array != NULL && size > 0)
    {
        retorno = 1;
        for(i=0; i < size && array[i] != '\0'; i++)
        {
            if((array[i] < '0') && (array[i] > '9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
*\brief [Funcion interna de GetStringChar] Valida que el usuario solo haya ingresado caracteres de la A a la Z
*\param pArray Puntero a la direccion de memoria donde esta almacenada el string a validar
*\param limiteArray tamaño del array
*\return Exito=1 y Error=0
*/
int validator_StringCodigoProductoEsValido (char* pArray, int limiteArray)
{
    int retorno=-1;
    int i;

    if((pArray!= NULL && limiteArray > 0) && (strlen(pArray) > 0))
    {
        retorno = 1;

        for (i=1; i<limiteArray && pArray[i] != '\0'; i++) ///Recorre el array hasta el ultimo caracter ingresado, no incluye el \0
        {
            switch(pArray[i])
            {
            case 95: ///Guion bajo
                break;
            default:
                if((pArray[i] < 48 && pArray[i] > 57) || (pArray[i] > 65 && pArray[i] > 90))///Verifica que no haya espacios ni caracteres fuera de rango
                {

                    retorno = 0;

                }
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief Evalua si es un Cuil o Cuit (XX-XXXXXXXX-X)
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
int validator_isValidCuilOrCuit(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) == 13 &&
            pBuffer[2] == '-' && pBuffer[11] == '-')
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if((pBuffer[i] < '0' || pBuffer[i] > '9') && i!=2 && i!=11)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el string recibido tiene solo letras
 * \param array Es el array para validar su tipo
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int validator_StringCharEsValidoDos(char* array,int size)
{
    int retorno = 0;
    int i;
    int digitosIngresados;

    digitosIngresados = strlen(array);

    if(array != NULL)
    {
        retorno = 1;
        for(i=0; i < digitosIngresados && array[i] != '\0'; i++)
        {
            if((tolower(array[i]) < 'a' || tolower(array[i]) > 'z') && array[i]!= ' ' && array[i]!= '-')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief Evalua si se trata de un entero
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/
int validator_isValidEntero(char* array,int size)
{
    int retorno = 0;
    int i;

    if((array != NULL && size > 0 && strlen(array) > 0) &&
            (array[0] == '-' || array[0] == '+' ||
             (array[0] > '0' && array[0] <= '9')))//Verifico que el primer digito sea valido
    {
        retorno = 1;
        for(i=1; i < size && array[i] != '\0'; i++) //Verifico los digitos restantes
        {
            if(!(array[i] >= '0' && array[i] <= '9'))//Rango valido de numeros
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
*\brief [Funcion interna de GetStringChar] Valida que el usuario solo haya ingresado caracteres de la A a la Z
*\param pArray Puntero a la direccion de memoria donde esta almacenada el string a validar
*\param limiteArray tamaño del array
*\return Exito=1 y Error=0
*/
int validator_StringCharEsValido (char* pArray, int limiteArray)
{
    int retorno=-1;
    int i;
    int indiceEspacio=0;

    if((pArray!= NULL && limiteArray > 0) && (strlen(pArray) > 0))
    {
        retorno = 1;

        for (i=1; i<limiteArray && pArray[i] != '\0'; i++) ///Recorre el array hasta el ultimo caracter ingresado, no incluye el \0
        {
            switch(pArray[i])
            {
            case 39: ///Apostrofe
                break;
            case 45: ///Apostrofe
                break;
            case 32: ///Espacio
                indiceEspacio=i;
                if(indiceEspacio!=0)
                {
                    pArray[indiceEspacio+1]=toupper(pArray[indiceEspacio+1]);
                }
                break;
            default:           ///a                  z
                if((pArray[i] < 97) || (pArray[i] > 122))///Verifica que no haya espacios ni caracteres fuera de rango
                {
                    ///A                   Z
                    if((pArray[i] < 65) || (pArray[i] > 90))
                    {
                        retorno = 0;
                    }
                }
                break;
            }
        }
    }
    return retorno;
}

int validator_isValidFecha(char* pArray)
{
    int retorno = -1;
    char dias[3];
    char meses[3];
    char anios[5];
    int dia;
    int mes;
    int anio;
    static int i = 1;

    if(sscanf(pArray, "%2s/%2s/%4s", dias, meses, anios) == 3 && pArray != NULL )
    {
        i++;
        mes=atoi(meses);
        dia=atoi(dias);
        anio=atoi(anios);

        if ( mes >= 1 && mes <= 12 && validator_isValidEntero(dias,3))
        {
            switch ( mes )
            {
            case  1 :
            case  3 :
            case  5 :
            case  7 :
            case  8 :
            case 10 :
            case 12 :
                if (dia >= 1 && dia <= 31)
                {
                    //printf( "\n   FECHA CORRECTA" );
                }
                else
                {
                    //printf( "\n   FECHA INCORRECTA" );
                    retorno = 0;
                }
                break;

            case  4 :
            case  6 :
            case  9 :
            case 11 :
                if (dia >= 1 && dia <= 30)
                {
                    //printf( "\n   FECHA CORRECTA" );
                }
                else
                {
                    //printf( "\n   FECHA INCORRECTA\nNOOOOOOOOO" );
                    retorno = 0;
                }
                break;

            case  2 :
                if( (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0 )
                {
                    if ( dia >= 1 && dia <= 29 )
                    {
                        //      printf( "\n   FECHA CORRECTA" );
                    }
                    else
                    {
                        //    printf( "\n   FECHA INCORRECTA" );
                        retorno = 0;
                    }
                }
                else if ( dia >= 1 && dia <= 28 )
                {
                }
                else
                {
                    retorno = 0;
                }
            }
        }
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}
