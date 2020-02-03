  
#include<bits/stdc++.h>

using namespace std;

#define WHITE 0

#define GRAY 1

#define BLACK 2

int G[100][100]/*={0}*/,color[100],d[100],prev[100],f[100];

int front = 0, rear =0;

int time1=0;
int array[100],front1=0;
void print_path(int s, int v)

{

if(s==v)

{

cout<<s<<"->";

}

else if(prev[v]==-1)

{

cout<<"No Path";

}



else

{

print_path(s,prev[v]);

cout<<v<<"->";

}

}

void DFS_visit(int u, int n)

{

time1++;

d[u]=time1;

color[u]=GRAY;

for(int v=0; v<n; v++)

{

if(G[u][v]==1)

{

if(color[v]==WHITE)

{

prev[v]=u;

DFS_visit(v,n);

}

}

}

}

void DFS(int n)

{

for(int i=0; i<n; i++)

{

color[i]=WHITE;

prev[i]=-1;

}

for(int u=0; u<n; u++)

{

if(color[u]==WHITE){

DFS_visit(u,n);

}



}

}



int main()

{

int n,e,u,v,i,j;

cout<<"Enter Number of nodes: ";

cin>>n;

cout<<"Enter Number of edges: ";

cin>>e;



for(i=0; i<e; i++)

{

cout<<"Enter edges :";

cin>>u>>v;

G[u][v]=1;

G[v][u]=1;

}



for(i=0; i<n; i++)

{

for(j=0; j<n; j++)

{

cout<<G[i][j]<<"\t";

}

cout<<endl;

}



DFS(n);

for(i=0; i<n; i++)

{

cout<<color[i]<<" ";

}



cout<<endl;

for(i=0; i<n; i++)

{

cout<<d[i]<<" ";

}

for(i=0; i<n; i++)

{

cout<<f[i]<<" ";

}



cout<<endl;

for(i=0; i<n; i++)

{

cout<<prev[i]<<" ";

}



cout<<endl;

print_path(2,7);



return 0;



}
