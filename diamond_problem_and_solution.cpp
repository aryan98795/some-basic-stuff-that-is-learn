//Diamond problem
//jab do base class same parent se inherit kare aur phr ek child class dono classes ko inherit kare 
//code 
#include<bits/stdc++.h>
using namspace std;

class A
{
  public: 
    void show(){ cout<<"A"; }
}

class B :public A {};
class C :public A {};
class D :public B,public C {};

int main()
{
  D obj;
  obj.show()//ambigous gives error . compiler ko aisa lagega ki do objects hai A type ke 
  obj.B::show()//correct possible solution 
  //solution using virtual key word
  // class B : virtual public A {};
  // class C : virtual public A {};
  // now obj.show() will work
}
