#include<bits/stdc++.h>
using namespace std;

struct Process{
    int pid;
    int art;
    int bt;
    
    int pr;
};

bool cmp(Process a, Process b){
    if(a.art == b.art){
        return a.pr < b.pr;
    }
    else 
        return a.art < b.art;
}

void FindWaitingTime(Process proc[], int n, int wt[]){
    int service[n]; // declaring service array that stores cumulative burst time
    service[0] = proc[0].art;
    wt[0] = 0;

    for (int i=1; i <n; i++){
        service[i] = proc[i-1].bt + service[i-1];
        wt[i] = service[i] - proc[i].art;

        if(wt[i] < 0)
            wt[i] = 0;
    }

}

void FindTatTime(Process proc[], int n, int wt[], int tat[]){
    for(int i=0; i<n; i++){
        tat[i] = proc[i].bt + wt[i];
    }
}

void FindGc(Process proc[], int n){
    int wt[n], tat[n];
    double total_wt = 0, total_tat = 0;
    FindWaitingTime(proc,n,wt);
    FindTatTime(proc,n,wt,tat);

    int stime[n], ctime[n];
    stime[0] = proc[0].art;
    ctime[0] = stime[0] + tat[0];

    for(int i =1; i<n; i++){
        stime[i] = ctime[i-1];
        ctime[i] = stime[i] + tat[i] - wt[i];
    }

    cout<<"Process Start_time Complete_time TAT Waiting_Time"<<endl;

    for(int i=0; i<n; i++){
        total_wt = total_wt+wt[i];
        total_tat = total_tat+tat[i];
        cout << proc[i].pid << "  "<<stime[i]<<"  "<<ctime[i]<<"  "<< tat[i]<<"  "<<wt[i]<<endl;
    }
    cout<<"Average waiting time is : ";
    cout<<total_wt/(float)n<<endl;
    cout<<"average turnaround time : ";
    cout<<total_tat/(float)n<<endl;
}

int main(){
    Process proc[] = {
        {1,0,4,1}, {2,0,3,2}, {3,6,7,1}, {4,11,4,3}, {5,12,2,2} //id, arrt, bt, prio
    };
    int n = sizeof(proc) / sizeof(proc[0]);

    sort(proc, proc+n, cmp);
    FindGc(proc, n);
}
