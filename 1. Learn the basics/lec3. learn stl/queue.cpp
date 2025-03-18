//a data structure similar to stack but it is FIFO first in first out data structure
#include<iostream>
using namespace std;

void explainQueue(){

    queue<int> q;
    q.push(1); //{1}
    q.push(2); //{1,2}
    q.emplace(4); //{1,2,4}

    q.back() += 5;

    cout << q.back();  //priints 9;
    
    //q is {1,2,9}
    cout<< q.front() ; //prints 1

    q.pop() ; //{2,9}

    cout << q.front(); //prints 2

    //size swap empty same as stack

    //all the operations are happening in constant time


}