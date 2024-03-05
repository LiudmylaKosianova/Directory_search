#include <stdio.h>
#include <dirent.h>
#include <unistd.h>



int main(){

    DIR *folder;
    struct dirent *file;
    char dirPath[1000];

    getcwd(dirPath, sizeof(dirPath));

    //folder = opendir(".");
    folder = opendir("/home/cyan/Downloads/");

    while( (file = readdir(folder)) != NULL ){
        printf("File name: %s\n", file->d_name);
        char path[1500];

        printf("File path: %s/%s\n", dirPath, file->d_name);
    }

    closedir(folder);

    return 0;
}