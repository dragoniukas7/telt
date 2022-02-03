#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logger.h"

int main(void)
{
	int i = 1;
	add_log("name", &i, "SELECT *");
	
	return 0;
}
