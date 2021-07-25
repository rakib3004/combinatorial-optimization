#include<bits/stdc++.h>
using namespace std;
#define INF 100000
int path[100];
void print_path(int i, int j){

if(i==j){
cout<<i<<"-->";
return;
}
else if(i==INF){
return;
}
else{
print_path(path[i],j);
cout<<i<<"-->";
}

}
int main()
{

    int n,e;
    cout<<"Number of nodes : ";
    cin>>n;
    int cost[n][n],d[n];

    cout<<"Number of edges : ";
    cin>>e;
int i,j;
    int k;
    int p,q,w;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cost[i][j]=INF;
        }
        d[i]=INF;
        path[i]=INF;
    }
    path[0]=0;
    d[0]=0;

    cout<<"From-->To-->Cost"<<endl;
    for(i=0; i<e; i++)
    {
        cin>>p>>q>>w;
        cost[p][q] = w;

    }
//    for(i=1; i<n; i++)
//    {
//        d[i]=cost[0][i];
//    }

    for(k=0; k<n-1; k++)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(cost[i][j]!=INF)
                {
                    if(d[j]>cost[i][j]+d[i])
                    {
                        d[j] = cost[i][j]+d[i];
                        path[j]=i;
                    }
                }
            }
        }
    }

bool isNegativePath =false;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(d[j]>d[i]+cost[i][j]){
isNegativePath = true;
print_path(path[i],i);
cout<<i<<endl;
cout<<endl;

}
}
}

if(isNegativePath==false){
cout<<"There is no negative path exits"<<endl;

}

 return 0;
}
    /*

    8 13
    0 1 4
    0 2 4
    0 3 3
    5 1 3
    2 5 -2
    3 2 2
    4 3 1
    2 4 4
    5 4 -3
    6 5 2
    4 6 -2
    6 7 2
    7 4 2

*/
