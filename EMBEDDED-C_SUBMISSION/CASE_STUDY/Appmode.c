/******************************************************************************
* File Name: Appmode.c
* Description: This file contains API definitions for Appmode functionality
* Tool-Chain: AVR GCC
*
* Modification History:25/SEP/2020
* Created by: K.Raviteja V1.0 25/SEP/2020
* Description: V1.0
******************************************************************************/
/******************************************************************************
* Includes
******************************************************************************/
#include <avr/io.h>
#include "Appmode.h"
/******************************************************************************
* Defines and data types
******************************************************************************/
/******************************************************************************
* Global variables
******************************************************************************/
static int left,right;
static uint16_t ADC_value;
/******************************************************************************
* Static variables
******************************************************************************/
/******************************************************************************
* Internal function prototypes
******************************************************************************/
/******************************************************************************
* Public functions definitions
******************************************************************************/
int t;
/******************************************************************************
* Name: manualmode()
* Description: Wiper state for Engine ON and Wiper is in manual mode
* Arguments:None
* Returns: None
******************************************************************************/
void manualmode()
{
    ADCSRA &=~(1 << ADSC);
    t = 128;
};
/******************************************************************************
* Name: automode()
* Description: Wiper state for Engine ON and Wiper is in auto mode
* Arguments: None
* Returns: None
******************************************************************************/
void automode()
{
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    left = (int)ADCL;
    right = (int)ADCH * 256;
    ADC_value = left + right;

    if(ADC_value >= 0 && ADC_value <= 50)
    {
        t=0;
    }
    else if(ADC_value > 50 && ADC_value <= 200)
    {
        t=63;
    }
    else if(ADC_value > 200 && ADC_value <= 500)
    {
        t=127;
    }
    else if(ADC_value > 500 && ADC_value <= 1000)
    {
        t=191;
    }
    else if(ADC_value >1000)
    {
        t = 255;
    }

};
/******************************************************************************
* Name: standbymode()
* Description: Wiper state for Engine OFF
* Arguments: None
* Returns: None
******************************************************************************/
void standbymode()
{
    GPIOPinWrite(PD6,LOW);
    ADCSRA &= ~(1<<ADSC);
};
/******************************************************************************
* Internal functions
******************************************************************************/
/******************************************************************************
* Name:
* Description:
******************************************************************************/
/******************************************************************************
*******************************************************************************
* End of File
******************************************************************************/