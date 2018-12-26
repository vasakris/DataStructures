#include <iostream>

using namespace std;

struct data
{
	int value;
	data *next;
};

class linkedList
{
	data *head;
	data *current;

 public:
	linkedList()
	{
		head = current = NULL;
	}

	void addElementBack(int value)
	{
		data *s = new data();
		s->value = value;

		if (NULL == head)
		{
			head = s;
		}
		else
		{
			current->next = s;
		}
		s->next = NULL;
		current = s;
	}

	void addElementFront(int value)
	{
		data *s = new data();
		s->value = value;
		s->next = head;
		head = s;
	}

	void display()
	{
		data *temp = head;
		cout << "List: ";
		while (temp)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void remove(int value)
	{
		data *temp = head;
		data *prev = NULL;

		while (temp)
		{
			if (temp->value == value)
			{
				if (prev == NULL)
				{
					head = temp->next;
				}
				else
				{
					prev->next = temp->next;
				}
				delete temp;
				break;
			}
			prev = temp;
			temp = temp->next;
		}
	}

	void removeDuplicates()
	{
		data *temp = head;

		while (temp)
		{
			data *temp1 = temp->next;
			data *prev = temp;

			while (temp1)
			{
				if (temp->value == temp1->value)
				{
					prev->next = temp1->next;
					delete temp1;
					temp1 = prev->next;
				}
				else
				{
					prev = temp1;
					temp1 = temp1->next;
				}
			}
			temp = temp->next;
		}
	}

	void reverse()
	{
		data *temp = head;
		data *prev = NULL;
		data *next = head;

		while (temp)
		{
			next = temp->next;
			temp->next = prev;
			prev = temp;
			temp = next;
		}
		head = prev;
	}

	void reverse(data *node)
	{
		if (node->next == NULL)
		{
			head = node;
			return;
		}

		reverse(node->next);
		node->next->next = node;
		node->next = NULL;
	}

	data *reverse(data *node, int k)
	{
		if (node == NULL)
		{
			return NULL;
		}

		data *current = node;
		data *prev = node;
		data *next = NULL;

		int j = k;
		while (current && j > 0)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
			j--;
		}

		node->next = reverse(current, k);
		head = prev;
		return prev;
	}

	data *getHead()
	{
		return head;
	}
};