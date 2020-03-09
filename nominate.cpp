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

struct follower {
	struct follower* next;
	char* contender;
	char* follower;
};

class contenders {

	struct Node* head;
	struct manifesto* headManifesto;
	struct idea* headIdea;
	struct follower* headContender;

public:
	contenders()
	{
		head = NULL;
		headManifesto = NULL;
		headIdea = NULL;
		headContender = NULL;
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
			//Point num 7 : Anytime a contender posts an idea, an email should be sent out
			MailToContender(temp->contender);
			return 1;
		}
		else
		{
			temp->next = headManifesto;
			headManifesto = temp;
			//Point num 7 : Anytime a contender posts an idea, an email should be sent out
			MailToContender(temp->contender);
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

		//citizen added as follower 
		if (rating > 5)
			addFollower(contender, citizen);

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

		struct idea* temp1 = NULL;
		//if ((!strcmp(headIdea->idea, idea)) && (!strcmp(headIdea->contender, contender)) && (!strcmp(headIdea->citizen, citizen)))
		{
			temp1 = headIdea;
			headIdea = headIdea->next;

			/*important to avoid memory leakage*/
			free(temp1);
			return 1;
		}

		struct idea* prev = headIdea;
		if (headIdea->next != NULL)
			temp1 = headIdea->next;
		while (temp1 != NULL)
		{
			//if ((!strcmp(temp1->idea, idea)) && (!strcmp(temp1->contender, contender)) && (!strcmp(temp1->citizen, citizen)))
			{
				prev->next = temp1->next;

				/*important to avoid memory leakage*/
				free(temp1);
				return 1;
			}
			if (temp1->next != NULL)
				temp1 = temp1->next;
		}
		return 0;
	}

	int addFollower(const char* contender, const char* follower)
	{
		struct follower* temp = (struct follower*) malloc(sizeof(struct follower));
		temp->contender = (char*)contender;
		temp->follower = (char*)follower;

		if (headContender == NULL)
		{
			headContender = temp;
			headContender->next = NULL;
			return 1;
		}
		else
		{
			temp->next = headContender;
			headContender = temp;
			return 1;
		}
		return 0;
	}

	int listFollowersForContender(char* contender)
	{
		int num_follower = 0;
		if (headContender == NULL)
		{
			printf("No follower for contender : %s\n", contender);
			return 0;
		}
		struct follower* temp = headContender;
		printf("****************************************************\n");
		printf("Follower for Contender '%s' , are : \n", contender);
		printf("****************************************************\n");
		while (temp->next != NULL)
		{
			if (!strcmp(temp->contender, contender))
			{
				printf(temp->follower);
				printf("\n");

				num_follower++;
			}
			if (temp->next != NULL)
				temp = temp->next;
		}
		if (!strcmp(temp->contender, contender))
		{
			printf(temp->follower);
			printf("\n");

			num_follower++;
		}

		if (num_follower == 0)
			return 0;

		return 1;
	}

	//Point num 7 : Anytime a contender posts an idea, an email should be sent out
	int MailToContender(char* contender)
	{
		int num_follower = 0;
		if (headContender == NULL)
		{
			printf("No follower for contender : %s, So No email\n", contender);
			return 0;
		}
		struct follower* temp = headContender;
		printf("   \n");
		printf("   \n");
		printf("****************************************************\n");
		while (temp->next != NULL)
		{
			if (!strcmp(temp->contender, contender))
			{
				printf("Follower for Contender '%s' , is : ", contender);
				printf(temp->follower);

				printf(" , Email will be sent to him");
				printf("\n");
				MailToContender(temp->follower);

				num_follower++;
			}
			if (temp->next != NULL)
				temp = temp->next;
		}
		if (!strcmp(temp->contender, contender))
		{
			printf("Follower for Contender '%s' , is : ", contender);
			printf(temp->follower);

			printf(" , Email will be sent to him");
			printf("\n");
			MailToContender(temp->follower);

			num_follower++;
		}

		if (num_follower == 0)
			return 0;

		return 1;
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

	int postAnIdea(char* contender, char* idea)
	{
		if (headManifesto == NULL)
		{
			printf("No Manifesto for contender : %s, hence can not post an idea\n", contender);
			return 0;
		}

		struct manifesto* temp = headManifesto;
		while (temp->next != NULL)
		{
			/*if any of the 3 ideas are blank, post the idea there*/
			if (!strcmp(temp->contender, contender))
			{
				if (!strcmp(temp->idea1, ""))
				{
					temp->idea1 = idea;
				}
				else
					if (!strcmp(temp->idea2, ""))
					{
						temp->idea2 = idea;
					}
					else
						if (!strcmp(temp->idea3, ""))
						{
							temp->idea3 = idea;
						}
				//if none of the ideas are blank, clean idea1 and post the new idea there
						else
						{
							//Will avoid memory leak;
							free(temp->idea1);
							temp->idea1 = idea;
						}
				//Send email to followers and their followers further
				MailToContender(temp->contender);
			}
			if (temp->next != NULL)
				temp = temp->next;
		}

		if (!strcmp(temp->contender, contender))
		{
			if (!strcmp(temp->idea1, ""))
			{
				temp->idea1 = idea;
			}
			else
				if (!strcmp(temp->idea2, ""))
				{
					temp->idea2 = idea;
				}
				else
					if (!strcmp(temp->idea3, ""))
					{
						temp->idea3 = idea;
					}
			//if none of the ideas are blank, clean idea1 and post the new idea there
					else
					{
						//Will avoid memory leak;
						//free(temp->idea1);
						temp->idea1 = idea;
					}
			//Send email to followers and their followers further
			MailToContender(temp->contender);
		}
		else
		{
			printf("No Manifesto for contender : %s, hence can not post an idea\n", contender);
			return 0;
		}
		return 1;

	}

};
