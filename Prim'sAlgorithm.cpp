#include<bits/stdc++.h>
using namespace std;
int graph[10][10]={0},n,cost[10],previous[10],visited[10];
//int i,j;
void initializeSingleSource(int s){
for(int i=0;i<n;i++){

    cost[i]=10000;
    previous[i]=-1;
    visited[i]=0;
}
cost[s]=0;

}
int extractMin(){
int min=10000;
int u;
for( int i=0;i<n;i++){

    if(visited[i]==0&&cost[i]<min){
        min = cost[i];
        u=i;
    }
}
return u;
}
void relax(int u,int v){
if(cost[v]>graph[u][v]&&visited[v]==0){

    cost[v]=graph[u][v];
    previous[v]=u;
}
}

void prim(int s){
int u;
initializeSingleSource(s);
while(1){

    u = extractMin();
    visited[u]=1;

    for(int v=0;v<n;v++){
        if(graph[u][v]>0){
            relax(u,v);
        }

    }
     int i=0;
      for(;i<n;i++){
        if(visited[i]==0) break;
      }
          if(i==n) break;

}
}

int main(){

int m,u,v,w;
cout<<"Input nodes : ";
cin>>n;

cout<<"Input edges : ";
cin>>m;
int i,j;

for(i=0;i<m;i++){

    cin>>u>>v>>w;
    graph[u][v] =w;
    graph[v][u] = w;
}
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        cout<<graph[i][j]<<" ";
    }
    cout<<endl;
}

prim(0);
int MST=0;
for(i=0;i<n;i++){
    MST = MST + cost[i];
}
cout<<endl<<"Total Cost : "<<MST;
return 0;

}
  /*0 1 1
1 3 1
3 2 2
0 2 6
1 2 2
2 4 5
3 4 5*/
