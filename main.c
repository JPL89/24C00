// @File		MAIN.C		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		01/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#include "config.h"
#include "ks0066.h"
#include "wire.h"
#include "eeprom.h"

void main(void)
{   
    __delay_ms(500);
    
    PIC18F2520(); 
    
    Wire_Init();
    
    KS0066_Init();
    KS0066_Clear(0);
    KS0066_Clear(1);    
    KS0066_Goto(0,0); 
    
    Eeprom_Write( 15, 127);
    
    unsigned char data = Eeprom_Read( 15 );
    
    KS0066_Int( data );        
    
    while(1){};
    
    return;
}