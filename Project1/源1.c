#include <stdio.h>


int main(void)
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

	return 0;
}
//���ڼ������л���1�ֽھ�Ϊ8λ��
//C���԰�1�ֽڶ���Ϊchar����ռ�õ�λ��
// 
//printf������Ҫ��ʾǰ׺�����#����printf("%#x",toes)�� 
//�з������ͣ�short (int)<= int <= long (int)< long long (int)
/*
* short:		16λ
* int:			16λ��32λ
* long:			32λ
* long long:	64λ
*/
//�������������ﵽ���ܱ�ʾ�����ֵʱ�����������´���㿪ʼ��
//



