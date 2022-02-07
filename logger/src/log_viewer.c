#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <logger.h>
#include <unistd.h> 

int main(int argc, char *argv[])
{

	int option;
	char* program;	

	int i;
	i = init_logger();
	
	while ((option = getopt(argc, argv, "P:")) != -1) {
		switch (option) {
		case 'P':
			program = optarg;
			print_program_log(program);
		break;
		default:
			print_log();
			printf("Unknown flag");
	}
	
	}
	
	add_log("program2", 2, "negerai");
	i = close_logger();
	
	return 0;
}
