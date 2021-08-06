/*============================================ 运算符、表达式、语句 ================================================
* 1.整数除法会截断计算结果的小数部分（舍弃整个小数部分）；混合整数和浮点数计算的结果是浮点数，在进行计算前，编译器会把整数转换成浮点数。
*
* 2.递增/递减运算符的前后缀(以递增运算符为例)：
*
*						value = i++; //使用i值后再递增i
*					<=> value = i; i = i + 1;
*
* 						value = ++i; //递增i后再使用i值
*					<=> i = i + 1; value = i;
*
* 3.递增/递减运算符只能影响一个变量（即只能影响一个可修改的左值）。如(x*y)++无效。
*
* 4.自动类型转换：在赋值表达式语句中，计算的最终结果会被转换成被赋值变量的类型。有些旧版本编译器无法识别该意图。
*	C语言中，许多类型转换都是自动进行的。当char和short类型出现在表达式里或作为函数的参数（函数原型除外）时，都会被升级为int类型；
*	float类型在函数参数中时，会被升级为double类型。在K&R C下，表达式中的float类型也会被升级为double类型。
*
* 5.强制类型转换：即在某个量的前面放置用圆括号括起来的目标类型。形如（type）xx，强制转换类型强调了转换类型的意图，编译器能够识别该意图。
*
* 6.C语言中调用函数前，使用函数原型，避免使用函数声明。函数声明只指明了函数名和返回类型，有些场景并不适用，而函数原型还指明了参数类型。
*
*
*/

#include "deal_data.h"
#include <stdio.h>

double Centigrade = 0;			//摄氏度
double Kelvin = 0;				//开氏度
const double F_trans_C_K = 5.0 / 9.0;	//华氏度转摄氏度乘积项系数
const double F_trans_C_E = 32.0;		//华氏度转摄氏度差项系数
const double C_trans_K_E = 273.16;		//摄氏度转开氏度差项系数

void Temperatures(double Fahrenheit)
{
	Centigrade = F_trans_C_K * (Fahrenheit - F_trans_C_E);	//华氏度转摄氏度
	Kelvin = Centigrade + C_trans_K_E;						//摄氏度转开氏度
}

void deal_data(void)
{
	double Fahrenheit = 0;
	printf("请输入华氏温度：");
	while (scanf_s("%lf", &Fahrenheit))
	{
		Temperatures(Fahrenheit);
		printf("华氏度：%1.2f\n摄氏度：%1.2f\n开氏度：%1.2f\n", Fahrenheit, Centigrade, Kelvin);
		printf("\n请输入华氏温度：");
	}
}