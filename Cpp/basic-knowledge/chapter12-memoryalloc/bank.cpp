#include<iostream>
#include<cstdlib>
#include<ctime>
#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    std::srand(std::time(0));

    cout<<"Case Study: Bank of Heather Automatic Teller\n";
    cout<<"Enter maximum size of queue: ";
    int qs;
    cin>>qs;
    Queue line(qs);

    cout<<"Enter the number of simulation hours: ";
    int hours;
    cin>>hours;

    // simulation will run 1 cycle per minite;
    long cyclelimit = MIN_PER_HR * hours;

    cout <<"Enter the average number of customers per hours: ";
    double perhour;
    cin>>perhour;

    double min_per_cus; // average time between arrivals
    min_per_cus = MIN_PER_HR / perhour;

    Item temp;           // new customer data
    long turnaways = 0;  // turned away by full queue
    long customers = 0;  //joined the queue
    long served = 0;     // served during the simulation
    long sum_line = 0;   // cumulative line length
    int wait_time = 0;   //time until autoteller is free
    long line_wait = 0; //cumulative time in line

    for(int cycle = 0; cycle<cyclelimit;cycle++) {
        if(newcustomer(min_per_cus)) {   //have new customer
            if(line.isfull())
                turnaways++;
            else {
                customers++;
                temp.set(cycle);   //cycle = time of arrival
                line.enqueue(temp);
            }
        }
        if(wait_time<=0 && !line.isempty()) {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait +=cycle-temp.when();
            served++;
        }
        if(wait_time > 0) {
            wait_time--;
        }
        sum_line += line.queuecount();
    }

    if(customers>0) {
        cout<<"customers accepted: "<<customers<<endl;
        cout<<"  customers served: "<<served<<endl;
        cout<<"          turnways: "<<turnaways<<endl;
        cout<<"average queue size: ";

        cout.precision(2);
        cout<<" average wait time: "
            <<(double) line_wait / served << " minutes\n";
    }

    else
        cout<<"No customers!\n";
    cout<<"Done!\n";
    return 0;

}

bool newcustomer(double x) {
    std::cout<<std::rand() *x<<std::endl;
    std::cout<<RAND_MAX<<std::endl;
    return (std::rand() * x /RAND_MAX <1);
}