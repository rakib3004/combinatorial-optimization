
#include<bits/stdc++.h>

using namespace std;

#define WHITE 0

#define GRAY 1

#define BLACK 2

int G[100][100],color[100],d[100],previous[100],f[100];

int front = 0, rear =0;

int time1=0;
int array[100],front1=0;
void print_path(int s, int v)

{

if(s==v)

{

cout<<s<<"->";

}

else if(previous[v]==-1)

{

cout<<"No Path->";

}



else

{

print_path(s,previous[v]);

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

previous[v]=u;

DFS_visit(v,n);

}

}

}
time1++;
f[u]=time1;
color[u]=BLACK;

}

void DFS(int n)

{

for(int i=0; i<n; i++)

{

color[i]=WHITE;

previous[i]=-1;

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

//cout<<"Enter edges :";

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


cout<<"Symbol of Nodes : \t";

for(i=0; i<n; i++)

{
cout<<i<<" ";

}
    cout<<endl;
    cout<<"Colors of Nodes: \t";
for(i=0; i<n; i++)

{

cout<<color[i]<<" ";

}


cout<<endl;
cout<<"Discovery Time : \t";

for(i=0; i<n; i++)

{

cout<<d[i]<<" ";

}
cout<<endl;
cout<<"Finishing Time : \t";

for(i=0; i<n; i++)

{

cout<<f[i]<<" ";

}
cout<<endl;
cout<<"Previous Node : \t";

for(i=0; i<n; i++)

{

cout<<previous[i]<<" ";

}



cout<<endl;

print_path(0,7);



return 0;


}
/*
0 1
1 4
1 2
0 3
3 6
2 6
2 7
7 5*/
