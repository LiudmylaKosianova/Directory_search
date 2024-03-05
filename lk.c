#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>


void printFilePaht(const char *dirName){
    DIR *folder;
    struct dirent *file;
    char dirPath[1000];

    getcwd(dirPath, sizeof(dirPath));
         
    folder = opendir(dirName);
    if(folder == NULL){
        perror("Can't open directory\n");
        return;
    }
     

    while( (file = readdir(folder)) != NULL ){
        printf("File path: %s/%s\n", dirPath, file->d_name);
    }

    closedir(folder);
}

int calculateElement(const char *dirName){
    DIR *folder;
    struct dirent *file;
    int a;

    folder = opendir(dirName);
    if(folder == NULL){
        perror("Can't open directory\n");
        printf("Returned -1\n");
        return -1;
    }

    while( (file = readdir(folder)) != NULL ){
        a++;
    }

    closedir(folder);
    return a;

}


int main(){     
    
    printFilePaht("/home/cyan/Download/");
    //printFilePaht(".");
    printf("There are %d files\n", calculateElement("p"));

    return 0;
}