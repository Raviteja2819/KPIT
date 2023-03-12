/******************************************************************************
* File Name: GPIO.h
* Description: This file contains function Prototypes of GPIO.c
* Tool-Chain: AVR GCC
*
* Modification History:25/SEP/2020
* Created by: K.Raviteja V1.0 25/SEP/2020
* Description: V1.0
*
******************************************************************************/
#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
/******************************************************************************
* Includes
******************************************************************************/
#include "AppMode.h"
#include <avr/interrupt.h>
#include "GPIO.h"
/******************************************************************************
* Defines and data types
******************************************************************************/
/******************************************************************************
* Global variables
******************************************************************************/
struct
{
    volatile unsigned int FLAG_TIMER2: 1;
    volatile unsigned int MODE_FLAG:1;
    volatile unsigned int APP_FLAG_INT0 : 1;

    volatile unsigned int APP_FLAG_INT1 : 1;

}FLAG_BIT;
/******************************************************************************
* Public function prototypes
******************************************************************************/
/******************************************************************************
* End of File
******************************************************************************/
#endif





