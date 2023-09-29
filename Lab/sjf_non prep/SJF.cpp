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
    sort(processes.begin(),processes.end(), sort_by_arrival_burst);
    for(int i=0;i<n;i++){
        cout<<processes[i].arrival<<" "<<processes[i].burst<<endl;
    }
    processes[0].complition=processes[0].arrival+processes[0].burst;
    processes[0].turn_out_time=processes[0].complition-processes[0].arrival;
    processes[0].done= true;
    processes[0].waiting_time=processes[0].turn_out_time-processes[0].burst;
    int com_low=processes[0].complition;
    int count=1;
    while(count<n) {
        if (processes[count].done) {
            count++;
            continue;
        } else {
            if (processes[count].arrival >= com_low) {
                com_low = processes[count].arrival;
            }
            int burst_low = processes[count].burst;
            int pro = count;
            for (int j = count; j < n; j++) {
                if (!processes[j].done && processes[j].arrival <= com_low && processes[j].burst <= burst_low) {
                    pro = j;
                    burst_low = processes[j].burst;
                }
            }
            if (pro == count) {
                count++;
            }
            processes[pro].complition = com_low + processes[pro].burst;
            processes[pro].turn_out_time = processes[pro].complition - processes[pro].arrival;
            processes[pro].waiting_time = processes[pro].turn_out_time - processes[pro].burst;
            com_low = processes[pro].complition;
            processes[pro].done = true;
        }
    }

    for(int i=0;i<n;i++){
        cout<<i<<"  "<<processes[i].arrival<<"  "<<processes[i].burst<<"  "<<processes[i].complition<<"  "<<
        processes[i].turn_out_time<<"  "<<processes[i].waiting_time<<endl;
    }

}