#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> v;
    for(int a,i=0;i<N;i++){
        cin>>a;
        v.push_back(a);
    }
    cout<<N;
    return 0;
}