
#include<bits/stdc++.h>
using namespace std;
int G[100][100];
int i,j;
int main(){
      int u,v,w;
      int n,e;

      cout<<"Enter Number of Nodes : ";
      cin>>n;
    cout<<"Number of Edges : ";
    cin>>e;

    for(i=0;i<e;i++){
               cin>>u>>v>>w;
               G[u][v]=w;
               G[v][u]=w;

    }
    cout<<endl;
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                     cout<<G[i][j]<<" ";
                }
                cout<<endl;
            }

         //   for(i=0;i<e;i++);


    return 0;
}
