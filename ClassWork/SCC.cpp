#include<bits/stdc++.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;
int G[100][100];
int GT[100][100];
int color[100], d[100], f[100], previous[100],counter[100];
int color2[100], d2[100], f2[100], previous2[100];
int component[100];
int top=0;
int time1=0;
int count2=0;
int time2=0;
int n, e, u, v;

/*void print_path(int s, int v) {
    if(s==v) {
       // printf("%d->",s);
       return 1;
    }
    else if(previous[v]==-1) {
            return 0;
       // printf("No Path");
    }
    else {
        print_path(s,previous[v]);

     //   printf("%d->",v);
    }
}*/

void DFS_visit2(int u, int n)
{
    time2++;
    d2[u]=time2,
          color2[u]=GRAY;


    for(int v=0; v<n; v++)
    {
        if(GT[u][v]==1)
        {
            if(color2[v]==WHITE)
            {
                previous2[v]=u;
                //counter[u]=pic;
                DFS_visit2(v,n);
            }
        }
        time2++;
        f2[u]=time2;

        color2[u]=BLACK;
        counter[u]=count2;

    }


}

void DFS2(int n)
{

    for(int i=0; i<n; i++)
    {
        color2[i]=WHITE;
        previous2[i]=-1;
        d2[i]=0;
        f2[i]=0;
    }

    while(top!=0)
    {

        u=component[top];
        top--;

        if(color2[u]==WHITE)
        {
            DFS_visit2(u,n);
        count2++;

        }
    }

}
void DFS_visit(int u, int n)
{
    time1++;
    d[u]=time1,
         color[u]=GRAY;
    for(int v=0; v<n; v++)
    {
        if(G[u][v]==1)
        {
            if(color[v]==WHITE)
            {
                previous[v]=u;
                DFS_visit(v,n);
            }
        }
    }
    time1++;
    f[u]=time1;

    color[u]=BLACK;
    component[top++]=u;
}

void DFS(int n)
{

    for(int i=0; i<n; i++)
    {
        color[i]=WHITE;
        previous[i]=-1;
        d[i]=0;
        f[i]=0;
    }

    for(int u=0; u<n; u++)
    {
        if(color[u]==WHITE)
        {
            DFS_visit(u,n);

        }
    }
}


int main()
{
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            G[i][j]=0;
            GT[i][j]=0;
        }
    }

    for(int i=0; i<e; i++)
    {
        // printf("Enter edges:");
        scanf("%d %d",&u,&v);
        G[u][v]=1;
        GT[v][u]=1;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%-4d",G[i][j]);
        }
        printf("\n");
    }

    DFS(n);

    DFS2(n);
    for(int i=0; i<count2; i++)
    {
        cout<<endl<<"Forest "<<i<<" :";
        for(int j=0; j<n; j++)
        {
            if(counter[j]==i)
            {
                cout<<j<<" ";
            }
        }
    }

    return 0;
}

/*
1 0
0 2
2 3
1 3
3 5
5 3
4 5
2 4
4 6
6 4
6 7
7 7
5 7
2 1
*/
