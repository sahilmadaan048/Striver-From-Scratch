//stack is a LIFO data structure (Last in first out)

//all the operations are o(1)

//it has mainly 3 functions which are push , pop , top....there are others like
//clear , empty..etc

void explainStack(){

    stack<int> st;
    st.push(1); //{1}
    st.push(2); //{2,1}
    st.push(3); //{3,2,1}
    st.push(4); //{4,3,2,1}
    st.push(5); //{5,4,3,2,1}

    cout<< st.top(); //prints 5 "** st[2] is invalid **"
    
    st.pop(); //st looks like {4,3,2,1}

    cout<<st.top(); //3

    cout<<st.size() ; //4

    cout<<st.empty() ;//false

    stack<int> st1,st2 ;
    st1.swap(st2);
}