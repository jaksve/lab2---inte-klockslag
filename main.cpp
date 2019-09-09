#include<iostream>
#include <iterator>
#include <sstream>
#include <vector>
using namespace std;

bool is_prime(unsigned in)
{
    if(in<=3)
        return in>1 ;
    else if(in % 2 == 0 || in % 3 == 0)
    {
        return false;
    }
    unsigned i = 5;
    while(i*i <= in)
    {
        if (in % i == 0 || in % (i+2) == 0)
        {
            return false;
        }
        i+=6;
    }

    return true;
}

int main()
{
    unsigned q,n;
    string line;
    cin>>n>>q;
    vector<unsigned> v;

    unsigned prim = 1;

    for (unsigned i = 1; i <=n ; i+=2)
    {
        if(is_prime(i))
        {prim+=1;}
    }



    for (unsigned i=0;i<q;++i)
    {
        unsigned hejsan{};
        cin>>hejsan;
        v.push_back(hejsan);
    }
    cout<<prim<<endl;
    for(auto it : v)
    {
        cout<<is_prime(it)<<endl;


    }

    /*

    while(getline(cin,line))
    {
        stringstream ss{line};
        ss>>q;
        v.push_back(q);

    }
*/
    return 0;
}