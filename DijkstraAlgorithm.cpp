#include<bits/stdc++.h>
using namespace std;

int graph[100][100];
int distance[100];
int pathHistory[100];

int main()
{
    graph[1][8]=14;
    graph[1][6]=45;
    graph[1][3]=11;
    graph[2][4]=17;
    graph[2][5]=25;
    graph[3][6]=20;
    graph[3][5]=33;
    graph[2][8]=40;
    graph[1][4]=16;
    graph[5][8]=29;
    graph[7][3]=24;
    graph[7][5]=14;
    graph[7][4]=36;



    return 0;

}
/*

Graph 1(Array Methods):



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


    Example 2(Console Methods):

        1 8 14
        1 6 45
        1 3 11
        2 4 17
        2 5 25
        3 6 20
        3 5 33
        2 8 40
        1 4 16
        5 8 29
        7 3 24
        7 5 14
        7 4 36
*/
