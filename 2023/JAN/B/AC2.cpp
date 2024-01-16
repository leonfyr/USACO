// https://www.luogu.com.cn/problem/P9011
#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[22],t[22],c[22];
int a[12],b[12],p[12],mm[12];
int ans=9999999;
inline void input(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>t[i]>>c[i];
    }
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>p[i]>>mm[i];
    }
}
int cows[111];
int mny;
void dfs(int k){
    if(k==m+1){
        for(int i=1;i<=n;i++){
            for(int j=s[i];j<=t[i];j++){
                if(cows[j]<c[i]){
                    return ;
                }
            }
        }
        ans=min(ans,mny);
        return ;
    }
    dfs(k+1);
    mny+=mm[k];
    for(int i=a[k];i<=b[k];i++){
        cows[i]+=p[k];
    }
    dfs(k+1);
    mny-=mm[k];
    for(int i=a[k];i<=b[k];i++){
        cows[i]-=p[k];
    }
}
int main(){
    input();
    dfs(1);
    cout<<ans<<endl;
    return 0;
}