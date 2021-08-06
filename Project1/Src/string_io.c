/*
* ============================字符串和格式化输入/输出====================================
*
* 1.C语言没有专门用来存储字符串的变量类型，字符串都被存储在char类型的数组里。
*	C语言中的字符串一定以空字符（\0）结束。
*
* 2.scanf()函数在遇到（空格、制表符或换行符）时就不再读取了。
*
* 3.sizeof()运算符以字节为单位给出对象的大小。
*	strlen()函数给出字符串的字符长度。
*	在相同输入的情况下，虽然一字节存储一个字符，但两者得到的结果并不一定相同。
*	例：
*	void size(void){
*			int a,b;
*			char name[40];
*			name="ZMH";
*			a=sizeof(name);
*			b=strlen(name);
*	}
*	此时，a=40；b=3。表示name[40]有40个存储单元，只用了3个来存储ZMH。
*
*	若
*			a=sizeof("ZMH");
*			b=strlen("ZMH");
*	此时，a=4；b=3。因为sizeof()可以把字符串末尾不可见的空字符也计算在内。
*
* 4.const关键字限定一个变量为只读，在程序中不可更改。
*
* 5.printf()函数有一个返回值，返回打印字符的个数（包括空格和不可见的换行符）。若输出错误，则返回一个负值。
*
* 6.有时，printf()打印的语句太长，空白（空格、制表符、换行符）仅仅用来分隔不同的部分，此时编译器会忽略空白。
*	在字符串中，可以使用\n来表示换行字符，但是不能通过按下Enter键来产生实际的换行符。
*
* 7.利用反斜杠(\)和回车键(Enter)组合在程序任意处断行，不影响程序输出结果。
*
* 8.用scanf()读取基本变量类型的值，在变量名前加上一个&。
*	用scanf()把字符串(%s)读入字符数组中，不使用&。
*
* 9.在scanf()中，除了%c，其他转换说明都会自动跳过待输入值前面所有空白。
*	对于%c，若格式字符串中把空格放到%c前面，scanf()便会跳过空格，从第一个非空白字符开始读取。如：scanf(" %c",&ch)
*
* 10.scanf()函数返回成功读取的项数；若没有读取任何项且数据类型不匹配，则返回0；若检测到"文件结尾"，则返回EOF，EOF=-1；
*
*
*/

#include "string_io.h"
#include <stdio.h>
#include <string.h>

void string_io(void)
{
	char ming[20] = { 0 }, xing[20] = { 0 };
	int ming_num, xing_num;

	printf("请输入名：\n");
	scanf_s("%s", ming, 20);
	printf("请输入姓：\n");
	scanf_s("%s", xing, 20);
	printf("%s %s\n", ming, xing);
	ming_num = (int)strlen(ming);
	xing_num = (int)strlen(xing);
	printf("%*d %*d\n", ming_num, ming_num, xing_num, xing_num);
	printf("%s %s\n", ming, xing);
	printf("%-*d %-*d\n", ming_num, ming_num, xing_num, xing_num);
}