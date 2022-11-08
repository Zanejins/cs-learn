//
// Created by zanejins on 2022/11/5.
//

#ifndef NEW_PROJECT_QUEUE_H
#define NEW_PROJECT_QUEUE_H

class Customer {
private:
    long arrive;         //arrival time for customer
    int processtime;     //processing time for customer

public:
    Customer() { arrive = processtime = 0;}
    void set(long when);
    long when() const {return arrive;}
    int ptime() const {return processtime;}
};

typedef Customer Item;


class Queue {
private:
    enum {Q_SIZE = 10};
    struct Node {
        Item item;
        struct Node * next;
    };

    Node * front; //pointer to front of Queue
    Node * rear; //pointer to rear of Queue
    int items; //current number of items in Queue
    const int qsize; //maximum number of items in Queue;

    //preeemptive definitions to prevent public copying
    Queue(const Queue &q):qsize(0) { }
    Queue& operator=(const Queue q) { return *this;}

public:
    Queue(int qs = Q_SIZE); // create queue with a qs limit
    ~Queue();
    bool isempty() const;
    bool isfull() const;

    int queuecount() const;
    bool enqueue(const Item &item); //add item to end
    bool dequeue(Item &item); //remove item from front

};


#endif //NEW_PROJECT_QUEUE_H