#include<bits/stdc++.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;
int G[100][100];
int GT[100][100];
int color[100], d[100], f[100], prev[100],c[100];
int component[100];
int top=0;
int time1=0;
int count1=0;
    int n, e, u, v;

/*void print_path(int s, int v) {
    if(s==v) {
       // printf("%d->",s);
       return 1;
    }
    else if(prev[v]==-1) {
            return 0;
       // printf("No Path");
    }
    else {
        print_path(s,prev[v]);

     //   printf("%d->",v);
    }
}*/

void DFS_visit2(int u, int n,int count1) {
    time1++;
    d[u]=time1,
    color[u]=GRAY;
    for(int v=0;v<n;v++) {
        if(G[u][v]==1) {
            if(color[v]==WHITE)
            {
                prev[v]=u;
               //c[u]=pic;
                DFS_visit2(v,n,count1);
            }
        }
    }
    time1++;
    f[u]=time1;

    color[u]=BLACK;
    c[u]=count1;
}

void DFS2(int n)
{

  for(int i=0;i<n;i++) {
        color[i]=WHITE;
        prev[i]=-1;
    }

while(top!=0){

    u=component[top];
    top--;
}        if(color[u]==WHITE)
        {
            count1++;
        DFS_visit2(u,n,count1);

        }

}
void DFS_visit(int u, int n) {
    time1++;
    d[u]=time1,
    color[u]=GRAY;
    for(int v=0;v<n;v++) {
        if(G[u][v]==1) {
            if(color[v]==WHITE)
            {
                prev[v]=u;
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

  for(int i=0;i<n;i++) {
        color[i]=WHITE;
        prev[i]=-1;
    }

    for(int u=0;u<n;u++) {
        if(color[u]==WHITE)
        {
        DFS_visit(u,n);

        }
    }
}


int main() {
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            G[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        printf("Enter edges:");
        scanf("%d %d",&u,&v);
        G[u][v]=1;
        GT[v][u]=1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%-4d",G[i][j]);
        }
        printf("\n");
    }

    DFS(n);

DFS2(n);
for(int i=0;i<=count1;i++){
    cout<<endl<<"Forest "<<i<<" :";
    for(int j=0;j<n;j++){
        if(c[j]==i){
            cout<<j<<" ";
        }
    }
}

    return 0;
}
