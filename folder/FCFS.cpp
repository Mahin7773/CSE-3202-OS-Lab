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
    for(int i=0;i<n;i++){
        int arrival,burst,priority;
        cin>>arrival>>burst;
        process z(i,arrival,burst);
        p.push_back(z);
    }
    sort(p.begin(),p.end(), sort_by_arr_pri);
    int temp=0;
    for(int i=0;i<n;i++){
        if(p[i].arrival>temp){
            temp=p[i].arrival;
        }
        p[i].start=temp;
        p[i].completion=p[i].start+p[i].burst;
        temp=p[i].completion;
        p[i].turnaround=p[i].completion-p[i].arrival;
        p[i].waiting=p[i].turnaround-p[i].burst;

    }
    for(int i=0;i<n;i++){
        cout<<p[i].id<<" "<<p[i].completion<<" "<<p[i].turnaround<<" "<<p[i].waiting<<endl;
    }
}