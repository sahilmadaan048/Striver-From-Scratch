//kinda like queue
//just that the maximum element stays at the top


//the data is not stored in a linear fashion
//..inside it a tree data structure is implemented which is not linear

/*
push and pop functions happen in log(n) time 
while top takes o(1) time
*/


#include<bits/stdc++.h>
using namespace std ;

void explainPQ(){
    //max heap
    // priority_queue<int> pq;

    // pq.push(5); //{5}
    // pq.push(2); //{5,2}
    // pq.push(8); //{8,5,2}
    // pq.push(10); //{10,8,5,2}

    // cout<<pq.top(); //prints 10

    // pq.pop(); //{8,5,2}

    // cout<<pq.top();  //prints 8

    //size swap empty functions are same as others

    //Minimum heap
    priority_queue<int , vector<int>, greater<int>> pq;
    pq.push(5); //{5}
    pq.push(2); //{2,5}
    pq.push(8); //{2,5,8}
    pq.emplace(10); //{2,5,8,10}

    cout<<pq.top(); //prints 2

}
