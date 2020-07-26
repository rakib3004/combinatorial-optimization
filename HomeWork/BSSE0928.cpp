#include<bits/stdc++.h>
using namespace std;
#define INF 100000
int previousNode[100];
int pathCost[100][100],distance[100];

void print_path(int a, int b)
{
    if(a==b){
        cout<<a<<"-->";
        return;
    }
    else if(a==INF){
        return;
    }
    else{
        print_path(path[a],b);
        cout<<a<<"-->";
    }

}
int main()
{

    int n,e;
    cout<<"Number of node  : ";
    cin>>n;

    cout<<"Number of edges : ";
    cin>>e;
    int u,v;


    int k;
    int p,q,w;
    for(u=0; u<n; u++)
    {
        for(v=0; v<n; v++)
        {
            pathCost[u][v]=INF;
        }
        distance[u]=INF;
        path[u]=INF;
    }
    path[0]=0;
    distance[0]=0;

    cout<<"From-->To-->Cost"<<endl;
    for(u=0; u<e; u++)
    {
        cin>>p>>q>>w;
        pathCost[p][q] = w;

    }
//    for(i=1; i<n; i++)
//    {
//        d[i]=cost[0][i];
//    }

    for(k=0; k<n-1; k++)
    {
        for(u=0; u<n; u++)
        {
            for(v=0; v<n; v++)
            {
                if(pathCost[u][v]!=INF)
                {
                    if(distance[v]>pathCost[u][v]+distance[u])
                    {
                        distance[v] = pathCost[u][v]+distance[u];
                        path[v]=u;
                    }
                }
            }
        }
    }

    bool isNegativePath =false;
    for(u=0;u<n;u++){
        for(v=0;v<n;v++){
            if(distance[v]>distance[u]+pathCost[u][v]){
                isNegativePath = true;
                print_path(path[u],u);
                cout<<u<<endl;
                cout<<endl;

            }
        }
    }

    if(isNegativePath==false){
        cout<<"There is no negative path exits"<<endl;

    }

    return 0;
}

