# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "SqBiTreeQueue.cpp"

# include <iostream>
using namespace std;

//# define CHAR 1  //�ַ��� 
# define CHAR 0  //���� 

#if CHAR
	typedef char TElemType;
	TElemType Nil = ' ';
#else
	typedef int TElemType;
	TElemType Nil = 0;
#endif

# define MAX_TREE_SIZE 100

typedef TElemType SqBiTree[MAX_TREE_SIZE];

typedef struct position
{
	int level;
	int order;
} position;

void InitBiTree(SqBiTree);
void CreateBiTree(SqBiTree);
bool BiTreeEmpty(SqBiTree);
int BiTreeDepth(SqBiTree);
bool Root(SqBiTree, TElemType *);
TElemType Value(SqBiTree, position *);
bool Assign(SqBiTree, position *, TElemType);
TElemType Parent(SqBiTree, TElemType);
TElemType LeftChild(SqBiTree, TElemType);
TElemType RightChild(SqBiTree, TElemType);
TElemType LeftSibling(SqBiTree, TElemType);
TElemType RightSibling(SqBiTree, TElemType);
void Move(SqBiTree, int, SqBiTree, int);
void InsertChild(SqBiTree, TElemType, int, SqBiTree);
bool DeleteChild(SqBiTree, position *, int);
void PreTraverse(SqBiTree, int);
void PreOrderTraverse(SqBiTree, void(*Visit)(TElemType));
void InTraverse(SqBiTree, int);
void InOrderTraverse(SqBiTree, void(*Visit)(TElemType));
void PostTraverse(SqBiTree, int);
void PostOrderTraverse(SqBiTree, void(*Visit)(TElemType));
void LevelOrderTraverse(SqBiTree, void(*Visit)(TElemType));
void Print(SqBiTree);

void visit(TElemType e)
{
	cout << e << ' ';
}

int main(void)
{
	SqBiTree T;
	SqBiTree c; 
	TElemType e;
	position p;
	
	InitBiTree(T);
	CreateBiTree(T);
	
//	Root(T, &e);
//	cout << e << endl;
	
//	cout << "��������޸Ľ��Ĳ�� ������ţ�";
//	cin >> p.level >> p.order;
//	e = Value(T, &p);
//	cout << "���޸Ľ���ԭֵΪ" << e << "��������ֵ��";
//	cin >> e;
//	Assign(T, &p, e);
//	LevelOrderTraverse(T, visit);
	
//	cout << "������һ����ֵ����Ѱ��˫�׽�㣺";
//	cin >> e;
//	e = Parent(T, e);
//	cout << "�ý���˫��ֵΪ" << e << endl;

//	cout << "������һ����ֵ����Ѱ�����ӽ�㣺";
//	cin >> e;
//	e = LeftChild(T, e); 
//	cout << "�ý�������ֵΪ" << e << endl;

//	cout << "������һ����ֵ����Ѱ���Һ��ӽ�㣺";
//	cin >> e;
//	e = RightChild(T, e); 
//	cout << "�ý����Һ���ֵΪ" << e << endl;

//	cout << "������һ����ֵ����Ѱ�����ֵܽ�㣺";
//	cin >> e;
//	e = LeftSibling(T, e); 
//	cout << "�ý������ֵ�ֵΪ" << e << endl;	

//	cout << "������һ����ֵ����Ѱ�����ֵܽ�㣺";
//	cin >> e;
//	e = RightSibling(T, e); 
//	cout << "�ý������ֵ�ֵΪ" << e << endl;	
	
//	LevelOrderTraverse(T, visit);
//	cout << "�ٹ���һ˳��������������в��������" << endl;
//	InitBiTree(c);
//	CreateBiTree(c);
//	cout << "������Ҫ������T��Ӧ���λ�õ�ֵ��";
//	cin >> e;
//	InsertChild(T, e, 1, c);
//	InsertChild(T, e, 0, c);
//	LevelOrderTraverse(T, visit);

//	cout << "������Ҫɾ������λ�ã�������źͱ�����ţ���";
//	cin >> p.level >> p.order;
//	LevelOrderTraverse(T, visit);
//	DeleteChild(T, &p, 1);
//	DeleteChild(T, &p, 0);
//	LevelOrderTraverse(T, visit);

	cout << "���������";
	PreOrderTraverse(T, visit);
	cout << "���������";
	InOrderTraverse(T, visit);
	cout << "���������";
	PostOrderTraverse(T, visit);
	
	cout << "��ϸ��ӡ˳���������" << endl;
	Print(T);
	
	return 0;
}

