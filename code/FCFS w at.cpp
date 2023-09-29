#include <bits/stdc++.h>
using namespace std;

class Process{
    public:
    int id, bt, at, ct, tat, wt;

    void input(Process*, int);
    void calc(Process*, int);
    void show(Process*, int);
    void sort(Process*, int);
};
bool sort1(Process a,Process b){
    return a.at<b.at;
}
int main(){
    int n; // no. of process
    cin >>n;
    Process *p = new Process[n];
    Process f;
    f.input(p,n);
    f.sort(p, n);
    f.calc(p,n);
    f.show(p,n);

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

    }

}