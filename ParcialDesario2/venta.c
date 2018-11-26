#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "venta.h"
#include <string.h>
#include "validator.h"
#define BUFFER 2048

/**
*\brief Funcion que reserva espacio dinamicamente para el sizeof de Venta
*\return THIS si se pudo reservar memoria para el empleado
*        NULL si no se pudo reservar memoria
*/
Venta* venta_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}
/**
*\brief Funcion que libera espacio reservado para una Venta
*\param Venta* this es la venta que se va a borrar
*\return void
*/
void venta_delete(Venta* this)
{
    free(this);
}

/**
*\brief Funcion que recibe desde el parser todos los datos de la estructura que hay setear en los campos
        correspondientes con previa validacion
*\param char* codigoProducto
*\param char* fecha
*\param char* precioUnitario
*\param char* idVenta
*\return char* cuit
*/
Venta* venta_newConParametros(char* codigoProducto,char* fecha,char* precioUnitario,char* idVenta,char* cantidad, char* cuit)
{
    Venta* this;
    this=venta_new();
    if(validator_StringCodigoProductoEsValido(codigoProducto,BUFFER) && validator_StringFloatEsValido(precioUnitario,BUFFER) &&
            validator_StringIntEsValido(idVenta,BUFFER) && validator_isValidCuilOrCuit(cuit,15) &&
            validator_StringIntEsValido(cantidad,BUFFER) && validator_isValidFecha(fecha))
    {
        venta_setCodigoProducto(this,codigoProducto);
        venta_setFecha(this,fecha);
        venta_setPrecioUnitario(this,atof(precioUnitario));
        venta_setIdVenta(this,atoi(idVenta));
        venta_setCantidad(this,atoi(cantidad));
        venta_setCuit(this,cuit);
        return this;
    }
    else
    {
        printf("VENTA INCORRECTA\n"
        "ID\tCod.Producto Fecha\t   Cuit\t\t  Precio   Cantidad\n%s)\t%s - %s -  %s - %s  -  %s\n\n\n", idVenta,codigoProducto,fecha,cuit,precioUnitario,cantidad);
    }

    venta_delete(this);
    return NULL;
}
/**
 * \brief Funcion que setea el campo Codigo Producto
 * \param Venta* this es la Venta a la cual se le va a setear el codigo de producto vendido
 * \param char* codigoProducto es el string que se va a setear
 * \return [0] EXITO - [-1] ERROR
 */
int venta_setCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(this->codigoProducto,codigoProducto);
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que lee el Codigo Producto y lo guarda en un array
 * \param Venta* this Venta de la cual se va a leer el codigo de producto
 * \param char* codigoProducto array donde se va a almacenar el campo codigoProducto
 * \return [0] EXITO - [-1] ERROR
 */
int venta_getCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(codigoProducto,this->codigoProducto);
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que setea el campo Fecha
 * \param Venta* this es la Venta a la cual se le va a setear la fecha de realizacion
 * \param char* fecha es el string que se va a setear
 * \return [0] EXITO - [-1] ERROR
 */
