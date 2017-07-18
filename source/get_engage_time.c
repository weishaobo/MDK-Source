#include "includes.h"

uchar get_engage_time(uint rev_a, uint rev, uchar *arr_t)
{
    uint code rev_a_segment[] = {106,112,120,128};
    uint code rev_segment[] = {90,120,150,180,240};
    uchar code time_tbl[][6] = {
    {0, 1, 2, 3, 4, 5},
    {1, 2, 3, 4, 5, 5},
    {2, 2, 3, 3, 4, 5},
    {3, 3, 3, 4, 4, 5},
    {5, 5, 5, 5, 5, 5}
    };
    uchar t = 0;
    uchar x = 0;
    uchar y = 0;
    x = position_in_array(rev_a, rev_a_segment, sizeof(rev_a_segment)/2,0);
    y = position_in_array(rev, rev_segment, sizeof(rev_segment)/2,0);
    t = arr_t[time_tbl[x][y]];
    return t;
}

