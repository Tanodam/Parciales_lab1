#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "venta.h"
#include <string.h>
#define BUFFER 4096

/** \brief Parsea los datos los datos de ventas desde el archivo data.csv (modo texto).
 * \param FILE* pFile Puntero del tipo file al archivo que hay que parsear
 * \param pArrayListEmployee LinkedList* lista donde se van a guardar las ventass
 * \return Exito=1 y Error=-0
 */
int parser_ventaFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Venta* pVenta;
    char string[2000];
    char bufferCodigoProducto[BUFFER];
    char bufferFecha[BUFFER];
    char bufferId[BUFFER];
    char bufferCantidad[BUFFER];
    char bufferPrecioUnitario[BUFFER];
    char bufferCuit[BUFFER];
    int retorno = -1;

    if(pFile != NULL)
    {
        fgets(string,sizeof(string),pFile);
        while(!feof(pFile))
        {
            fgets(string,sizeof(string),pFile);
            if(strlen(string) > 5)
            {
                strncpy(bufferId,strtok(string, ","),BUFFER);
                strncpy(bufferFecha,strtok(NULL,","),BUFFER);
                strncpy(bufferCodigoProducto,strtok(NULL,","),BUFFER);
                strncpy(bufferCantidad,strtok(NULL,","),BUFFER);
                strncpy(bufferPrecioUnitario,strtok(NULL,","),BUFFER);
                strncpy(bufferCuit,strtok(NULL,"\n"),BUFFER);
                pVenta = venta_newConParametros(bufferCodigoProducto,bufferFecha,bufferPrecioUnitario,bufferId,bufferCantidad,bufferCuit);
               // printf("%s", bufferFecha/*,bufferFecha,bufferCuit,bufferPrecioUnitario*/);

                if(pVenta != NULL && !ll_add(pArrayListEmployee,pVenta))
                {
                    retorno = 1;
                }
            }
        }
    }
    return retorno; // OK
}

/** \brief Parsea los datos los datos de los infores al archivo informes.txt (modo texto).
 * \param FILE* pFile Puntero del tipo file al archivo que hay que parsear
 * \param pArrayListEmployee LinkedList* lista de ventas
 * \return Exito=1 y Error=-0
 */
int parser_SaveToText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int contadorDiez = 0;
    int contadorVeinte = 0;
    int contadorTV = 0;
    int contadorUnidadesTotales = 0;

    contadorDiez = ll_count(pArrayListEmployee,criterioMayorA10000);
    contadorVeinte = ll_count(pArrayListEmployee,criterioMayorA20000);
    contadorTV = ll_count(pArrayListEmployee,criterioTV);
    contadorUnidadesTotales = ll_count(pArrayListEmployee,criterioUnidades);
    if(pFile != NULL)
    {
        fprintf(pFile,"\n*********************\nInforme de ventas\n*********************\n"
                "- Cantidad de unidades vendidas totales: %d\n"
                "- Cantidad de ventas por un monto mayor a $10000: %d\n"
                "- Cantidad de ventas por un monto mayor a $20000: %d\n"
                "- Cantidad de TV's LCD vendidas: %d\n"
                "*********************",contadorUnidadesTotales,contadorDiez,contadorVeinte,contadorTV);
        retorno = 0;
    }
    fclose(pFile);
    printf("\n*********************\nInforme de ventas\n*********************\n"
                "- Cantidad de unidades vendidas totales: %d\n"
                "- Cantidad de ventas por un monto mayor a $10000: %d\n"
                "- Cantidad de ventas por un monto mayor a $20000: %d\n"
                "- Cantidad de TV's LCD vendidas: %d\n"
                "*********************",contadorUnidadesTotales,contadorDiez,contadorVeinte,contadorTV);
    return retorno;
}
