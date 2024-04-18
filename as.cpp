#include<iostream>


using namespace std;

class Node
{
	public:
		int data;
		Node* next;
		Node* prev;
		Node()
		{
			data = 0;
			next = NULL;
			prev = NULL;
		}
		Node(int data)
		{
			this->data = data;
			next = NULL;
			prev = NULL;
		}
};

class dlinked
{
	public:
		Node* Head;
		Node* tail;
		dlinked()
		{
			Head = NULL;
			tail = NULL;
		}
		void addstart(int data) // Not making code to remove from linked
		{
			if(Head == NULL)
			{
				Node* temp;
			    temp = new Node(data);
			    Head = temp;
			    tail = temp;
			}
			else
			{
			   	Node* temp;
			    temp = new Node(data);
			    temp->next = Head;
			    Head->prev = temp;
			    Head = temp;
			}
		}
		void print()
		{
			Node* temp = Head;
			while(temp != NULL)
			{
				cout << temp->data << endl;
				temp = temp->next;
			}
		}
		void printfa()
		{
			Node* temp = tail;
			while(temp != NULL)
			{
				cout << temp->data << endl;
				temp = temp->prev;
			}
		}
	
};

dlinked* addtwolinked(Node* h1,Node* h2)
{
	Node* temp;
	temp = h1;
	Node* temp1;
	temp1 = h2;
	dlinked* temp2;
	temp2 = new dlinked();
	int data1 = 0;
	while(temp != NULL && temp1 != NULL)
	{
		int data = 0;
		data = temp->data + temp1->data + data1;
		if( data > 9)
		{
			data1 = data - (data%10);
			data1 = data1/10;
			data = data%10;
			temp2->addstart(data);
		}
		else
		{
			temp2->addstart(data);
			data1 = 0;
		}
		temp = temp->prev;
		temp1= temp1->prev;
	}
	while(temp != NULL)
	{
		temp2->addstart(temp->data);
        temp = temp->prev;
	}
	while(temp1 != NULL)
	{
		temp2->addstart(temp1->data);
        temp1 = temp1->prev;
	}
	return temp2;
}

// Node* deleter(Node* h1,Node* h2,Node* t1,int num)
// {
// 	if(t1 == NULL)
// 	{
// 		return t1;
// 	}
// 	bool flag = false;
// 	Node* temp = h1;
// 	Node* temp1 = h2;
// 	Node* temp2 = t1;
// 	while( flag == false && temp != NULL)
// 	{
// 		if(num == temp->data)
// 		{
// 			flag = true;
// 		}
// 		temp = temp->next;
// 	}
// 	while( flag == false && temp1 != NULL)
// 	{
// 		if(num == temp1->data)
// 		{
// 			flag = true;
// 		}
// 		temp1 = temp1->next;
// 	}
// 	if(flag == true)
// 	{
// 		temp2->prev->next = temp2->next;
// 		temp2->next->prev = temp2->prev;
// 	}
// 	t1 = deleter(h1,h2,temp->next,num+1);
// }

int main()
{
	dlinked* l1;
	l1 = new dlinked;
	l1->addstart(5);
	l1->addstart(6);
	l1->addstart(6);
	// l1->addstart(4);
	// l1->addstart(3);
	
	dlinked* l2;
	l2 = new dlinked;
	l2->addstart(6);
	l2->addstart(7);
	l2->addstart(7);
	
	dlinked* l3;
	l3 = addtwolinked(l1->tail,l2->tail);
// //	l1->Head = deleter(l3->Head,l2->Head,l1->Head,0);
 	l3->print();
	return 0;
}