#include<bits/stdc++.h>
using namespace std;
int main(){
int number;
cout<<"Enter How Many Coins You Have : ";
cin>>number;
int n = number;

int array[n];
int iterator;
cout<<endl<<"Enter all the coins Value : "<<endl;
for(iterator=0;iterator<n;iterator++){
    cout<<"Coin_"<<iterator+1<<" : ";
    cin>>array[iterator];
}
   //  sort(array,array+number);

        int count=0;
        int vector;
int money;
cout<<"Enter How Much Dollars You Exchange : ";
cin>>money;
int money1 = money;

  for(iterator=n-1;iterator>=0;iterator--){
vector = (money/array[iterator]);
    count = count+ vector;
        cout<<"Coins_"<<iterator+1<<" : "<<count<<endl;

    money = money-(vector*array[iterator]);

  }

  cout<<"You need "<<count<<" Coins to Exchange "<<money1<<" Dollar"<<endl;
}
