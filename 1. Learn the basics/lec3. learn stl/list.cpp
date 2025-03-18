//lists are internally implemented using doubly linked lists

//while vectors are inplemented using singly linked list

void expplainList(){
    list<int> ls;

    ls.push_back(2);   //{2}

    ls.emplace_back(4); //{2,4}
    
    ls.push_front(5);

    ls.emplace_front(1);
    //rst functions are same as vector
    //begin, end, rbegin, rend, clear, clear, insert, size, swap
    }

