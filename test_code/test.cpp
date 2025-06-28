#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    bool res = 1;
    vector<int> v(100015);
    cin >> n;
    
    for(int i = 0;i < n; i++){
        
        cin >> v[i];
        
    }

    sort(v.begin()+1,v.end());
    
    for(int i = 1;i < n; i++){
        if(v[0] <= v[i]){
            res = 0;
            break;
        }

        v[0] += v[i];
    }
    
    if (res){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    
    return 0;
}