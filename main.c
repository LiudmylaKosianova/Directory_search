#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include "directory_search.h"


int main(int argc, char *arg[]){ 

    if( (argc<2)||(strcmp(arg[1], "-h")==0)||(strcmp(arg[1],"--help")==0) ){
        help_user();
        return 0;
    }

    pthread_t thread1;
    pthread_t thread2;
    
    char *dir_name = arg[1];
    pthread_create(&thread1, NULL, T_printFilePaht, (void*) dir_name);
    pthread_create(&thread2, NULL, T_calculateElement, (void*) dir_name);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);  
 

    return 0;
}