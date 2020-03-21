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
            v.erase(v.begin()+v.size());
        }
        int size(){
            return v.size();
        }
        int top(){
            return v[v.size()-1];
        }
};