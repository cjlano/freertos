/*
    FreeRTOS V9.0.0 - Copyright (C) 2016 Real Time Engineers Ltd.
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.

    ***************************************************************************
    >>!   NOTE: The modification to the GPL is included to allow you to     !<<
    >>!   distribute a combined work that includes FreeRTOS without being   !<<
    >>!   obliged to provide the source code for proprietary components     !<<
    >>!   outside of the FreeRTOS kernel.                                   !<<
    ***************************************************************************

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available on the following
    link: http://www.freertos.org/a00114.html

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that is more than just the market leader, it     *
     *    is the industry's de facto standard.                               *
     *                                                                       *
     *    Help yourself get started quickly while simultaneously helping     *
     *    to support the FreeRTOS project by purchasing a FreeRTOS           *
     *    tutorial book, reference manual, or both:                          *
     *    http://www.FreeRTOS.org/Documentation                              *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org/FAQHelp.html - Having a problem?  Start by reading
    the FAQ page "My application does not run, what could be wrong?".  Have you
    defined configASSERT()?

    http://www.FreeRTOS.org/support - In return for receiving this top quality
    embedded software for free we request you assist our global community by
    participating in the support forum.

    http://www.FreeRTOS.org/training - Investing in training allows your team to
    be as productive as possible as early as possible.  Now you can receive
    FreeRTOS training directly from Richard Barry, CEO of Real Time Engineers
    Ltd, and the world's leading authority on the world's leading RTOS.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.FreeRTOS.org/labs - Where new FreeRTOS products go to incubate.
    Come and try FreeRTOS+TCP, our new open source TCP/IP stack for FreeRTOS.

    http://www.OpenRTOS.com - Real Time Engineers ltd. license FreeRTOS to High
    Integrity Systems ltd. to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and commercial middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/

/* Simple LED IO functions.  LED 0 is toggled by a timer every half second. */

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "timers.h"

/* Library includes. */
#include "lpc18xx_gpio.h"
#include "lpc18xx_scu.h"
#include "lpc18xx_cgu.h"

#define ledTOGGLE_RATE	( 500 / portTICK_RATE_MS )

#define ledLED0_PORT	1
#define ledLED0_BIT		( 1UL << 11UL )

#define ledLED1_PORT	2
#define ledLED1_BIT		( 1UL << 12UL )

/*
 * Toggles an LED just to show the application is running.
 */
static void prvLEDToggleTimerCallback( xTimerHandle xTimer );

/*-----------------------------------------------------------*/

void vLEDsInitialise( void )
{
static xTimerHandle xLEDToggleTimer = NULL;

	/* Set the LED pin-muxing and configure as output. */
	scu_pinmux( 0x2 , 11, MD_PUP, FUNC0 );
	scu_pinmux( 0x2 , 12, MD_PUP, FUNC0 );
	GPIO_SetDir( ledLED0_PORT, ledLED0_BIT, 1 );
	GPIO_SetDir( ledLED1_PORT, ledLED1_BIT, 1 );

    /* Create the timer used to toggle LED0. */
	xLEDToggleTimer = xTimerCreate(	"LEDTmr", 		/* Just a text name to associate with the timer, useful for debugging, but not used by the kernel. */
									ledTOGGLE_RATE,	/* The period of the timer. */
									pdTRUE,			/* This timer will autoreload, so uxAutoReload is set to pdTRUE. */
									NULL,			/* The timer ID is not used, so can be set to NULL. */
									prvLEDToggleTimerCallback );		/* The callback function executed each time the timer expires. */

    /* Sanity check that the timer was actually created. */
    configASSERT( xLEDToggleTimer );

    /* Start the timer.  If this is called before the scheduler is started then
    the block time will automatically get changed to 0 (from portMAX_DELAY). */
    xTimerStart( xLEDToggleTimer, portMAX_DELAY );
}
/*-----------------------------------------------------------*/

static void prvLEDToggleTimerCallback( xTimerHandle xTimer )
{
static uint8_t ucState = 0;

	/* Remove compiler warnings. */
	( void ) xTimer;

	/* Just toggle an LED to show the program is running. */
	if( ucState == 0 )
	{
		GPIO_SetValue( ledLED0_PORT, ledLED0_BIT );
	}
	else
	{
		GPIO_ClearValue( ledLED0_PORT, ledLED0_BIT );
	}

	ucState = !ucState;
}

