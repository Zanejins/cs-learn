#include<iostream>
#include<new>

const int BUF = 512;
const int N = 5;
char buffer[BUF];

int main() {
    using namespace std;

    double *pd1;
    double *pd2;
    int i;

    cout<<"Calling new and placement new:\n";

    pd1 = new double[N];
    pd2 = new (buffer) double[N];

    for(int i=0;i<N;i++) {
        pd2[i] = pd1[i] = 1000+20.0+i;
    }

    cout <<"Memory addresses:\n"<<" heap:"<<pd1 <<" static: "<<(void *) buffer<<endl;
    cout <<"Memory contents:\n";
    for(i=0;i<N;i++) {
        cout<<pd1[i]<<" at "<<&pd1[i]<<" ;";
        cout<<pd2[i]<<" at "<<&pd2[i]<<"\n";
    }

    cout<<"\nCalling new and placement new a second time:\n";
    double *pd3;
    double *pd4;
    pd3 = new double[N];
    pd4 = new (buffer) double[N];

     for(int i=0;i<N;i++) {
        pd3[i] = pd4[i] = 1000+40.0+i;
    }

    cout <<"Memory contents:\n";
    for(i=0;i<N;i++) {
        cout<<pd3[i]<<" at "<<&pd3[i]<<" ;";
        cout<<pd4[i]<<" at "<<&pd4[i]<<"\n";
    }

    cout<<"\nCalling new and placement new a third time:\n";
    delete [] pd1;
    pd1 = new double[N];
    pd2 = new (buffer + N *sizeof(double)) double[N];

     for(int i=0;i<N;i++) {
        pd2[i] = pd1[i] = 1000+60.0+i;
    }

    cout <<"Memory contents:\n";
    for(i=0;i<N;i++) {
        cout<<pd1[i]<<" at "<<&pd1[i]<<" ;";
        cout<<pd2[i]<<" at "<<&pd2[i]<<"\n";
    }
    //为什么不delete [] p2 和 p4 呢？
    //因为p2和p4是使用定位new从静态内存buffer中分的，而buffer数组位于delete的管辖语句之外，所以不能使用delete
    delete [] pd1; 
    delete [] pd3;
    return 0;
}
