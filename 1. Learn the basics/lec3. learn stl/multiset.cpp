//while multiset allows repeptetion but it's still sorted

void explainNumtiset(){

    //everything is same as set
    //only difference is it also stores duplicated elements also
    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(1); //{1,1}
    ms.insert(1); //{1,1,1}

    ms.erase() ; //all 1's erased

    int cnt = ms.count(1);

    //only a single one erased
    ms.erase(ms.find(1));  //erases just that iterator

    ms.erase(ms.find(1),ms.find(1)+2);

    //rest all the functions are same as sets

}