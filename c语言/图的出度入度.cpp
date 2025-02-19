#include<stdio.h> 
void Creat_AdjMatrix(AdjMatrix *G);
int LocateVex_AdjMatrix(AdjMatrix *G,Vextype v);
void Print_AdjMatrix(AdjMatrix *G);
void GetDegree_AdjMatrix(AdjMatrix *G,int InDegree[],int OutDegree[]);

main()
{
    AdjMatrix g;
    int In[MAXVEX]={0},Out[MAXVEX]={0},i; 
    Creat_AdjMatrix(&g);
    GetDegree_AdjMatrix(&g,In,Out); 
    for(i=1;i<=g.vexnum;i++)
        printf("%d ",Out[i]);
    printf("\n");
    for(i=1;i<=g.vexnum;i++)
        printf("%d ",In[i]);
    printf("\n");
}

void Creat_AdjMatrix(AdjMatrix *G)
{
    int i,j,k;
    char v1,v2;
    scanf("%d\n",&(G->vexnum));
    for(i=1;i<=G->vexnum;i++)
    { 
        scanf("%c",&(G->vex[i]));
        for(j=1;j<=G->vexnum;j++)
            G->arcs[i][j]=0;
    }
    scanf("%d\n",&(G->arcnum));
    for(k=1;k<=G->arcnum;k++)
    {
        scanf("<%c,%c>",&v1,&v2);
        i=LocateVex_AdjMatrix(G,v1);
        j=LocateVex_AdjMatrix(G,v2);
        G->arcs[i][j]=1; 
    }
}


int LocateVex_AdjMatrix(AdjMatrix *G,Vextype v)
{
    int i;
    for(i=1;i<=G->vexnum;i++)
        if(G->vex[i]==v) 
            return i;
    return 0;
}


/* ����������д�� */
void GetDegree_AdjMatrix(AdjMatrix *G,int InDegree[],int OutDegree[])
{
    int i,j;
    int count = 0;
    int count2 = 0;
    
    for(i = 1;i <= G->vexnum;i++ ){
        for(j = 1;j <= G->vexnum;j++){
            if(G->arc[i][j] == 1) count++;
            if(G->arc[j][i] == 1) count2++;
        }
        InDegree[i] = count;
        OutDegree[i] = count2;
        count2 = 0;
        count = 0;
    }
}

