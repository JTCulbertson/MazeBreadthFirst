/* queue.cpp */
#include "list.h"
#include "queue.h"

Queue::Queue()
{
}

void Queue::Insert( QueueItemType newItem ){
  L.AddNode( newItem );
} 

int Queue::Delete()
{
  int iVal;

  iVal = L.FirstNode();
  L.DeleteNode();

  return iVal;
}

int Queue::GetFront()
{
  return L.FirstNode();
}

int Queue::GetEnd()
{
  return L.LastNode();
}

bool Queue::IsEmpty()
{
  int length = L.Size();
  return bool(length == 0 );
}

void Queue::Print()
{
  L.PrintNodes();
}

