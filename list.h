#ifndef LIST_H
#define LIST_H

#include <iostream>

class LinkedList{
	private:
		
		struct node {
			int info;
			node * next;
		};

		typedef node * nodeptr;
		nodeptr start;
    nodeptr end;
		int count;
		
	public:
		
		LinkedList(){
			start = NULL;
      end = start;
			count = 0;
		}

		~LinkedList(){
			nodeptr p = start, n;

			while(p!= NULL){
				n = p;
				p = p->next;
				delete n;
			}
		}
	void AddNode(int x);
	void DeleteNode();
	int FirstNode();
  int LastNode();
	void PrintNodes();
	bool IsInList(int x);
	int Size();
};
#endif
