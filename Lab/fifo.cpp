#include <bits/stdc++.h>
using namespace std;

int main(){
    int stream[] = {4,1,2,4,5};
    int frame;
    cout << "Frame size: ";
    cin >> frame;
    int i, psize, flag;
    int pagefault = 0;
    psize = sizeof(stream) / sizeof(stream[0]);
    int temp[frame];
    for (i = 0;i < frame; i++){
        temp[i] = -1;
    }
    for (i = 0;i < psize; i++){
        flag = 0;
        for(int j=0; j< frame; j++){
            if(stream[i] == temp[j]){
                flag++;
                pagefault--;
            }
        }
        pagefault++;
        if((pagefault<=frame) && (flag ==0)){
            temp[i] = stream[i];
        }
        else if(flag == 0){
            temp[(pagefault-1)%frame] = stream[i];
        }
        //cout << stream[i] <<"   ";
        for(int j =0; j < frame; j++){
            cout << temp[j] << "   ";
        }
    }
    cout << endl << "Total fault: "<< pagefault<<endl;
}