void InitBiTree(SqBiTree T)
{
	int i;
	for(i = 0; i < MAX_TREE_SIZE; ++i)
	{
		T[i] = Nil;
	}
}

void CreateBiTree(SqBiTree T)
{
	int i = 0;
	
	InitBiTree(T);
	
#if CHAR
	int len;
	char s[MAX_TREE_SIZE];
	
	cout << "�밴�����������ֵ(�ַ�)���ո��ʾ�ս�㣬�����<=" << MAX_TREE_SIZE << ':' << endl;
	gets(s);
	
	len = strlen(s);
	for(; i < len; ++i)
	{
		T[i] = s[i];
	}
#else
	cout << "�밴�����������ֵ(����)��0��ʾ�ս�㣬��999�����������<=" << MAX_TREE_SIZE << ':' << endl;
	while(1)
	{
		cin >> T[i];
		if(T[i] == 999)
		{
			T[i] = Nil;
			break;
		}
		i++;
	}
#endif
	
	for(i = 1; i < MAX_TREE_SIZE; ++i)
	{
		if(i != 0 && T[i] != Nil && T[(i+1)/2 - 1] == Nil)
		{
			cout << "������˫�׵ķǸ����" << T[i] << endl;
			exit(-1);
		}
	}
}

bool BiTreeEmpty(SqBiTree T)
{
	if(T[0] == Nil)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int BiTreeDepth(SqBiTree T)
{
	int i;
	int j = -1;
	
	for(i = MAX_TREE_SIZE - 1; i >= 0; --i)
	{
		if(T[i] != Nil)
		{
			break;
		}
	}
	i += 1;
	
	do
	{
		j++;
	} while(i >= pow(2, j));
	
	return j;
}

bool Root(SqBiTree T, TElemType * e)
{
	if(BiTreeEmpty(T))
	{
		return false;
	}
	else
	{
		*e = T[0];
		return true;
	}
}

TElemType Value(SqBiTree T, position * e)
{
	if(BiTreeEmpty(T))
	{
		return Nil;
	}
	else
	{
		return T[int(pow(2, e->level-1) - 1 + e->order - 1)];
	}
}

bool Assign(SqBiTree T, position * e, TElemType value)
{
	if(BiTreeEmpty(T))
	{
		return false;
	}
	else
	{
		int i = int(pow(2, e->level-1) - 1 + e->order - 1);
		
		if(value != Nil && T[(i+1)/2 - 1] == Nil)
		{
			return false;
		}
		if(value == Nil && (T[(i+1)*2 - 1] != Nil || T[(i+1)*2+1 - 1] != Nil))
		{
			return false;
		}
		
		T[i] = value;
		
		return true;
	}
}

TElemType Parent(SqBiTree T, TElemType e)
{
	int i;
	
	if(BiTreeEmpty(T))
	{
		return Nil;
	}
	
	for(i = 1; i < MAX_TREE_SIZE; ++i)
	{
		if(T[i] == e)
		{
			return T[(i+1)/2 - 1];
		}
	}
	
	return Nil;
}

TElemType LeftChild(SqBiTree T, TElemType e)
{
	int i;
	
	if(BiTreeEmpty(T))
	{
		return Nil;
	}
	
	for(i = 0; i < MAX_TREE_SIZE; ++i)
	{
		if(T[i] == e)
		{
			return T[(i+1)*2 - 1];
		}
	}
	
	return Nil;
}

TElemType RightChild(SqBiTree T, TElemType e)
{
	int i;
	
	if(BiTreeEmpty(T))
	{
		return Nil;
	}
	
	for(i = 0; i < MAX_TREE_SIZE; ++i)
	{
		if(T[i] == e)
		{
			return T[(i+1)*2+1 - 1];
		}
	}
	
	return Nil;
}

TElemType LeftSibling(SqBiTree T, TElemType e)
{
	int i;
	
	if(BiTreeEmpty(T))
	{
		return Nil;
	}
	
	for(i = 1; i < MAX_TREE_SIZE; ++i)
	{
		if(T[i] == e && i%2 == 0)
		{
			return T[i - 1];
		}
	}
	
	return Nil;
}

TElemType RightSibling(SqBiTree T, TElemType e)
{
	int i;
	
	if(BiTreeEmpty(T))
	{
		return Nil;
	}
	
	for(i = 1; i < MAX_TREE_SIZE; ++i)
	{
		if(T[i] == e && i%2 == 1)
		{
			return T[i + 1];
		}
	}
	
	return Nil;
}

void Move(SqBiTree q, int j, SqBiTree T, int i)
{
	if(q[(j+1)*2 - 1] != Nil)
	{
		Move(q, 2*j + 1, T, 2*i + 1);
	}
	if(q[(j+1)*2+1 - 1] != Nil)
	{
		Move(q, 2*j + 2, T, 2*i + 2);
	}
	T[i] = q[j];
	q[j] = Nil;
}

void InsertChild(SqBiTree T, TElemType e, int LR, SqBiTree c)
{
	int i = 0;
	int j, k;
	
	if(BiTreeEmpty(T))
	{
		return;
	}
	
	for(j = 0; j < int(pow(2, BiTreeDepth(T))) - 1; ++j)
	{
		if(T[j] == e)
		{
			break;
		}
	}
	
	k = (j+1)*2 + LR - 1;
	if(T[k] != Nil)
	{
		Move(T, k, T, (k+1)*2+1 - 1);
	}
	Move(c, i, T, k);
}

bool DeleteChild(SqBiTree T, position * e, int LR)
{
	int i;
	bool k = true;
	
	if(BiTreeEmpty(T))
	{
		return false;
	}
	
	Queue q;
	init(&q);
	
	i = int(pow(2, e->level - 1) - 1 + e->order - 1);
	if(T[i] == Nil)
	{
		return false;
	}
	i = (i+1)*2 + LR - 1;
	
	while(k)
	{
		if(T[(i+1)*2 - 1] != Nil)
		{
			enqueue(&q, 2*i + 1);
		}
		if(T[(i+1)*2+1 - 1] != Nil)
		{
			enqueue(&q, 2*i + 2);
		}
		
		T[i] = Nil;
		
		k = dequeue(&q, &i);
	}
	
	//ʹ������ʽ�������ֶ��ͷ����ڴ棬��������ڴ�й©
	destroy(&q);
	
	return true;
}

void(*VisitFunc)(TElemType);

void PreTraverse(SqBiTree T, int e)
{
	VisitFunc(T[e]);
	if(T[(e+1)*2 - 1] != Nil)
	{
		PreTraverse(T, 2*e + 1);
	}
	if(T[(e+1)*2+1 - 1] != Nil)
	{
		PreTraverse(T, 2*e + 2);
	}
}

void PreOrderTraverse(SqBiTree T, void(*Visit)(TElemType))
{
	VisitFunc = Visit;
	
	if(!BiTreeEmpty(T))
	{
		PreTraverse(T, 0);
	}
	
	cout << endl;
}

void InTraverse(SqBiTree T, int e)
{
	if(T[(e+1)*2 - 1] != Nil)
	{
		InTraverse(T, 2*e + 1);
	}
	VisitFunc(T[e]);
	if(T[(e+1)*2+1 - 1] != Nil)
	{
		InTraverse(T, 2*e + 2);
	}
}

void InOrderTraverse(SqBiTree T, void(*Visit)(TElemType))
{
	VisitFunc = Visit;
	
	if(!BiTreeEmpty(T))
	{
		InTraverse(T, 0);
	}
	
	cout << endl;
}

void PostTraverse(SqBiTree T, int e)
{
	if(T[(e+1)*2 - 1] != Nil)
	{
		PostTraverse(T, 2*e + 1);
	}
	if(T[(e+1)*2+1 - 1] != Nil)
	{
		PostTraverse(T, 2*e + 2);
	}
	VisitFunc(T[e]);
}

void PostOrderTraverse(SqBiTree T, void(*Visit)(TElemType))
{
	VisitFunc = Visit;
	
	if(!BiTreeEmpty(T))
	{
		PostTraverse(T, 0);
	}
	
	cout << endl;
}

void LevelOrderTraverse(SqBiTree T, void(*Visit)(TElemType))
{
	int i = MAX_TREE_SIZE - 1;
	int j;
	
	while(T[i] == Nil)
	{
		i--;
	}
	
	for(j = 0; j <= i; ++j)
	{
		if(T[j] != Nil)
		{
			Visit(T[j]);
		}
	}
	
	cout << endl;
}

void Print(SqBiTree T)
{
	int j, k;
	position p;
	TElemType e;
	
	for(j = 1; j <= BiTreeDepth(T); ++j)
	{
		cout << "��" << j << "�㣺";
		for(k = 1; k <= int(pow(2, j - 1)); ++k)
		{
			p.level = j;
			p.order = k;
			
			e = Value(T, &p);
			if(e != Nil)
			{
				cout << k << ':' << e << ' ';
			}
		}
		cout << endl;
	}
}

