#include "includes.h"

ComponentDef CompentArr[10] = {0};		// 零件列表

static uchar TestSet23 = 0;

void set23()
{
	TestSet23++;
}

void main()
{
	uint  i = 0;
	uchar cnt = 0;
	uchar arr[256] = {0};
	uchar arr_h[256] = {0};
	uchar arr_r[32] = {0};
	unsigned long adat = 5319654;
	uchar larr[7] = {0};
	uint code arr_map[]={10,20,30,40,50,60,70,80,90,100};
	uint ArrTest = 85;
	uchar Position = 0;
	uchar code TimeArr[] = {10,20,30,40,50,60};
	uchar EngageTime = 0;
	
	uint code testarr[] = {1,2,3,4,5,6,7};
	
	uchar sizearr = sizeof(testarr);
	
	uint ucx = 1;
	uint ucy = 3;
	uint ucz = 500+(ucx - ucy);
	uchar diva = 3;
	uchar divb = 200;
	uchar divc = 3*divb/2;
	//dat2char(adat, larr);
	uint  AdSampleTest = 0;
	
	dat2char(adat, larr);
	Position = position_in_array(ArrTest, arr_map, sizeof(arr_map)/2, 1);
	EngageTime = get_engage_time(125, 95, TimeArr);
	for(i=0;i<256;i++)
	{
		arr_h[i] = calculate_high(arr[i]);
	}
	make_map(arr_h, arr_r);
	cnt++;
	
	CompentArr[3].ErrCode = 3;
	
	AdSampleTest = adc_sample(0);
	
	while(1)
	{
		cnt++;
		func_switch(set23);
		move_test();
		process();
	}
}