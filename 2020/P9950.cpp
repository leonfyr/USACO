// P9950 [USACO20FEB] Mad Scientist B
#include<bits/stdc++.h>
using namespace std;
bool tmp=true;
int main(){
    string a,b;
    cin>>a>>a>>b;
    int ans=0;
    for(int i=0;i<a.length();i++){
        if(a[i] == b[i]){
            tmp=true;
        }else{
            if(tmp==true){
                ans++;
            }
            tmp=false;
        }
    }
    cout<<ans<<endl;
    return 0;
}