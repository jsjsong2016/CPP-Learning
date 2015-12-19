#include<iostream>
#include<time.h>
using namespace std;
class Base {
public:
    int k;
    Base(int n):k(n) { }
};
class Big  {
public:
    int v; Base b;
    Big(int n):v(n),b(n){};
    Big(Big const& m):v(m.v),b(m.b){};
};
int main()
{
   clock_t start,finish;
   double totaltime;
   start=clock();
   Big a1(5);    Big a2 = a1;
   cout << a1.v << "," << a1.b.k << endl;
   cout << a2.v << "," << a2.b.k << endl;
//把你的程序代码插入到这里面
   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<endl;
}
