#include <iostream>
using namespace std;
 
class B;
class A {
    int a;
public:
    A():a(0) { }
    void show(A& x, B& y);
};
 
class B {
private:
    int b;
public:
    B():b(0) { }
    friend void A::show(A& x, B& y);
};
 
void A::show(A& x, B& y) {
    x.a = 10;
    y.b=5;
    cout << "A::a=" << x.a << " B::b=" << y.b;
}
 
int main() {
    A a;
    B b;
    a.show(a,b);
    return 0;
}
