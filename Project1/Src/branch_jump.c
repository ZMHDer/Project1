/*================================== 分支和跳转 ==================================
* 
* 1.	ch = getchar();	等效于	scanf("%c", &ch);
*		putchar();		等效于	printf("%c", ch);
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
* 
* 
* 
* 
*/

#include "branch_jump.h"


