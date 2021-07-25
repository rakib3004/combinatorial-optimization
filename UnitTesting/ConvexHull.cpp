#include<bits/stdc++.h>
using namespace std;
int x[100],y[100];
bool act[100];

int main(){

int n;
cin>>n;
int Y;
int i;
int minY=15456456465;
for(i=1;i<=n;i++){
    cin>>x[i]>>y[i];
    act[i]=true;
    if(y[i]<minY){
    minY = y[i];
    Y=i;
    }else if(y[i]==minY){
    if(x[i]<x[Y]){
    minY = y[i];
    Y=i;
    }
    }

}
act[Y]=false;
int temp=0;
temp  =x[0];
x[0]=x[Y];
x[Y]=temp;

temp  =y[0];
y[0]=y[Y];
y[Y]=temp;

sort(x[1],x[n]);
sort(y[1],y[n]);
stack<int>aStack;

aStack.push(x[1]);
aStack.push(x[2]);
aStack.push(x[3]);


for(i=4;i<=n;i++){
if(x[i+1]<x[i-1]){
aStack.push(x[i]);

}
}

return 0;
}
