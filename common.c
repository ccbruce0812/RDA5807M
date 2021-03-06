/* BSD 3-Clause License
 * 
 * RDA5807M driver for ESP8266
 * Copyright (c) 2017, ccbruce0812 (ccbruce@gmail.com)
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * 
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "common.h"
#include "rda5807m.h"

int RDA5807M_readReg(unsigned char regAddr, unsigned short *pData) {
	if(!pData) {
		DBG("Bad argument. Check your code.\n");
		assert(false);
	}
	
	if(!i2c_slave_read(RDA5807M_ADDR, regAddr, (unsigned char *)pData, sizeof(unsigned short)))
		goto failed;

	unsigned char *pArr=(unsigned char *)pData;
	
	SWAP(pArr[0], pArr[1]);
	
	return 0;

failed:
	return -1;
}

int RDA5807M_writeReg(unsigned char regAddr, unsigned short data) {
	unsigned char buf[3]={regAddr, (unsigned char)(data>>8), (unsigned char)data};

	if(!i2c_slave_write(RDA5807M_ADDR, buf, sizeof(buf)))
		goto failed;

	return 0;

failed:
	return -1;
}

/*
int readRegs(unsigned short *pData, unsigned int count) {
	int i;
	
	if(count<1)
		goto failed;
	
	count=Wire.requestFrom((int)RDA5807M_SEQADDR, count*2);
	for(i=0;i<count/2;i++) {
		pData[i]=Wire.read();
		pData[i]<<=8;
		pData[i]|=Wire.read();
	}
	
	return 0;

failed:
	DBG("Failed.\n");
	return -1;
}

int writeRegs(unsigned short *pData, unsigned int count) {
	int i;
	
	if(count<1)
		goto failed;
	
	Wire.beginTransmission(RDA5807M_SEQADDR);
	for(i=0;i<count;i++) {
		Wire.write(pData[i]>>8);
		Wire.write(pData[i]&0xff);
	}
	Wire.endTransmission();
	
	return 0;
	
failed:
	return -1;
}
*/