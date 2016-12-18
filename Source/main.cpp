#include <iostream>
#include <string>
#include "Omniscient/DelegateMemberFunction.hpp"
#include "Omniscient/EventSystem.hpp"
#include "Omniscient/ObjectEventManager.hpp"

#define ENABLE_DEBUG_PRINT
#ifdef ENABLE_DEBUG_PRINT
  #define D_PRINT(v) do{ std::cout << #v << " : " << v << '\n'; } while (0)
#else
  #define D_PRINT(v)
#endif
static OEvent::EventSystem es;

class TestEvent : public OEvent::OEvent
{
public:
  TestEvent(const std::string msg) : Message(msg) { }
  const std::string Message;
  friend std::ostream &operator<<(std::ostream &os, const TestEvent &rhs)
  {
    os << rhs.Message;
    return os;
  }
};

class MyObj : public OEvent::ObjectEventManager
{
public:
  MyObj();
  void MyFunction(TestEvent *e);
};

void MyObj::MyFunction(TestEvent *function_argument)
{
  D_PRINT(*function_argument);
}

MyObj::MyObj() : ObjectEventManager(es)
{
  Connect(this, &MyObj::MyFunction);
  Connect(this, &MyObj::MyFunction);
}


int main(int argc, char **argv)
{
  {
    MyObj m;
    D_PRINT(es.Dispatch(new TestEvent("object should exist")));
  }
  D_PRINT(es.Dispatch(new TestEvent("no object exists")));
  return 0;
}

