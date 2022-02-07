#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <unistd.h>

#define DB_PATH "/var/log/logger.db"
sqlite3 *db;

int add_log(char *program_name, int level, char *content){

	sqlite3_stmt *stmt;
	
	//char *zErrMsg = 0;
	int rc;
	char *sql;
	
	sql = "INSERT INTO LOG (program,level,content) VALUES (?, ?, ?);";
          
	rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		printf("prepare failed: %s\n", sqlite3_errmsg(db));
		return 1;
	}

	sqlite3_bind_text(stmt, 1, program_name, -1, SQLITE_STATIC);
	sqlite3_bind_int (stmt, 2, level);
	sqlite3_bind_text(stmt, 3, content, -1, SQLITE_STATIC);


	rc = sqlite3_step(stmt);

	if (rc != SQLITE_DONE) {
    	printf("execution failed: %s\n", sqlite3_errmsg(db));
    	sqlite3_finalize(stmt);
    	sqlite3_close(db);
    	return 1;
	}

    sqlite3_finalize(stmt);
	
	return 0;
}

static char* level_converter(int level){
	switch (level)
	{
		case 0:
			return "emergency";
		case 1:
			return "alert";
		case 2:
			return "critical";
		case 3:
			return "error";
		case 4:
			return "warning";
		case 5:
			return "notice";
		case 6:
			return "info";
		case 7:
			return "debug";
		default:
			return "";
	}
}

int init_logger(){

	int err;
	char *sql;
	sqlite3_stmt *stmt;
	
	err = sqlite3_open(DB_PATH, &db);
	if( err ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
	}
	
	sql = "CREATE TABLE IF NOT EXISTS LOG("  \
	"id     INTEGER PRIMARY KEY AUTOINCREMENT," \
	"time TIMESTAMP DEFAULT CURRENT_TIMESTAMP,"\
	"program        TEXT    NOT NULL," \
	"level          INT     NOT NULL," \
	"content        TEXT );";

	err = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (err != SQLITE_OK) {
		printf("prepare failed: %s\n", sqlite3_errmsg(db));
		return 1;
	}

	err = sqlite3_step(stmt);

	if (err != SQLITE_DONE) {

		printf("execution failed: %s\n", sqlite3_errmsg(db));
		sqlite3_finalize(stmt);

		return 1;
	}

	int k = sqlite3_finalize(stmt);
	
	return k;
}

int close_logger(){
	return sqlite3_close(db);
}

int print_log(){
		
	const char *sql = "SELECT level, program, content, time FROM LOG";
	sqlite3_stmt *stmt;
	int err;

	err = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (err != SQLITE_OK) {
		printf("prepare failed: %s\n", sqlite3_errmsg(db));
		return 1;
	}

	for (;;) {
		err = sqlite3_step(stmt);
		if (err != SQLITE_ROW)
		    break;

		const char* level = level_converter(sqlite3_column_int (stmt, 0));
		const unsigned char *program_name = sqlite3_column_text(stmt, 1);
		const unsigned char *content = sqlite3_column_text(stmt, 2);
		const unsigned char *timestamp = sqlite3_column_text(stmt, 3);
		
		printf("%s Level: %s, Program: %s, Content: %s\n", timestamp, level, program_name, content);
	}

	if (err != SQLITE_DONE) {

		printf("execution failed: %s\n", sqlite3_errmsg(db));
		sqlite3_finalize(stmt);

		return 1;
	}

	int k = sqlite3_finalize(stmt);
	
	printf("kodas: %d", k);
	
	return 1;
}

int print_program_log(char *name){

	const char *sql = "SELECT level, program, content, time FROM LOG WHERE program = ?";
	sqlite3_stmt *stmt;
	int err;

	err = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (err != SQLITE_OK) {
		printf("prepare failed: %s\n", sqlite3_errmsg(db));
		return 1;
	}
	
	sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);

	for (;;) {
		err = sqlite3_step(stmt);
		if (err != SQLITE_ROW)
		    break;

		const char* level = level_converter(sqlite3_column_int (stmt, 0));
		const unsigned char *program_name = sqlite3_column_text(stmt, 1);
		const unsigned char *content = sqlite3_column_text(stmt, 2);
		const unsigned char *timestamp = sqlite3_column_text(stmt, 3);
		
		printf("%s Level: %s, Program: %s, Content: %s\n", timestamp, level, program_name, content);
	}

	if (err != SQLITE_DONE) {

		printf("execution failed: %s\n", sqlite3_errmsg(db));
		sqlite3_finalize(stmt);

		return 1;
	}

	int k = sqlite3_finalize(stmt);
	
	printf("kodas: %d", k);

	return 0;
}
