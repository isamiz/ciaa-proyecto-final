
#include "leds.h"          

static int32_t fd_out;

void leds_init(void)
{
   /* open CIAA digital outputs */
   fd_out = ciaaPOSIX_open("/dev/dio/out/0", ciaaPOSIX_O_RDWR);
}


void leds_blink(uint8_t mask)
{
   //
   uint8_t outputs;

   //Read the led register status
   ciaaPOSIX_read(fd_out, &outputs, 1);
   outputs ^= mask;
   ciaaPOSIX_write(fd_out, &outputs, 1);
}

