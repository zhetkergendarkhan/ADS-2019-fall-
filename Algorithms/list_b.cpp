#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
 
    ListNode(int x) : val(x), next(NULL) {}
};

struct List{
    ListNode * head;
    ListNode * tail;
    List(){
        head = NULL;
        tail = NULL;
    }
    void add(int x){
        ListNode * t = new ListNode(x);
        if(tail == NULL){
            head = tail = t;
        }else{
            tail->next = t;
            tail = t;
        }
    }
    
};

void print(ListNode * t){
        while(t != NULL){
            cout << t->val;
            t = t->next;
            if(t != NULL){
                cout << "->";
            }
        }
}

int main(){
    List l;
    l.add(1);
    l.add(2);
    l.add(3);
    print(l.head);
    return 0;
}