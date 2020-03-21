#include <iostream>

using namespace std;

bool f1(int x){
    if(x == 1) return false;
    bool res = true;
    for(int i = 2; i < x; ++i){
        if(x % i == 0){
            res = false;
            break;
        }
    }
    return res;
}

bool f2(int x){
    if(x == 1) return false;
    bool res = true;
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0){
            res = false;
            break;
        }
    }
    return res;
}

bool isPrime[1000];

void init(int x){

    for(int i = 2; i <=x; ++i){
        isPrime[i] = true;
    }
    
    isPrime[1] = false;

    for(int i = 2; i <= x; ++i){
        if(isPrime[i] == true){
            int t = i + i;
            while (t <= x){
                isPrime[t] = false;
                t += i;
            }
        }
    } 

    /*for(int i = 2; i <= x; ++i){
        if(isPrime[i]){
            cout << i << " ";
        }
    }
    cout << endl;
    */


}