#ifndef LINKEDLIST_H
#define LINKEDLIST_H	
	typedef struct LinkedListNode
	{
		void* data;
		struct LinkedListNode* next;
	}LinkedListNode;
	
	typedef struct
	{
		LinkedListNode* head;
		LinkedListNode* tail;
	}LinkedList;
	
	LinkedList* createLinkedList();
	void insertStart(LinkedList* list, void* entry);
	void* removeStart(LinkedList* list);
	void insertLast(LinkedList* list, void* entry);
	void* removeLast(LinkedList* list);
	void printLinkedList(LinkedList* list, void (*fptr)(void* ));
	void freeLinkedList(LinkedList* list, void (*fptr)(void* ));

    void (*fptr)(void* );
	void printLog(void* data);
	void freeLog(void *data);
#endif
