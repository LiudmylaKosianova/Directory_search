#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include "directory_search.h"
 
 
void *T_printFilePaht(void *dirName){
    DIR *folder;
    struct dirent *file;
    char dirPath[1000];
    char *new_dirName = (char*)dirName;

    getcwd(dirPath, sizeof(dirPath));
         
    folder = opendir(new_dirName);
    if(folder == NULL){
        perror("Can't open directory\n");
        return NULL;
    }
     

    while( (file = readdir(folder)) != NULL ){
        printf("File path: %s/%s\n", dirPath, file->d_name);
    }

    closedir(folder);
    return NULL;
}

void *T_calculateElement(void *dirName){
    DIR *folder;
    struct dirent *file;
    int a;
    char *new_dirName = (char*)dirName;

    folder = opendir(new_dirName);
    if(folder == NULL){
        perror("Can't open directory\n");
        return NULL;
    }

    while( (file = readdir(folder)) != NULL ){
        a++;
    }
    closedir(folder);
    printf("There are %d items in directory %s\n", a, new_dirName);
    return NULL;

}

 