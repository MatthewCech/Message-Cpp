#include <iostream>
#include "Omniscient/DelegateMemberFunction.hpp"


class MyObj
{
public:
  MyObj();
  void MyFunction(OEvent::OEvent *e);
};

void MyObj::MyFunction(OEvent::OEvent *e)
{
  std::printf("My function was called!\n");
}

MyObj::MyObj()
{
  OEvent::OEvent e;
  auto a = OEvent::DelegateMemberFunction<MyObj, OEvent::OEvent>(&MyObj::MyFunction, this);
  a.Call(&e);
}




int main(int argc, char **argv)
{
  MyObj m;
  return 0;
}

