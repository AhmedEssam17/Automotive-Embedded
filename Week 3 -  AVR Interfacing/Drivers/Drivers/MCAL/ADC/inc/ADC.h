/*
 * ADC.h
 *
 * Created: 8/24/2023 11:14:25 AM
 *  Author: Lenovo
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "DIO.h"
#include "Atmega32.h"
#include "EXTI.h"

//====================================================================
//						Configuration Structure
//====================================================================
typedef struct
{
	uint8_t ADC_MODE;					// specifies ADC Mode (Single conversion mode or Free running mode)						>> @ref ADC_MODE_DEFINE
	uint8_t ADC_VREF;					// Selects ADC VREF source																>> @ref ADC_Voltage_REF_DEFINE
	uint8_t ADC_Result_Presentation;	// specifies ADC Output result presentation(right adjusted or left adjusted)			>> @ref ADC_Result_Presentation_DEFINE
	uint8_t ADC_PRESCALER;				// Selects the division factor between the XTAL frequency and the input clock to ADC	>> @ref ADC_PRESCALER_DEFINE
	uint8_t IRQ_Enable;					// Enable interrupt or Disable it and use polling mechanism								>> @ref IRQ_ENABLE_DEFINE
	void (*P_CallBack)(void);			// set the C Function which will be called once IRQ Happens when Conversion completed
}ADC_Config_t;


//====================================================================
//						Macros Configuration Reference
//====================================================================

//-----------------------------
//@ref ADC_MODE_DEFINE (ADCSRA >> ADSC)
//-----------------------------
#define ADC_MODE_SINGLE_CONVERSION							(uint8_t)(0)
#define ADC_MODE_FREE_RUNNING								(uint8_t)(1<<6)

//-----------------------------
//@ref ADC_Voltage_REF_DEFINE (ADMUX >> REFS0)
//-----------------------------
#define ADC_VREF_AVCC										(uint8_t)(1<<6)
#define ADC_VREF_INTERNAL									(uint8_t)(3<<6)
#define ADC_VREF_EXTERNAL_AREF								(uint8_t)(0)

//-----------------------------
//@ref ADC_Result_Presentation_DEFINE (ADMUX >> ADLAR)
//-----------------------------
#define ADC_Result_Presentation_RIGHT						(uint8_t)(0)
#define ADC_Result_Presentation_LEFT						(uint8_t)(1<<5)

//-----------------------------
//@ref ADC_PRESCALER_DEFINE (ADCSRA >> ADPS0)
//-----------------------------
#define ADC_PRESCALER_2										(uint8_t)(1<<0)
#define ADC_PRESCALER_4										(uint8_t)(2<<0)
#define ADC_PRESCALER_8										(uint8_t)(3<<0)
#define ADC_PRESCALER_16									(uint8_t)(4<<0)
#define ADC_PRESCALER_32									(uint8_t)(5<<0)
#define ADC_PRESCALER_64									(uint8_t)(6<<0)
#define ADC_PRESCALER_128									(uint8_t)(7<<0)

//-----------------------------
//@ref IRQ_ENABLE_DEFINE (ADCSRA >> ADIE)
//-----------------------------
#define ADC_IRQ_DISABLE									    (uint8_t)(0)
#define ADC_IRQ_ENABLE										(uint8_t)(1<<3)


typedef enum
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}Channel_Select_t;


typedef enum
{
	Polling_ENABLE,
	Polling_DISABLE
}Polling_Mechanism_t;

//====================================================================
//								APIs
//====================================================================
void ADC_init(ADC_Config_t* ADC_Config);

void ADC_ReadData(Channel_Select_t channel, uint16_t* data, Polling_Mechanism_t Polling);

#endif /* ADC_H_ */