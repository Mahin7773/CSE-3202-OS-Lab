#include <iostream>
using namespace std;

void findWaitingTime( int process[], int n, int bt[], int wt[]){
    wt[0] = 0;
    for(int i=1; i<n; i++){
        wt[i] = bt[i-1] + wt[i-1];
    }
}

void findTurnAroundTime(int process[], int n, int bt[], int wt[], int tat[]){
    for(int i =0; i<n; i++){
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int process[], int n, int bt[]){
    int wt[n], tat[n], total_wt= 0, total_tat = 0;
    findWaitingTime(process, n, bt, wt);
    findTurnAroundTime(process, n, bt, wt, tat);
    cout << "Process  "<<"Burst time   "<<"Waiting   "<< "Tat\n";

    for(int i=0; i<n; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " "<< i+1 <<"  "<< bt[i]<<"  "<<wt[i]<< "  "<<tat[i]<<endl; 
    } 

    cout << "Avg waiting time: "<< (float)total_wt/(float)n <<endl;
    cout << "Avg TAT: " << (float)total_tat/(float)n <<endl;

}

int main(){
    int process[] = {1, 2, 3};
    int n = sizeof(process)/sizeof(process[0]);

    int burst_time[] = {10, 5, 8};
    findAverageTime(process, n, burst_time);
}