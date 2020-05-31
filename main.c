#include "TM4C123.h"                    // Device header
#include "FreeRTOS.h"                   // ARM.FreeRTOS::RTOS:Core
#include "task.h"                       // ARM.FreeRTOS::RTOS:Core


#define	RED	(1<<1)
#define BLUE (1<<2)
#define GREEN (1<<3)

void Leds_Init(void);
void vRedLedControllerTask(void *pvParamters);
void vBlueLedControllerTask(void *pvParamters);
void vGreenLedControllerTask(void *pvParamters);







void vRedLedControllerTask(void *pvParamters){
	while(1){
		int i;
		GPIOF->DATA ^= RED;
		for(i=0; i<700000; i++){}
	}
}

void vBlueLedControllerTask(void *pvParamters){
	while(1){
		int i;
		GPIOF->DATA ^= BLUE;
		for(i=0; i<700000; i++){}
	}
}

void vGreenLedControllerTask(void *pvParamters){
	while(1){
		int i;
		GPIOF->DATA ^= GREEN;
		for(i=0; i<700000; i++){}
	}
}






int main(void){
	Leds_Init();
	
	xTaskCreate	(vRedLedControllerTask,
				"Red Led Controller",
				100,
				NULL,
				1,
				NULL
				);
	
	xTaskCreate	(vBlueLedControllerTask,
				"Blue Led Controller",
				100,
				NULL,
				1,
				NULL
				);

	xTaskCreate	(vGreenLedControllerTask,
				"Green Led Controller",
				100,
				NULL,
				1,
				NULL
				);
	
	vTaskStartScheduler();
	while(1){}
}







void Leds_Init(void)
{
	SYSCTL->RCGCGPIO |= (1<<5);
	GPIOF->DIR |= RED | BLUE | GREEN;
	GPIOF->DEN |= RED | BLUE | GREEN;
}
