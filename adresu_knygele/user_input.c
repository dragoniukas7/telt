#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_input.h"
#include "main.h"


void actions(char operator, struct Person **list)
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
				print_list(*list);
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
           			add_to_list(list, person);
				
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
           			add_to_list_at(list, person, &pos);
				
				break;
			case '-': //istrinti pagal pozicija
				printf("Įveskite poziciją\n");
				
				scanf("%d", &pos);
				
				delete_pos(list, &pos);
				
				break;
			case 'd': //istrinti visa sarasa
				delete_list(*list) ;
				break;
			case 's': //rasti pagal vieta
				printf("Įveskite poziciją\n");
				
				scanf("%d", &pos);
				person = find_pos(*list, &pos);
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
