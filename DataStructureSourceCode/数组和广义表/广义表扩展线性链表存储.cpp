# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef char AtomType;

typedef enum ElemTag
{
	ATOM, LIST
} ElemTag;

typedef struct GLNode
{
	ElemTag tag;
	union
	{
		AtomType atom;
		struct GLNode * hp;
	};
	struct GLNode * tp;
} GLNode, * GList;

int main(void)
{
	//��������չ��������洢�����ݽṹ�����д���ﲻ�ٽ��У���Ϊ���� 
	
	return 0;
}

