#include<bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2


int G[10][10],flow[10][10],capacity[10][10],color[10],prev[10];
int n, e, s, t, sinkInput, totalFlow=0;

int findPathCapacity(int s, int t)
{
    int value=INT_MAX;
    while(prev[t]!=-1)
    {
        if(value>capacity[prev[t]][t]){
            value = capacity[prev[t]][t];
        }
        t = prev[t];
    }
    return value;
}

int BFS(int s, int t, int n)
{
    bool isTrue= false;
    for(int i=0;i<n;i++)
    {
        color[i]=WHITE;
        prev[i]=-1;
    }

    color[s]=GREY;
    queue<int> queue1;
    queue1.push(s);
    while(!queue1.empty())
    {
        int u=queue1.front();
        color[u]=GREY;
        queue1.pop();
        for(int v=0;v<n;v++)
        {
            if(color[v]==WHITE && capacity[u][v]-flow[u][v]>0)
            {
                color[v]=GREY;
                queue1.push(v);
                prev[v]=u;

                if(v==t) {
                    isTrue= true;
                }

            }
        }
        color[u]=BLACK;
    }
      return isTrue;
}


void input(){

    cout<<"Number of Nodes : ";
    cin>>n;
    cout<<"Number of edges : ";
    cin>>e;
    cout<< "From-->To-->Capacity : "<<endl;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>> u>>v>>w;
        capacity[u][v]=w;
    }

}

int main()
{
 input();
    cout<<"Source Point :";
    cin>>s;
    cout<<"Sink Point : ";
    cin>>sinkInput;

    while(BFS(s, sinkInput, n))
    {
        t= sinkInput;
        int residualCapacity = findPathCapacity(s, t);
        totalFlow += residualCapacity;
        while(prev[t]!=-1)
        {
            flow[prev[t]][t] += residualCapacity;
            flow[t][prev[t]] -= residualCapacity;
            t= prev[t];
        }
    }
    cout << "Maximum flow is : "<< totalFlow <<endl;
}
