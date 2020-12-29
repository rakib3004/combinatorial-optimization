#include<bits/stdc++.h>
using namespace std;

struct Process
{

    int processPriority;
    int burstTime;
    int arrivalTime;
    int index;

    Process()
    {

    }

    Process(int processPriority1,int burstTime1,int arrivalTime1,int index1)
    {

        processPriority = processPriority1;
        burstTime= burstTime1;
        arrivalTime= arrivalTime1;
        index=index1;

    }

};
int totalProcess=6;

bool sortingByProcessArrivalTime(Process process1, Process process2)
{

    return(process1.arrivalTime<process2.arrivalTime);
}


bool sortingByProcessBurstTime(Process process1, Process process2)
{

    return(process1.burstTime<process2.burstTime);
}


bool sortingBasedOnProcessPriority(Process process1, Process process2)
{

    return(process1.processPriority < process2.processPriority);
}





bool sortingByArriving(const pair<int,int> &processVector1,
               const pair<int,int> &processVector2)
{
    return (processVector1.second < processVector2.second);
}




void firstComeFirstServed(Process cpu_Process[])
{
    int iterator=0;

vector< pair <int,int> > processVector;
vector<int> processSerialization;


for(iterator=0;iterator<totalProcess;iterator++){
processVector.push_back(make_pair(cpu_Process[iterator].index,cpu_Process[iterator].arrivalTime));

}

sort(processVector.begin(),processVector.end(),sortingByArriving);

    int processWaitingTime[totalProcess]= {0};
    int processTurnarooundTime[totalProcess]= {0};
    int processExecutionTime=0;



    for(iterator=0; iterator<totalProcess; iterator++)
    {

  if(processVector[iterator].second>=processExecutionTime){
    processWaitingTime[iterator]=0;
    processTurnarooundTime[iterator]= cpu_Process[processVector[iterator].first].burstTime;
    processExecutionTime = processVector[iterator].second+ processTurnarooundTime[iterator];

  }
  else{

    processWaitingTime[iterator] = processExecutionTime-processVector[iterator].second;
    processTurnarooundTime[iterator]= cpu_Process[processVector[iterator].first].burstTime+ processWaitingTime[iterator];

     processTurnarooundTime[iterator]= processTurnarooundTime[iterator]+cpu_Process[processVector[iterator].first].burstTime;

  }

        }
        int summationOfWaitingTime = 0;
        int summationOfTurnOverTime =0;

        cout<<"Process Scheduling Order: "<<endl;

        for(iterator=0;iterator<totalProcess;iterator++){
        cout<<"Process["<<processVector[iterator].first<<"]\t";
        summationOfWaitingTime =summationOfWaitingTime+ processWaitingTime[iterator];
        summationOfTurnOverTime = summationOfTurnOverTime + processTurnarooundTime[iterator];
                }
        double averageWaitingTime =0.0;
        double averageTurnaroundTime = 0.0;

        averageWaitingTime = (double)summationOfWaitingTime/(double)totalProcess;
        averageTurnaroundTime = (double)summationOfTurnOverTime/(double)totalProcess;

        cout<<"Average Waiting Time :"<<averageWaitingTime<<endl;
        cout<<"Average Waiting Time :"<<averageTurnaroundTime <<endl;
        }



void shortestJobFirstPreemptive(Process cpu_Process[])
{

}

void shortestJobFirstNonPreemptive(Process cpu_Process[])
{

}

void roundRobinScheduling(Process cpu_Process[])
{

}

void priorityScheduling(Process cpu_Process[])
{

    int iterator=0;
    for(iterator=0; iterator<totalProcess; iterator++)
    {
        cout<<"Process Priority\tBurst Time\tArrival Time"<<endl;
        cout<<cpu_Process[iterator].processPriority<<"\t\t\t"<<cpu_Process[iterator].burstTime<<"\t\t\t"<<cpu_Process[iterator].arrivalTime<<endl;

    }
}


void processScheduling(Process cpu_Process[],int iterator)
{

    if(iterator==0)
    {

        firstComeFirstServed(cpu_Process);
    }
    else if(iterator==1)
    {

        shortestJobFirstPreemptive(cpu_Process);
    }

    else if(iterator==2)
    {

        shortestJobFirstNonPreemptive(cpu_Process);
    }
    else if(iterator==3)
    {

        roundRobinScheduling(cpu_Process);
    }
    else if(iterator==4)
    {

        priorityScheduling(cpu_Process);
    }
}
int main()
{


    Process cpu_Process[6];


// Add Process Priority
    cpu_Process[0].processPriority=8;
    cpu_Process[1].processPriority=3;
    cpu_Process[2].processPriority=4;
    cpu_Process[3].processPriority=4;
    cpu_Process[4].processPriority=5;
    cpu_Process[5].processPriority=5;


// Add Process burst time
    cpu_Process[0].burstTime=15;
    cpu_Process[1].burstTime=20;
    cpu_Process[2].burstTime=20;
    cpu_Process[3].burstTime=20;
    cpu_Process[4].burstTime=5;
    cpu_Process[5].burstTime=15;


// Add Process arrival time
    cpu_Process[0].arrivalTime=0;
    cpu_Process[1].arrivalTime=0;
    cpu_Process[2].arrivalTime=20;
    cpu_Process[3].arrivalTime=25;
    cpu_Process[4].arrivalTime=45;
    cpu_Process[5].arrivalTime=55;

// Add Process index
    cpu_Process[0].index=1;
    cpu_Process[1].index=2;
    cpu_Process[2].index=3;
    cpu_Process[3].index=4;
    cpu_Process[4].index=5;
    cpu_Process[5].index=6;


    int iterator=0;

    int numberOfMethods=5;

    for(iterator=0; iterator<numberOfMethods; iterator++)
    {


        cout<<"Methods No "<<iterator+1<<": "<<endl;
        processScheduling(cpu_Process,iterator);
        cout<<endl<<endl;

    }

    cout<<"\t"<<"The End"<<endl;
    cout<<"-------------------------"<<endl;

}
