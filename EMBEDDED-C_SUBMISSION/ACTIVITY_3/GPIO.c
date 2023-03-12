/******************************************************************************
* File Name: GPIO.c
* Description: This file contains API definitions for GPIO functionality
* Tool-Chain: AVR GCC
*
* Modification History:25/SEP/2020
* Created by: K.Raviteja V1.0 25/SEP/2020
* Description: V1.0
******************************************************************************/
/******************************************************************************
* Includes
******************************************************************************/
#include "GPIO.h"
/******************************************************************************
* Defines and data types
******************************************************************************/
/******************************************************************************
* Global variables
******************************************************************************/
/******************************************************************************
* Static variables
******************************************************************************/
static int a;
/******************************************************************************
* Internal function prototypes
******************************************************************************/
/******************************************************************************
* Public functions definitions
******************************************************************************/
/******************************************************************************
* Name: GPIOConfig (pin, mode)
* Description: Configures the mode of the pin as INPUT/PULLUP or OUTPUT
* Arguments: pin and mode
* Returns: None
******************************************************************************/
void GPIOConfig(Pin,mode){

        if(mode==1){
            SET_BIT(DDRD,Pin);
        }
        else{
            CLR_BIT(DDRD,Pin);
            SET_BIT(PORTD,Pin);
        }
};
/******************************************************************************
* Name: int GPIOPinRead(int Pin)
* Description: Reads the mode of the pin as INPUT or OUTPUT
* Arguments: pin
* Returns: a
******************************************************************************/
int GPIOPinRead(Pin){


            uint8_t PIN_READ=PIND;
            if(PIN_READ & (1<<Pin)){
                a=1;
            }
            else{
                a=0;
            }
    return a;
};
/******************************************************************************
* Name: void GPIOPinWrite(int Pin,int state)
* Description: Writes the state of the pin as HIGH or LOW
* Arguments: pin and state
* Returns: None
******************************************************************************/
void GPIOPinWrite(Pin,state){
        if(state==0){
            CLR_BIT(PORTD,Pin);
        }
        else{
            SET_BIT(PORTD,Pin);
        }

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