/*
 * MIT License
 * 
 * Copyright (c) 2017 ccbruce0812 (ccbruce@gmail.com)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef RDA5807M_DATA_H
#define RDA5807M_DATA_H

//Data types
#define RDA5807M_BOOL				unsigned char
#define RDA5807M_TRUE				(0xff)
#define RDA5807M_FALSE				(0x00)

#define RDA5807M_OK					(0)
#define RDA5807M_ERR_FAILED			(-1)

enum {
	RDA5807M_CLK_FREQ_32_768KHZ=0,
	RDA5807M_CLK_FREQ_12MHZ,
	RDA5807M_CLK_FREQ_13MHZ,
	RDA5807M_CLK_FREQ_19_2MHZ,
	RDA5807M_CLK_FREQ_UNUSED,
	RDA5807M_CLK_FREQ_24MHZ,
	RDA5807M_CLK_FREQ_26MHZ,
	RDA5807M_CLK_FREQ_38_4MHZ
};

enum {
	RDA5807M_BAND_87_108_MHZ=0,
	RDA5807M_BAND_76_91_MHZ,
	RDA5807M_BAND_76_108_MHZ,
	RDA5807M_BAND_65_76MHZ
};

enum {
	RDA5807M_SPACE_100_KHZ=0,
	RDA5807M_SPACE_200_KHZ,
	RDA5807M_SPACE_50_KHZ,
	RDA5807M_SPACE_25_KHZ
};

typedef struct {
	struct {
		RDA5807M_BOOL isClkNoCalb;
		RDA5807M_BOOL isClkDirInp;
		unsigned char freq;
	} clkSetting;
	RDA5807M_BOOL useRDS;
	RDA5807M_BOOL useNewDMMethod;
	RDA5807M_BOOL isDECNST50us;
	struct {
		unsigned char band;
		RDA5807M_BOOL is6575Sys;
		unsigned char space;
	} system;
} RDA5807M_SETTING;

#endif