#include<iostream>
#include <iterator>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

bool even(string line)
{
    if(line.length()== 1)
    {return true;}
    int space = 0;
    int reference = distance(line.begin(), find(line.begin()+1,line.end(),'*'))-1;


    for (auto it = line.begin()+1; it != line.end();++it)
    {
        if (*it == '*')
        {
            if (space!= reference)
            {return false;}
            space = 0;

        }
        else{space += 1;}
    }
    return true;
}
int main() {
    string line;
    vector <bool> v;
    while (getline(cin, line))
    {
        if(line == "END")
        {break;}
        v.push_back(even(line));
    }
unsigned siffra_ockso{1};
    for (auto it : v)
    {
        cout<<siffra_ockso;
        if (it) { cout << " EVEN"; }
        else { cout << " NOT EVEN"; }
        cout<<endl;
        siffra_ockso++;
    }
    return 0 ;
}
