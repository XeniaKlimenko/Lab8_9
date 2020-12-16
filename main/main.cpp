#include <iostream>
#include "QueueList.h"
#include "StackList.h"
#include "List.h"

int main()
{
  TStackList<int> s;
  s.Push(10);
  s.Push(11);

  std::cout<< s.Get() << "\n\n";

  TQueueList<int> q;
  q.Push(10);
  q.Push(11);

  std::cout << q.Get() << "\n\n";
  return 0;
}
