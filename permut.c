#include "permut.h"

int main(int argc,char *argv[]){
FILE *fp;
char *word = argv[SECOND_ARGV];
char *str = (char *)malloc(sizeof(char) * strlen(word));
char *copystr = (char *)malloc(sizeof(char) * strlen(word));
int count = 0;
/*checks if the amount of argc is correct*/
if(valid_args(argc) == 0){
printf("the number of argc is not correct");
return EXIT_FAILURE;
}
/*check if the file path is valid*/
if(valid_file(argv[FIRST_ARGV]) == 0){
    printf("there is error with the file path");
    return EXIT_FAILURE;
}
/*check if the file is empty or not*/
if(valid_file_empty(argv[FIRST_ARGV]) == 0){
    printf("the file is empty");
    return EXIT_FAILURE;
}
/*opens file and define the word needs to be searched*/
fp = fopen(argv[FIRST_ARGV], "r");
qsort(word,strlen(word),sizeof(char),compare);
printf("the permuts are... \n");
/*checks the file by array in size of the given word*/
while(fgets(str,(strlen(word)+1),fp) != NULL){
    strcpy(copystr,str);
    qsort(str,strlen(str),sizeof(char),compare);
if(strcmp(word,str) == 0) {
    count++;
    printf("%s\n",copystr);
}
    fseek(fp,-strlen(str)+1,SEEK_CUR); 
    
}
if(count == 0){
    printf("no permut were found");
}
fclose(fp);
free(str);
free(copystr);
return EXIT_SUCCESS;
}

int valid_args(int argc){
    if(argc == ARG)
    return (1);
    else
    return (0);
}

int valid_file(const char *path){
    FILE *fptr = fopen(path, "r");
    if (fptr == NULL)
    return (0);
    
    fclose(fptr);
    return (1);
}

int valid_file_empty(const char *path){
    int length;
    FILE *fptr = fopen(path,"r");
    fseek(fptr,0,SEEK_END);
    length = ftell(fptr);
    if(length == 0)
    return (0);
    else
    return (1);
}

int compare(const void *str1, const void *str2)
{
    return (*(char *)str1 - *(char *)str2);
}