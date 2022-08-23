#include <bits/stdc++.h>
using namespace std;
typedef struct item *pitem;
struct item{
   int prior, value, cnt, sum, min, max, add, assign;
   bool rev;
   pitem l, r, p;
   item(){}
   item(int value) :prior(rand()), value(value), cnt(0),sum(0), min(INT_MAX), max(-INT_MAX), add(0),assign(INT_MAX),rev(false), l(NULL), r(NULL), p(NULL){ }
   item(int prior, int value) :prior(prior), value(value), cnt(0),sum(0), min(INT_MAX), max(-INT_MAX), add(0),assign(INT_MAX),rev(false), l(NULL), r(NULL), p(NULL){ }
};
class implicitTreap{
   pitem root=NULL;
   bool valueAsPrior=false; //false indicates that prior is randomly generated to ensure a balance tree
   public:
      implicitTreap(){
      }
      void remove(pitem it){
	if(!it)return;
	if(it->l)remove(it->l);
	if(it->r)remove(it->r);
	delete it;
      }
      ~implicitTreap(){
	remove(root);
      }
      int cnt(pitem it){
         return it?it->cnt:0;
      }
      int sum(pitem it){
          return it?it->sum:0;
      }
      int minv(pitem it){
        return it?it->min:INT_MAX;
      }
      int maxv(pitem it){
        return it?it->max:-INT_MAX;
      }
      void upd_cnt(pitem it){
         if(it) it->cnt = cnt(it->l)+cnt(it->r)+1;
      }
      void upd_min(pitem it){
         if(it) it->min=min({minv(it->l), minv(it->r), it->value});
      }
      void upd_max(pitem it){
         if(it) it->max=max({maxv(it->l), maxv(it->r), it->value});
      }
      void upd_sum(pitem it){
         if(it) it->sum = sum(it->l)+sum(it->r)+it->value;
      }
      void update(pitem t){
          upd_cnt(t);
          upd_sum(t);
          upd_min(t);
          upd_max(t);
      }
      /*
       *Lazy propagation...
       * */
      void pushReverse(pitem it) {
          if (it && it->rev) {
              it->rev = false;
              swap (it->l, it->r);
              if (it->l)  it->l->rev ^= true;
              if (it->r)  it->r->rev ^= true;
          }
      }
      void pushAdd(pitem it){
         if(it && it->add != 0){
             it->value +=it->add;
             if(it->l) it->l->add+=it->add;
             if(it->r) it->r->add+=it->add;
             it->add=0;
         }
      }
      void pushAssign(pitem it){
        if(it && it->assign!=INT_MAX){
           it->value =it->assign;
           if(it->l)it->l->assign=it->assign;
           if(it->r)it->r->assign=it->assign;
           it->assign=INT_MAX;
        }
      }
      void push(pitem it){
         pushReverse(it);
         pushAdd(it);
         pushAssign(it);
	 if(it && valueAsPrior)it->prior=it->value;
      }
      void merge(pitem &t, pitem l, pitem r){
          push(l);
          push(r);
          if(!l || !r) t = (l)?l:r;
          else if(l->prior < r->prior) merge(l->r, l->r, r), t=l;
          else merge(r->l,l,r->l), t=r;
          update(t);
      }
      void split(pitem t, pitem &l, pitem &r, int key, int add=0){
         if(!t) return void(l=r=0);
         push(t);
         int cur_key = add + cnt(t->l);
         if(key <= cur_key) //to left...
           split(t->l, l, t->l, key, add), r=t;
         else
           split(t->r, t->r, r , key, add+1+cnt(t->l)), l=t;
         update(t);
      }
      void insert(pitem &t, pitem it, int pos){
           if(!t){
      	     t=it;
      	     return;
           }
           pitem T1, T2;
           split(t, T1, T2, pos);
           merge(T1, T1, it);
           merge(t, T1, T2);
           update(t);
      }
      void insert(int val, int pos){
	  if(!valueAsPrior)
          insert(root, new item(val), pos);
	  else
          insert(root, new item(val, val), pos);
      }
      pitem find(pitem &t, int key, int add=0){
         if(!t) return NULL;
         int cur_key = add + cnt(t->l);
         pitem item =NULL;
         if(cur_key==key) item=t;
         else if(key < cur_key) //to left...
           item = find(t->l, key, add);
         else
           item = find(t->r, key, add+1+cnt(t->l));
         update(t);
         return item;
      }
      pitem find(int key){
	return find(root, key);
      }
      void erase(pitem &t, int key, int add=0){
         int cur_key = add + cnt(t->l);
         if(cur_key == key){
      	pitem th = t;
      	merge(t, t->l, t->r);
      	delete th;
         }else erase(key < cur_key?t->l:t->r, key, add+1+cnt(t->l));
         update(t);
      }
      void erase(int key){
	erase(root, key);
      }
      int kth(pitem T, int k){
        if(!T)return -1;
	int val=-1;
        if(cnt(T->l)+1==k)val=T->value;
	else if(cnt(T->l)+1<k) val=kth(T->r, k-cnt(T->l)-1);
        else val=kth(T->l, k); 
	update(T);
	return val;
      }
      int LEQ(pitem T, int target){
	 if(!T)return 0;
	 int v=(T->value <=target);
	 if(T->l && T->l->value <=target) v+=LEQ(T->l, target);
	 if(T->r && T->r->value <=target) v+=LEQ(T->r, target);
	 return v;
      }
      void reverse(int l, int r){
        pitem t1, t2, t3;
        split(root, t1, t2, l);
        split(t2, t2, t3, r-l+1);
        t2->rev ^=true;
        merge(root, t1, t2);
        merge(root, root, t3);
      }
      void add(int l, int r, int val){
        pitem t1, t2, t3;
        split(root, t1, t2, l);
        split(t2, t2, t3, r-l+1);
        t2->add +=val;
        merge(root, t1, t2);
        merge(root, root, t3);
      }
      void assign(int l, int r, int val){
        pitem t1, t2, t3;
        split(root, t1, t2, l);
        split(t2, t2, t3, r-l+1);
        t2->assign=val;
        merge(root, t1, t2);
        merge(root, root, t3);
      
      }
      int querySum(int l, int r){
       pitem t1,t2,t3;
       split(root, t1, t2, l);
       split(t2, t2, t3, r-l+1);
       int sum = t2->sum;
       merge(root, t1, t2);
       merge(root, root, t3);
       return sum;
      }
      int queryMin(int l, int r){
       pitem t1,t2,t3;
       split(root, t1, t2, l);
       split(t2, t2, t3, r-l+1);
       int minv= t2->min;
       merge(root, t1, t2);
       merge(root, root, t3);
       return minv;
      }
      int queryMax(int l, int r){
       pitem t1,t2,t3;
       split(root, t1, t2, l);
       split(t2, t2, t3, r-l+1);
       int maxv= t2->max;
       merge(root, t1, t2);
       merge(root, root, t3);
       return maxv;
      }
      int queryKth(int l, int r, int k){
        pitem t1,t2,t3;
        split(root, t1, t2, l);
        split(t2, t2, t3, r-l+1);
        int knum= kth(t2, k);
        merge(root, t1, t2);
        merge(root, root, t3);
        return knum;
      }
      int queryLEQ(int l, int r, int target){
        pitem t1,t2,t3;
        split(root, t1, t2, l);
        split(t2, t2, t3, r-l+1);
        int NL= LEQ(t2, target);
        merge(root, t1, t2);
        merge(root, root, t3);
        return NL;
      }
      void build(vector<int> &A){
        int n=A.size();
        pitem T=NULL;
        for(int i=0; i < n; i++){
           pitem T1=new item(A[i]);
           insert(root, T1, i);
        }
      }
      /*
       *The tree is created by value instead randomly, which can not ensure a blanced tree!!
       * */
      void buildValue(vector<int> &A){
        int n=A.size();
        pitem T=NULL;
        for(int i=0; i < n; i++)
           insert(root, new item(A[i], A[i]), i);
	valueAsPrior=true;
      }

      void output(pitem t){
        if(!t) return;
        push(t);
        output(t->l);
        cout<<t->value<<" ";
        output(t->r);
      }
      void output(){
	output(root);
      }
};
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int N,M;
   vector<int> data;
   while(cin>>N>>M){
      data.assign(N+1, 10000);
      implicitTreap it;
      it.buildValue(data);
      while(M--){
         int Q;
         cin>>Q;
         if(Q==0){
   	   int id, v;
   	   cin>>id>>v;
//	   it.assign(id,id, v);
//	   cout<<"val... "<<v<<endl;
//	   cout<<it.querySum(id,id)<<endl;
	   it.insert(v, id);
//	   cout<<it.querySum(id,id)<<endl;
         }else{
   	   int i, j, b;
   	   cin>>i>>j>>b;
//	   it.output();cout<<endl;
	   cout<<it.queryLEQ(i,j, b)<<endl;
         }
      }
      
   }
   return 0;
}
