#include "includes.h"

extern ComponentDef CompentArr[10];		// 零件列表

void compnent_move(ComponentDef * com)
{
	static uint num = 0;
	uchar i = 0;
	for(i=9;i>0;i--)
	{
		com[i] = com[i-1];
	}
	num++;
	com[0].ErrCode = 0;
	com[0].Num = num;
}

void move_test(void)
{
	compnent_move(CompentArr);
}

void process(void)
{
	if(CompentArr[2].Num == 20)
	{
		CompentArr[2].ErrCode = 83;
	}
	
	if(CompentArr[9].ErrCode == 83)
	{
		CompentArr[2].ErrCode = 168;
	}
}

void func_switch(uint *addr)
{
	DPL = (uint)addr;
	DPH = (uint)addr>>8;
	#pragma asm
//    POP  SP
//	POP  SP
	PUSH DPL
	PUSH DPH
	#pragma endasm
}
