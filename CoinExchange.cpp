#include<bits/stdc++.h>
using namespace std;


int Count(int array[],int m,int n){

if(n==0){
    return 0;
}
if(n<0){
    return 0;
}
if(m<=0&&n>=1){
return 0;
}
return Count(array,m-1,n)+ Count(array,m,n-array[m-1]);

}
int main(){

int i,j;

int array[] = {1,2,3};
int n = sizeof(array)/sizeof(array[0]);

cout<<Count(array,n,4);
return 0;
}
