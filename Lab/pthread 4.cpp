
#include <pthread.h>
#include <bits/stdc++.h>
#define num_thread 3
using namespace std;


void *busywork(void *t){
    int i;
    long *tid;
    float result= 0;
    tid = (long*) t;
    cout << "Thread "<<tid<<" starting" <<endl;
    for(i = 0; i< 10; i++){
        result = result + i;
    }
    cout << "Thread "<<tid <<" is done. Result is "<< result << endl;
    pthread_exit((void*) t);

}

int main(int argc, char *argv[])
{
    pthread_t threads[num_thread];
    pthread_attr_t attr;
    int rc, t;
    void *status;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(t = 0; t<num_thread; t++) {
        cout << "Main: creating thread "<< t<<endl;
        rc = pthread_create(&threads[t], &attr, busywork, (void*) t);
        if(rc){
            cout << "error" <<endl;
        }

    }
    pthread_attr_destroy(&attr);
    for(t=0; t<num_thread;t++){
        rc = pthread_join(threads[t], &status);
        if(rc){
            cout << "error" <<endl;
        }
        cout<< "Main: completed join thread " << t <<" status "<<(long*) status<<endl;
    }
    cout<< "Main done" << endl;
    pthread_exit(NULL);
}
