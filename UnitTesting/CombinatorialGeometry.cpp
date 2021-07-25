#include<bits/stdc++.h>
using namespace std;
int x[100],y[100];

bool onSegment(int i, int j, int k){
int x1 = min(x[i],x[j]);
int x3 = max(x[i],x[j]);
int y1 = min(y[i],y[j]);
int y3 = max(y[i],y[j]);
if((x1<=x[k]<=x3)&&(y1<=y[k]<=y3)){
return true;
}
else{
return false;
}

}
int matrix(int i, int j, int k){

int x1,x2,y1,y2;

x1 = x[k]-x[i];
x2 = x[j]-x[i];
y1 = y[k]-y[i];
y2 = y[j]-y[i];
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


d1 = matrix(3,4,1);
d2 = matrix(3,4,2);
d3 = matrix(1,2,3);
d4 = matrix(1,2,4);

        int p1 = d1*d2;
        int p2 = d3*d4;
        if(((d1>0 and d2< 0) or (d1<0 and d2>0)) and ((d3>0 and d4<0) or (d3<0 and d4>0))){

        cout<<"Lines are intersect"<<endl;
        }
        else if(d1==0&&onSegment(3,4,1)){
        cout<<"Lines are intersect"<<endl;
        }
         else if(d2==0&&onSegment(3,4,2)){
        cout<<"Lines are intersect"<<endl;
        }
         else if(d3==0&&onSegment(1,2,3)){
        cout<<"Lines are intersect"<<endl;
        }
         else if(d4==0&&onSegment(1,2,4)){
        cout<<"Lines are intersect"<<endl;
        }

        else{

        cout<<"Lines are not intersect"<<endl;
        }


return 0;
}
