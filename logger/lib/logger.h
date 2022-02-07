int init_logger();
int close_logger();
int add_log(char *program_name, int level, char *content);
int print_log();
char* print_program_log(char *name);
