#include <stdio.h>


int main(void)
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

	return 0;
}
//对于几乎所有机器1字节均为8位。
//C语言把1字节定义为char类型占用的位数
// 
//printf函数中要显示前缀必须加#，如printf("%#x",toes)。 
//有符号整型：short (int)<= int <= long (int)< long long (int)
/*
* short:		16位
* int:			16位或32位
* long:			32位
* long long:	64位
*/
//对于整数，当达到它能表示的最大值时，溢出后会重新从起点开始。
//



