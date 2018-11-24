#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "venta.h"


int main()
{
    LinkedList* listaVentas= ll_newLinkedList();


    if(!controller_loadFromText("data.csv",listaVentas))
    {
        controller_generarInforme(listaVentas);
    }
    //ll_map(listaVentas,venta_mostrar);
    return 0;
}
