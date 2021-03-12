# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct ArrayList
{
	int * pBase;
	int len;
	int cnt;
} array, * pArray;

void init_array(pArray, int);
bool append_array(pArray, int);
bool insert_array(pArray, int, int);
bool delete_array(pArray, int, int *);
bool get(pArray, int, int *);
int find(pArray, int);
bool is_empty(pArray);
bool is_full(pArray);
void sort_array(pArray);
void show_array(pArray);
void inversion_array(pArray);

int main(void)
{
	array arr;
	int len = 6;
	int delete_value;
	int get_value;
	
	init_array(&arr, len);
	show_array(&arr);
	
	append_array(&arr, 1);
	append_array(&arr, 2);
	append_array(&arr, 3);
	append_array(&arr, 4);
	show_array(&arr);
	
	insert_array(&arr, 2, 100);
	show_array(&arr);
	
	if( delete_array(&arr, 5, &delete_value) )
	{
		printf("\nɾ���ɹ���ɾ����ֵΪ��%d\n", delete_value);
	}
	else
	{
		printf("\nɾ��ʧ�ܣ�\n");
	}
	show_array(&arr);
	
	get(&arr, 2, &get_value);
	printf("\n�õ���������Ϊ2��Ԫ�ص�ֵΪ��%d\n", get_value);
	
	int index = find(&arr, 3);
	printf("\n���ҳ�3���ֵ�������е�����Ϊ��%d\n", index); 
	
	printf("\n��������������֮��Ľ���ǣ�");
	sort_array(&arr);
	show_array(&arr);
	
	printf("\n�����鵹��֮��Ľ���ǣ�");
	inversion_array(&arr);
	show_array(&arr);
	
	return 0;
}

void init_array(pArray pArr, int len)
{
	pArr->pBase = (int *)malloc(sizeof(int)*len);
	if(NULL == pArr->pBase)
	{
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	else
	{
		pArr->len = len;
		pArr->cnt = 0;
	}
	
	return;
}

bool is_empty(pArray pArr)
{
	if(0 == pArr->cnt)
		return true;
	else
		return false;
}

bool is_full(pArray pArr)
{
	if(pArr->len == pArr->cnt)
		return true;
	else
		return false;
}

void show_array(pArray pArr)
{
	if( is_empty(pArr) )
	{
		printf("����Ϊ�գ��޷���ʾ��\n");
	}
	else
	{
		printf("\n");
		for(int i=0; i<pArr->cnt; ++i)
		{
			printf("%d ", pArr->pBase[i]);
		}
		printf("\n");
	}
	
	return;
}

bool append_array(pArray pArr, int val)
{
	if( is_full(pArr) )
		return false;
	
	pArr->pBase[pArr->cnt] = val;
	pArr->cnt++;
	return true;
}

bool insert_array(pArray pArr, int pos, int val)
{
	int i;
	
	if( is_full(pArr) )
		return false;
	
	if(pos<1 || pos>pArr->cnt+1)
		return false;
	
	for(i=pArr->cnt-1; i>=pos-1; --i)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1] = val;
	
	pArr->cnt++;
	
	return true;
}

bool delete_array(pArray pArr, int pos, int * pVal)
{
	int i;
	
	if( is_empty(pArr) )
		return false;
		
	if(pos<1 || pos>pArr->cnt)
		return false;
		
	*pVal = pArr->pBase[pos-1];
	
	for(i=pos; i<pArr->cnt; ++i)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	
	pArr->cnt--;
	
	return true;
}

bool get(pArray pArr, int index, int * pVal)
{
	if(index<0 || index>pArr->cnt-1)
		return false;
		
	*pVal = pArr->pBase[index];
	
	return true;
}

int find(pArray pArr, int val)
{
	int i;
	int index;
	
	for(i=0; i<pArr->cnt; ++i)
	{
		if(val == pArr->pBase[i])
		{
			index = i;
			break;
		}
		if(i == pArr->cnt-1)
		{
			return -1;
		}
	}
	
	return index;
}

void sort_array(pArray pArr)
{
	int t;
	int i;
	int j;
	
	for(i=0; i<pArr->cnt-1; ++i)
	{
		for(j=0; j<pArr->cnt-1-i; ++j)
		{
			if(pArr->pBase[j] > pArr->pBase[j+1])
			{
				t = pArr->pBase[j];
				pArr->pBase[j] = pArr->pBase[j+1];
				pArr->pBase[j+1] = t;
			}
		}
	}
	
	return;
}

void inversion_array(pArray pArr)
{
	int i = 0;
	int j = pArr->cnt-1;
	int t;
	
	while(i < j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		
		i++;
		j--;
	}
	
	return;
}
