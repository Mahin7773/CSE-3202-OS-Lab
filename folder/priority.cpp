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
    int id;
    int arrival;
    int burst;
    int priority;
    int start;
    int completion;
    int turnaround;
    int waiting;
    bool done=false;
    process(int id,int arrival,int burst,int priority){
        this->id=id;
        this->arrival=arrival;
        this->burst=burst;
        this->priority=priority;
    }
};
bool sort_by_arr_pri(process a,process b){
    if(a.arrival==b.arrival){
        return a.priority<b.priority;
    }
    return a.arrival<b.arrival;
}

int main() {
    vector<process> p;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int arrival,burst,priority;
        cin>>arrival>>burst>>priority;
        process z(i,arrival,burst,priority);
        p.push_back(z);
    }
    sort(p.begin(),p.end(), sort_by_arr_pri);

    int temp=0;
    temp=max(temp,p[0].arrival);
    p[0].start=temp;
    p[0].completion=p[0].start+p[0].burst;
    p[0].turnaround=p[0].completion-p[0].arrival;
    p[0].waiting=p[0].turnaround-p[0].burst;
    temp=p[0].completion;
    p[0].done= true;
    cout<<0<<" "<<p[0].start<<" "<<p[0].completion<<" "<<p[0].turnaround<<" "<<p[0].waiting<<endl;
    int com=1;
    while(com<n) {
        int ma=INT_MAX;
        int ma_pr=INT_MAX;
        for (int i = 1; i < n; i++) {
            if(p[i].arrival<=temp && !p[i].done) {
                if(p[i].priority<ma_pr){
                    ma_pr=p[i].priority;
                    ma=i;
                }
            }
            else if (p[i].arrival>temp && !p[i].done){
                ma=i;
            }
        }
        temp = max(temp, p[ma].arrival);
        p[ma].start = temp;
        p[ma].completion = p[ma].start + p[ma].burst;
        p[ma].turnaround = p[ma].completion - p[ma].arrival;
        p[ma].waiting = p[ma].turnaround - p[ma].burst;
        p[ma].done= true;
        cout<<ma<<" "<<p[ma].start<<" "<<p[ma].completion<<" "<<p[ma].turnaround<<" "<<p[ma].waiting<<endl;
        com++;
        temp = p[ma].completion;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" "<<p[i].start<<" "<<p[i].completion<<" "<<p[i].turnaround<<" "<<p[i].waiting<<endl;
    }
}