
#include<bits/stdc++.h>
using namespace std;

int graph[100][100];
int cost[100];
int previous[100];
int visit[100];

int totalComponent=0;

struct graphValue
{

    int x;
    int y;
    int cost;
    int point;

} graphComponent[100];


void sorting()
{
    int i=0,j=0;
    graphValue temporaryGraph;
    for(i=1; i<=totalComponent; i++)
    {

        for(j=i+1; j<=totalComponent; j++)
        {

            if(graphComponent[j].cost<graphComponent[i].cost)
            {
                temporaryGraph=graphComponent[j];
                graphComponent[j]=graphComponent[i];
                graphComponent[i]=temporaryGraph;
            }
        }
    }
}


int main()
{

    graph[1][6]=54;
    graph[1][3]=47;
    graph[1][5]=80;
    graph[2][3]=55;
    graph[2][4]=31;
    graph[2][5]=32;
    graph[2][7]=74;
    graph[2][8]=79;
    graph[3][4]=88;
    graph[3][5]=23;
    graph[3][6]=75;
    graph[3][7]=66;
    graph[4][6]=74;
    graph[4][8]=29;
    graph[5][7]=93;
    graph[7][8]=68;

    int n=8;


    int i,j;
    int k=1;
    for(i=1; i<=8; i++)
    {

        for(j=1; j<=8; j++)
        {

            if(graph[i][j])
            {
                graphComponent[k].x=i;
                graphComponent[k].y=j;
                graphComponent[k].cost=graph[i][j];
                graphComponent[k].point=i;
                k++;
            }
        }
    }


    totalComponent=k-1;
    sorting();
int MinimumSpanningTree=0;

    for(i=1;i<=totalComponent; i++)
    {
        int  a= graphComponent[i].x;
        int  b=graphComponent[i].y;
        if(graphComponent[a].point!=graphComponent[b].point)
        {
              graphComponent[b].point  =graphComponent[a].point;
              MinimumSpanningTree+=graphComponent[i].cost;
        }
    }



    cout<<"Total Cost : "<<MinimumSpanningTree<<endl;

    return 0;
}
