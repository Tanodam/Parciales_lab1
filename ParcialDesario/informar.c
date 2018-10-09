#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"
#include "ventaAfiches.h"
#include "array.h"


static int comparacionZona(Ventas* arrayUno, Ventas* arrayDos);
/**
* \brief Funcion que compara empleados por zona
* \param arrayUno es la primera zona que se va a comparar
* \param arrayUno es la segunda zona que se va a comparar
* \return si el primero es mayor devuelve 0(para que se realice el swap), si no -1
*/

static int comparacionZona(Ventas* arrayVentaUno, Ventas* arrayVentaDos)
{
    int retorno=-1;
    if(arrayVentaUno != NULL && arrayVentaDos != NULL && !arrayVentaUno->isEmpty && !arrayVentaDos->isEmpty)
    {
        if( arrayVentaUno->zona > arrayVentaDos->zona)
        {
            retorno = 0;
        }
    }
    return retorno;
}
/**
* \brief Funcion que muestra el cliente con mas ventas
* \param arrayClientes es el array de clientes utilizado para informar
* \param arrayVentas es el array de ventas utilizado para informar
* \return 0 si puede mostrar el cliente y -1 si hubo algun error
*/

int informar_clienteConMasVentas(Cliente* arrayClientes, Ventas* arrayVentas, int limiteClientes, int limiteVentas)
{
    int retorno=-1;
    int i, j;
    int contadorVentas=0;
    int ventasMaximo=0;
    int clienteMaximoConMasVentas=0;

    if(arrayClientes != NULL && arrayVentas != NULL)
    {
        for (i=0; i<limiteClientes; i++)
        {
            if(arrayClientes[i].isEmpty==0)
            {
                contadorVentas=0;
                for(j=0; j<limiteVentas; j++)
                {
                    if(arrayVentas[j].idCliente == arrayClientes[i].id && // Para cambiar criterio de busqueda en alguna venta modificar el strcmp
                            arrayVentas[j].isEmpty== 0)
                    {

                        contadorVentas++;

                    }
                }
                if(contadorVentas>ventasMaximo || i==0)
                {
                    ventasMaximo=contadorVentas;
                    clienteMaximoConMasVentas=i;
                }

            }

        }//Maximo
        printf("\nEl clinete con mas ventas es:");
        printf("\nID: %d",arrayClientes[clienteMaximoConMasVentas].id);
        printf("\nNombre: %s, %s",arrayClientes[clienteMaximoConMasVentas].nombre,
               arrayClientes[clienteMaximoConMasVentas].apellido);
        printf("\nCuit: %s",arrayClientes[clienteMaximoConMasVentas].cuit);
        printf("\nCantidad de ventas: %d\n",ventasMaximo);
        retorno = 0;


    }
    pausarPantalla();
    return retorno;
}

