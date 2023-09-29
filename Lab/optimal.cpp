#include <bits/stdc++.h>
using namespace std;


int main(){
    int fsize, psize, i,j, count= 0, flag1, flag2,flag3, pfault = 0, pos, max;
    int stream[] = {2,3,4,2,1,3,7,5,4,3};
    cout<< "No. of frame: ";
    cin>> fsize;

    int temp[fsize];
    psize = sizeof(stream) / sizeof(stream[0]);
    int frame[fsize];
    for(i = 0; i < fsize; i++){
        frame[i] = -1;
    }
    for(i = 0; i<psize; i++){
        flag1=flag2=0;
        for(j = 0; j<fsize; j++){
            if(frame[j] == stream[i]){
                flag1=flag2=1;
                break;
            }
        }
        if(flag1==0){
            for(j = 0; j<fsize; j++){
                if(frame[j] == -1){
                    frame[j] = stream[i];
                    pfault++;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2==0){
            flag3 = 0;
            for(j = 0; j<fsize; j++){
                temp[j] = -1;
                for(int k= i+1; k<psize; k++){
                    if(frame[j] == stream[k]){
                        temp[j] = k;
                        break;
                    }
                }
            }

            for(j = 0; j<fsize; j++){
                if(temp[j] == -1){
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }
            if(flag3 == 0){
                max = temp[0];
                pos = 0;
                for(j = 1; j<fsize; j++){
                    if(temp[j] > max){
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frame[pos] = stream[i];
            pfault++;
        }

        cout << endl;
        for(j=0; j<fsize; j++){
            cout << frame[j]<<"    ";
        }
    }
    cout << endl <<"Total fault: "<<pfault;

}