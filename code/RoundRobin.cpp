#include<bits/stdc++.h>
using namespace std;

void FindWaitingTime(int process[], int n, int bt[], int wt[], int quantum){
    int rem_bt[n]; // Make a copy of burst times bt[] to store remaining burst times

    for(int i=0; i<n; i++){
        rem_bt[i] = bt[i];
    }
    int t=0;
    while(1){
        bool done = true;

        for(int i=0; i<n;i++){
            if(rem_bt[i]>0){
                done =false;
                if(rem_bt[i] > quantum){
                    t+=quantum;
                    rem_bt[i] -= quantum;
                }
                else{
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if(done == true)
            break;
    }
}

void FindTatTime(int process[], int n, int bt[], int wt[], int tat[]){
    for(int i=0; i<n; i++){
        tat[i] = bt[i] + wt[i];
    }
}   

void FindAvgTime(int process[], int n, int bt[], int quantum){
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    FindWaitingTime(process, n , bt, wt, quantum);
    FindTatTime(process, n, bt, wt, tat);

    cout << "Pid  "<<" BT  "<< "WT  "<<"TAT\n";
    for (int i=0; i<n;i++){
        total_wt+= wt[i];
        total_tat+= tat[i];
        cout<<process[i]<<"  "<<bt[i]<<"  "<<wt[i]<<"  "<<tat[i]<<endl;
    }

    cout<<"Avg wt: "<<(float)total_wt/(float)n<<endl;
    cout<<"Avg tat: "<<(float)total_tat/(float)n<<endl;
}

int main(){
    int process[] = {1,2,3};
    int bt[] = {10, 5, 8};
    int n = sizeof(process)/ sizeof(process[0]);
    int quantum = 2;
    FindAvgTime(process,n,bt,quantum); 
}