#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDLENGTH 51

int lines(char filename[]){
	int counter = 0;
	FILE *file;
	file = fopen(filename, "r");
	if(file == NULL) return 0;
	while(1){
		char temp[WORDLENGTH];
		if(feof(file)) break;
		fscanf(file, "%s", temp);
		counter++;
	}
	fclose(file);
	return counter;
}

void open(char filename[], int size, char array[][WORDLENGTH]){
	//printf("%s\n\n", filename);

	FILE *file;
	file = fopen(filename, "r");
	if(file == NULL) return;
	for(int i = size; 1 ; i++){
		if(feof(file)) break;
		fscanf(file, "%s", array[i]);
		//printf("%d = %s\n", i, array[i]);
	}
	fclose(file);
}

void sort(int total, char array[][WORDLENGTH]){
	for(int i = 0; i < total-1; i++){
		for(int j = i + 1; j < total; j++){ 
			if(strcmp(array[i], array[j]) > 0){ // can be strcasecpm() to 
				char temp[WORDLENGTH];          // sort CAPS within lower case
				strcpy(temp, array[i]);
				strcpy(array[i], array[j]);
				strcpy(array[j], temp);
			}
		}
	}
}

void write(int size, char array[][WORDLENGTH]){
	FILE *file;
	file = fopen("words.txt", "w");
	for(int i = 0; i < size ; i++){
		fprintf(file, "%s\n", array[i]);
	}
	fclose(file);
}

int main(){
	char filename1[] = "americam0.txt";
	char filename2[] = "americam1.txt";
	char filename3[] = "americam2.txt";

	int entries1 = lines(filename1);
	int entries2 = lines(filename2);
	int entries3 = lines(filename3);
	int total = entries1 + entries2 + entries3;

	char array[total][WORDLENGTH];

	open(filename1, 0, array);
	open(filename2, entries1, array);
	open(filename3, (entries1 + entries2), array);

	sort(total, array);

	// for(int i = 0; i < total; i++)
	// 	printf("%d = %s\n", i, array[i]);

	write(total, array);
	return 0;
}
