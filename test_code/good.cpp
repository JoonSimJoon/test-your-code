#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

vector<int> v,c1v,c2v;
int N;
int ans[2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int a,i=0;i<N;i++){
        cin>>a;
        v.push_back(a);
        //checkodd[a%2]++;
    }
    vector<int> sorted = v;
    c1v = v;
    sort(sorted.begin(),sorted.end());
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N-1;k++){
                if(c1v[k]>c1v[k+1] && (c1v[k]+c1v[k+1])%2==1){
                    //cout<<c1v[k]<<" "<<c1v[k+1]<<"\n";
                    swap(c1v[k],c1v[k+1]);
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        if(c1v[i]!=sorted[i]){
            ans[1]=1;
            break;
        }
    }
    if(ans[1]==0) cout<<"So Lucky\n";
    else cout<<"Unlucky\n";
    c2v = v;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N-1;k++){
                if(c2v[k]>c2v[k+1] && (c2v[k]+c2v[k+1])%2==0){
                    swap(c2v[k],c2v[k+1]);
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        if(c2v[i]!=sorted[i]){
            ans[0]=1;
            break;
        }
    }


    if(ans[0]==0) cout<<"So Lucky\n";
    else cout<<"Unlucky\n";

    return 0;
}