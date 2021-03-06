#include <string>
#include <iostream>
#include<stdlib.h>
#include <stdafx.h>



using namespace std;
struct student
{
	int ID;
	char Firstname[20];
	char Fathername[20];
	char Family[20];
	char EGN[10];
	student* next;
}*start = NULL, *p;


void add()
{
	p = start;
	start = new student;
	cout << "Firstname:" << endl;
	cin >> start->Firstname;
	cout << "Fathername:" << endl;;
	cin >> start->Fathername;
	cout << "Family:" << endl;;
	cin >> start->Family;
	cout << "EGN:" << endl;
	cin >> start->EGN;
	cout << "ID" << endl;
	cin >> start->ID;
	start->next = p;

}

void list()
{
	student *p = start;
	while (p != NULL)
	{
		cout << "#" << p->ID << " " << p->Firstname << " " << p->Fathername << " " << p->Family << " " << p->EGN << endl;
		p = p->next;
	}
}

void search()
{
	student *p = start;
	char key[10];
	cout << "Enter key to find: " << endl;
	cin >> key;
	while (p != NULL)
	{
		if (strstr(p->Firstname, key))
			p = p->next;
		else
		{
			cout << "#" << p->ID << " " << p->Firstname << " " << p->Fathername << " " << p->Family << " " << p->EGN << endl;
			p = p->next;
		}
	}

}

//Bubble sort
void sort()
{
	student *lst, *tmp = start, *prev, *pprev = start;
	char a;
	char b;
	int n = 0;
	student* p = start;
	while (p != NULL)
	{
		n++;
		p = p->next;
	}

	for (a = 0; a<n - 1; a++)
	{
		for (b = 0, lst = start; lst && lst->next && (b <= n - 1 - a); b++)
		{
			if (!b == NULL)
			{
				prev = lst;
			}
			if (strcmp(lst->Firstname, lst->next->Firstname) && strcmp(lst->Family, lst->next->Family) == 1)
			{
				tmp = (lst->next ? lst->next->next : 0);
				if (!b && (prev == start))
				{
					start = lst->next;
				}
				pprev = lst->next;
				prev->next = lst->next;
				lst->next->next = lst;
				lst->next = tmp;
				prev = pprev;
			}
			else
			{
				lst = lst->next;
				if (b)
				{
					prev = prev->next;
				}
			}
		}
	}

	list();
}

int main()
{

	int choice;

	do {

		cout << "\n =============================================";

		cout << "\n1.Add\n2.View\n3.Search\n";

		cout << "4.Sort\n5.Exit\n";

		cout << "\n =============================================";

		cout << "\nChoice:";

		cin >> choice;

		switch (choice)
		{
		case 1: add(); break;
		case 2: list(); break;
		case 3: search(); break;
		case 4: sort(); break;
		}

	} while (choice != 5);
	return 0;
}