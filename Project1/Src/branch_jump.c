/*================================== 分支和跳转 ==================================
*
* 1.	ch = getchar();	等效于	scanf("%c", &ch);
*		putchar(ch);	等效于	printf("%c", ch);
*
* 2.如果没有花括号，else与其最近的if匹配。
*
* 3.C语言保证逻辑表达式的求值顺序是从左往右，一旦发现有使整个表达式为假的因素，立刻停止求值。
*
* 4.条件运算符(?:) 条件表达式：value = expression1 ? expression2 : expression3
*							若expression1 != 0，	则value = expression2；
*							若expression1  = 0，	则value = expression3；
*
* 5.continue语句：	执行该语句后，会跳过本次循环的剩余部分，并进行下一轮循环的条件判断。
*					如果该语句在嵌套循环内，则只会影响包含该语句的内层循环。
*
* 6.break语句：执行该语句后，会终止包含它的循环。如果该语句在嵌套循环内，则只会影响包含该语句的内层循环。
*
* 7.ctype.h头文件中声明了字符测试函数和字符映射函数。如：判断是否大写字母（isupper()）、小写转大写（toupper()）等。
*
* 8.C语言中尽量避免使用goto，但可以接受一种goto的用法——出现问题时从一组嵌套循环种跳出（一条break语句只能跳出当前循环）。
*	如：
*		while(funct > 0)
*		{
*			for(i = 1; i < 100; i++)
*			{
*				for(j = 1; j <= 50; j++)
*				{
*					其他语句
*					if（问题）
*					goto help;
*					其他语句
*				}
*				其他语句
*			}
*			其他语句
*		}
*		其他语句
*		help：语句
*
*/

#include "branch_jump.h"
#include <stdio.h>
#include <string.h>

const double Price_per_pound_of_artichoke = 2.05;	//每磅洋蓟2.05美元
const double Price_per_pound_of_sugar = 1.15;		//每磅甜菜1.15美元
const double Price_per_pound_of_carrot = 1.09;		//每磅胡萝卜1.09美元
const double discount = 0.05;	//折扣

double artichoke_weight = 0;	//洋蓟重量
double sugar_weight = 0;		//甜菜重量
double carrot_weight = 0;		//胡萝卜重量
double sum_weight = 0;			//蔬菜总重量

double artichoke_cost = 0;	//洋蓟费用
double sugar_cost = 0;		//甜菜费用
double carrot_cost = 0;		//胡萝卜费用

double cost_of_vegetables = 0;	//蔬菜折后总费用
double freight = 0;				//运费和包装费
double cost_discount = 0;		//折扣费用
double total_cost = 0;			//总费用

//C primer Plus(第6版)中文版 p185-t11
void vegetable_shopping(void)
{
	char ch;
	double pound = 0;

	printf("请输入要购买什么蔬菜(a代表洋蓟，b代表甜菜，c代表胡萝卜，q代表退出订购，enter键确认)：");
	while ((ch = getchar()) != 'q')
	{
		if (ch == '\n')		//如果首字符不是回车符，则继续，否则重新循环判断下一字符。
			continue;

		while (getchar() != '\n') //丢弃首字符后的其余字符
			continue;

		switch (ch)
		{
		case 'a':
			printf("请输入购买多少磅洋蓟：");
			scanf_s("%lf", &pound);
			artichoke_weight += pound;
			break;
		case 'b':
			printf("请输入购买多少磅甜菜：");
			scanf_s("%lf", &pound);
			sugar_weight += pound;
			break;
		case 'c':
			printf("请输入购买多少磅胡萝卜：");
			scanf_s("%lf", &pound);
			carrot_weight += pound;
			break;
		default:
			printf("无效指令！请按enter键重新输入！");
			break;
		}

		while (getchar() != '\n') //丢弃首字符后的其余字符s
			continue;
		printf("\n请输入要购买什么蔬菜(a代表洋蓟，b代表甜菜，c代表胡萝卜，q代表退出订购，enter键确认)：");
	}
	//计算各蔬菜费用
	artichoke_cost = artichoke_weight * Price_per_pound_of_artichoke;	//洋蓟费用
	sugar_cost = sugar_weight * Price_per_pound_of_sugar;				//甜菜费用
	carrot_cost = carrot_weight * Price_per_pound_of_carrot;			//胡萝卜费用

	//算折扣费
	if ((artichoke_cost + sugar_cost + carrot_cost) >= 100)
		cost_discount = (artichoke_cost + sugar_cost + carrot_cost) * discount;
	else cost_discount = 0;

	//蔬菜订单总费用
	cost_of_vegetables = (artichoke_cost + sugar_cost + carrot_cost) - cost_discount;

	//计算蔬菜总重量
	sum_weight = artichoke_weight + sugar_weight + carrot_weight;

	//计算运费和包装费
	if (sum_weight <= 5)
		freight = 6.5;
	else if (sum_weight > 5 && sum_weight < 20)
		freight = 14;
	else if (sum_weight > 20)
		freight = (sum_weight - 20) * 0.5 + 14;

	//计算所有费用
	total_cost = cost_of_vegetables + freight;

	//打印输出
	printf("\n\n");
	if (artichoke_weight > 0)
		printf("洋蓟%.2lf美元/磅，共购买%.2lf磅，花了%.2lf美元。\n", Price_per_pound_of_artichoke, artichoke_weight, artichoke_cost);
	if (sugar_weight > 0)
		printf("甜菜%.2lf美元/磅，共购买%.2lf磅，花了%.2lf美元。\n", Price_per_pound_of_sugar, sugar_weight, sugar_cost);
	if (carrot_weight > 0)
		printf("洋蓟%.2lf美元/磅，共购买%.2lf磅，花了%.2lf美元。\n", Price_per_pound_of_carrot, carrot_weight, carrot_cost);
	if (cost_discount > 0)
		printf("共优惠%.2lf美元。\n", cost_discount);
	printf("订单总费用共%.2lf美元。\n", cost_of_vegetables);
	printf("运费和包装费共%.2lf美元。\n", freight);
	printf("共花费%.2lf美元。\n", total_cost);
}