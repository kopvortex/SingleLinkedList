#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

node *head = NULL;
node *tail = NULL;

/* 
 * Insert node to a linked list
 */
void insertNode(int value) {
	node *newNode = new node;
	if (newNode) {
		newNode->data = value;
		newNode->next = NULL;
	}
	if (!head) {
		head = newNode;
		tail = newNode;
	} else {
		tail->next = newNode;
		tail = newNode;
	}
}

/*
 * Print the elements in a linked list
 */
void displayNode(void) {
	if (!head)
		return;
	node *tmpNode = head;
	while (tmpNode) {
		cout<<tmpNode->data<<endl;
		tmpNode = tmpNode->next;
	}
}

/* 
 * Delete a linkedlist
 */
void deleteList(void) {
	if (!head)
		return;
	while (head) {
		node *tmpNode = head;
		head = head->next;
		tmpNode->next = NULL;
		delete tmpNode;
		tmpNode = NULL;
	}
}

/*
 * Reverse a linkedlist recursively
 */
void recReverse (node *tmpNode) {
	if (!tmpNode)
		return;
	node *first = tmpNode;
	node *rest = first->next;
	if (!rest) {
		head = first;
		return;
	}
	recReverse(rest);
	first->next->next = first;
	first->next = NULL;
}

/* 
 * Reverse a linked list iteratively
 */
void itReverse (node *tmpNode) {
	if (!tmpNode) 
		return;
	node *prev = NULL;
	node *cur = tmpNode;
	node *next = NULL;
	while (cur) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	head = prev;
}
/*
 * Detect if there is cycle in a linkedlist
 */
void checkCycle (node *tmpNode) {
   if (!tmpNode) 
	   return;
   node *slowPtr = tmpNode;
   node *fastPtr = tmpNode;
   while (slowPtr && fastPtr && fastPtr->next) {
	   slowPtr = slowPtr->next;
	   fastPtr = fastPtr->next->next;
	   if (slowPtr == fastPtr) {
		   cout<<"\n Cycle detected"<<endl;
		   break;
	   }
   }
}

/* 
 * Display Nth node from end of a linkedlist
 */
void displayNthFromEnd(node *tmpNode, int N) {
	if (!tmpNode || N < 1)
		return;
	int count = 1;
	node *slowNode = tmpNode;
	while (count < N && tmpNode) {
		tmpNode = tmpNode->next;
		count++;
	}
	while (tmpNode && tmpNode->next) {
		slowNode = slowNode->next;
		tmpNode = tmpNode->next;
	}
	cout<<"\n"<<N<<" node from end is "<<slowNode->data<<endl;
}
/* 
 * Return middle element of a linked list
 */
int middleElement (void) {
	if (!head)
		return 0;
	node *tmpNode1= head;
	node *tmpNode2 = head;
	while (tmpNode2 && tmpNode2->next) {
		tmpNode1 = tmpNode1->next;
		tmpNode2 = tmpNode2->next->next;
	}
	return tmpNode1->data;
}

/*
 * Remove Duplicates from a linkedlist 
 */
void removeDuplicate(void) {
	if (!head)
		return;
	node *cur = head;
	node *nex = head;
	node *dup = NULL;
	node *prev = NULL;
	while (cur && cur->next) {
		nex = cur->next;
		prev = cur;
		while (nex) {
			if (cur->data == nex->data) {
				prev->next = nex->next;
				dup = nex;
				nex = nex->next;
				delete dup;
				dup->next = NULL;
			} else {
				prev = nex;
				nex = nex->next;
			}
		}
		cur = cur->next;
	}
}

int main() {
	insertNode(10);
	insertNode(12);
	cout<<"\n Middle element "<<middleElement()<<endl;
	insertNode(10);
	insertNode(11);
	insertNode(12);
	insertNode(11);
	insertNode(12);
	displayNode();
	itReverse(head);
	displayNode();
	recReverse(head);
	displayNode();
	checkCycle(head);
	displayNthFromEnd(head, 2);
	removeDuplicate();
	displayNode();
	return 0;
}
