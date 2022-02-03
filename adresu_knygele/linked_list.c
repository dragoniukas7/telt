#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#define DELIMETER ","

void load_addresses(FILE *file, struct Person **list)
{
	char line[128];
	while (fgets(line, sizeof(line), file))
	{
		struct Person *person = NULL;
		if (strcmp(line, "\n") == 0)
		{
			continue;
		}
		strtok(line, "\n");
		person = create_address_node(line);
		if (person != NULL)
		{
			add_to_list(list, person);
		}
	}
}

struct Person* create_address_node(char *address_line)
{
	struct Person *person = NULL;
	char *name;
	char *surname;
	char *email;
	char *number;

	name = strtok(address_line, DELIMETER);
	surname = strtok(NULL, DELIMETER);
	email = strtok(NULL, DELIMETER);
	number = strtok(NULL, DELIMETER);

	person = create_node(name, surname, email, number);

	return person;
}

struct Person* create_node(char *name, char *surname, char *email, char *number)
{
	struct Person *person = NULL;
	person = (struct Person *) malloc(sizeof(struct Person));
	if (person == NULL)
	{
		return NULL;
	}
	strncpy(person->name, name, sizeof(person->name));
	strncpy(person->surname, surname, sizeof(person->surname));
	strncpy(person->email, number, sizeof(person->email));
	strncpy(person->number, email, sizeof(person->number));
	person->next = NULL;
	return person;
}

void add_to_list(struct Person **list, struct Person *person)
{
	struct Person *temp = *list;
	if (temp == NULL)
	{
		*list = person;
		return;
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = person;
}

int add_to_list_at(struct Person **list, struct Person *person, int *pos)
{
	struct Person *temp = *list;
	if (*pos < 1) return 1;
	if (temp == NULL)
	{
		*list = person;
		return 1;
	}

	for (int i = 1; i<*pos - 1; i++)
	{
		if (temp->next == NULL)
		{
			return 1;
		}
		temp = temp->next;
	}

	person->next = temp->next;
	temp->next = person;
	return 0;
}

void print_list_num(struct Person *list, int num)
{
	struct Person *temp = list;
	int i = 0;

	printf("Adresatų sąrašas:\n");
	while (temp != NULL && i++<num)
	{
		printf("%s %s %s %s\n", temp->name, temp->surname, temp->number, temp->email);
		temp = temp->next;
	}
}

void print_list(struct Person *list)
{
	struct Person *temp = list;

	printf("Adresatų sąrašas:\n");
	while (temp != NULL)
	{
		printf("%s %s %s %s\n", temp->name, temp->surname, temp->number, temp->email);
		temp = temp->next;
	}
}

void delete_list(struct Person **list)
{
	struct Person *to_delete = *list;
	while (*list != NULL)
	{
		*list = (*list)->next;
		free(to_delete);
		to_delete = *list;
	}
}

int delete_pos(struct Person **list, int *pos)
{
	struct Person *to_delete = *list;
	if (*pos < 1) return 1;

	if (*pos == 1)
	{
		to_delete = *list;

		*list = (*list)->next;
		free(to_delete);

		return 0;
	}
	else
	{

		for (int i = 1; i<*pos - 1; ++i)
		{
			if (to_delete->next->next == NULL)
			{
				return 1;
			}
			to_delete = to_delete->next;
		}

		struct Person *tmp = to_delete;
		to_delete = to_delete->next;

		if (tmp->next != NULL)
			tmp->next = to_delete->next;

		free(to_delete);

		return 0;
	}
}

struct Person* find_pos(struct Person *list, int *pos)
{

	struct Person *p = list;
	for (int i = 1; i<*pos; ++i)
	{
		if (list->next != NULL)
		{
			list = list->next;
			p = list;
		}
		else return NULL;
	}
	return p;
}

void find(struct Person *list, char *search, char crit)
{

	struct Person *temp = list;
	printf("Adresatų sąrašas:\n");

	switch (crit)
	{
		case '1':	//paieska pagal varda

			while (temp != NULL)
			{
				if (strcmp(temp->name, search) == 0)
				{

					printf("%s %s %s %s\n", temp->name, temp->surname, temp->number, temp->email);
				}
				temp = temp->next;
			}

			break;
		case '2':	//paieska pagal pavarde

			while (temp != NULL)
			{
				if (strcmp(temp->surname, search) == 0)
				{
					printf("%s %s %s %s\n", temp->name, temp->surname, temp->number, temp->email);
				}
				temp = temp->next;
			}

			break;
		case '3':	//paieska pagal numeri
			while (temp != NULL)
			{
				if (strcmp(temp->number, search) == 0)
				{
					printf("%s %s %s %s\n", temp->name, temp->surname, temp->number, temp->email);
				}
				temp = temp->next;
			}

			break;
		case '4':	//paieska pagal email

			while (temp != NULL)
			{
				if (strcmp(temp->email, search) == 0)
				{
					printf("%s %s %s %s\n", temp->name, temp->surname, temp->number, temp->email);
				}
				temp = temp->next;
			}

			break;
		case '\n':
			break;
		default:
			printf("Komanda nerasta\n");
	}
}
