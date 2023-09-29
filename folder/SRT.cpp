#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <pthread.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<long long,long long>
using namespace std;
using namespace __gnu_pbds;
const int MOD= 1e9+7;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
//template< class InputIt, class Distance >
//struct custom_hash {
//    static int splitmix64(int x) {
//        x += 0x9e3779b97f4a7c15;
//        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//        return x ^ (x >> 31);
//    }
//
//    int operator()(int x) const {
//        static const int FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//        return splitmix64(x + FIXED_RANDOM);
//    }
//};
class process{
public:
    int arrival;
    int burst;
    int complition{};
    int turn_out_time{};
    int waiting_time{};
    bool done=false;
    process(int a,int b){
        arrival=a;
        burst=b;
    }
};
bool sort_by_arrival_burst(process a,process b){
    if(a.arrival==b.arrival){
        return a.burst<b.burst;
    }
    return  a.arrival<b.arrival;
}
int main() {
    vector<process> processes;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp1;
        int temp2;
        cin>>temp1>>temp2;
        process z= process(temp1,temp2);
        processes.push_back(z);
    }
    for(int i=0;i<n;i++){
        cout<<processes[i].arrival<<" "<<processes[i].burst<<endl;
    }
    int burst2[n];
    for(int i=0;i<n;i++){
        burst2[i]=processes[i].burst;
    }
    int count=0;
    int t=0;
    int low=INT_MAX;
    int pro;
    bool z=false;
    int end;
    while(count!=n){
        for(int i=0;i<n;i++){
            if(processes[i].arrival<=t && processes[i].burst<low && burst2[i]>0){
                low=burst2[i];
                pro=i;
                z=true;
            }
        }
        if(!z){
            t++;
            continue;
        }
        low--;
        burst2[pro]--;
        if(low==0){
            low=INT_MAX;
        }
        if(burst2[pro]==0){
            count++;
            end=t+1;
            processes[pro].done= true;
            processes[pro].complition=t+1;
            processes[pro].turn_out_time=end-processes[pro].arrival;
            processes[pro].waiting_time=processes[pro].turn_out_time-processes[pro].burst;
            z=false;
        }
        t++;
    }

    for(int i=0;i<n;i++){
        cout<<i<<"  "<<processes[i].arrival<<"  "<<processes[i].burst<<"  "<<processes[i].complition<<"  "<<
            processes[i].turn_out_time<<"  "<<processes[i].waiting_time<<endl;
    }

}