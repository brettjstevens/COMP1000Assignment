/* Author: Brett Stevens
File name: LinkedList.c
Purpose: generic linked list
Last modified: 20/10/19
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "logs.h"

LinkedList* createLinkedList()
{
	LinkedList* list;
	
	list = (LinkedList*)malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	
	return list;
}

void insertStart(LinkedList* list, void* entry)
{
	LinkedListNode* newNode;
	
	newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	
	newNode->data = entry;
	
	if(list->head == NULL)
	{
		list->tail = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = list->head;
	}
	
	list->head = newNode;
	
	return;
}

void* removeStart(LinkedList* list)
{
	LinkedListNode* nextNode = NULL;
	void* data = NULL;
	
	if(list->head == NULL)
	{
		printf("List is empty.");
	}
	else
	{
		nextNode = list->head->next;
		data = list->head->data;
        list->head = NULL;
		list->head = nextNode;
	}
	
	return data;
}

void insertLast(LinkedList* list, void* entry)
{
	LinkedListNode* newNode;
	
	newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	
	newNode->data = entry;
	newNode->next = NULL;
	
	if(list->head == NULL)
	{
		list->head = newNode;
	}
	else
	{
		list->tail->next = newNode;
	}
	
	list->tail = newNode;

	return;
}

void* removeLast(LinkedList* list)
{
	LinkedListNode* currNode = NULL;
	LinkedListNode* prevNode = NULL;
	void* data = NULL;
	
	if(list->head == NULL)
	{
		printf("List is empty.");
	}
	else if(list->head->next == NULL)
	{
		data = list->head->data;
		list->head = NULL;
	}
	else
	{
		currNode = list->head;
		
		while(currNode->next != NULL)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}
		
		data = currNode->data;
		free(currNode);
        currNode = NULL;
		list->tail = prevNode;
		list->tail->next = NULL;
	}
	
	return data;
}

void freeLinkedList(LinkedList* list, void (*fptr)(void* ))
{
	LinkedListNode *currNode = NULL, *nextNode = NULL;
    
    currNode = list->head;
    while(currNode != NULL)
    {
        nextNode = currNode->next;
        (*fptr)(currNode->data);
        free(currNode);
        currNode = nextNode;
    }

    free(list);

    return;
}

/*-------------To be used as function pointer-----------------*/
void freeLog(void *data)
{
	free((log*)data);

    return;
}

