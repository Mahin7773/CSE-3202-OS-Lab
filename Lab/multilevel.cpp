#include<bits/stdc++.h>
using namespace std;

int main(){
    int temp, total_wt=0, total_tat = 0;
    int p[] = { };
    int su[] = { };
    int bt[] = { };
    int n = sizeof(p)/sizeof(p[0]);
    int wt[n], tat[n];
    for(int i=0; i<n;i++){
        for(int j= i+1; j<n;j++){
            if(su[i]>su[j]){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = su[i];
                su[i] =  su[j];
                su[j] = temp;

            }
        }
    }
    wt[0] = 0;
    tat[0] = bt[0];
    for(int i=1; i<n; i++){
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }

    cout <<"Process  S/U process  Burst  Waiting  TAT"<<endl;
    for(int i=0; i<n; i++){
        cout << p[i] << "  "<< su[i] << "  "<< bt[i] << "  "<< wt[i] << "  "<<endl;
    }

    cout<<"Avg wt: "<< (float)total_wt/(float)n<<endl;
    cout<<"Avg tat: "<< (float)total_tat/(float)n<<endl;
}