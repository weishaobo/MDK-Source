#ifndef _HEADER_H_
#define _HEADER_H_

#define uchar unsigned char
#define uint  unsigned int
	
typedef struct
{
	uchar ErrCode;
	uint  Num;
}ComponentDef;

typedef struct
{
	uchar Num;
	ComponentDef * ptComponent;
}WorkBayDef;
	
#define DefWorkMode 3
	
uchar calculate_high(uchar byt);
void make_map(uchar *arr_src, uchar *arr_dis);

void dat2char(unsigned long dat, uchar *buf);
uchar position_in_array(uint dat, uint *arr, uchar arr_len, uchar mode);
uchar get_engage_time(uint rev_a, uint rev, uchar *arr_t);

void move_test(void);
void process(void);
void set23();
void func_switch(uint *addr);

uint adc_sample(uchar ch);
	
#endif