/**
* \brief Funcion que ordena el array comparando zonas.
* \param ventas* array Es el array que se recorre
* \param limite Es el limite de ventas
* \return El retorno es 0 si se realizo el ordenamiento, si no el retorno es -1.
*/
int informar_sortVentasPorZona(Ventas* arrayVentas, int limite)
{
    Ventas auxiliar;
    Ventas* array= arrayVentas;
    int retorno=-1;
    int i;
    int j;
    if(array != NULL && limite > 0 )
    {
        for(i=1; i < limite; i++)
        {
            auxiliar = array[i];
            j = i - 1;
            if(!auxiliar.isEmpty)
            {
                while ((j >= 0) && !comparacionZona(&array[j], &auxiliar))
                {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = auxiliar;
            }
        }
        retorno = 0;
    }
    return retorno;
}
/**
* \brief Funcion que muestra el cliente con mas ventas a cobrar y con mas ventas cobradas
* \param arrayClientes es el array de clientes utilizado para informar
* \param arrayVentas es el array de ventas utilizado para informar
* \param limiteclientes es el limite de clientes que tiene el programa
* \param limiteventas es el limite de ventas que tiene el programa
* \return 0 si puede mostrar los clientes y -1 si hubo algun error
*/
int informar_clienteConMasVentasACobraryCobradas(Cliente* arrayClientes, Ventas* arrayVentas, int limiteClientes, int limiteVentas)
{
    int retorno=-1;
    int i, j;
    int contadorVentasACobrar=0;
    int contadorVentasCobradas=0;
    int clienteConMasVentasACobrar=0;
    int clienteConMasVentasCobradas=0;
    int indexClienteConMasVentasACobrar=0;
    int indexClienteConMasVentasCobradas=0;

    if(arrayClientes != NULL && arrayVentas != NULL)
    {
        for (i=0; i<limiteClientes; i++)
        {
            if(arrayClientes[i].isEmpty==0)
            {
                contadorVentasACobrar=0;
                contadorVentasCobradas=0;
                for(j=0; j<limiteVentas; j++)
                {
                    if(arrayVentas[j].idCliente == arrayClientes[i].id && // Para cambiar criterio de busqueda en alguna venta modificar el strcmp
                            arrayVentas[j].isEmpty== 0 &&
                            strcmp(arrayVentas[j].estadoVenta, "A COBRAR")==0)
                    {
                        retorno = 0;
                        contadorVentasACobrar++;

                    }
                    if(arrayVentas[j].idCliente == arrayClientes[i].id && // Para cambiar criterio de busqueda en alguna venta modificar el strcmp
                            arrayVentas[j].isEmpty== 0 &&
                            strcmp(arrayVentas[j].estadoVenta, "COBRADA")==0)
                    {
                        retorno = 0;
                        contadorVentasCobradas++;

                    }
                }
                if(contadorVentasACobrar>clienteConMasVentasACobrar || i==0)
                {
                    clienteConMasVentasACobrar=contadorVentasACobrar;
                    indexClienteConMasVentasACobrar=i;
                }
                if(contadorVentasCobradas>clienteConMasVentasCobradas || i==0)
                {
                    clienteConMasVentasCobradas=contadorVentasCobradas;
                    indexClienteConMasVentasCobradas=i;
                }

            }

        }//Maximo a cobrar
        if(contadorVentasACobrar!=0)
        {
            printf("\nEl clinete con mas ventas a cobrar es:");
            printf("\nID: %d",arrayClientes[indexClienteConMasVentasACobrar].id);
            printf("\nNombre: %s, %s",arrayClientes[indexClienteConMasVentasACobrar].nombre,
                   arrayClientes[indexClienteConMasVentasACobrar].apellido);
            printf("\nCuit: %s",arrayClientes[indexClienteConMasVentasACobrar].cuit);
            printf("\nCantidad de ventas a cobrar: %d\n",clienteConMasVentasACobrar);
        }
        //Maximo cobrada
        if(arrayVentas!=NULL)
        {
            printf("\nEl clinete con mas ventas cobradas es:");
            printf("\nID: %d",arrayClientes[indexClienteConMasVentasCobradas].id);
            printf("\nNombre: %s, %s",arrayClientes[indexClienteConMasVentasCobradas].nombre,
                   arrayClientes[indexClienteConMasVentasCobradas].apellido);
            printf("\nCuit: %s",arrayClientes[indexClienteConMasVentasCobradas].cuit);
            printf("\nCantidad de ventas cobradas: %d\n",clienteConMasVentasCobradas);
        }

    }
    pausarPantalla();
    return retorno;
}
/**
* \brief Funcion que muestra el cliente con mas afiches a cobrar
* \param arrayClientes es el array de clientes utilizado para informar
* \param arrayVentas es el array de ventas utilizado para informar
* \param limiteclientes es el limite de clientes que tiene el programa
* \param limiteventas es el limite de ventas que tiene el programa
* \return 0 si puede mostrar el cliente y -1 si hubo algun error
*/
int informar_clienteConMasAfichesACobrar(Cliente* arrayClientes, Ventas* arrayVentas, int limiteClientes, int limiteVentas)
{
    int retorno=-1;
    int i, j;
    int contadorAfiches=0;
    int clienteConMasAfichesACobrar=0;
    int indexClienteConMasAfichesACobrar=0;

    if(arrayClientes != NULL && arrayVentas != NULL)
    {
        for (i=0; i<limiteClientes; i++)
        {
            if(arrayClientes[i].isEmpty==0)
            {
                contadorAfiches=0;
                for(j=0; j<limiteVentas; j++)
                {
                    if(arrayVentas[j].idCliente == arrayClientes[i].id && // Para cambiar criterio de busqueda en alguna venta modificar el strcmp
                            arrayVentas[j].isEmpty== 0 &&
                            strcmp(arrayVentas[j].estadoVenta, "A COBRAR")==0)
                    {
                        retorno = 0;
                        contadorAfiches=contadorAfiches+arrayVentas[j].cantidad;

                    }
                }
                if(contadorAfiches>clienteConMasAfichesACobrar || i==0)
                {
                    clienteConMasAfichesACobrar=contadorAfiches;
                    indexClienteConMasAfichesACobrar=i;
                }

            }

        }
        printf("\nEl clinete con mas ventas a cobrar es:");
        printf("\nID: %d",arrayClientes[indexClienteConMasAfichesACobrar].id);
        printf("\nNombre: %s, %s",arrayClientes[indexClienteConMasAfichesACobrar].nombre,
               arrayClientes[indexClienteConMasAfichesACobrar].apellido);
        printf("\nCuit: %s",arrayClientes[indexClienteConMasAfichesACobrar].cuit);
        printf("\nCantidad de afiches a cobrar: %d\n",clienteConMasAfichesACobrar);

    }
    pausarPantalla();
    return retorno;
}
