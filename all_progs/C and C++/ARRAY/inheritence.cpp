#include <iostream>
using namespace std;

class B 
{
public:
   void fun() { cout << "B::fun() "; }
};
  
class C: public B
{
public:
   void fun() { cout << "C::fun() "; }
};
  
int main()
{
     C *bp = new C;
    bp->fun();
    return 0;
}
