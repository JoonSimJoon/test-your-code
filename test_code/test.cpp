#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> sorted;
bool isSortable1() {
    vector<int> even, odd;
    for (int x : arr) {
        if (x % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }
    vector<int> sorted_even, sorted_odd;
    for (int x : sorted) {
        if (x % 2 == 0) sorted_even.push_back(x);
        else sorted_odd.push_back(x);
    }
    return even == sorted_even && odd == sorted_odd;
}
bool isSortable2() {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] % 2 != sorted[i] % 2)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for(int a,i=0;i<N;i++){
        cin>>a;
        arr.push_back(a);
    }
    sorted = arr;
    sort(sorted.begin(),sorted.end());
    if (isSortable1()) cout << "So Lucky\n";
    else cout << "Unlucky\n";
    if (isSortable2()) cout << "So Lucky\n";
    else cout << "Unlucky\n";

    return 0;
}