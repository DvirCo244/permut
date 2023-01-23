#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ARG 3
#define FIRST_ARGV 1
#define SECOND_ARGV 2

int valid_args(int argc);
/*gets the amount of argc given and checks if the given numbers equals two 3 (the amount needed)*/


int valid_file(const char *path);
/*gets the path given and check if the file is valid*/


int valid_file_empty(const char *path);
/*after the file gets valid it checks if its empty or not*/


int compare(const void *str1,const void *str2);
/*compare to char pointer*/