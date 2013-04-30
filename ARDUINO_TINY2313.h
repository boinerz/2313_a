
/************************************************************************
 ARDUINO TINY2313 BOARD DEFINITIONS

 C. Prichard 4-6-13

************************************************************************/


#ifndef ARDUINO_TINY_2213_H_INCLUDED
#define ARDUINO_TINY_2213_H_INCLUDED


/* ARDUINO TINY 2313 operating frequencies
*/

// #define BOARD_FREQ_SLCK_XTAL			(32768U)
// #define BOARD_FREQ_SLCK_BYPASS		(32768U)
#define BOARD_FREQ_MAINCK_XTAL			(4000000U)  // Change to 8 MHz internal if desired. Can use external as well.
#define BOARD_FREQ_MAINCK_BYPASS		(4000000U)

/* MASTER clock frequency */

#define BOARD_MCK				CHIP_FREQ_CPU_MAX
#define BOARD_NO_32K_XTAL

/** BOARD main clock startup time */

#define BOARD_OSC_STARTUP_US		69000   // (DUE value 15625,, TODO: check datasheet)

/* -------------------------------------------------------------------------------------------------------- */
/*! Name of the board */
#define BOARD_NAME "Arduino TINY2313"
/*! Board definition */
#define arduino_tiny2313
/*! Family definition (already defined) */
#define attiny
/*! Core definition */
#define avr

// PIO definitions

#define PIN_PA[0..2]	PIO_PB[0..2]_IDX    // APORT generally used for RESET and OSC
											// DEBUG uses RESET See Wd RESET information in datasheet...

#define PIN_PB[0..7]	PIO_PB[3..10]_IDX
#define PIN_PD[2..6]	PIO_PB[11..17]_IDX

/************************************************************************
 LEDS
***********************************************************************/

#define PIN_POWER_LED [___]	{POWER}

// #define PIN_USER_LED_1		{PIO_PB7, PIOB, ID_PIOB, PIO_OUTPUT_1, PIO_DEFAULT}

#define LED_0_NAME			"YELLOW LED" //PB7 NOT PB5 as on other boards
#define LED0_GPIO			(PIO_PB5_IDX)
#define LED0_FLAGS			(PIO_TYPE_PIO_OUTPUT_1 | PIO_DEFAULT)
#define LED0_ACTIVE_LEVEL	0

#define PIN_LED_0			{1 << 5, PIOB, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}	// PB7
#define PIN_LED_0_MASK		(1 << 5)
#define PIN_LED_0_PIO		PIOB
#define PIN_LED_0_ID		ID_PIOB
#define PIN_LED_0_TYPE		PIO_OUTPUT_0
#define PIN_LED_0_ATTR		PIO_DEFAULT

/************************************************************************
 BUTTONS
************************************************************************/

//RESET BUTTON is only button

#define PIN_PUSHBUTTON_1_PIO		PIO_RESET
#define PIN_PUSHBUTTON_1_PIO_ID		ID_PIO_RESET
#define PIN_PUSHBUTTON_1_PIO_TYPE	PIO_INPUT
#define PIN_PUSHBUTTON_1_PIO_ATTR	(PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE)


/*! PWME_PWM0_TRIG pin definition OUTPUT HIGH. */

#define PIN_PWME_PWMH0_TRIG				PIO_PB0_IDX
#define PIN_PWME_PWMH0_TRIG_FLAG		PIO_PERIPH_B | PIO_DEFAULT

/*! PWMB_PWM5 pin definition OUTPUT LOW. */
#define PIN_PWMB_PWMH5 {PIN_PWM5, PIO_PB5_IDX, PIOB, ID_PIOB, PIO_PERIPH_B, PIO_DEFAULT}

/* PWM PINS definition for LED0 */
#define PIN_PWM_LED0 PIN_PWMB_PWMH5

/* PWM Channel for LED0 */

#define CHANNEL_PWM_LED0 PWM_CHANNEL_5

/* PWM "PWM13" LED0 pin definitions */

#define PIN_PWM_LED0_GPIO PIO_PB5_IDX
#define PIN_PWM_LED0_FLAGS (PIO_PERIPH_B | PIO_DEFAULT)
#define PIN_PWM_LED0_CHANNEL PWM_CHANNEL_5



/************************************************************************
 SPI
************************************************************************/
/*! SPIO MISO PIN definition. */
#define SPIO_MISO_GPIO			(PIO__PB21_IDX)
#define SPIO_MISO_FLAGS			(PIO_PERIPH_B | PIO_DEFAULT)

/*! SPIO MOSI PIN definition. */
#define SPIO_MOSI_GPIO			(PIO__PB20_IDX)
#define SPIO_MOSI_FLAGS			(PIO_PERIPH_B | PIO_DEFAULT)

/*! SPIO SCK PIN definition. */
#define SPIO_SPCK_GPIO			(PIO__PB22_IDX)
#define SPIO_SPCK_FLAGS			(PIO_PERIPH_B | PIO_DEFAULT)

//*! SPIO SELECT 0 PIN definition. */
//#define SPIO_SPSS_GPIO			(PIO__PB53_IDX)
//#define SPIO_SPSS_FLAGS			(PIO_PERIPH_B | PIO_DEFAULT)


/************************************************************************
 TWI
************************************************************************/

#define TWI0_DATA_GPIO			PIO_PB24_IDX
#define TWIO_DATA_FLAGS			(PIO_PERIPH_B | PIO_DEAFAULT)

#define TWIO_CLK_GPIO			PIO_PB25_IDX
#define TWIO_CLK_FLAGS			(PIO_PERIPH_B | PIO_DEAFAULT)

/* ------------------------------------------------------------------------
 PCK
 ------------------------------------------------------------------------ */
/*! PCK0 */
#define PIN_PCK0        (PIO_PD2_SCK)
#define PIN_PCK0_FLAGS  (PIO_PERIPH_B | PIO_DEFAULT)

#define PIN_PCK_0_MASK  PIO_PD2_SCK | PIO_PB26_IDX
#define PIN_PCK_0_PIO   PIOB
#define PIN_PCK_0_ID    ID_PIOB
#define PIN_PCK_0_TYPE  PIO_PERIPH_B
#define PIN_PCK_0_ATTR  PIO_DEFAULT

/************************************************************************
 USART
************************************************************************/
/*! USART pins (UTXD0 and URXD0) definitions, PB0,1. (labeled RXD0->0 and TXD0->1)*/
#define PINS_USART0        (PIO_PD0_URXD | PIO_PD1_UTXD)
#define PINS_USART0_FLAGS  (PIO_PERIPH_B | PIO_DEFAULT)

#define PINS_USART0_MASK (PIO_PD0_URXD | PIO_PD1_UTXD)
#define PINS_USART0_PIO  PIOB
#define PINS_USART0_ID   ID_PIOB
#define PINS_USART0_TYPE PIO_PERIPH_B
#define PINS_USART0_ATTR PIO_DEFAULT

#define CONSOLE_USART USART0
#define CONSOLE_USART_ID ID_USART0


#endif /* ARDUINO_TINY2313_H_INCLUDED */
