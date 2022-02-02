#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELIMETER ","

struct Person {
    char name[30];
    char surname[30];
    char number[30];
    char email[30];
    struct Person *next;
};

struct Person* create_node(char *name, char *surname, char *email, char *number);//
struct Person* create_address_node(char *address_line);

int delete_pos(struct Person *list, int *pos);
struct Person* find_pos(struct Person *list, int *pos);
struct Person* find(char *name, char *surname, char *email, char *number);
void add_to_list(struct Person **list, struct Person *node);
int add_to_list_at(struct Person **list, struct Person *node, int *pos);
void actions(char operator, struct Person *list);
void print_list(struct Person *list);//
void delete_list(struct Person *list);
void load_addresses(FILE *file, struct Person **list);


int main(void)
{
    char address_file_path[30] = "addresses.csv";
    char operator;

    struct Person *list = NULL;
    FILE *address_file = NULL;

    address_file = fopen(address_file_path, "r");

    if( address_file == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    load_addresses(address_file, &list);
    print_list(list);

    printf("Enter command: ");
        while((operator = getchar()) != '0') {
            if (operator == 'q')
                break;
            if (operator != '\n') {
                actions(operator, list);
                printf("Enter command: ");
            }
	}
    //delete_list(list);
    //fclose(address_file);
    return 0;
}

void actions(char operator, struct Person *list)
{

	struct Person *person = NULL;
	char name[30];
    	char surname[30];
    	char number[30];
    	char email[30];
    	int pos;
	
	switch(operator) {
			case 'r': //perziureti visa sarasa
				printf("Adresatų sąrašas:\n");
				print_list(list);
				break;
			case '+': //prideti i gala
				
				printf("Įveskite adresato vardą:\n");
				
				scanf("%s", name);
				printf("Įveskite adresato pavardę:\n");
				
				scanf("%s", surname);
				printf("Įveskite adresato el. pašto adresą:\n");
				
				scanf("%s", email);
				printf("Įveskite adresato tel. nr.:\n");
				
				scanf("%s", number);
				
				person = create_node(name, surname, email, number);
           			add_to_list(&list, person);
				
				break;
			case 'p': //prideti i pozicija

				printf("Įveskite adresato vardą:\n");
				
				scanf("%s", name);
				printf("Įveskite adresato pavardę:\n");
				
				scanf("%s", surname);
				printf("Įveskite adresato el. pašto adresą:\n");
				
				scanf("%s", email);
				printf("Įveskite adresato tel. nr.:\n");
				
				scanf("%s", number);
				printf("Įveskite poziciją\n");
				
				scanf("%d", &pos);
				
				person = create_node(name, surname, email, number);
           			add_to_list_at(&list, person, &pos);
				
				break;
			case '-': //istrinti pagal pozicija
				printf("Įveskite poziciją\n");
				
				scanf("%d", &pos);
				
				delete_pos(list, &pos);
				
				break;
			case 'd': //istrinti visa sarasa
				delete_list(list) ;
				break;
			case 's': //rasti pagal vieta
				printf("Įveskite poziciją\n");
				
				scanf("%d", &pos);
				person = find_pos(list, &pos);
				if(person){
				printf("%s %s %s %s", person->name, person->surname, person->number, person->email);
				}
				break;
			case 'f': //rasti pagal kriteriju
				
				break;
			case '\n':
				break;
			default:
				printf("Command not found\n");
		}
}


void load_addresses(FILE *file, struct Person **list)
{
    char line[128];
    while (fgets(line, sizeof(line), file)) {
        struct Person *person = NULL;
        if(strcmp(line, "\n") == 0) {
            //exit(1);
            continue;
        }
        person = create_address_node(line);
        if (person != NULL) {
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
    person = (struct Person*) malloc(sizeof(struct Person));
    if (person == NULL) {
        return NULL;
    }
    strcpy(person->name, name);
    strcpy(person->surname, surname);
    strcpy(person->email, number);
    strcpy(person->number, email);
    person->next = NULL;
    return person;
}

void add_to_list(struct Person **list, struct Person *person)
{
    struct Person* temp = *list;
    if (temp == NULL) {
        *list = person;
        return; 
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = person;
}

int add_to_list_at(struct Person **list, struct Person *person, int *pos) 
{
    struct Person* temp = *list;
    if (temp == NULL) {
        *list = person;
        return 1; 
    }

    for (int i = 1; i < *pos - 1; i++)
    {
    	if(temp->next == NULL){
    	    return 1;
    	}
    	temp = temp->next;
    }
    person->next = temp->next;
    temp->next = person;
    return 0;
}

void print_list(struct Person *list)
{
    struct Person *temp = list;

    while (temp != NULL) {
        printf("%s %s %s %s", temp->name, temp->surname, temp->number, temp->email);
        temp = temp->next;
    }
}

void delete_list(struct Person *list) 
{
    struct Person *to_delete = list;
    while (list != NULL) {
        list = list->next;
        free(to_delete);
        to_delete = list;
    }
}

int delete_pos(struct Person *list, int *pos)
{
    struct Person *to_delete = list;
    /*
    while (list != NULL) {
        list = list->next;
        free(to_delete);
        to_delete = list;
    }*/
    
    if(*pos == 1){
    	

        *to_delete = *list;
        free(to_delete);
        *list = *list->next;

    
    	return 0;
    }
    else {
    
    for (int i = 1; i < *pos - 1; ++i)
    {
    	if(list->next == NULL){
    	    return 1;
    	}
    	list = list->next;
    }

    
    to_delete = list->next;
    
    if(list->next != NULL)
    list->next = to_delete->next;
    free(to_delete);
    
    return 0;
    }
}

struct Person* find_pos(struct Person *list, int *pos){

    
    struct Person *p = list;
    for (int i = 1; i < *pos ; ++i){
    if(list->next != NULL){
        list = list->next;
        p = list;
    }
    else return NULL;
    }
    return p;
}

