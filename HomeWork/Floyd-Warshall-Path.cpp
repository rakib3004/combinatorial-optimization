
#include<bits/stdc++.h>
using namespace std;
int main(){
int n,e;
cout<<"Number of Nodes : ";
cin>>n;
cout<<endl;

int f[n][n],c[n][n],path[n][n],flag[n][n],weight[n][n];
int i,j;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
weight[i][j]=1000000000;
path[i][j]=j;
}
}
for(i=0;i<n;i++){
weight[i][i]=0;
}
int x,y,flow,w;
cout<<"Number of edges :";
cin>>e;
cout<<endl;
cout<<"From-->To-->Weight"<<endl;
for(i=0;i<e;i++){
cin>>x>>y>>w;
weight[x][y]=w;
}

int k;

for(k=0;k<n;k++){
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(weight[i][j]>(weight[i][k]+weight[k][j])){
weight[i][j]= (weight[i][k]+weight[k][j]);
path[i][j]=path[i][k];
}
}
}
}
cout<<"From-->To-->Minimum cost"<<endl;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(weight[i][j]&&weight[i][j]!=1000000000){
cout<<i<<"--->"<<j<<"===>"<<weight[i][j]<<endl;
}
}
}
int a,b;
cout<<"Source Vertex : ";
cin>>a;
cout<<"Sink Vertex : ";
cin>>b;
if(weight[a][b]!=1000000000){
cout<<"Path is : "<<a;
while(a!=b){
a=path[a][b];
cout<<"-->"<<a;
}
cout<<endl;
}
else{

cout<<"No Path is found"<<endl;
}
return 0;

}
/*
  6-----8
0 2 5
0 4 2
0 5 9
1 4 2
1 5 7
2 3 2
2 4 1
4 5 3*/


