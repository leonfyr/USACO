#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,m,k;
struct node{
	int w,n;
	bool operator<(const node& a) const{
		return w < a.w;
	}
	bool operator>(const node& a) const{
		return w > a.w;
	}
}nodes[200009];
node nodee(int a,int b){
	node x;
	x.w=a;x.n=b;
	return x;
}
inline void input(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>nodes[i].w>>nodes[i].n;
	}
	sort(nodes,nodes+n,greater<node>());
}
priority_queue < node > pq;
inline void printnode(node x){
	// cout<<'('<<x.w<<','<<x.n<<')';
}
signed main(){
	input();
	pq.push(nodee((unsigned long long)(-1),m));
	int used=0;
	for(int i=0;i<n;i++){
		// cout<<"Pour:"<<i;
		// printnode(nodes[i]);
		// cout<<endl;
        int theo=min(m,nodes[i].n); // the maximum of number of i
		int cur=0; // how many cows are used now
		while(!pq.empty()){
			node pqtop=pq.top();
			pq.pop();
			// printnode(pqtop);
			if(pqtop.w-nodes[i].w<k){// the gap is less than k, break the loop
				pq.push(pqtop);
				break;
			}else if(pqtop.n<=theo-cur){ 
				cur += pqtop.n;
                //MODIFIED
                if(cur == theo){
                    break;
                }
                //EOM
			}else{// pqtop.n>theo-cur
				pq.push(nodee(pqtop.w,pqtop.n-(theo-cur)));
				cur = theo;
				break;
			}
		}
		if(cur!=0){
			pq.push(nodee(nodes[i].w,cur));
			used+=cur;
		}	
	}
	cout<<used<<endl;
	return 0;
}