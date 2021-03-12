# include <stdio.h>

# define MAXSIZE 100

typedef struct
{
	int data;
	int cur;
}component, SLL[MAXSIZE];

void init_list(SLL);
int malloc_S(SLL);
void free_S(SLL, int);
void difference(SLL);
int create_list(SLL);
void traverse_list(SLL, int);
bool insert_list(SLL, int, int, int);
bool delete_list(SLL, int, int, int *);
int locate_list(SLL, int, int);

int main(void)
{
	SLL space;  //����һ�����ÿռ�space 
	int S;  //����һ��ͷ��� 
	int delete_value;
	
	difference(space);  //���(A-B)U(B-A) 
	
	S = create_list(space);
	traverse_list(space, S);
	
	insert_list(space, S, 3, 100);
	traverse_list(space, S);
	
	delete_list(space, S, 4, &delete_value);
	traverse_list(space, S);
	printf("ɾ����̬�����е�4������ֵ�ǣ�%d\n", delete_value);
	
	int locate = locate_list(space, S, 5);
	printf("����5���ֵ�ھ�̬�����е�λ��Ϊ��%d\n", locate);
	
	return 0;
}

void init_list(SLL space)
{
	int i;
	
	for(i=0; i<MAXSIZE-1; ++i)
	{
		space[i].cur = i+1;
	}
	space[MAXSIZE-1].cur = 0;
}

int malloc_S(SLL space)
{
	int i;
	
	i = space[0].cur;
	if(space[0].cur)
	{
		space[0].cur = space[i].cur;
		//����Ϊ�����Ͻ��ԣ�Ӧ�����������ע�͵�����һ�� 
		//space[i].cur = 0; 
	}
	
	return i;
}

void free_S(SLL space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
	
	return;
}

void difference(SLL space)
{
	int S, r, T, q;
	int m, n;
	int j;
	int i;
	init_list(space);  //space���ÿռ���г�ʼ�� 
	
	S = malloc_S(space);  //������S��ͷ��㣬S������ͷָ�� 
	r = S;
	
	printf("������Ҫ���ɵ�A���ϵ�Ԫ�صĸ�����");
	scanf("%d", &m);
	for(j=1; j<=m; ++j)
	{
		i = malloc_S(space);
		scanf("%d", &space[i].data);
		space[r].cur = i;
		r = i;
	}
	space[r].cur = 0;
//----------------------------------------------	
	T = malloc_S(space);
	q = T;
	
	printf("������Ҫ���ɵ�B���ϵ�Ԫ�صĸ�����");
	scanf("%d", &n);
	for(j=1; j<=n; ++j)
	{
		i = malloc_S(space);
		scanf("%d", &space[i].data);
		space[q].cur = i;
		q = i;
	}
	space[q].cur = 0;
	
	//��ʼ����(A-B)U(B-A)����� 
	int w = T;
	int l, b;
	int p, k;
	for(j=1; j<=n; ++j)
	{
		l = space[w].cur;
		b = space[l].data;
		
		p = S;
		k = space[S].cur;
		
		while(k!=space[r].cur && space[k].data!=b)
		{
			p = k;
			k = space[k].cur;
		}
		if(k == space[r].cur)
		{
			i = malloc_S(space);
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;
		}
		else
		{
			space[p].cur = space[k].cur;
			free_S(space, k);
			
			if(r == k)
			{
				r = p;
			}
		}
		
		w = space[w].cur;
	}
	
	printf("\n");
	int c = S;
	while(space[c].cur)
	{
		c = space[c].cur;
		printf("%d ", space[c].data);
	}
	printf("\n");
	
	int e = T;
	while(space[e].cur)
	{
		e = space[e].cur;
		printf("%d ", space[e].data);
	}
	printf("\n");
	
	return;
}

int create_list(SLL space)
{
	int len;
	int i;
	int n;
	
	int S = malloc_S(space);
	int q = S;
	
	printf("��������Ҫ���ɵĽ��ĸ�����");
	scanf("%d", &len);
	
	for(i=1; i<=len; ++i)
	{
		n = malloc_S(space);
		scanf("%d", &space[n].data);
		space[q].cur = n;
		q = n;
	}
	space[q].cur = 0;
	
	return S;
}

void traverse_list(SLL space, int S)
{
	int p = space[S].cur;
	
	printf("\n");
	while(0 != p)
	{
		printf("%d ", space[p].data);
		p = space[p].cur;
	}
	printf("\n");
	
	return;
}

bool insert_list(SLL space, int S, int pos, int val)
{
	int i = 0;
	int p = S;
	
	while(0!=p && i<pos-1)
	{
		p = space[p].cur;
		i++;
	}
	if(i>pos-1 || 0==p)
	{
		return false;
	}
	
	int n = malloc_S(space);
	if(n)
	{
		space[n].data = val;
		space[n].cur = space[p].cur;
		space[p].cur = n;
	}
	
	return true;
}

bool delete_list(SLL space, int S, int pos, int * pVal)
{
	int i = 0;
	int p = S;
	
	while(0!=space[p].cur && i<pos-1)
	{
		p = space[p].cur;
		i++;
	}
	if(i>pos-1 || 0==space[p].cur)
	{
		return false;
	}
	
	int q = space[p].cur;
	*pVal = space[q].data;
	space[p].cur = space[q].cur;
	free_S(space, q);
	
	return true;
}

int locate_list(SLL space, int S, int val)
{
	int locate = 1;
	int p = space[S].cur;
	
	while(p && val!=space[p].data)
	{
		p = space[p].cur;
		locate++;
	}
	if(0 == p)
	{
		return p;
	}
	else
	{
		return locate;
	}
}