int venta_setFecha(Venta* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(this->fecha,fecha);
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que lee la fecha y lo guarda en un array
 * \param Venta* this Venta de la cual se va a leer la fecha
 * \param char* codigoProducto array donde se va a almacenar el campo fecha
 * \return [0] EXITO - [-1] ERROR
 */
int venta_getFecha(Venta* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(fecha,this->fecha);
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que setea el campo Precio Unitario
 * \param Venta* this es la Venta a la cual se le va a setear el precio unitario del producto
 * \param float precioUnitario es el string que se va a setear
 * \return [0] EXITO - [-1] ERROR
 */
int venta_setPrecioUnitario(Venta* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que lee el Precio Unitario del producto y lo guarda en un array
 * \param Venta* this Venta de la cual se va a leer el precio del producto
 * \param float* precioUnitario puntero a float donde se va a almacenar el campo precioUnitario
 * \return [0] EXITO - [-1] ERROR
 */
int venta_getPrecioUnitario(Venta* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que setea el campo Id Venta
 * \param Venta* this es la Venta a la cual se le va a setear el identificador de venta
 * \param int idVenta es el string que se va a setear
 * \return [0] EXITO - [-1] ERROR
 */
int venta_setIdVenta(Venta* this,int idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idVenta=idVenta;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que lee el Id Venta y lo guarda en un array
 * \param Venta* this Venta de la cual se va a leer el id de la venta
 * \param int* idVenta puntero a int donde se va a almacenar el campo id
 * \return [0] EXITO - [-1] ERROR
 */
int venta_getIdVenta(Venta* this,int* idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idVenta=this->idVenta;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que setea el campo cantidad
 * \param Venta* this es la Venta a la cual se le va a setear la cantidad de productos vendidos
 * \param int cantidad es el string que se va a setear
 * \return [0] EXITO - [-1] ERROR
 */
int venta_setCantidad(Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que lee ella cantidad de productos vendidos y lo guarda en un array
 * \param Venta* this Venta de la cual se va a leer el la cantidad de productos vendidos
 * \param int* cantidad puntero a int donde se va a almacenar el campo cantidad
 * \return [0] EXITO - [-1] ERROR
 */
int venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que setea el campo cuit
 * \param Venta* this es la Venta a la cual se le va a setear el cuit del cliente
 * \param char* cuit es el string que se va a setear
 * \return [0] EXITO - [-1] ERROR
 */
int venta_setCuit(Venta* this,char* cuit)
{
    int retorno=-1;
    if(this!=NULL && cuit!=NULL)
    {
        strcpy(this->cuit,cuit);
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que lee el cuit de un cliente y lo guarda en un array
 * \param Venta* this Venta de la cual se va a leer el cuit del cliente
 * \param char* cuit array donde se va a almacenar el campo cuit
 * \return [0] EXITO - [-1] ERROR
 */
int venta_getCuit(Venta* this,char* cuit)
{
    int retorno=-1;
    if(this!=NULL && cuit!=NULL)
    {
        strcpy(cuit,this->cuit);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Funcion que muestra todos los campos de una estructura
*\param this es el elemento seleccionado para mostrar
*\return [0]= Mostro el elemento - [-1] ERROR
*/
int venta_mostrar(void* this)
{
    int retorno = -1;
    int auxiliarId = 0;
    char auxiliarFecha[BUFFER];
    float auxiliaPrecio;
    int auxiliarCantidad;
    char auxiliarCodigoProducto[1024];
    char auxiliarCuit[15];

    if(this != NULL)
    {
            venta_getIdVenta(this,&auxiliarId);
            venta_getPrecioUnitario(this,&auxiliaPrecio);
            venta_getFecha(this,auxiliarFecha);
            venta_getCantidad(this,&auxiliarCantidad);
            venta_getCodigoProducto(this,auxiliarCodigoProducto);
            venta_getCuit(this,auxiliarCuit);
            retorno = 0;
            printf("\n%d - %s - %.2f - %s - %d - %s\n",
                   auxiliarId,auxiliarCodigoProducto,auxiliaPrecio,auxiliarFecha,
                   auxiliarCantidad, auxiliarCuit);
    }
    return retorno;
}
/**
 * \brief Funcion que filtra las ventas de TV's
 * \param void* this Puntero al elemento que hay que filtrar
 * \return [0] EXITO - [-1] ERROR
 */
int criterioTV(void* this)
{
    char modeloTV[15];
    int unidades = 0;

    if(this != NULL)
    {
        venta_getCodigoProducto(this,modeloTV);
        if(strcmp(modeloTV, "LCD_TV") == 0)
        {
            venta_getCantidad(this,&unidades);
        }
    }
    return unidades;
}
/**
 * \brief Funcion que devuelve la cantidad de productos que hay en cada compra
 * \param void* this Puntero al elemento que hay que filtrar
 * \return [0] EXITO - [-1] ERROR
 */
int criterioUnidades(void* this)
{
    int cantidad = 0;

    if(this != NULL)
    {
        venta_getCantidad(this, &cantidad);
    }

    return cantidad;
}
/**
 * \brief Funcion que devuelve la cantidad de compras con un monto mayor a $10.0000
 * \param void* this Puntero al elemento que hay que filtrar
 * \return [0] EXITO - [-1] ERROR
 */
int criterioMayorA10000(void* this)
{
    int retorno = 0;
    float precio = 0;
    int cantidad = 0;
    float montoTotal = 0;

    if(this != NULL)
    {
        venta_getPrecioUnitario(this,&precio);
        venta_getCantidad(this,&cantidad);
        montoTotal = precio*cantidad;

        if(montoTotal > 10000)
        {
            retorno = 1;
        }
    }
    return retorno;
}
/**
 * \brief Funcion que devuelve la cantidad de compras con un monto mayor a $20.0000
 * \param void* this Puntero al elemento que hay que filtrar
 * \return [0] EXITO - [-1] ERROR
 */
int criterioMayorA20000(void* this)
{
    int retorno = 0;
    float precio = 0;
    int cantidad = 0;
    float montoTotal = 0;

    if(this != NULL)
    {
        venta_getPrecioUnitario(this,&precio);
        venta_getCantidad(this,&cantidad);
        montoTotal = precio*cantidad;

        if(montoTotal > 20000)
        {
            retorno = 1;
        }
    }
    return retorno;
}
