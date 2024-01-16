// https://www.luogu.com.cn/problem/P9012
#include<bits/stdc++.h>
using namespace std;
int m;
inline bool compare(string x, int pos, string cmp){
    if(x[pos]==cmp[0] && x[pos+1]==cmp[1] && x[pos+2]==cmp[2]){
        return true;
    }
    return false;
}
inline void process(string x){
    int base=x.length()-3;
    int add=9;
    if(base<0){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i+3<=x.length();i++){
        if(compare(x,i,"MOO")){
            add=0;
        }else if(compare(x,i,"MOM") || compare(x,i,"OOO")){
            add=min(add,1);
        }else if(compare(x,i,"OOM")){
            add=min(add,2);
        }
    }
    if(add==9){
        cout<<-1<<endl;
    }else{
        cout<<add+base<<endl;
    }
}https://literate-fortnight-9w6666j6rqw2jj7.github.dev/
int main(){
    cin>>m;
    while(m--){
        string x;
        cin>>x;
        process(x);
    }
}