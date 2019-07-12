/*
 * SH1103.h
 *
 *  Created on: Jul 12, 2019
 *      Author: graemef
 */

#ifndef SH1103_H_
#define SH1103_H_
#define 	SSD1306_SPI SPI2


#define S2_Pin GPIO_PIN_0
#define S2_GPIO_Port GPIOC
#define S3_Pin GPIO_PIN_1
#define S3_GPIO_Port GPIOC
#define CS_Pin GPIO_PIN_12
#define CS_GPIO_Port GPIOB
#define DC_Pin GPIO_PIN_14
#define DC_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_8
#define LED2_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_9
#define LED1_GPIO_Port GPIOB

// Pin Definitions
#define 	SSD1306_DC_PORT				GPIOB     // Data/Command
#define 	SSD1306_DC_PIN				(12)
#define 	SSD1306_RST_PORT            GPIOB     // Reset
#define 	SSD1306_RST_PIN             (13)
#define 	SSD1306_CS_PORT             GPIOA     // Select
#define 	SSD1306_CS_PIN              (15)
#define 	SSD1306_SCLK_PORT           GPIOB     // Serial Clock
#define 	SSD1306_SCLK_PIN            (3)
#define 	SSD1306_SDAT_PORT           GPIOB     // Serial Data
#define 	SSD1306_SDAT_PIN            (5)


#define   BLACK     						0
#define   WHITE     						1
#define   INVERSE   						2

#define   MULTILAYER   					    0
#define   LAYER0							1
#define   LAYER1							2

#define		SSD1306_LCDWIDTH         		128
//#define		SSD1306_LCDWIDTH         			132
#define		SSD1306_LCDHEIGHT           	64

// Commands
#define SSD1306_SETCONTRAST               0x81
#define SSD1306_DISPLAYALLON_RESUME       0xA4
#define SSD1306_DISPLAYALLON              0xA5
#define SSD1306_NORMALDISPLAY             0xA6
#define SSD1306_INVERTDISPLAY             0xA7
#define SSD1306_DISPLAYOFF                0xAE
#define SSD1306_DISPLAYON                 0xAF
#define SSD1306_SETDISPLAYOFFSET          0xD3
#define SSD1306_SETCOMPINS                0xDA
#define SSD1306_SETVCOMDETECT             0xDB
#define SSD1306_SETDISPLAYCLOCKDIV        0xD5
#define SSD1306_SETPRECHARGE              0xD9
#define SSD1306_SETMULTIPLEX              0xA8
#define SSD1306_SETLOWCOLUMN              0x00
#define SSD1306_SETHIGHCOLUMN             0x10
#define SSD1306_SETSTARTLINE              0x40
#define SSD1306_MEMORYMODE                0x20
#define SSD1306_COMSCANINC                0xC0
#define SSD1306_COMSCANDEC                0xC8
#define SSD1306_SEGREMAP                  0xA0
#define SSD1306_CHARGEPUMP                0x8D
#define SSD1306_EXTERNALVCC               0x1
#define SSD1306_SWITCHCAPVCC              0x2
// macros
#define SSD1306MSDELAY(c)      HAL_Delay( c );



// Initialisation/Config Prototypes
void    ssd1306Init (uint8_t);

#endif /* SH1103_H_ */



