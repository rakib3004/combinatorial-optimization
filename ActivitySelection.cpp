#include<bits/stdc++.h>
using namespace std;

void printMaxActivities(int s_array[],int f_array[],int n){
int i,j;

i=0;

cout<<i;

for(j=1;j<n;j++){
    if(s_array[j]>=f_array[i]){
        cout<<j<<" ";
        i=j;
    }

    }
}


int main(){

int s_array[] = {1,3,0,5,8,5};
int f_array[]={2,4,6,7,9,9};
int n = sizeof(s_array)/sizeof(s_array[0]);
printMaxActivities(s_array,f_array,n);
return 0;
}
