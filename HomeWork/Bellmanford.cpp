#include<bits/stdc++.h>
using namespace std;
#define INF 100000
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
    }
    d[0]=0;

    cout<<"From-->To-->Cost"<<endl;
    for(i=0; i<e; i++)
    {
        cin>>p>>q>>w;
        cost[p][q] = w;

    }
    for(i=1; i<n; i++)
    {
        d[i]=cost[0][i];
    }

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
                    }
                }
            }
        }
    }
    cout<<"From-->To-->minimum cost"<<endl;

    for(i=0; i<n; i++)
    {
        if(d[i]!=INF)
        {
            cout<<0<<"--->"<<i<<"===>"<<d[i]<<endl;
        }
    }

}
/*6---->6
0 2 2
0 3 4
3 4 7
2 3 1
3 5 5
1 2 10
*/
