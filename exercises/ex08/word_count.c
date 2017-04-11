/*
*Reads in a text file and prints out teh frequency
*of all words that appear in a text file
*/

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
* Function to print out the word and how many times it appears
*/
void printFrequency(void *word, void *frequency, void *userData) {
	printf("%s appear %i times!\n", (char *)word, *(int *)frequency);
}

/*
*Function to check if the character is  a letter
*/
int isText(char letter) {
	if ((letter <= 90 && letter >= 65) || (letter <= 122 && letter >= 97)) {
		return 1;
	}
	return 0;
}


int main (int argc, char** argv) {
	int IN_WORD = 0;
	//No word is longer than 100 characters. If it was wed buf overflow
	char wordArray[100] = {0};
	int numLetters = 0;
	int c;
	FILE *file;

	GHashTable *hash_table = g_hash_table_new_full (g_str_hash,  /* Hash function  */
                           g_str_equal, /* Comparator     */
                           free,   /* Key destructor */
                           free);  /* Val destructor */
	if (argc != 2) {
		printf("Usage ./wordCount FILE_NAME\n");
		return -1;
	}
	file = fopen(argv[1], "r");
	if (file) { 
		while ((c = getc(file)) != EOF)
			if (IN_WORD) {
				if (isText(c)) {
					//This is a letter in a word
					wordArray[numLetters] = tolower(c);
					numLetters++;
				} else {
					//We just finished our last letter, add to map falsify and reset
					IN_WORD = 0;
					//Add it to the ole hash table
					int *result = malloc(sizeof(int));
					char *wordToInsert = malloc(sizeof(char) * numLetters);
					wordToInsert = strdup(wordArray);
					
					int *isInserted = g_hash_table_lookup(hash_table, wordToInsert);
					if (isInserted == NULL) {
						*result = 1;
						g_hash_table_insert(hash_table, wordToInsert, result);
					} else {
						*result = *isInserted + 1;
						g_hash_table_insert(hash_table, wordToInsert, result);
						//printf("%i\n", test);
					}
					memset(wordArray,0, numLetters);
					numLetters = 0;

				}
			} else {
				if (isText(c)) {
					//This is the first letter of a word
					wordArray[numLetters] = tolower(c);
					IN_WORD = 1;
					numLetters++;
				} 
			}

		    if (isText(c)) {
		    	printf("%c", c);
		    }
		fclose(file);
	} else {
		printf("File not found, exiting...");
		return -1;
	}
	//We have built the full array.

	g_hash_table_foreach(hash_table, printFrequency, NULL);

	g_hash_table_unref (hash_table);

	return 1;
}