// https://www.luogu.com.cn/problem/P9010
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string x;
int e[200009];
int fg,lg,fh,lh; // first g, last g, first h, last h
inline void input(){
    fg=lg=fh=lh=-1;
    cin>>n;
    cin>>x;
    for(int i=1;i<=n;i++){
        cin>>e[i];
        if(x[i-1]=='G'){
            lg=i;
            if(fg==-1)
                fg=i;
        }
        if(x[i-1]=='H'){
            lh=i;
            if(fh==-1)
                fh=i;
        }
    }
}
signed main(){
    input();
    int gl,hl;// g leader h leader
    gl = (e[fg]>=lg?fg:-1);
    hl = (e[fh]>=lh?fh:-1);
    // cout<<gl<<','<<hl<<endl;
    int gln,hln; // numbers of other g leader or h leader
    gln=hln=0;
    for(int i=1;i<gl;i++){
        if(x[i-1]=='H'&&e[i]>=gl&&i!=hl){
            hln++;
        }
    }
    for(int i=1;i<hl;i++){
        if(x[i-1]=='G'&&e[i]>=hl&&i!=gl){
            gln++;
        }
    }
    hln+=(hl!=-1);
    gln+=(gl!=-1);
    cout<<(hln*gln)<<endl;
}