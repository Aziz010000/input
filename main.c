#include<stdio.h>

#include"input.h"


int main(int arcv, char *argv[]){
	printf("Inserisci un numero da tastiera:\n"); 
	int n = get_number();
	printf("%d\n",n);
	printf("Inserisci una stringa da tastiera:\n"); 
	char buffer[1024]; 
	get_string(buffer);
	printf("%s\n",buffer);

	return 0;
}
