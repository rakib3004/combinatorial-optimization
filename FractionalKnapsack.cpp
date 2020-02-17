#include<bits/stdc++.h>
using namespace std;

int main()
{

    int number ;
    cout<<"How Many Product You Have :";
    cin>>number;

    int n=number;

    int weight[n];
    int value[n];
    double ratio[n];
    int i,j;

    double total_weight;
    cout<<"Total Weight You Have : ";
    cin>>total_weight;

    cout<<"Enter Every Product Value & Weight : ";
    cout<<"Product No: V_W_"
        for(i=0; i<n; i++)
    {

        cout<<"Product_"<<i+1<<" : ";
        cin>>value[i]>>weight[i];
        ratio[i] = (double)(value[i]/weight[i]);
    }


for(i=0;i,n;i++){
    for(j=i+1;j<n;j++){
        if(ratio[i]<ratio[j]){
            swap(ratio[i],ratio[j]);
            swap(value[i],value[j]);
            swap(weight[i],weight[j]);
        }
    }
}
double current_weight=0.0;
double final_value=0.0;
for(i=0;i<n;i++){
    if((current_weight+weight[i]<=total_weight)){
        current
    }
}
    return 0;
}

