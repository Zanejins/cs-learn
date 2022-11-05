#include "Queue.h"
#include<cstdlib>

//初始化列表
//对于const类成员必须只用这种语法
//对于被声明为引用的类成员也必须使用这种语法
//注意：这种格式智能用于构造函数
Queue::Queue(int qs) :qsize(qs) { //对于const成员变量，必须再执行到构造函数之前进行初始化，因此智能使用初始化列表
    front = rear = nullptr;
    items = 0;
}

Queue::~Queue() {
    Node* temp;
    while(front != nullptr) {
        temp=front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const {
    return items == 0;
}

bool Queue::isfull() const {
    return items == qsize;
}

int Queue::queuecount() const {
    return items;
}
bool Queue::enqueue(const Item &item) {
    if(isfull())
        return false;
    Node *add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if(front== nullptr)
        front = add;
    else
        rear->next = add;
    return true;
}

bool Queue::dequeue(Item &item) {
    if(front == nullptr)
        return false;
    item = front->item;
    items--;
    Node * temp = front; //save location of first item
    front = front->next; //reset front to next item
    delete temp;         //delete former first item

    if(items ==0) {
        rear = nullptr;
    }
    return true;
}

void Customer::set(long when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;
}


