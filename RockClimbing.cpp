#include<bits/stdc++.h>
using namespace std;


int main()
{


    int m,n;

cin>>n>>m;
//
//    n = rand()%15+5;
//    m = rand()%15+4;


    int a[n+1][m+2]= {0};

    int c[n+1][m+1]= {0};

    int i,j;
    int infinity=65654;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            c[i][j]=rand()%(20+i+j)+(5);

            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m+1; j++)
        {

        if(j==0||j==m+1){
            a[i][j]=infinity;
        }
        else if(i==0){
            a[i][j]=0;
        }


        }
    }


    for(i=1;i<=n;i++){

        for(j=1;j<=m;j++){

         //   A(i,j) = C(i,j)+min{A(i-1,j-1),A(i-1,j),A(i-1,j+1)}
            int middleMin = min(a[i-1][j-1],a[i-1][j]);

            a[i][j]=c[i][j] + min(middleMin,a[i-1][j+1]);
        }

    }
    int minimumCost=455445;
    for(i=1;i<=m;i++){
            minimumCost=min(minimumCost,a[n][i]);
    }

    cout<<"The minimum cost is: "<<minimumCost<<endl;

    return 0;

}
