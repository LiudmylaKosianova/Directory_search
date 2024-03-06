#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>



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
        return -1;
    }

    while( (file = readdir(folder)) != NULL ){
        a++;
    }

    closedir(folder);
    return a;

}

void *threefive(void *b){
    //int *new_a = (int*)(a);
    char *new_b = (char*)b;
    //printf("Three %d five %d\n", *new_a, *new_a + 3);
    printf("%s\n", new_b);
    return NULL;
}
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



int main(){ 

    pthread_t thread1;
    // int value3 = 3;
    // char b[] = "b string";
    //pthread_create(&thread1, NULL,threefive,(void*) &value3);
    // pthread_create(&thread1, NULL, threefive, (void*) b);
    // pthread_join(thread1, NULL);
    char name[] = ".e";
    char cyan[] = "/home/cyan/Downloads";
    pthread_create(&thread1, NULL, T_printFilePaht, (void*) name);
    pthread_join(thread1,NULL);
    

    
    //printFilePaht("/home/cyan/Download/");
    //printFilePaht(".");
    //printf("There are %d files\n", calculateElement("p"));

    return 0;
}