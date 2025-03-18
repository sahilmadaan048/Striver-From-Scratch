//maps are used to store unique keys in sorted order 

//these are used to store data using key value pairs

void explainMap(){

    map<int,int> mpp ;
    ap<int,pair<int,int>> mpp;

    map<pair<int,int> ,int> pp;

    mpp[1]=2;
    mpp.enplace({3,1});

    pp.insert({2,4}) ;

    mpp({2,3}) = 18 ;

    {

        {1,3}
        {2,4}
        {3,1}
    }

    for(auto it: mpp)
{
    cout<<it.first << " "<< it.second <<endl;
}

cout<< mpp[1];
cout<<mpp[5];

auto it = mpp.find(3);
cout<<*(it).second ;

auto it = mpp.find(5);

//this is the syntax
auto it= mpp.lower_bound(2);

auto it = mpp.upper_bound(3);

//erase, swap, size, empty, are same as above
}