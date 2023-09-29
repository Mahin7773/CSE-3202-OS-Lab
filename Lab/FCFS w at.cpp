#include <bits/stdc++.h>
using namespace std;

class Process{
public:
    int id, bt, at, ct, tat, wt;

    void input(Process*, int);
    void calc(Process*, int);
    void show(Process*, int);
    void fsort(Process*, int);
};

int main(){
    int n; // no. of process
    cin >>n;
    Process *p = new Process[n];
    Process f;
    f.input(p,n);
    f.fsort(p,n);
    f.calc(p,n);
    f.show(p,n);

}

bool compare(Process a, Process b){
    return a.at<b.at;
}

void Process::fsort(Process*p, int n){
    sort(p, p+n, compare);
}

void Process::input(Process *p, int n){
    for(int i=0; i<n; i++){
        cout<<"Arrival time for process "<<i+1<<": "<<endl;
        cin>> p[i].at;
        cout<<"Burst time for process "<<i+1<<": "<<endl;
        cin>> p[i].bt;

        p[i].id = i+1;
    }
}



void Process::calc(Process *p, int n){
    int sum =0;
    sum = p[0].at; //
    for(int i = 0; i<n;i++){
        sum = sum + p[i].bt;
        p[i].ct = sum;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        if(sum<p[i+1].at){
            int t = p[i+1].at - sum;
            sum = sum+t;
        }
    }

}

void Process::show(Process *p, int n){
    cout<<"Process Arrival Burst Waiting Turn Around Completion\n";
    for(int i =0;i<n;i++){
        cout<<"  P["<<p[i].id<<"]\t  "<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].wt<<"\t   "<<p[i].tat<<"\t\t"<<p[i].ct<<"\n";
    }
}