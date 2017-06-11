#include <iostream>

using namespace std;

//Structures
struct List
{
	int value;
	List* next;
};

//Functions declarations
void initialization(List*, int, int*);
void print(List*);
void insertf_begin(List**, int);
void free(List**);

int main()
{
	List* begin = new List;
	
	begin -> value = 0;
	
	int values[5] = {10, 21, 32, 48, 56};
	
	initialization(begin, 5, values);
	print(begin);
	insertf_begin(&begin, -5);
	print(begin);
	
	free(&begin);
	cin.sync();
	cin.get();
	return 0;
}

//Functions definitions
void initialization(List* begin, int length, int* values)
{
	
	List *end = begin;
	
	for (int i = 0; i < length; i++)
	{
		end -> next = new List;
		end = end -> next;
		end -> value = values[i];
	}
	
	end -> next = NULL;
}

void print(List* begin)
{
	List* printed = begin;
	
	while (printed)
	{
		cout << printed -> value << " => ";
		printed = printed -> next;
	}
	
	cout << "NULL" << endl;
	
}

void free(List** begin)
{
	if (*begin == 0)
		return;
	
	List* temp, * current = *begin;
	
	while (current)
	{
		temp = current;
		current = current -> next;
		delete temp;
	}
	*begin = NULL;
}

void insertf_begin(List** begin, int value)
{
	List* item = new List;
	
	item -> value = value;
	item -> next = *begin;
	
	*begin = item;
}

