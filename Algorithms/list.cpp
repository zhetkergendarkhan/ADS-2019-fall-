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

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode * prev = NULL;
            ListNode * curr = head;
            ListNode * next = NULL;

            while (curr != NULL){
                next = curr -> next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
            return head;
        }

        void deleteNode(ListNode * head, int pos){
            if (pos == 0){
                head = NULL;
                return;
            }
            ListNode * temp = head;
            int i = 0;;
            while (i < pos - 1){
                temp = temp -> next;
                i++;
            }
            ListNode * next = temp -> next -> next;
            temp -> next = next;

        }
};


int main(){

    List l;
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(4);
    l.add(5);


    Solution s;
    s.deleteNode(l.head, 3);

    cout << "output: ";
    print(l.head);
    cout << endl;

    return 0;
}