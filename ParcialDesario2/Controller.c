#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "venta.h"
#include <string.h>

/** \brief Carga los datos de las ventas desde el archivo data.csv (modo texto).
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* lista donde se va a guardar el archivo
 * \return [0] Exito y [-1] Error
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo = fopen(path,"r");
    if(ll_isEmpty(pArrayListEmployee))
    {

        retorno = parser_ventaFromText(pArchivo,pArrayListEmployee);
        if(retorno!=-1 && !ll_isEmpty(pArrayListEmployee))
        {
            printf("ARCHIVO CARGADO CON EXITO!\nCANTIDAD DE ARTICULOS: %d\n", ll_len(pArrayListEmployee));
            retorno = 0;
        }

    }
    fclose(pArchivo);

    return retorno;
}
/** \brief Funcion que genera el archivo donde se van a guardar los datos
 * \param path char* ruta del archivo a guardar
 * \param pArrayListEmployee LinkedList* listaen la cual se encuentran los datos a guardar
 * \return [0] Exito y [-1] Error
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path,"w");
    int retorno = -1;
    if(pArchivo != NULL && !parser_SaveToText(pArchivo,pArrayListEmployee) &&
            pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
    {
        retorno = 0;
        printf("\nARCHIVO %s GUARDADO CON EXITO", path);
    }

    return retorno;
}
/** \brief Funcion que genera un informe.txt
 * \param pArrayListEmployee LinkedList* lista de la cual se van a tomar los datos para el informe
 * \return [0] Exito y [-1] Error
 */
int controller_generarInforme (LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(!controller_saveAsText("informes.txt",pArrayListEmployee))
    {
        retorno = 0;
    }
    return retorno;
}
