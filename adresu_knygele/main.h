#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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

int delete_pos(struct Person **list, int *pos);
struct Person* find_pos(struct Person *list, int *pos);
struct Person* find(char *name, char *surname, char *email, char *number);
void add_to_list(struct Person **list, struct Person *node);
int add_to_list_at(struct Person **list, struct Person *node, int *pos);

void print_list(struct Person *list);//
void delete_list(struct Person *list);
void load_addresses(FILE *file, struct Person **list);

#endif
