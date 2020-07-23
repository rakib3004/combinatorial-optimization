#include<bits/stdc++.h>

using namespace std;

int main(){

int  n;

cout<<"Number of  Activities : ";
cin>>n;

int start_time[n];
int finish_time[n];

int i,j;
    cout<<"Enter Your Activities Time Schedules :"<<endl;
    cout<<"Activities No.>> Start Finish"<<endl;
for(i=0;i<n;i++){
   cout<<"Activities_"<<i+1<<" : ";
   cin>>start_time[i]>>finish_time[i];
}
for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){

            if(finish_time[i]>finish_time[j]){
               swap(finish_time[i],finish_time[j]);
               swap(start_time[i],start_time[j]);
            }
    }
}

       cout<<"Selected Job's Are :"<<endl;
         i=0;
        cout<<"Start Time \t Finish Time"<<endl;
        cout<<start_time[i]<<" \t\t "<<finish_time[i]<<endl;
        for(j=1;j<n;j++){
            if(start_time[j]>=finish_time[i]){

        cout<<start_time[j]<<" \t\t "<<finish_time[j]<<endl;

                i=j;

            }
        }

}
