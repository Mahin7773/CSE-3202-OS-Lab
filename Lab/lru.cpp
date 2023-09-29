#include <bits/stdc++.h>
using namespace std;

int findlru(int time[], int n){
    int i, min = time[0], pos = 0;
    for(i =1; i<n; i++){
        if(time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main(){
    int fsize, psize, i,j, count= 0, flag1, flag2, pfault = 0, pos;
    int time[10];
    int stream[] = {5,7,5,6,7,3};
    cout<< "No. of frame: ";
    cin>> fsize;
    psize = sizeof(stream) / sizeof(stream[0]);
    int frame[fsize];
    for(i = 0; i < fsize; i++){
        frame[i] = -1;
    }
    for(i = 0; i<psize; i++){
        flag1=flag2=0;
        for(j = 0; j<fsize; j++){
            if(frame[j] == stream[i]){
                count++;
                time[j] = count;
                flag1=flag2=1;
                break;
            }
        }
        if(flag1==0){
            for(j=0; j<fsize; j++){
                if(frame[j] == -1){
                    frame[j] = stream[i];
                    count++;
                    pfault++;
                    time[j] = count;
                    flag2 =1;
                    break;
                }
            }
        }

        if(flag2 == 0){
            pos = findlru(time, fsize);
            count++;
            pfault++;
            time[pos] = count;
            frame[pos] = stream[i];
        }

        cout << endl;
        for(j=0; j<fsize; j++){
            cout << frame[j]<<"    ";
        }
    }
    cout << endl <<"Total fault: "<<pfault;

}