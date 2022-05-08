#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 while(cin >>n && n > 0)
 {
    int N = ceil(n/4.0);
    cout << "Printing order for "<<n<<" pages:"<<endl;
    for(int i =1 ;i <=N; i++)
    {
       int f1 = 4*N-2*(i-1), f2 = (2*i)-1, b1 = f2 + 1, b2 = f1 - 1;
       if( f1 <= n || f2 <= n)
	{
            cout << "Sheet "<<i<<", front: ";
            if(f1 > n) cout << "Blank, "; else cout << f1<<", ";
            if(f2 > n) cout << "Blank"; else cout << f2;
            cout <<endl;
	}

       if( b1 <= n || b2 <= n)
       {
          cout << "Sheet "<<i<<", back : ";
          if(b1 > n) cout << "Blank, "; else cout << b1<<", ";
          if(b2 > n) cout << "Blank"; else cout << b2;
          cout <<endl;
       }
    }
 }
}
