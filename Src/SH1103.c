/*
 * SH1103.c
 *
 *  Created on: Jul 12, 2019
 *      Author: graemef
 */


#include "stdint.h"
#include "SH1103.h"
#include "stm32f1xx_hal.h"


extern SPI_HandleTypeDef hspi2;


/**
 *  \brief SPI write
 *
 *  \param [in] byte Parameter_Description
 *  \return Return_Description
 *
 *  \details Details
 *
 *  \code
 *  \endcode
 */
void ssd1306SendByte(uint8_t byte)
{
	HAL_SPI_Transmit  ( &hspi2,  (uint8_t *) &byte, 1, 20) ;
}




#define CMD(c)        do { HAL_GPIO_WritePin( DC_GPIO_Port, DC_Pin, GPIO_PIN_RESET); \
                           ssd1306SendByte( c ); \
                         } while (0);

void ssd1306TurnOn(void)
{
    CMD(SSD1306_DISPLAYON);
}

/**************************************************************************/
/**
 *  \brief Initialises the SSD1306 LCD display
 *
 *  \param [in] vccstate Parameter_Description
 *  \return Return_Description
 *
 *  \details Details
 */
void  ssd1306Init(uint8_t vccstate)
{
  //vccstate = 1;

  HAL_Delay  (100);
  // Initialisation sequence
  CMD(SSD1306_DISPLAYOFF);                    // 0xAE
  CMD(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
  CMD(0x80);                                  // the suggested ratio 0x80
  CMD(SSD1306_SETMULTIPLEX);                  // 0xA8
  CMD(0x3F/*1F*/);
  CMD(SSD1306_SETDISPLAYOFFSET);              // 0xD3
  CMD(0x0);                                   // no offset
  CMD(SSD1306_SETSTARTLINE | 0x0);            // line #0
  CMD(SSD1306_CHARGEPUMP);                    // 0x8D
  if (vccstate == SSD1306_EXTERNALVCC)
  { CMD(0x10); }
  else
  { CMD(0x14); }
  CMD(SSD1306_MEMORYMODE);                    // 0x20
  CMD(0x00);                                  // 0x0 act like ks0108
  CMD(SSD1306_SEGREMAP | 0x1);
  CMD(SSD1306_COMSCANDEC);
  CMD(SSD1306_SETCOMPINS);                    // 0xDA
  //CMD(0x12);
  CMD(0x12);
  CMD(SSD1306_SETCONTRAST);                   // 0x81
  CMD(0x8f);
#if 0
//  if (vccstate == SSD1306_EXTERNALVCC)
//  { CMD(0x9F); }
//  else
//  { CMD(0xCF); }
  CMD(SSD1306_SETPRECHARGE);                  // 0xd9
  if (vccstate == SSD1306_EXTERNALVCC)
  { CMD(0x22); }
  else
  { CMD(0xF1); }
#else
  if (vccstate == SSD1306_EXTERNALVCC)
      { CMD(0x9F); }
    else
      { CMD(0xCF); }
  CMD(SSD1306_SETPRECHARGE);                  // 0xd9
    if (vccstate == SSD1306_EXTERNALVCC)
      { CMD(0x22); }
    else
      { CMD(0xF1); }

#endif
  CMD(SSD1306_SETVCOMDETECT);                 // 0xDB
  CMD(0x40);
  CMD(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
  //CMD(SSD1306_DISPLAYALLON);           // 0xA4
  CMD(SSD1306_NORMALDISPLAY);                 // 0xA6
  HAL_Delay  (100);
  ssd1306TurnOn();
}
