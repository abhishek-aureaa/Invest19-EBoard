#include <stdio.h>
#include <iostream>
#include <string.h>

struct Node {
	struct Node* next;
	char* value;
};

struct manifesto {
	struct manifesto* next;
	char* contender;
	char* manifesto;
	char* idea1;
	char* idea2;
	char* idea3;
};

struct idea {
	struct idea* next;
	char* idea;
	char* contender;
	char* citizen;
	int rating;
};

class contenders {

	struct Node* head;
	struct manifesto* headManifesto;
	struct idea* headIdea;

public:
	contenders()
	{
		head = NULL;
		headManifesto = NULL;
		headIdea = NULL;
	}
        int nominate(const char* value)
        {
                struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
                temp->value = (char*)value;

                if (head == NULL)
                {
                        head = temp;
                        head->next = NULL;
                        return 1;
                }
                else
                {
                        temp->next = head;
                        head = temp;
                        return 1;
                }
                return 0;
        }


	int manifesto(const char* contender, const char* manifesto, const char* idea1, const char* idea2, const char* idea3)
	{
		struct manifesto* temp = (struct manifesto*) malloc(sizeof(struct manifesto));
		temp->contender = (char*)contender;
		temp->manifesto = (char*)manifesto;
		temp->idea1 = (char*)idea1;
		temp->idea2 = (char*)idea2;
		temp->idea3 = (char*)idea3;

		if (headManifesto == NULL)
		{
			headManifesto = temp;
			headManifesto->next = NULL;
                        return 1;
		}
		else
		{
			temp->next = headManifesto;
			headManifesto = temp;
                        return 1;
		}
                return 0;
	}
 
	int rateIdea(char* idea, char* contender, char* citizen, int rating)
	{
		struct idea* temp = (struct idea*) malloc(sizeof(struct idea));
		temp->idea = (char*)idea;
		temp->contender = (char*)contender;
		temp->citizen = (char*)citizen;
		temp->rating = rating;

		if (headIdea == NULL)
		{
			headIdea = temp;
			headIdea->next = NULL;
                        return 1;
		}
		else
		{
			temp->next = headIdea;
			headIdea = temp;
                        return 1;
		}
                return 0;
	}

	int deleteRating(char* idea, char* contender, char* citizen)
	{
		if (headIdea == NULL)
			return 0;

		struct idea* temp = NULL;
		if ((!strcmp(headIdea->idea, idea)) && (!strcmp(headIdea->contender, contender)) && (!strcmp(headIdea->citizen, citizen)))
		{
			temp = headIdea;
			headIdea = headIdea->next;

			/*important to avoid memory leakage*/
			free(temp);
                        return 1;
		}

		struct idea* prev = headIdea;
		if (headIdea->next != NULL)
			temp = headIdea->next;
		while (temp != NULL)
		{
			if ((!strcmp(temp->idea, idea)) && (!strcmp(temp->contender, contender)) && (!strcmp(temp->citizen, citizen)))
			{
				prev->next = temp->next;

				/*important to avoid memory leakage*/
				free(temp);
                        	return 1;
			}
			if (temp->next != NULL)
				temp = temp->next;
		}
              	return 0;
	}

	int listRatings()
	{
		if (headIdea == NULL)
		{
			printf("No rating in the record\n");
			return 0;
		}
		struct idea* temp = headIdea;
		printf("****************************************************\n");
		printf("IDEA         CONTENDER         CITIZEN        RATING\n");
		printf("****************************************************\n");
		while (temp->next != NULL)
		{
			printf(temp->idea);
			printf("            ");
			printf(temp->contender);
			printf("            ");
			printf(temp->citizen);
			printf("            ");
			printf("%d", temp->rating);
			printf("\n");
			if (temp->next != NULL)
				temp = temp->next;
		}
		printf(temp->idea);
		printf("            ");
		printf(temp->contender);
		printf("            ");
		printf(temp->citizen);
		printf("            ");
		printf("%d", temp->rating);
		printf("\n");
		printf("****************************************************\n");
              	return 1;
	}

	int listcontenders()
	{
		if (head == NULL)
		{
			printf("No contenders in the record\n");
			return 0;
		}
		struct Node* temp = head;
		printf("*******************\n");
		printf("CONTENDERS         \n");
		printf("*******************\n");
		while (temp->next != NULL)
		{
			printf(temp->value);
			printf("\n");
			if (temp->next != NULL)
				temp = temp->next;
		}
		printf(temp->value);
		printf("\n");
		printf("*********************\n");
              	return 1;
	}
	int listmanifesto()
	{
		if (headManifesto == NULL)
		{
			printf("No Manifesto in the record\n");
			return 0;
		}
		struct manifesto* temp = headManifesto;
		printf("********************************************************************************\n");
		printf("CONTENDER             MANIFESTO           IDEA1            IDEA2          IDEA3\n");
		printf("********************************************************************************\n");
		while (temp->next != NULL)
		{
			printf(temp->contender);
			printf("            ");
			printf(temp->manifesto);
			printf("            ");
			printf(temp->idea1);
			printf("            ");
			printf(temp->idea2);
			printf("            ");
			printf(temp->idea3);
			printf("\n");
			if (temp->next != NULL)
				temp = temp->next;
		}
		printf(temp->contender);
		printf("            ");
		printf(temp->manifesto);
		printf("            ");
		printf(temp->idea1);
		printf("            ");
		printf(temp->idea2);
		printf("            ");
		printf(temp->idea3);
		printf("\n");
		printf("********************************************************************************\n");
              	return 1;
	}

};
