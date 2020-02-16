#include<bits/stdc++.h>
using namespace std;

void printMaxActivities(int StartingTimeArray[],int FinishingTImeArray[],int n){
int i,j;

i=0;

cout<<i;

for(j=1;j<n;j++){
    if(StartingTimeArray[j]>=FinishingTImeArray[i]){
        cout<<j<<" ";
        i=j;
    }

    }
}


int main(){

int StartingTimeArray[] = {1,3,0,5,8,5};
int FinishingTImeArray[]={2,4,6,7,9,9};
int n = sizeof(StartingTimeArray)/sizeof(StartingTimeArray[0]);
printMaxActivities(StartingTimeArray,FinishingTImeArray,n);
return 0;
}
