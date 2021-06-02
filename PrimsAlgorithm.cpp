#include<bits/stdc++.h>
using namespace std;

int graph[100][100];
int cost[100];
int previous[100];
int visit[100];


void initialization(int source){


int i;

for(i=1;i<=8;i++){
    cost[i]=100000000;
    visit[i]=0;
    previous[i]=-1;
}
cost[source]=0;

}


int findOutMinimumCostVertexIndex(){

    int min=10000;
        int nodeIndex;
    for(int i=1;i<=8;i++){
        if(visit[i]==0&&cost[i]<min){
            min=cost[i];
            nodeIndex=i;

        }
    }

    return nodeIndex;
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

int i=0,j=0;


initialization(1);

while(1){


i=findOutMinimumCostVertexIndex();
visit[i]=1;

cout<<i<<" is covered"<<endl;
for(j=1;j<=8;j++){
    if(graph[i][j]>0&&visit[j]==0){


    if(graph[i][j]<cost[i]){
        cost[i]=graph[i][j];
        previous[j]=i;
    }

    }
}

int i1;

for(i1=1;i1<=8;i1++){
    if(visit[i1]==0){
        break;
        //again run the whole primes algorithm
    }

}

if(i1==9){
        break;
    }



}

int MinimumSpanningTree=0;

cout<<"Minimum Spanning Tree: "<<endl;
for(i=1;i<=8;i++){
MinimumSpanningTree+=cost[i];
if(i==8){
    cout<<cost<<" = ";
}
else{
        cout<<cost<<" + ";

}
}

cout<<MinimumSpanningTree<<endl;

    return 0;

}
