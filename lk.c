#include <stdio.h>
#include <dirent.h>

int main(){

    DIR *folder;
    struct dirent *file;

    folder = opendir(".");
    //folder = opendir("/home/cyan/Downloads/");

    while( (file = readdir(folder)) != NULL ){
        printf("File name: %s\n", file->d_name);
    }

    closedir(folder);

    return 0;
}