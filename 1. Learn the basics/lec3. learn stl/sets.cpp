// //stores everything in sorted order
// //everything stored is unique

// //it is also not linear

// //inside each bucket a tree is mantainned


// //evertything happens in log(N) time complexity

// //while multiset allows repeptetion but it's still sorted
#include<bits/stdc++.h>
using namespace std;


void explainSet(){
    set<int> st;
    st.insert(1); //{1}
    st.insert(2); //{1,2}
    st.insert(2); //{1,2}
    st.insert(4); //{1,2,4}
    st.insert(3); //{1,2,3,4}

    //functionality of insert in vector
    //can be used also, tat only increase
    //efficiency

    //begin() , end() , rbegin() , rend() , size() , 
    //empty() and swap() are same as those of above

    //{1,2,3,4,5}
    auto it = st.find(3);

    //{1,2,3,4,5}
    auto it=st.find(6) ; //if element is not present it returns the iterator after the last element

    //{1,4,5}
    st.erase(5); //erases 5 // takes logarithmic time

    int cnt = st.count(1);

    auto itt=st.find(3);
    st.erase(itt); //it takes constant time

    //{1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1,it2);  //after erase {1,4,5} [first,last)
    
    //lower_bound() and upper_bound() functions works in the same way
    //as i vector it does

    //this is the syntaxx
    // auto it = st.lower_bound(2);
    // auto it= st.upper_bound(3);

}

int main() {
    explainSet();
    return 0;
}


// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;


// class Shape {
// public:
//     virtual void draw() = 0;
//     virtual float area() = 0;
// };

// class Circle : public Shape {
// private:
//     float radius;
// public:
//     Circle(float r) : radius(r) {}
//     void draw() {
//         std::cout << "Drawing a circle" << std::endl;
//     }
//     float area() {
//         return 3.14 * radius * radius;
//     }
// };

// class Rectangle : public Shape {
// private:
//     float length;
//     float width;
// public:
//     Rectangle(float l, float w) : length(l), width(w) {}
//     void draw() {
//         std::cout << "Drawing a rectangle" << std::endl;
//     }
//     float area() {
//         return length * width;
//     }
// };

// int main() {
//     int t; 
//     cout << "Enter the number of test cases: " ;
//     cin >> t;
//     int i=1;
//     while(t--){
//         cout << "Test case: " << i << endl;
//         float circleRadius, rectLength, rectWidth;
//         std::cout << "Enter the radius of the circle: ";
//         std::cin >> circleRadius;

//         std::cout << "Enter the length and width of the rectangle: ";
//         std::cin >> rectLength >> rectWidth;

//         Shape *s1 = new Circle(circleRadius);
//         Shape *s2 = new Rectangle(rectLength, rectWidth);

//         s1->draw();
//         std::cout << "Area of Circle: " << s1->area() << std::endl;

//         s2->draw();
//         std::cout << "Area of Rectangle: " << s2->area() << std::endl;

//         delete s1;
//         delete s2;
//         i++;
//     }
//     return 0;
// }