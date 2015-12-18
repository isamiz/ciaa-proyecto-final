
#include "myFunctions.h"           /* <= own header */

void initMyVariables(void)
{
   tiltLed = 0B100000;

   tiltFrec = 100;
   
   tiltSup = 50;

   tiltInf = 1000;

   tiltCounter = 0;

   //Write the led register
   ciaaPOSIX_write(fd_out, &tiltLed, 1);
}


void procesarTeclas(uint8_t teclas)
{
   GetResource(BLOCK);

   uint8_t outputs;

   if (TECLADO_TEC1_BIT & teclas)
   {
      if (tiltFrec <= tiltInf)
      {
      	tiltFrec += 50;
	
	if (tiltFrec == tiltInf)
	{
	   tiltLed += EDU_CIAA_NXP_RGB_BLANCO;
	   ciaaPOSIX_write(fd_out, &tiltLed, 1);
	   for(delay = 0; delay < 50000; delay++)
       	   	{
        	}
	   tiltLed -= EDU_CIAA_NXP_RGB_BLANCO;
	   ciaaPOSIX_write(fd_out, &tiltLed, 1);
	}
      }
   }

   if (TECLADO_TEC2_BIT & teclas)
   {
      if (tiltFrec > tiltSup)
      {
      	tiltFrec -= 50;
	
	if (tiltFrec == tiltSup)
	{
	   tiltLed += EDU_CIAA_NXP_RGB_BLANCO;
	   ciaaPOSIX_write(fd_out, &tiltLed, 1);
	   for(delay = 0; delay < 50000; delay++)
       	   	{
        	}
	   tiltLed -= EDU_CIAA_NXP_RGB_BLANCO;
	   ciaaPOSIX_write(fd_out, &tiltLed, 1);
	}
      }
   }


   if (TECLADO_TEC3_BIT & teclas)
   {
      if (tiltLed == EDU_CIAA_NXP_RGB_AZUL)
      {
         tiltLed = EDU_CIAA_NXP_RGB_VERDE;
         ciaaPOSIX_write(fd_out, &tiltLed, 1);
      }
      else if (tiltLed == EDU_CIAA_NXP_RGB_VERDE)
      {
         tiltLed = EDU_CIAA_NXP_RGB_ROJO;
         ciaaPOSIX_write(fd_out, &tiltLed, 1);
      }
      else if (tiltLed == EDU_CIAA_NXP_RGB_ROJO)
      {
         tiltLed = EDU_CIAA_NXP_LED3_VERDE;
         ciaaPOSIX_write(fd_out, &tiltLed, 1);
      }
      else if (tiltLed == EDU_CIAA_NXP_LED1_AMARILLO)
      {
         tiltLed = EDU_CIAA_NXP_RGB_AZUL;
         ciaaPOSIX_write(fd_out, &tiltLed, 1);
      }
      else if (tiltLed == EDU_CIAA_NXP_LED2_ROJO)
      {
         tiltLed = EDU_CIAA_NXP_LED1_AMARILLO;
         ciaaPOSIX_write(fd_out, &tiltLed, 1);
      }
      else if (tiltLed == EDU_CIAA_NXP_LED3_VERDE)
      {
         tiltLed = EDU_CIAA_NXP_LED2_ROJO;
         ciaaPOSIX_write(fd_out, &tiltLed, 1);
      }
   }

   if (TECLADO_TEC4_BIT & teclas)
   {
      if (tiltLed == EDU_CIAA_NXP_RGB_AZUL)
      {
         tiltLed = EDU_CIAA_NXP_LED1_AMARILLO;
         ciaaPOSIX_write(fd_out, &tiltLed, 1);
      }
      else if (tiltLed == EDU_CIAA_NXP_RGB_ROJO)
      {
         tiltLed = EDU_CIAA_NXP_RGB_VERDE;
         ciaaPOSIX_write(fd_out, &tiltLed, 1);
      }
      else if (tiltLed == EDU_CIAA_NXP_RGB_VERDE)
      {
         tiltLed = EDU_CIAA_NXP_RGB_AZUL;
         ciaaPOSIX_write(fd_out, &tiltLed, 1);
      }
      else if (tiltLed == EDU_CIAA_NXP_LED1_AMARILLO)
      {
         tiltLed = EDU_CIAA_NXP_LED2_ROJO;
         ciaaPOSIX_write(fd_out, &tiltLed, 1);
      }
      else if (tiltLed == EDU_CIAA_NXP_LED2_ROJO)
      {
         tiltLed = EDU_CIAA_NXP_LED3_VERDE;
         ciaaPOSIX_write(fd_out, &tiltLed, 1);
      }
      else if (tiltLed == EDU_CIAA_NXP_LED3_VERDE)
      {
         tiltLed = EDU_CIAA_NXP_RGB_ROJO;
         ciaaPOSIX_write(fd_out, &tiltLed, 1);
      }
   }

   ReleaseResource(BLOCK);
}

