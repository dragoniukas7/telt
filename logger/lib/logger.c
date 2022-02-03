#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
	int i;
	for(i=0; i<argc; i++){
	  printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
  }

int add_log(char *program_name, int *level, char *content)
{
	sqlite3 *db;
	
	char *zErrMsg = 0;
	int rc;
  
	rc = sqlite3_open("./db", &db);
	if( rc ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return(1);
	}
	rc = sqlite3_exec(db, "SELECT *", callback, 0, &zErrMsg);
	if( rc!=SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);
	
	return 0;
}

char* get_log(){
	
	
	
	return '\0';

}

char* get_program_log(char *name){
	
	
	return '\0';

}
