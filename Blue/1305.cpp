#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],n,k,tree[4*N],dp[N];
int ls(int p){return p<<1;}
int rs(int p){return p<<1|1;}
void push_up(int p){tree[p]=max(tree[ls(p)],tree[rs(p)]);}
void build(int p,int pl,int pr){//重构一个树
  tree[p]=0;
  if(pl==pr) return;
  int mid=(pl+pr)/2;
  build(ls(p),pl,mid);
  build(rs(p),mid+1,pr);
}
void update(int p,int pl,int pr,int x,int v){
  if(pl==pr){
    tree[p]=max(tree[p],v);
    return;
  }
  int mid=(pl+pr)/2;
  if(x<=mid) update(ls(p),pl,mid,x, v);
  else update(rs(p),mid+1,pr,x,v);
  push_up(p);
}
int query(int p,int pl,int pr,int L,int R){
  if(L<=pl&&pr<=R) return tree[p];
  int res=0;
  int mid=(pl+pr)/2;
  if(L<=mid) res=max(res,query(ls(p),pl,mid,L,R));
  if(R>mid) res=max(res,query(rs(p),mid+1,pr,L,R));
  return res;
}
int main()
{
  cin>>n>>k;
  if(n==k){cout <<n;return 0;}//一个特判
  for(int i=1;i<=n;i++){cin>>a[i];b[i]=a[i];}
  sort(b+1,b+1+n);
  for(int i=1;i<=n;i++) a[i]=(lower_bound(b+1,b+1+n,a[i])-b);
  build(1,1,N);
  for(int i=1;i<=n;i++){//计算各叶子节点权值，也即以原始数列各个数为结尾的最长不下降子序列的长度
    dp[i]=query(1,1,N,1,a[i])+1;
    update(1,1,N,a[i],dp[i]);
  }
  int ans=0;
  build(1,1,N);
  for(int i=n;i>k;i--){
    ans=max(ans,dp[i-k]+k-1+query(1,1,N,a[i-k],N)+1);//query(1,1,N,a[i-k],N)求的是以a[i-k]开头的最长不下降子序列长度。由于还没将a[i-k]本身算进去，所以query(1,1,N,a[i-k],N)+1才是这长度。
    //第一个-1对应的是原来的a[i]，由于被修改成了a[i-k]的值，所以它不能存在于使i-k+1~i这k个值为i-k的值后新的数列内，所以须-1将其剔出，以免影响query(1,1,N,a[i-k],N)+1的统计。
    //其实query(1,1,N,a[i-k],N)+1统计的是新数列中以a[i]开头的最长不下降子序列长度。
    int tmp=query(1,1,N,a[i],N)+1;//tmp统计的是原数列中以a[i]开头的最长不下降子序列长度
    ans=max(ans,tmp+k);
    update(1,1,N,a[i],tmp);
  }
  cout<<ans;
  return 0;
}