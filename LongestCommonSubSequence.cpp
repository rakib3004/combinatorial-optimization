#include<bits/stdc++.h>
using namespace std;


int main()
{

    string x;
    string y;
    cin>>x>>y;

    int n = x.size();
    int m = y.size();

    int i,j;

    int c[n][m]= {0};

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(i==0||j==0)
            {
                c[i][j]=0;
            }
            else if(x[i]==y[j])
            {
                c[i][j]= c[i-1][j-1]+1;
            }
            else
            {
                c[i][j]=  max(c[i][j-1],c[i-1][j]);
            }
        }

    }

    cout<<c[n-1][m-1]<<endl;
    return 0;
}
