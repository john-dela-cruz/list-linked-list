#include<iostream>
#include<malloc.h>

using namespace std;

struct NODE
{
	int value;
	NODE *next;
};

int listEmpty(NODE *p)
{
	if(p == NULL)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void addNode(NODE **ptrStart, int data)
{
	NODE *ptr1, *ptr2;
	ptr1 = (NODE*)malloc(sizeof(NODE));
	ptr1 -> value = data;
	ptr1 -> next = NULL;
	
	if(*ptrStart == NULL)
	{
		*ptrStart = ptr1;
	}
	else
	{
		ptr2 = *ptrStart;
		while(ptr2->next != NULL)
		{
			ptr2 = ptr2 -> next;
		}
		ptr2 -> next = ptr1;
	}
	cout << "Item Successfully Added!" << endl << endl;
}

void deleteNode(NODE **ptrStart, int deleteData)
{
	NODE *discard, *before;
	
	discard = *ptrStart;
	
	if(listEmpty(*ptrStart) == 1)
	{
		cout << "The List is Empty!" << endl;
	}
	else
	{
		if((*ptrStart) -> value == deleteData)
		{
			*ptrStart = (*ptrStart) -> next;
			free(discard);
			
			cout << "Item Successfully Deleted!" << endl;
		}
		else
		{
			while(discard != NULL && discard -> value != deleteData)
			{
				before = discard;
				discard = discard -> next;
			}
			
			if(discard == NULL)
			{
				cout << "Node to be deleted does not Exist!" << endl;
			}
			else
			{
				before -> next = discard -> next;
				free(discard);
				cout << "Item Successfully Deleted!" << endl;
			}
		}
	}
}

void locateNode(NODE *p, int searchData)
{
	int counter;
	
	if(listEmpty(p) == 1)
	{
		cout << "The List is Empty!" << endl;
	}
	else
	{
		counter = 1;
		
		while(p != NULL && p -> value != searchData)
		{
			p = p -> next;
			counter++;
		}
		if(p != NULL)
		{
			cout << "Node requested is Node " << counter << "." << endl;
		}
		else
		{
			cout << "Node does not exist." << endl;
		}
	}
}

int countNodes(NODE *p)
{
	int counter;
	
	counter = 0;
	while(p != NULL)
	{
		counter++;
		p = p -> next;
	}
	
	return(counter);
}

void printNodes(NODE *p)
{
	int counter;
	
	if(listEmpty(p) == 1)
	{
		cout << "The List is Empty!" << endl;
	}
	else
	{
		counter = 1;
		while(p != NULL)
		{
			cout << "The value of node " << counter << " is " << p->value << "." << endl;
			counter++;
			p = p-> next;   
		}
	}
}

main()
{
	NODE *start, *ptr1, *ptr2;
	int data, choice, counter, searchData, deleteData;
	
	start = ptr1 = ptr2 = NULL;
	
	while(choice != 5)
	{
		cout << "There are currently " << counter << " items in the list." << endl;
		cout << "Options: " << endl << endl;
		cout << "1. Add Item to the List" << endl;
		cout << "2. Delete Item from the List" << endl;
		cout << "3. Locate Item in the List" << endl;
		cout << "4. Print Items in the List" << endl;
		cout << "5. Exit Program" << endl << endl;
		
		cout << "Enter the number of your choice: ";
		cin >> choice;
		cout << endl;
		
		if(choice == 1)
		{
			cout << "Add Item to the List" << endl;
			cout << "Enter the item to be added: ";
			cin >> data;
			
			addNode(&start, data);
			cout << endl;
		}
		else if(choice == 2)
		{
			cout << "Delete Item from the List" << endl;
			cout << "Enter the item to be deleted: ";
			cin >> deleteData;
			
			deleteNode(&start, deleteData);
			cout << endl;
		}
		else if(choice == 3)
		{
			cout << "Locate Item in the List" << endl;
			cout << "Enter the item to be searched: ";
			cin >> searchData;
			
			locateNode(start, searchData);
			cout << endl;
		}
		else if(choice == 4)
		{
			printNodes(start);
			cout << endl;
		}
		else if(choice == 5)
		{
			cout << "Exiting Program..." << endl;
		}
		else
		{
			cout << "Input Error!" << endl;
		}
		
		counter = countNodes(start);
	}
}
