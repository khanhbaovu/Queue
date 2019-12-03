#include <iostream>

using namespace std;

struct node {
    float data;
    node *link;
};

class Queue {
private:
    node *starter;
    node *finisher;
public:
    Queue();
    void Add(float);
    void Delete();
    void See();
};

Queue::Queue() {
    starter = NULL;
    finisher = NULL;
}

void Queue::Add(float info) {
    node *newNode = new node;

    newNode->data = info;

    if(starter == NULL) {
        starter = newNode;
        finisher = newNode;
        return;
    }

    finisher->link = newNode;

    finisher = newNode;
}

void Queue::Delete() {
    if(starter == NULL) {
        cout<<"EMPTY QUEUE!"<<endl;
        return;
    }

    node *tmp;

    tmp = starter;

    starter = starter->link;

    delete tmp;
}

void Queue::See() {
    if(starter == NULL) {
        cout<<"EMPTY QUEUE!"<<endl;
        return;
    }

    for(node *k=starter; k!=NULL; k=k->link) {
        cout<<k->data<<" ";
    }
    cout<<endl;
}

int main()
{
    Queue myQueue;

    int choice = -1;

    while(choice != 0) {
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
        case 1:
            float info;
            cout<<"Enter a number: ";
            cin>>info;
            myQueue.Add(info);
            break;

        case 2:
            myQueue.Delete();
            break;

        case 3:
            myQueue.See();
            break;
        }
    }
    return 0;
}
