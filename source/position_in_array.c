#include "includes.h"

uchar position_in_array(uint dat, uint *arr, uchar arr_len, uchar mode)
{
    uchar i = 0;
    if ( 0==mode )
    {
        for ( i=0;i<arr_len;i++ )
        {
            if ( dat<arr[i] )
            {
                return i;
            }
        }
    }
    else
    {
        for ( i=0;i<arr_len;i++ )
        {
            if ( dat<=arr[i] )
            {
                return i;
            }
        }
    }
    return i;
}

