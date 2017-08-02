#include "includes.h"

#define SubLen 4
#define BufLen 16

// find n minimal number and put it to the front of array
void find_n_min(uint *buf, uchar len, uchar n)
{
	char i = 0;
	char j = 0;
	uint  TempData = 0;
	
	for(i=0;i<n;i++)
	{
		for(j=i;j<len;j++)
		{
			if(buf[j]<buf[i])
			{
				TempData = buf[i];
				buf[i] = buf[j];
				buf[j] = TempData;
			}
		}
	}
}

// find n maximal number and put them to end of array
void find_n_max(uint *buf, uchar len, uchar n)
{
	char i = 0;
	char j = 0;
	uint  TempData = 0;
	
	for(i=0;i<n;i++)
	{
		for(j=len-1-i;j>=0;j--)
		{
			if(buf[len-1-i]<buf[j])
			{
				TempData = buf[len-1-i];
				buf[len-1-i] = buf[j];
				buf[j] = TempData;
			}
		}
	}
}

uint get_arr_sum(uint *arr, uchar len)
{
	uchar i = 0;
	uint  sum = 0;
	for(i=0;i<len;i++)
	{
		sum += arr[i];
	}
	return sum;
}

uint adc_sample(uchar ch)
{
	uchar i = 0;
	uchar j = 0;
	uint  buf[BufLen];
	uint  sum = 0;
	//uchar idata *p = 0x05;
	
	ch = ch;

	// 采样BufLen个数据
	for(i=0; i<BufLen; i++)
	{
		buf[i] = i;//ADC_GET(ch);
	}
	
	find_n_min(buf,BufLen,SubLen);
	find_n_max(&buf[SubLen],BufLen-SubLen,SubLen);
	sum = get_arr_sum(&buf[SubLen],BufLen-SubLen-SubLen);
	sum >>= 3;
	
	return sum;
}