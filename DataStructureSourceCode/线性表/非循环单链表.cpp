# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
} NODE, * PNODE;

PNODE create_list(void);
void traverse_list(PNODE);
bool is_empty(PNODE);
int length_list(PNODE);
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int *);
void sort_list(PNODE, int);
bool get_list(PNODE, int, int *);
void delete_max(PNODE, int *);
void destroy_list(PNODE);

int main(void)
{
	PNODE pHead;
	int delete_value;
	int get_value;
	int delete_max_value;
	
	pHead = create_list();
	traverse_list(pHead);
	
	if( is_empty(pHead) )
		printf("����Ϊ�գ�");
	else
		printf("����Ϊ�գ�");
		
	int len = length_list(pHead);
	printf("����ĳ���Ϊ��%d\n", len);
	
	printf("\n���������ð������(����)֮��Ľ���ǣ�\n");
	sort_list(pHead, len);
	traverse_list(pHead);
	
	printf("\n�������в���һ��ֵ��Ľ���ǣ�\n");
	insert_list(pHead, 4, 100);
	traverse_list(pHead);
	
	printf("\nɾ��������һ������Ľ���ǣ�\n");
	delete_list(pHead, 5, &delete_value);
	traverse_list(pHead);
	printf("ɾ����ֵΪ��%d\n", delete_value);
	
	get_list(pHead, 3, &get_value);
	printf("�õ���ѭ���������е�3������ֵ�ǣ�%d\n", get_value);
	
	delete_max(pHead, &delete_max_value);
	printf("ɾ���������е����ֵ�ǣ�%d\n", delete_max_value);
	traverse_list(pHead);
	
	destroy_list(pHead);  //�ͷ��������� 
	
	return 0;
}

PNODE create_list(void)
{
	int len;
	int i;
	int val;
	
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(NULL == pHead)
	{
		printf("ϵͳ����ʧ�ܣ�");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	
	printf("��������Ҫ���ɵĽ�������");
	scanf("%d", &len);
	
	for(i=0; i<len; ++i)
	{
		printf("������Ҫ����ڵ�%d���ڵ��ֵ��", i+1);
		scanf("%d", &val);
		
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL == pNew)
		{
			printf("ϵͳ����ʧ�ܣ�");
			exit(-1);
		}
		
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	
	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	
	printf("\n");
	while(NULL != p)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
	
	return;
}

bool is_empty(PNODE pHead)
{
	printf("\n");
	if(NULL == pHead->pNext)
		return true;
	else
		return false;
}

int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int cnt = 0;
	
	printf("\n");
	while(NULL != p)
	{
		++cnt;
		p = p->pNext;
	}
	printf("\n");
	
	return cnt;
}

void sort_list(PNODE pHead, int len)
{
	PNODE p, q;
	int i, j;
	int t;
	
	for(i=0; i<len-1; ++i)
	{
		p = pHead->pNext;
		q = pHead->pNext->pNext;
		
		for(j=0; j<len-1-i; ++j)
		{
			if(p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
			p = p->pNext;
			q = q->pNext;
		}
	}
	
	return;
}

bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	
	//���µ�whileѭ����if�ж� Ϊһ����Ҫ�㷨 
	while(NULL!=p && i<pos-1)
	{
		p = p->pNext;  //p��һ�������������ʱ���а��� 
		i++;
	}
	if(i>pos-1 || NULL==p)
	{
		return false;
	}
	//���㷨������ʹ���������ǰ�ж�����(���������᷵��false)�����ܹ��������������������Ľ��� 
	
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL == pNew)
	{
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	
	pNew->data = val;
	//������������д��롣 
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	
	return true;
}

bool delete_list(PNODE pHead, int pos, int * pVal)
{
	int i = 0;
	PNODE p = pHead;
	
	//���������Ҫ�㷨 whileѭ��+if�ж�
	while(NULL!=p->pNext && i<pos-1)
	{
		p = p->pNext;  //p��һ�������ɾ������ʱ���а��� 
		i++;
	}
	if(i>pos-1 || NULL==p->pNext)
	{
		return false;
	}
	
	PNODE q = p->pNext;
	*pVal = p->pNext->data;  //�ȼ��� *pVal = q->data; 
	p->pNext = p->pNext->pNext;  //�ȼ��� p->pNext = q->pNext; 
	free(q);
	q = NULL;
	
	return true;
}

bool get_list(PNODE pHead, int pos, int * pVal)
{
	int i = 1;
	PNODE p = pHead->pNext;
	
	while(NULL!=p && i<pos)
	{
		p = p->pNext;
		i++;
	}
	if(i>pos || NULL==p)
	{
		return false;
	}
	
	*pVal = p->data;
	
	return true;
}

void delete_max(PNODE pHead, int * pVal)
{
	PNODE p = pHead->pNext;
	PNODE max = p;
	PNODE pre = pHead;
	PNODE maxpre = pre;
	
	while(NULL != p)
	{
		if(max->data < p->data)
		{
			max = p;
			maxpre = pre;
		}
		pre = p;
		p = p->pNext; 
	}
	
	*pVal = max->data;
	maxpre->pNext = max->pNext;
	free(max);
	
	return;
}

void destroy_list(PNODE pHead)
{
	if(NULL == pHead)
	{
		printf("�������ڣ������ͷš�\n"); 
		return;
	}
	else
	{
		PNODE p;
		while(NULL != pHead)
		{
			p = pHead->pNext;
			free(pHead);
			pHead = p;
		}
		printf("�����ͷųɹ���\n");
		
		return;
	}
}
