#include<bits/stdc++.h>
using namespace std;

struct Process {

int processPriority;
int burstTime;
int arrivalTime;
};
Process cpu_Process[7];
double averageTurnaroundTime=0.0;
double averageWaitingTime=0.0;

void firstComeFirstServed(){
int iterator=0;
for(iterator=1;iterator<=6;iterator++){


    cout<<"Process Priority\tBurst Time\tArrival Time"<<endl;
    cout<<cpu_Process[iterator].processPriority<<"\t\t\t"<<cpu_Process[iterator].burstTime<<"\t\t\t"<<cpu_Process[iterator].arrivalTime<<endl;

}
}

void shortestJobFirstPreemptive(){
int iterator=0;
for(iterator=1;iterator<=6;iterator++){


    cout<<"Process Priority\tBurst Time\tArrival Time"<<endl;
    cout<<cpu_Process[iterator].processPriority<<"\t\t\t"<<cpu_Process[iterator].burstTime<<"\t\t\t"<<cpu_Process[iterator].arrivalTime<<endl;

}
}

void shortestJobFirstNonPreemptive(){
int iterator=0;
for(iterator=1;iterator<=6;iterator++){


    cout<<"Process Priority\tBurst Time\tArrival Time"<<endl;
    cout<<cpu_Process[iterator].processPriority<<"\t\t\t"<<cpu_Process[iterator].burstTime<<"\t\t\t"<<cpu_Process[iterator].arrivalTime<<endl;

}
}

void roundRobinScheduling(){
int iterator=0;
for(iterator=1;iterator<=6;iterator++){


    cout<<"Process Priority\tBurst Time\tArrival Time"<<endl;
    cout<<cpu_Process[iterator].processPriority<<"\t\t\t"<<cpu_Process[iterator].burstTime<<"\t\t\t"<<cpu_Process[iterator].arrivalTime<<endl;

}
}

void priorityScheduling(){

int iterator=0;
for(iterator=1;iterator<=6;iterator++){


    cout<<"Process Priority\tBurst Time\tArrival Time"<<endl;
    cout<<cpu_Process[iterator].processPriority<<"\t\t\t"<<cpu_Process[iterator].burstTime<<"\t\t\t"<<cpu_Process[iterator].arrivalTime<<endl;

}
}


void processScheduling(int iterator){

if(iterator==0){

    firstComeFirstServed();
}
else if(iterator==1){

    shortestJobFirstPreemptive();
}

else if(iterator==2){

    shortestJobFirstNonPreemptive();
}
else if(iterator==3){

    roundRobinScheduling();
}
else if(iterator==4){

    priorityScheduling();
}
}
int main(){



cpu_Process[0].processPriority=0;
cpu_Process[0].burstTime=0;
cpu_Process[0].arrivalTime=0;

// Add Process Priority
cpu_Process[1].processPriority=8;
cpu_Process[2].processPriority=3;
cpu_Process[2].processPriority=4;
cpu_Process[4].processPriority=4;
cpu_Process[5].processPriority=5;
cpu_Process[6].processPriority=5;


// Add Process burst time
cpu_Process[1].burstTime=15;
cpu_Process[2].burstTime=20;
cpu_Process[2].burstTime=20;
cpu_Process[4].burstTime=20;
cpu_Process[5].burstTime=5;
cpu_Process[6].burstTime=15;


// Add Process arrival time
cpu_Process[1].arrivalTime=0;
cpu_Process[2].arrivalTime=0;
cpu_Process[2].arrivalTime=20;
cpu_Process[4].arrivalTime=25;
cpu_Process[5].arrivalTime=45;
cpu_Process[6].arrivalTime=55;

int iterator=0;

int numberOfMethods=5;

for(iterator=0;iterator<numberOfMethods;iterator++){


    cout<<"Methods No "<<iterator<<": "<<endl;
    processScheduling(iterator);
    cout<<endl<<endl;

}

cout<<"\t"<<"The End"<<endl;
cout<<"-------------------------"<<endl;

}
