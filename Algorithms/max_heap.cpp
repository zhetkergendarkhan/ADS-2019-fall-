#include<iostream>
#define MAXN 1000

using namespace std;

struct heap{
    int a[MAXN];
    int len;
    heap(){
        len = 0;
    }

    int get_min(){
        return a[0];
    }

    int cut_min(){
        int res = a[0];
        a[0] = a[--len];
        int p = 0;
        int x = 2 * p + 1;

        while (x < len ){
            int minp = (a[x] < a[x+1]) ? x : x + 1;
            if (a[p] > a[minp]){
                swap (a[p], a[minp]);
                p = minp;
                x = 2 * p + 1;
            }
            else {
                break;
            }
            
        }

        return res;
    }

    void add(int val){
        a[len] = val;
        int x = len;
        int p = (x-1)/2;

        while (a[p] < a[x] && x > 0){
            swap (a[p], a[x]);
            x = p;
            p = (x - 1) / 2;
        }

        len = len + 1;

    }

    void print (){
        for ( int i = 0; i < len; i++){
            cout << a[i] << " ";
        }
    }
};

struct priority_queue{
    heap h;
    priority_queue(){
    }

    int get_min(){
        return h.get_min();
    }

    void push(int x){
        h.add(x);
    }

    void pop(){
        h.cut_min();
    }

    int size(){
        return h.len;
    }

};

int main(){

    /*
    heap h;
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        h.add(x);
    }
    int k;
    cin >> k;
    bool f = false;
    int near;
    for (int i = 0; i < n; i++){
        int tmp = h.cut_min();
        if (tmp == k){
            cout << k << endl;
            return 0;
        }
        else if ( tmp > k && !f){
            near = tmp;
            f = true;
        }
    }
    cout << near;
    //h.print();
    */

    heap h;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        h.add(x);
    }
    cout << h.get_min();

    return 0;
}