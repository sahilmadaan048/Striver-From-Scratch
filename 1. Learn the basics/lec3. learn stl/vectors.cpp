//algorithms

//containers

//functions

//iterators  -> points at the memory address

//vectors
#include<iostream>
#include<vector>
#include<utility>
using namespace std;


void explainVector(){

    vector<int> v;

    v.push_back(3);
    v.emplace_back(2);   //this is faster than push back

    vector<pair<int,int>> vec ;   //vector of a pair datatype

    vec.push_back({1,2});
    vec.emplace_back({1,2});   //it automaticaly understands a pair is being stores so no need to apply the urly braces 

    vector<int> v(5,100);   //size 5 declared with 5 instances of 100

    vector<int> v(5);   //of size of with 0 or garbage values depending on compiler

    vector<int> v1(5,20);
    vector<int> v2(v1);  //v2 will be another container / a simiar copy f vector v1

    vector<int> :: iterator  it =v.begin();

    it++;
    cout<< *(it)<<" ";

    it =it+2;
    cout<< *(it) <<" ";   //*  -> dereference operator -.the value of element inside the iterator it is accessed

    vector<int>:: iterator it= v.end();  //it is poinitng at the position next to the last element of the vector


//generally not used but its good to know

    vector<int>:: iterator it =v.rend();

    vector<int>:: iterator it =v.rend();

    cout<<v[0]<<" "<<v.at(0);
    cout<<v.back()<<" ";     //v.back ->the last element

    for(vector<int>:: iterator it=v.begin();it!=v.end();it++){
        cour<<*(it)<<" ";
    }


    for(auto it = v.begin(); it!=v.end();it++){
        cout<< *(it) <<" ";
    }
 // auto means auto assignation of the data type which we don't have to mention separately

    for(auto it: v){
        cout<< it << " ";
    }

//DELETION FROM A VECTOR

    //{10,20,12,23}
    v.erase(v.begin()+1m);   //{10,12,23}

    //{10,20,12,23,25}
    v.erase(v.begin()+2,v.begin()+4);  //{10,20,25}  [start,end)

    //INSERT FUNCTION

        vector<int> v(2,100); //{100,100}
        v.insert(v.begin(),300);  //{30,100,100};
        v.insert(v.begin()+1,2,10); //(300,10,10,100,100)

        vector<int> copy(2,50); //{50,50} 
        v.insert(v.begin(),copy.begin(),copy.end());    //{50,50,300,10,10,100,100}

        //{10,20}
        cout<<v.size() ;   //2 

        //(10,20)
        v.pop_back();   //{10}

        //v1->{10,20}
        //v2->{30,40};

        v1.swap(v2); //v1->{30,40}  and v2-.{10,20}

        v.clear();  //erases the entire number

        cout<<v.empty();

}

int main(){

    explainVector();

    return 0 ;
}