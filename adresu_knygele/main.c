#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "usage.h"

#define PRINT_COUNT 10

struct Person;
void actions(char operator, struct Person **list);

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
    print_list_num(list, PRINT_COUNT);
    
    print_usage();

    printf("Įrašykite komandą: ");
        while((operator = getchar()) != '0') {
            if (operator == 'q'){
                break;
                }
            if (operator != '\n') {
                actions(operator, &list);
                printf("Įrašykite komandą: ");
                	fflush(stdin);
            }
	}
    delete_list(&list);
    fclose(address_file);
    return 0;
}

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
				print_list(*list);
				break;
			case '+': //prideti i gala
				
				printf("Įveskite adresato vardą:\n");
				
				scanf("%30s", name);
				printf("Įveskite adresato pavardę:\n");
				
				scanf("%30s", surname);
				printf("Įveskite adresato el. pašto adresą:\n");
				
				scanf("%30s", email);
				printf("Įveskite adresato tel. nr.:\n");
				
				scanf("%30s", number);
				
				person = create_node(name, surname, email, number);
           			add_to_list(list, person);
				
				break;
			case 'p': //prideti i pozicija

				printf("Įveskite adresato vardą:\n");
				
				scanf("%30s", name);
				printf("Įveskite adresato pavardę:\n");
				
				scanf("%30s", surname);
				printf("Įveskite adresato el. pašto adresą:\n");
				
				scanf("%30s", email);
				printf("Įveskite adresato tel. nr.:\n");
				
				scanf("%30s", number);
				printf("Įveskite poziciją\n");
				
				scanf("%d", &pos);
				
				person = create_node(name, surname, email, number);
           			if(add_to_list_at(list, person, &pos) != 0){
           				printf("Įvesta pozicija neegzistuoja:\n");
           			}
				
				break;
			case '-': //istrinti pagal pozicija
				printf("Įveskite poziciją\n");
				
				scanf("%d", &pos);
				if(delete_pos(list, &pos) != 0){
           			printf("Įvesta pozicija neegzistuoja:\n");
           		}

				
				break;
			case 'd': //istrinti visa sarasa
				delete_list(list) ;
				break;
			case 's': //rasti pagal vieta
				printf("Įveskite poziciją\n");
				
				scanf("%d", &pos);
				person = find_pos(*list, &pos);
				if(person){
					printf("%s %s %s %s\n", person->name, person->surname, person->number, person->email);
				}
				break;
			case 'f': //rasti pagal kriteriju
				char operator2;
				char crit[30];
				printf("Pasirinkite paieškos kriterijų\n");
				printf("1 - vardas, 2 - pavardė, 3 - tel. nr., 4 - el. paštas\n");

				scanf(" %c", &operator2);
				printf("Įveskite paieškos kriterijų\n");
				scanf("%30s", crit);

				find(*list, crit, operator2);
										
				break;
			case 'h': //pagalba
				print_usage();
				break;
			case '\n':
				break;
			default:
				printf("Komanda nerasta\n");
		}
}
