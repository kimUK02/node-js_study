#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <map>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
    set<string> table;
    table.
    
    vector<int> vec;
    map<string,int> mymap;
    mymap["a"] = 1;
    mymap["c"] = 3;
    mymap["b"] = 2;
    
    for(auto p :  mymap)
    {
        cout<< p.first ;
    } 

    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(12);
    vec.push_back(100);
    vec.push_back(0);
    std::sort(vec.begin(),vec.end(),greater<int>());

    for(auto iter = vec.begin();iter != vec.end();iter++){
        cout << (*iter) << endl;
    }
    for(auto n: vec){
        cout << n << " ";
    }
    cout <<endl;
    return 0;
}
