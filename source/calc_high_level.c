#include "includes.h"

// 计算一个字节里面1的个数

#define THRESHOLD 5

uchar calculate_high(uchar byt)
{
	uchar i = 0;
	uchar dat = byt;
	uchar cnt = 0;
	for(i=0;i<8;i++)
	{
		if(dat&0x01)
		{
			cnt++;
		}
		dat >>= 1;
	}
	return cnt;
}

void make_map(uchar *arr_src, uchar *arr_dis)
{
	uchar i = 0;
	uint j = 0;
	for(i=0;i<32;i++) // 32个字节,共256位
	{
		for(j=0;j<256;)
		{
			if(arr_src[j] >= THRESHOLD)
			{
				arr_dis[i] |= 0x80;
			}
			j++;
			if(j%8 == 0)
			{
				i++;
			}
			else
			{
				arr_dis[i] >>= 1;
			}
		}
	}
}