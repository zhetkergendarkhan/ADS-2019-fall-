#include <iostream>
#include <vector>

using namespace std;

struct queue{
    private:
        vector<int> v;
    public:
        queue(){
        
        } 
        void enqueue(int x){
            v.push_back(x);
        }
        void dequeue(){
            v.erase(v.begin());
        }
        int size(){
            return v.size();
        }
        int front(){
            return v[0];
        }
        int back(){
            return v[v.size()-1];
        }

};

int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.front();
    cout << q.back();    
    return 0;
}