#include<bits/stdc++.h>
using namespace std;

struct Item{

int value,weight;

Item(int value, int weight) : value(value) ,weight(weight)
{

}
};

bool cmp(struct Item a , struct Item b){
double r1 = (double)a.value/a.weight;
double r2 = (double)b.value/b.weight;
return r1>r2;

}


double fractionalKnapsack(int W,struct Item array[],int n){

sort(array,array+n,cmp);
int curWeight = 0;
double finalvalue = 0.0;

for(int i=0;i<n;i++){

    if(curWeight + array[i].weight<=W){

        curWeight  =curWeight + array[i].weight;
        finalvalue =finalvalue + array[i].value;
    }
    else{

        int remain = W- curWeight;
            finalvalue += array[i].value * ((double) remain / array[i].weight);
        break;
    }
}
    return finalvalue;
}
int main(){

int W =50;

Item array[] = {{60,10},{100,20},{120,30}};

int n = sizeof(array)/sizeof(array[0]);

cout<<"Maximum value we can obtain "<<fractionalKnapsack(W,array,n);

return 0;


return 0;
}
