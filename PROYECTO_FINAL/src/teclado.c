
#include "os.h"                /* <= operating system header */
#include "ciaak.h"             /* <= ciaa kernel header */
#include "teclado.h"           /* <= own header */
#define TECLADO_TOTAL_TECLAS     4

static int32_t fd_in;

static uint8_t estadoTeclas;
static uint8_t teclasFlancoUP;

void teclado_init(void)
{
   /* abre entradas para leer las teclas */
   fd_in = ciaaPOSIX_open("/dev/dio/in/0", ciaaPOSIX_O_RDWR);
}


void teclado_task(void)
{
   uint8_t inputs;

   /* lee el estado de las entradas */
   ciaaPOSIX_read(fd_in, &inputs, 1);

   /* detecta flanco ascendente */
   teclasFlancoUP |= (inputs ^ estadoTeclas) & inputs;

   /* guarda el nuevo estado de las teclas */
   estadoTeclas = inputs;
}


uint8_t teclado_getFlancos(void)
{
   uint8_t ret = teclasFlancoUP;

   teclasFlancoUP = 0;

   return ret;
}

