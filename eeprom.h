// @File		EEPROM.H		 		
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
#ifndef EEPROM_H
#define EEPROM_H

#include "wire.h"

// SLA, MASTER ADDRESS
#define EEPROM_SLA_W 0xA0
#define EEPROM_SLA_R 0xA1

void Eeprom_Write(unsigned char address, unsigned char data)
{
	Wire_Start();
	Wire_Write(EEPROM_SLA_W);
	Wire_Write(address);
	Wire_Write(data);
	Wire_Stop();
	
	while( Wire_Polling(EEPROM_SLA_W) == 1);
}

unsigned char Eeprom_Read(unsigned char address)
{
	unsigned char data = 0;
	
	Wire_Start();
	Wire_Write(EEPROM_SLA_W);
	Wire_Write(address);
	Wire_Start();
	Wire_Write(EEPROM_SLA_R);
	data = Wire_Nack();
	Wire_Stop();
	
	while( Wire_Polling(EEPROM_SLA_W) == 1);
	
	return ( data );
}

#endif 
