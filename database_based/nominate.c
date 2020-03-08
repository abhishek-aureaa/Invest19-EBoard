#include <stdio.h>
#include <iostream>
struct Node {
	struct Node* next;
 	char* value;
};

class contenders {

	struct Node* head;

public :
	void nominate(char* value)
	{
		struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
		temp->value = value;

		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
	}
};


int main(int argc, char **argv)
{
	nominate("abhishek");
	nominate("anuj");
}
