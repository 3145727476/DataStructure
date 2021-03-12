//��̬���б���������ʹ������ʵ�֣������鳤�����ޣ����Ա���ʹ��ѭ��������ʵ�ֺͲ����� 
# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Queue
{
	int * pBase;
	int front;
	int rear;
} QUEUE;

void init(QUEUE *, int);
bool enqueue(QUEUE *, int, int);
void traverse(QUEUE *, int);
bool dequeue(QUEUE *, int *, int);
bool empty(QUEUE *);
bool full(QUEUE *, int);

int main(void)
{
	QUEUE Q;
	int len = 6;  //��ʼ����̬���еĳ�����6����������ʱ��ֻ������5����Чֵ��ʣ��һ�����������Ч���ݡ�
	int dequeue_value;
	
	init(&Q, len);
	
	enqueue(&Q, 1, len);
	enqueue(&Q, 2, len);
	enqueue(&Q, 3, len);
	enqueue(&Q, 4, len);
	enqueue(&Q, 5, len);
	enqueue(&Q, 6, len);  //��ʱ�����������ô�����޷���ɣ��᷵��false��
	traverse(&Q, len);
	
	if( dequeue(&Q, &dequeue_value, len) )
	{
		printf("���ӳɹ�����ȥ����Ԫ�ص�ֵ�ǣ�%d\n", dequeue_value);
	}
	else
	{
		printf("����ʧ�ܣ�\n");
	}
	traverse(&Q, len);
	
	return 0;
}

void init(QUEUE * pQ, int len)
{
	pQ->pBase = (int *)malloc(sizeof(int)*len);
	if(NULL == pQ->pBase)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	else
	{
		pQ->front = 0;
		pQ->rear = 0;
	}
	
	return;
}

bool full(QUEUE * pQ, int len)
{
	if( (pQ->rear+1)%len == pQ->front )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool enqueue(QUEUE * pQ, int val, int len)
{
	if ( full(pQ, len) )
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear+1)%len;
		
		return true;
	}
}

bool empty(QUEUE * pQ)
{
	if( pQ->rear == pQ->front )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void traverse(QUEUE * pQ, int len)
{
	if( empty(pQ) )
	{
		printf("����Ϊ�գ��޷�������\n");
		return;
	}
	else
	{
		int i = pQ->front;
		
		while(pQ->rear != i)
		{
			printf("%d ", pQ->pBase[i]);
			i = (i+1)%len;
		}
		printf("\n");
		
		return;
	}
}

bool dequeue(QUEUE * pQ, int * pVal, int len)
{
	if( empty(pQ) )
	{
		return false;
	}
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front+1)%len;
		
		return true;
	}
}
