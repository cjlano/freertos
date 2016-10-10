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

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <stdint.h>
extern uint32_t SystemCoreClock;

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 * http://www.freertos.org/a00110.html
 *
 * The bottom of this file contains some constants specific to running the UDP
 * stack in this demo.  Constants specific to FreeRTOS+UDP itself (rather than
 * the demo) are contained in FreeRTOSIPConfig.h.
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION			1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 1
#define configUSE_TICKLESS_IDLE			0
#define configMAX_PRIORITIES			( 7 )
#define configCPU_CLOCK_HZ				( SystemCoreClock )
#define configTICK_RATE_HZ				100
#define configMINIMAL_STACK_SIZE		( ( unsigned short ) 300 )
#define configTOTAL_HEAP_SIZE			( ( size_t ) ( 40 * 1024 ) ) /* Has not effect in this demo as the heap is manually pointed to AHB RAM. */
#define configMAX_TASK_NAME_LEN			( 9 )
#define configIDLE_SHOULD_YIELD			0
#define configQUEUE_REGISTRY_SIZE		10
#define configUSE_TRACE_FACILITY		1
#define configUSE_16_BIT_TICKS			0
#define configUSE_MUTEXES				1
#define configUSE_CO_ROUTINES 			0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )
#define configUSE_COUNTING_SEMAPHORES 	1
#define configUSE_ALTERNATIVE_API 		0
#define configUSE_RECURSIVE_MUTEXES		1

/* Hook function related definitions. */
#define configUSE_TICK_HOOK				0
#define configUSE_IDLE_HOOK				0
#define configUSE_MALLOC_FAILED_HOOK	1
#define configCHECK_FOR_STACK_OVERFLOW	2

/* Software timer related definitions. */
#define configUSE_TIMERS				1
#define configTIMER_TASK_PRIORITY		( configMAX_PRIORITIES - 1 )
#define configTIMER_QUEUE_LENGTH		5
#define configTIMER_TASK_STACK_DEPTH	configMINIMAL_STACK_SIZE

/* Run time stats gathering definitions. */
void vMainConfigureTimerForRunTimeStats( void );
uint32_t ulMainGetRunTimeCounterValue( void );
#define configGENERATE_RUN_TIME_STATS	1
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() vMainConfigureTimerForRunTimeStats()
#define portGET_RUN_TIME_COUNTER_VALUE() ulMainGetRunTimeCounterValue()

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet			1
#define INCLUDE_uxTaskPriorityGet			1
#define INCLUDE_vTaskDelete					1
#define INCLUDE_vTaskCleanUpResources		0
#define INCLUDE_vTaskSuspend				1
#define INCLUDE_vTaskDelayUntil				1
#define INCLUDE_vTaskDelay					1
#define INCLUDE_uxTaskGetStackHighWaterMark	1
#define INCLUDE_xTimerGetTimerTaskHandle	0
#define INCLUDE_xTaskGetIdleTaskHandle		0
#define INCLUDE_xQueueGetMutexHolder		1

/* This demo makes use of one or more example stats formatting functions.  These
format the raw data provided by the uxTaskGetSystemState() function in to human
readable ASCII form.  See the notes in the implementation of vTaskList() within
FreeRTOS/Source/tasks.c for limitations. */
#define configUSE_STATS_FORMATTING_FUNCTIONS	1

/* Assert statement defined for debug builds. */
#ifdef DEBUG
	#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }
#endif

/* Interrupt priority configuration settings follow.
http://www.freertos.org/RTOS-Cortex-M3-M4.html */

/* Use the system definition for the number of interrupt priorities, if there
is one */
#ifdef __NVIC_PRIO_BITS
	#define configPRIO_BITS       __NVIC_PRIO_BITS
#else
	#define configPRIO_BITS       3        /* 8 priority levels */
#endif

/* The maximum priority an interrupt that uses an interrupt safe FreeRTOS API
function can have.  Note that lower priority have numerically higher values.  */
#define configMAX_LIBRARY_INTERRUPT_PRIORITY	( 5 )

/* The minimum possible interrupt priority. */
#define configMIN_LIBRARY_INTERRUPT_PRIORITY	( 7 )

/* The lowest priority. */
#define configKERNEL_INTERRUPT_PRIORITY 		( configMIN_LIBRARY_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* Priority 5, or 248 as only the top five bits are implemented. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configMAX_LIBRARY_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names. */
#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler
#define xPortSysTickHandler SysTick_Handler


/*
 * DEMO APPLICATION SPECIFIC DEFINITIONS FOLLOW FROM HERE
 */

/* Set to 1 to include "trace start" and "trace stop" CLI commands.  These
commands start and stop the FreeRTOS+Trace recording. */
#define configINCLUDE_TRACE_RELATED_CLI_COMMANDS 1

/* Dimensions a buffer that can be used by the FreeRTOS+CLI command
interpreter.  See the FreeRTOS+CLI documentation for more information:
http://www.FreeRTOS.org/FreeRTOS-Plus/FreeRTOS_Plus_CLI/ */
#define configCOMMAND_INT_MAX_OUTPUT_SIZE		1024

