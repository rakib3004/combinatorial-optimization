#include<bits/stdc++.h>
using namespace std;
int x[100],y[100];
bool boolArray[100];

int main(){

int n;
cin>>n;
int y2;
int i;
int minimumValue=1000000;
for(i=1;i<=n;i++){
    cin>>x[i]>>y[i];
    boolArray[i]=true;
    if(y[i]<minimumValue){
    minimumValue = y[i];
    y2=i;
    }else if(y[i]==minimumValue){
    if(x[i]<x[y2]){
    minimumValue = y[i];
    y2=i;
    }
    }

}
boolArray[y2]=false;
int temp=0;
temp  =x[0];
x[0]=x[y2];
x[y2]=temp;

temp  =y[0];
y[0]=y[y2];
y[y2]=temp;

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
