#include <stdio.h>
#include <dirent.h>
#include <unistd.h>


void printFilePaht(const char *dirName){
    DIR *folder;
    struct dirent *file;
    char dirPath[1000];

    getcwd(dirPath, sizeof(dirPath));

    folder = opendir(dirName);

    while( (file = readdir(folder)) != NULL ){
        printf("File path: %s/%s\n", dirPath, file->d_name);
    }

    closedir(folder);
}


int main(){     
    
    //printFilePaht("/home/cyan/Downloads/");
    printFilePaht(".");

    return 0;
}