//
// Created by User on 12/31/2022.
//
#include <pthread.h>
#include <bits/stdc++.h>
#define num_thread 3
using namespace std;



struct thread_data{
    int thread_id;
    int sum;
    char *msg;
};

thread_data thread_data_array[num_thread];

void *printhello(void *threadarg){
    int taskid, sum;
    char *message;
    thread_data *mydata;
    mydata = (thread_data*) threadarg;
    taskid = mydata->thread_id;
    sum = mydata->sum;
    message = mydata->msg;
    cout << "Thread "<< taskid << " : " << message << " Sum: "<<sum <<endl;

}

int main(int argc, char *argv[])
{
    char *messages[num_thread];
    pthread_t threads[num_thread];
    int rc, t, sum=0;
    messages[0] = "number 0";
    messages[1] = "number 1";
    messages[2] = "number 2";

    for(t = 0; t<num_thread; t++){
        sum+=t;
        thread_data_array[t].thread_id = t;
        thread_data_array[t].sum = sum;
        thread_data_array[t].msg = messages[t];
        cout << "creating " << t << endl;
        rc = pthread_create(&threads[t], NULL, printhello, (void *)&thread_data_array[t]);
        if(rc){
            cout << "Error" <<endl;
        }
    }
    pthread_exit(NULL);
}
