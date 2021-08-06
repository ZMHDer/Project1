#include <stdio.h>
//#include <string.h>
#include "string_io.h"
#include "deal_data.h"


int main(void)
{	
	deal_data();
	return 0;
}

/*========================= 基本数据类型 ==============================*/
void record1(void)
{
	int toes;
	/*在ANSI C中没有scanf_s(),只有scanf()，但是scanf()在读取时不检查边界，
	所以可能会造成内存泄露。于是Microsoft公司在VS中提供了scanf_s()。*/
	scanf_s("%d",&toes);
	//toes = 10;
	printf("toes = %d\n", toes);
	toes = 2 * toes;
	printf("2*toes = %d\n", toes);
	toes = (toes / 2) * (toes / 2);//c语言中没有^平方运算符
	printf("toes^2 = %d\n", toes);
}
// 对于几乎所有机器，1字节均为8位。
// C语言把1字节定义为char类型占用的位数。
// 
// printf函数中要显示前缀必须加#，如printf("%#x",toes)。 
// 有符号整型：short (int)<= int <= long (int)< long long (int)
/*
* 类型				 范围				后缀(作为特定数据类型对待时加后缀)	打印前缀(转换只能小写)
* short				 16位(-2^15~2^15-1)									%hd
* int				 16位或32位											%d
* long				 32位				l(L)							%ld
* long long			 64位				ll(LL)							%lld
* 
* unsigned int		 16位或32位			u(U)							%u
* unsigned short	 16位(0~2^16-1)										%hu
* unsigned long		 32位				lu(LU)							%lu
* unsigned long long 64位				llu(LLU)						%llu
*/
// 对于整型，当达到它能表示的最大值时，溢出后会重新从起点开始。
// 没有后缀的浮点型常量是Double类型。

void record2(void)
{
	float count;
	printf("Enter a floating-point value：");
	scanf_s("%f",&count);
	printf("fixed-point notation：%f\n", count);
	printf("exponential notation：%e\n", count);
	printf("p notation：%.2a\n", count);
}


