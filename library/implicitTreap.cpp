#include <bits/stdc++.h>
using namespace std;
typedef struct item *pitem;
struct item{
   int prior, value, cnt;
   bool rev;
   pitem l, r, p;
};
int cnt(pitem it){
   return it?it->cnt:0;
}
void upd_cnt(pitem it){
   if(it) it->cnt = cnt(it->l)+cnt(it->r)+1;
}
/*void heapify(pitem t){
   if(!t)return ;
   pitem max=t;
   if(t->l && t->l->prior > max->prior) max = t->l;
   if(t->r && t->r->prior > max->prior){
      max = t->r;
      if(max != t){
	swap(t->prior, max->prior);
	heapify(max);
      }
   }
}

 ///Builds a tree in O(N) given an array a[]
 
pitem build(int *a, int n){
   if(n==0)return NULL;
   int mid = n/2;
   pitem t=new item(a[mid], rand());
   t->l = build(a, mid);
   t->r = build(a+mid+1, n-mid-1);
   heapify(t);
   upd_cnt(t);
   return t;
}
void connect(auto from, auto to){
   vector<pitem> st;
   for(auto it=from; it!=to;it++){  
      while(!st.empty() && st.back()->prior > (*it)->prior)
	st.pop_back();
      if(!st.empty()){
	if(!(*it)->p || (*it)->p->prior < st.back()->prior)
	   (*it)->p=st.back();
      }
      st.push_back(*it);
   }
}
pitem build(int *x, int *y, int n){
   vector<pitem> nodes(n);
   for(int i = 0 ; i <n; i++)
      nodes[i] = new item(x[i], y[i]);
   connect(nodes.begin(), nodes.end());
   connect(nodes.rbegin(), nodes.rend());
   for(int i = 0 ; i < n ; i++){
      if(nodes[i]->p){ 
	if(nodes[i]->p->key < nodes[i]->key)
	  nodes[i]->p->r = nodes[i];
	else
	  nodes[i]->p->l = nodes[i];
      }
   }
   return nodes[min_element(y, y+n)-y];
}*/
void push(pitem it){
   if( it && it->rev){
      it->rev = false;
      swap(it->l, it->r);
      if(it->l) it->l->rev ^=true;
      if(it->r) it->r->rev ^=true;
   }
}
void merge(pitem &t, pitem l, pitem r){
    push(l);
    push(r);
    if(!l || !r) t = (l)?l:r;
    else if(l->prior > r->prior) merge(l->r, l->r, r), t=l;
    else merge(r->l,l,r->l), t=r;
    upd_cnt(t);
}
void split(pitem t, pitem &l, pitem &r, int key, int add=0){
   if(!t) return void(l=r=0);
   int cur_key = add + cnt(t->l);
   if(key <= cur_key) //to left...
     split(t->l, l, t->l, key, add), r=t;
   else
     split(t->r, t->r, r , key, add+1+cnt(t->l)), l=t;
   upd_cnt(t);
}
void reverse(pitem t, int l, int r){
  pitem t1, t2, t3;
  split(t, t1, t2, l);
  split(t2, t2, t3, r-l+1);
  t2->rev ^=true;
  merge(t, t1, t2);
  merge(t, t, t3);
}
void output(pitem t){
  if(!t) return;
  push(t);
  output(t->l);
  cout<<t->value<<" ";
  output(t->r);
}
int main(){
   return 0;
}
