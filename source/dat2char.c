#include "includes.h"

void dat2char(unsigned long dat, uchar *buf)
{
    buf[0] = dat/1000000;
	buf[1] = dat%1000000/100000;
    buf[1] = dat%1000000/100000;
    buf[2] = dat%100000/10000;
    buf[3] = dat%10000/1000;
    buf[4] = dat%1000/100;
    buf[5] = dat%100/10;
    buf[6] = dat%10;
}

