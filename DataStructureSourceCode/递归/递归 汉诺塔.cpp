# include <stdio.h>

//�˺��������ǽ����A�����ϵ�n�����ӽ���B�����ƶ���C�����϶���д�� 
void hannuota(int n, char A, char B, char C)
{
/*
	�����1������
		ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�C
	���� 
		1.�Ƚ�A�����ϵ�n-1�����ӽ���C�Ƶ�B
		2.ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�C
		3.���B�����ϵ�n-1�����ӽ���A�Ƶ�C
*/ 
	if(1 == n)
	{
		printf("�����Ϊ%d�����Ӵ�%c�����Ƶ�%c����\n", n, A, C);
	}
	else
	{
		hannuota(n-1, A, C, B);
		printf("�����Ϊ%d�����Ӵ�%c�����Ƶ�%c����\n", n, A, C);
		hannuota(n-1, B, A, C);
	}
}

int main(void)
{
	char A = 'A';
	char B = 'B';
	char C = 'C';
	int n;
	
	printf("�����뺺ŵ���Ĳ�����");
	scanf("%d", &n);
	
	hannuota(n, A, B, C);
	
	return 0;
}
