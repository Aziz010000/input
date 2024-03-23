#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include"input.h"

#define size 1024

void let_err(){
	fprintf(stderr, "Errore in lettura\n"); 
	exit(EXIT_FAILURE);
}

void get_string(char *buffer){
	if(fgets(buffer,size,stdin)){
		buffer[strcspn(buffer,"\n")]= 0;
	}
	else{
		let_err();
	}
}


int get_number(){
	char buffer[size]; 
	int success; 
	int n;
	do{
		if(!fgets(buffer,size,stdin)){
			let_err();
		}
		errno = 0;
		char *endptr; 
		n = (int)strtol(buffer,&endptr,10);
		if(errno == ERANGE){
			success = 0;
		}else if(buffer == endptr){
			success = 0; 
		}else if(*endptr && *endptr != '\n'){
			success = 0;
		}else{
			success = 1;
		}
	}while(success == 0); 
	return n;
}
