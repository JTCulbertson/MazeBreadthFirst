/* queue.h */

#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

typedef int QueueItemType;

class Queue
{
  public:
    Queue();

    void Insert( QueueItemType newItem );
    int Delete();

    int GetFront();
    int GetEnd();

    bool IsEmpty();
    void Print();

  private:
    LinkedList L;
};
#endif
