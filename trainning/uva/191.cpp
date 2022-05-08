#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;
struct point
{
   double x, y;
   point(){x=y=0;}
   point(int _x, int _y):x(_x), y(_y){}
};
struct line
{
  double a,b,c;
  point p1, p2;
  bool ispoint;
  line(){}
  line(point _p1, point _p2)
  {
    p1 = _p1, p2 = _p2;
    if(fabs(p1.x-p2.x) < EPS) a = 1.0, b=0.0, c=-p1.x;
    else a = -(double)(p1.y-p2.y)/(p1.x-p2.x), b = 1.0, c = -(double)(a*p1.x) - p1.y;
  }
};
bool isInRectangle( point p, point &t1, point &b2)
{
  return ( p.x>= min(t1.x,b2.x)  && p.x <= max(b2.x, t1.x) && p.y >= min(b2.y, t1.y) && p.y<=max(t1.y, b2.y));
}
bool inter(line &l1, line &l2, point &p)//intersection between segments.
{
  if (fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS) return false;
  p.x = (l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b);

  if( fabs(l1.b)>EPS) p.y = -(l1.a*p.x + l1.c);
  else p.y = -(l2.a*p.x+l2.c);
  return true;
}
bool inSegment(point &a, point &b, point &p)
{
   double ap = sqrt((a.x-p.x)*(a.x-p.x) + (a.y-p.y)*(a.y-p.y));
   double bp = sqrt((b.x-p.x)*(b.x-p.x) + (b.y-p.y)*(b.y-p.y));
   double ab = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
   return (ap <= ab && bp <= ab);
}
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
   point s, e, t1, t2, b1, b2, p;
   cin >>s.x>>s.y>>e.x>>e.y>>t1.x>>t1.y>>b2.x>>b2.y;
   t2.x = b2.x, t2.y=t1.y;
   b1.x = t1.x, b1.y=b2.y;

    if(isInRectangle(s, t1, b2) || isInRectangle(e, t1, b2)){cout << "T"<<endl; continue;} //check if endpoints are inside
    line l(s,e), l1(t1, t2), l2(t2, b2), l3(b2, b1), l4(b1, t1);   
    //collinear checking
    bool f = false;
    f |= (fabs(l.a-l1.a)<EPS && fabs(l.b-l1.b)<EPS && fabs(l.c-l1.c)<EPS && (inSegment(s, e, t1) || inSegment(s, e, t2)));
    f |= (fabs(l.a-l2.a)<EPS && fabs(l.b-l2.b)<EPS && fabs(l.c-l2.c)<EPS && (inSegment(s, e, t2) || inSegment(s, e, b2)));
    f |= (fabs(l.a-l3.a)<EPS && fabs(l.b-l3.b)<EPS && fabs(l.c-l3.c)<EPS && (inSegment(s, e, b2) || inSegment(s, e, b1)));
    f |= (fabs(l.a-l4.a)<EPS && fabs(l.b-l4.b)<EPS && fabs(l.c-l4.c)<EPS && (inSegment(s, e, b1) || inSegment(s, e, t1)));
     f |= (inter(l, l1, p) && inSegment(t1, t2, p) && inSegment(s, e, p) );
     f |= (inter(l, l2, p) && inSegment(t2, b2, p) && inSegment(s, e, p) );
     f |= (inter(l, l3, p) && inSegment(b2, b1, p) && inSegment(s, e, p) );
     f |= (inter(l, l4, p) && inSegment(b1, t1, p) && inSegment(s, e, p) );
    if(f)cout <<"T\n";else cout <<"F\n";
  }
  return 0;
}
