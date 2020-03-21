#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
    }
};

class Stack {
    public:
    Node *top;
    int sz;

    Stack() {
        top = NULL;
        sz = 0;
    }

    void push(int data) {
        Node *node = new Node(data);
        if (top != NULL)
            node->next = top;
        top = node;
        sz++;
    }

    void pop() {
        if (top != NULL) {
            top = top->next;
            sz--;
        }
    }

    int getTop() {
        return top->data;
    }

    bool empty() {
        return (sz == 0);
    }
};

int main() {
    Stack *stack = new Stack();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        stack->push(x);
    }
    int y = stack->top->data;
    stack->pop();
    int cnt = 0;

    for(int i =0 ;i < n;i++){
        if(stack->top->data > y){
            cnt++;
            cout << "++" << " ";
        }
        else{
            y = stack->top->data;
        }
        stack->pop();
    }
    //cout << n -cnt;
    return 0;
}