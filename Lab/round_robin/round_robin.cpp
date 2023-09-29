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
    int start;
    int completion;
    int turnaround;
    int waiting;
    bool done=false;
    process(int id,int arrival,int burst){
        this->id=id;
        this->arrival=arrival;
        this->burst=burst;

    }
};
bool sort_by_arr_pri(process a,process b){
    return a.arrival<b.arrival;
}

int main() {
    vector<process> p;
    int n;
    cin>>n;
    int temp_burst[n+1];
    int tq;
    cin>>tq;
    for(int i=0;i<n;i++){
        int arrival,burst,priority;
        cin>>arrival>>burst;
        process z(i,arrival,burst);
        temp_burst[i]=burst;
        p.push_back(z);
    }
    sort(p.begin(),p.end(), sort_by_arr_pri);
    int no=0;
    int timer=0;
    while(no<n){
        int z=0;
        for(int i=0;i<n;i++){
            if(p[i].arrival<=timer && temp_burst[i]>0 && !p[i].done) {
                z=1;
                if (temp_burst[i] <= tq) {
                    timer += temp_burst[i];
                    temp_burst[i] = 0;
                } else if (temp_burst[i] > tq) {
                    temp_burst[i] -= tq;
                    timer += tq;
                }

                if(temp_burst[i]==0){
                    p[i].done= true;
                    no++;
                    p[i].completion=timer;
                    p[i].turnaround=p[i].completion-p[i].arrival;
                    p[i].waiting=p[i].turnaround-p[i].burst;
                }
            }
        }
        if(z==0){
            for(int j=0;j<n;j++){
                if(temp_burst[j]!=0 && !p[j].done){
                    timer=p[j].arrival;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<p[i].id<<" "<<p[i].completion<<" "<<p[i].turnaround<<" "<<p[i].waiting<<endl;
    }
}