/* The priority used by the Ethernet MAC driver interrupt. */
#define configMAC_INTERRUPT_PRIORITY		( configMAX_LIBRARY_INTERRUPT_PRIORITY )

/* If configINCLUDE_DEMO_DEBUG_STATS is set to one, then a few basic IP trace
macros are defined to gather some UDP stack statistics that can then be viewed
through the CLI interface.  See
http://www.FreeRTOS.org/FreeRTOS-Plus/FreeRTOS_Plus_UDP/UDP_IP_Trace.shtml*/
#define configINCLUDE_DEMO_DEBUG_STATS 1

/* The LPC1830 Ethernet peripheral uses a DMA to transmit and receive packets.
The DMA uses a chain of descriptors to reference Ethernet buffers, and provide
information on the state of each buffer (full/empty/error/etc.).
configNUM_RX_ETHERNET_DMA_DESCRIPTORS defines the total number of receive
descriptors (descriptors that point to buffers into which the DMA will write
packets received from the network).  An Ethernet buffer is assigned to each
descriptor.  Having too few descriptors will impact reliability because the DMA
will have to drop packets that are received when there are no receive
descriptors free.  It is however only necessary to have a couple of free
descriptors at a time, and having more wastes the RAM used by the Ethernet
buffers that are surplus to requirements. */
#define configNUM_RX_ETHERNET_DMA_DESCRIPTORS	4

/* The LPC1830 Ethernet peripheral uses a DMA to transmit and receive packets.
The DMA uses a chain of descriptors to reference Ethernet buffers that are
waiting to be sent onto the network.  configNUM_TX_ETHERNET_DMA_DESCRIPTORS
defines the total number of transmit descriptors.  An Ethernet buffer is
not assigned to a transmit descriptor until data is actually sent, but will
remain assigned to the descriptor until the descriptor is re-used.  It is not
necessary to have many transmit descriptors as the IP stack task will be held
in the Blocked state (so other tasks can run) until a descriptor becomes
available if it attempts to transmit when all the descriptors are in use.  See
the iptraceWAITING_FOR_TX_DMA_DESCRIPTOR() IP trace macro. */
#define configNUM_TX_ETHERNET_DMA_DESCRIPTORS	1

/* The address of an echo server that will be used by the two demo echo client
tasks.
http://FreeRTOS.org/FreeRTOS-Plus/FreeRTOS_Plus_UDP/Embedded_Ethernet_Examples/Common_Echo_Clients.shtml */
#define configECHO_SERVER_ADDR0	172
#define configECHO_SERVER_ADDR1 25
#define configECHO_SERVER_ADDR2 218
#define configECHO_SERVER_ADDR3 103

/* MAC address configuration.  In a deployed production system this would
probably be read from an EEPROM.  In the demo it is just hard coded.  Make sure
each node on the network has a unique MAC address. */
#define configMAC_ADDR0	0x00
#define configMAC_ADDR1	0x01
#define configMAC_ADDR2	0x02
#define configMAC_ADDR3	0x03
#define configMAC_ADDR4	0x04
#define configMAC_ADDR5	0x08

/* Default IP address configuration.  Used in ipconfigUSE_DNS is set to 0, or
ipconfigUSE_DNS is set to 1 but a DNS server cannot be contacted. */
#define configIP_ADDR0		172
#define configIP_ADDR1		25
#define configIP_ADDR2		218
#define configIP_ADDR3		200

/* Default gateway IP address configuration.  Used in ipconfigUSE_DNS is set to
0, or ipconfigUSE_DNS is set to 1 but a DNS server cannot be contacted. */
#define configGATEWAY_ADDR0	172
#define configGATEWAY_ADDR1	25
#define configGATEWAY_ADDR2	218
#define configGATEWAY_ADDR3	1

/* Default DNS server configuration.  OpenDNS addresses are 208.67.222.222 and
208.67.220.220.  Used in ipconfigUSE_DNS is set to 0, or ipconfigUSE_DNS is set
to 1 but a DNS server cannot be contacted.*/
#define configDNS_SERVER_ADDR0 	208
#define configDNS_SERVER_ADDR1 	67
#define configDNS_SERVER_ADDR2 	222
#define configDNS_SERVER_ADDR3 	222

/* Defalt netmask configuration.  Used in ipconfigUSE_DNS is set to 0, or
ipconfigUSE_DNS is set to 1 but a DNS server cannot be contacted. */
#define configNET_MASK0		255
#define configNET_MASK1		255
#define configNET_MASK2		255
#define configNET_MASK3		0

#if configINCLUDE_TRACE_RELATED_CLI_COMMANDS == 1
	/* Only include the trace macro definitions required by FreeRTOS+Trace if
	the trace start and trace stop CLI commands are included. */
	#include "trcKernelPort.h"
#endif

#endif /* FREERTOS_CONFIG_H */
