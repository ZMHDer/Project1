#include <stdio.h>
//#include <string.h>
#include "string_io.h"
#include "deal_data.h"


int main(void)
{	
	deal_data();
	return 0;
}

/*========================= ������������ ==============================*/
void record1(void)
{
	int toes;
	/*��ANSI C��û��scanf_s(),ֻ��scanf()������scanf()�ڶ�ȡʱ�����߽磬
	���Կ��ܻ�����ڴ�й¶������Microsoft��˾��VS���ṩ��scanf_s()��*/
	scanf_s("%d",&toes);
	//toes = 10;
	printf("toes = %d\n", toes);
	toes = 2 * toes;
	printf("2*toes = %d\n", toes);
	toes = (toes / 2) * (toes / 2);//c������û��^ƽ�������
	printf("toes^2 = %d\n", toes);
}
// ���ڼ������л�����1�ֽھ�Ϊ8λ��
// C���԰�1�ֽڶ���Ϊchar����ռ�õ�λ����
// 
// printf������Ҫ��ʾǰ׺�����#����printf("%#x",toes)�� 
// �з������ͣ�short (int)<= int <= long (int)< long long (int)
/*
* ����				 ��Χ				��׺(��Ϊ�ض��������ͶԴ�ʱ�Ӻ�׺)	��ӡǰ׺(ת��ֻ��Сд)
* short				 16λ(-2^15~2^15-1)									%hd
* int				 16λ��32λ											%d
* long				 32λ				l(L)							%ld
* long long			 64λ				ll(LL)							%lld
* 
* unsigned int		 16λ��32λ			u(U)							%u
* unsigned short	 16λ(0~2^16-1)										%hu
* unsigned long		 32λ				lu(LU)							%lu
* unsigned long long 64λ				llu(LLU)						%llu
*/
// �������ͣ����ﵽ���ܱ�ʾ�����ֵʱ�����������´���㿪ʼ��
// û�к�׺�ĸ����ͳ�����Double���͡�

void record2(void)
{
	float count;
	printf("Enter a floating-point value��");
	scanf_s("%f",&count);
	printf("fixed-point notation��%f\n", count);
	printf("exponential notation��%e\n", count);
	printf("p notation��%.2a\n", count);
}


