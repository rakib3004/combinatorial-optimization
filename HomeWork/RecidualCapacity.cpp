#include<bits/stdc++.h>
using namespace std;
int main(){
int n,e;
cout<<"Number of Nodes : ";
cin>>n;
cout<<endl;

int f[n][n],c[n][n],r[n][n],flag[n][n];
int i,j;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
f[i][j]=0;
c[i][j]=0;
r[i][j]=0;
flag[i][j]=1;
}
}
int x,y,flow,capacity;
cout<<"Number of edges :";
cin>>e;
cout<<endl;
cout<<"From-->To-->Flow-->Capacity"<<endl;
for(i=0;i<e;i++){
cin>>x>>y>>flow>>capacity;
f[x][y]=flow;
c[x][y]=capacity;
}
cout<<"From-->To-->Data"<<endl;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(c[i][j]||c[j][i]){
//
//r[i][j] = r[i][j]+c[i][j]-f[i][j];
//r[j][i] = r[i][j] +f[i][j];
if(flag[i][j]){
// if there is a both side path between two nodes that means bi directional
flag[i][j]=0;
r[i][j]=c[i][j]-f[i][j]+f[j][i];
r[j][i] = c[j][i]-f[j][i]+f[i][j];
}
}
else if(c[i][j]){
// if two edeges have only one path that means uni directional
r[i][j] = c[i][j]-f[i][j];
r[j][i] = f[i][j];
}
else{
continue;
}
}
}
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(r[i][j]){
// print all connected edges recidual capacity
cout<<i<<"-->"<<j<<"==>"<<r[i][j]<<endl;
}

}
}

return 0;

}
/*
  5-----9
0 1 11 16
1 3 12 12
3 5 15 20
0 2 8 13
1 2 0 10
2 1 1 4
2 4 4 9
4 5 4 4
4 3 7 7*/

