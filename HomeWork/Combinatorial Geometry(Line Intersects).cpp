
#include<bits/stdc++.h>
using namespace std;
int x[100],y[100];
int matrix(int i, int j, int k ,int l){

int x1,x2,y1,y2;

x1 = x[i]-x[j];
x2 = x[k]-x[l];
y1 = y[i]-y[j];
y2 = y[k]-y[l];
return (x1*y2 - x2*y1);

}
int main(){

int n;
cin>>n;

int i;

for(i=1;i<=n;i++){
    cin>>x[i]>>y[i];
}
int d1,d2,d3,d4;


d1 = matrix(1,4,3,4);
d2 = matrix(2,4,3,4);
d3 = matrix(3,2,1,2);
d4 = matrix(4,2,1,2);

        int p1 = d1*d2;
        int p2 = d3*d4;
        if(p1<0&&p2<0){

        cout<<"Lines are intersect"<<endl;
        }
        else if(p1==0||p2==0){
        cout<<"Lines are intersect"<<endl;

        }
        else{

        cout<<"Lines are not intersect"<<endl;
        }


return 0;
}
