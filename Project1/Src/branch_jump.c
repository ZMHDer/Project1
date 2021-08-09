/*================================== ��֧����ת ==================================
*
* 1.	ch = getchar();	��Ч��	scanf("%c", &ch);
*		putchar(ch);	��Ч��	printf("%c", ch);
*
* 2.���û�л����ţ�else���������ifƥ�䡣
*
* 3.C���Ա�֤�߼����ʽ����ֵ˳���Ǵ������ң�һ��������ʹ�������ʽΪ�ٵ����أ�����ֹͣ��ֵ��
*
* 4.���������(?:) �������ʽ��value = expression1 ? expression2 : expression3
*							��expression1 != 0��	��value = expression2��
*							��expression1  = 0��	��value = expression3��
*
* 5.continue��䣺	ִ�и����󣬻���������ѭ����ʣ�ಿ�֣���������һ��ѭ���������жϡ�
*					����������Ƕ��ѭ���ڣ���ֻ��Ӱ������������ڲ�ѭ����
*
* 6.break��䣺ִ�и����󣬻���ֹ��������ѭ��������������Ƕ��ѭ���ڣ���ֻ��Ӱ������������ڲ�ѭ����
*
* 7.ctype.hͷ�ļ����������ַ����Ժ������ַ�ӳ�亯�����磺�ж��Ƿ��д��ĸ��isupper()����Сдת��д��toupper()���ȡ�
*
* 8.C�����о�������ʹ��goto�������Խ���һ��goto���÷�������������ʱ��һ��Ƕ��ѭ����������һ��break���ֻ��������ǰѭ������
*	�磺
*		while(funct > 0)
*		{
*			for(i = 1; i < 100; i++)
*			{
*				for(j = 1; j <= 50; j++)
*				{
*					�������
*					if�����⣩
*					goto help;
*					�������
*				}
*				�������
*			}
*			�������
*		}
*		�������
*		help�����
*
*/

#include "branch_jump.h"
#include <stdio.h>
#include <string.h>

const double Price_per_pound_of_artichoke = 2.05;	//ÿ����2.05��Ԫ
const double Price_per_pound_of_sugar = 1.15;		//ÿ�����1.15��Ԫ
const double Price_per_pound_of_carrot = 1.09;		//ÿ�����ܲ�1.09��Ԫ
const double discount = 0.05;	//�ۿ�

double artichoke_weight = 0;	//������
double sugar_weight = 0;		//�������
double carrot_weight = 0;		//���ܲ�����
double sum_weight = 0;			//�߲�������

double artichoke_cost = 0;	//�󼻷���
double sugar_cost = 0;		//��˷���
double carrot_cost = 0;		//���ܲ�����

double cost_of_vegetables = 0;	//�߲��ۺ��ܷ���
double freight = 0;				//�˷ѺͰ�װ��
double cost_discount = 0;		//�ۿ۷���
double total_cost = 0;			//�ܷ���

//C primer Plus(��6��)���İ� p185-t11
void vegetable_shopping(void)
{
	char ch;
	double pound = 0;

	printf("������Ҫ����ʲô�߲�(a�����󼻣�b������ˣ�c������ܲ���q�����˳�������enter��ȷ��)��");
	while ((ch = getchar()) != 'q')
	{
		if (ch == '\n')		//������ַ����ǻس��������������������ѭ���ж���һ�ַ���
			continue;

		while (getchar() != '\n') //�������ַ���������ַ�
			continue;

		switch (ch)
		{
		case 'a':
			printf("�����빺����ٰ��󼻣�");
			scanf_s("%lf", &pound);
			artichoke_weight += pound;
			break;
		case 'b':
			printf("�����빺����ٰ���ˣ�");
			scanf_s("%lf", &pound);
			sugar_weight += pound;
			break;
		case 'c':
			printf("�����빺����ٰ����ܲ���");
			scanf_s("%lf", &pound);
			carrot_weight += pound;
			break;
		default:
			printf("��Чָ��밴enter���������룡");
			break;
		}

		while (getchar() != '\n') //�������ַ���������ַ�s
			continue;
		printf("\n������Ҫ����ʲô�߲�(a�����󼻣�b������ˣ�c������ܲ���q�����˳�������enter��ȷ��)��");
	}
	//������߲˷���
	artichoke_cost = artichoke_weight * Price_per_pound_of_artichoke;	//�󼻷���
	sugar_cost = sugar_weight * Price_per_pound_of_sugar;				//��˷���
	carrot_cost = carrot_weight * Price_per_pound_of_carrot;			//���ܲ�����

	//���ۿ۷�
	if ((artichoke_cost + sugar_cost + carrot_cost) >= 100)
		cost_discount = (artichoke_cost + sugar_cost + carrot_cost) * discount;
	else cost_discount = 0;

	//�߲˶����ܷ���
	cost_of_vegetables = (artichoke_cost + sugar_cost + carrot_cost) - cost_discount;

	//�����߲�������
	sum_weight = artichoke_weight + sugar_weight + carrot_weight;

	//�����˷ѺͰ�װ��
	if (sum_weight <= 5)
		freight = 6.5;
	else if (sum_weight > 5 && sum_weight < 20)
		freight = 14;
	else if (sum_weight > 20)
		freight = (sum_weight - 20) * 0.5 + 14;

	//�������з���
	total_cost = cost_of_vegetables + freight;

	//��ӡ���
	printf("\n\n");
	if (artichoke_weight > 0)
		printf("��%.2lf��Ԫ/����������%.2lf��������%.2lf��Ԫ��\n", Price_per_pound_of_artichoke, artichoke_weight, artichoke_cost);
	if (sugar_weight > 0)
		printf("���%.2lf��Ԫ/����������%.2lf��������%.2lf��Ԫ��\n", Price_per_pound_of_sugar, sugar_weight, sugar_cost);
	if (carrot_weight > 0)
		printf("��%.2lf��Ԫ/����������%.2lf��������%.2lf��Ԫ��\n", Price_per_pound_of_carrot, carrot_weight, carrot_cost);
	if (cost_discount > 0)
		printf("���Ż�%.2lf��Ԫ��\n", cost_discount);
	printf("�����ܷ��ù�%.2lf��Ԫ��\n", cost_of_vegetables);
	printf("�˷ѺͰ�װ�ѹ�%.2lf��Ԫ��\n", freight);
	printf("������%.2lf��Ԫ��\n", total_cost);
}