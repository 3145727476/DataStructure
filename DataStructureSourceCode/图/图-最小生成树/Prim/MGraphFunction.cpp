# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

# define MAX_NAME 5
# define MAX_INFO 20
# define INFINITY INT_MAX
# define MAX_VERTEX_NUM 26

typedef int VRType;
typedef char InfoType;
typedef char VertexType[MAX_NAME];

typedef enum GraphKind
{
	DG, DN, UDG, UDN
} GraphKind;

typedef struct ArcCell
{
	VRType adj;
	InfoType * info;
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct MGraph
{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
	GraphKind kind;
} MGraph;

int LocateVex(MGraph, VertexType);
void CreateUDN(MGraph &);
void DestroyGraph(MGraph &);
void Display(MGraph);

int LocateVex(MGraph G, VertexType u)
{
	int i;
	
	for(i = 0; i < G.vexnum; ++i)
	{
		if(strcmp(u, G.vexs[i]) == 0)
		{
			return i;
		}
	}
	
	return -1;
}

void CreateUDN(MGraph & G)
{
	int i, j, k, w, IncInfo;
	char s[MAX_INFO];
	VertexType va, vb;
	
	printf("������������G�Ķ����������������Ƿ�������Ϣ(��:1, ��:0)��");
	scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &IncInfo);
	
	printf("������%d�������ֵ(<%d���ַ�)��\n", G.vexnum, MAX_NAME);
	for(i = 0; i < G.vexnum; ++i)
	{
		scanf("%s", G.vexs[i]);
	}
	for(i = 0; i < G.vexnum; ++i)
	{
		for(j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j].adj = INFINITY;
			G.arcs[i][j].info = NULL;
		}
	}
	
	printf("������%d���ߵĶ���1 ����2 Ȩֵ(�Կո���Ϊ���)��\n", G.arcnum);
	for(k = 0; k < G.arcnum; ++k)
	{
		scanf("%s%s%d%*c", va, vb, &w);
		
		i = LocateVex(G, va);
		j = LocateVex(G, vb);
		G.arcs[i][j].adj = G.arcs[j][i].adj = w;
		
		if(IncInfo)
		{
			printf("������ñߵ������Ϣ(<%d���ַ�)��", MAX_INFO);
			gets(s);
			
			w = strlen(s);
			if(w)
			{
				G.arcs[i][j].info = G.arcs[j][i].info = (char *)malloc(sizeof(char) * (w + 1));
				strcpy(G.arcs[i][j].info, s);
			}
		}
	}
	
	G.kind = UDN;
}

void DestroyGraph(MGraph & G)
{
	int i, j;
	int k = 0;
	
	if(G.kind%2)
	{
		k = INFINITY;
	}
	
	for(i = 0; i < G.vexnum; ++i)
	{
		if(G.kind < 2)
		{
			for(j = 0; j < G.vexnum; ++j)
			{
				if(G.arcs[i][j].adj != k)
				{
					if(G.arcs[i][j].info)
					{
						free(G.arcs[i][j].info);
						G.arcs[i][j].info = NULL;
					}
				}
			}
		}
		else
		{
			for(j = i+1; j < G.vexnum; ++j)
			{
				if(G.arcs[i][j].adj != k)
				{
					if(G.arcs[i][j].info)
					{
						free(G.arcs[i][j].info);
						G.arcs[i][j].info = G.arcs[j][i].info = NULL;
					}
				}
			}
		}
	}
	
	G.vexnum = 0;
	G.arcnum = 0;
}

void Display(MGraph G)
{
	int i, j;
	char s[7];
	
	switch(G.kind)
	{
		case DG:
			strcpy(s, "����ͼ");
			break;
		case DN:
			strcpy(s, "������");
			break;
		case UDG:
			strcpy(s, "����ͼ");
			break;
		case UDN:
			strcpy(s, "������");
			break;
	}
	
	printf("%d������%d������ߵ�%s�����������ǣ�", G.vexnum, G.arcnum, s);
	for(i = 0; i < G.vexnum; ++i)
	{
		printf("%s ", G.vexs[i]);
	}
	
	printf("\nG.arcs.adj:\n");
	for(i = 0; i < G.vexnum; ++i)
	{
		for(j = 0; j < G.vexnum; ++j)
		{
			printf("%11d", G.arcs[i][j].adj);
		}
		printf("\n");
	}
	
	printf("\nG.arcs.info:\n");
	printf("����1(��β) ����2(��ͷ) �û���ߵ���Ϣ��\n");
	for(i = 0; i < G.vexnum; ++i)
	{
		if(G.kind < 2)
		{
			for(j = 0; j < G.vexnum; ++j)
			{
				if(G.arcs[i][j].info)
				{
					printf("%5s %11s     %s\n", G.vexs[i], G.vexs[j], G.arcs[i][j].info);
				}
			}
		}
		else
		{
			for(j = i+1; j < G.vexnum; ++j)
			{
				if(G.arcs[i][j].info)
				{
					printf("%5s %11s     %s\n", G.vexs[i], G.vexs[j], G.arcs[i][j].info);
				}
			}
		}
	}
}

