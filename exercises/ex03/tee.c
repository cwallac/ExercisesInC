/**
Author: Chris Wallace
Personal implementation of the tee function.
tee should output whatever the user inputs to standard out
and any files that were provided as arguements.
usage:  ./tee fileOne.txt fileTwo.txt will output user input to
stdout, fileOne.txt and fileTwo.txt
*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
Main function to run tee from. 
./tee [FLAG] one.txt two.txt will output stdin to stdout, one.txt and two.txt
only supported flag is -a which if provided will append stdin to those files as 
opposed to overwriting them.
*/
int main(int argc, char *argv[]) {
	int APPEND_FLAG = 0;
	int numFiles = 0;
	char cOption;
	char in[100];
	int count;
	FILE *writeFile;

	while ((cOption = getopt(argc, argv, "a?")) != EOF) {
  		switch(cOption) {
  			case 'a':
  				//handling append flag
  				APPEND_FLAG = 1;
  				break;
			case '?':
				printf("tee [flags] filename filname2 \n -a flag to append to files instead of overwriting\n");
				exit(1);
				break;
			default:
				break;
  		}
  	}
  		//We don't want to count the name of our file in this list.
  		numFiles -= 1;
  		argv += 1;

  		//If append is 0 there was no -a flag passed in so all things passed in were files
  		numFiles = argc - APPEND_FLAG;
  		
  		//Move pointer past first arg or not
		argv += APPEND_FLAG;
		
	//If we aren't appending erase all of these things
	if(!APPEND_FLAG) {
		for (count = 0; count < numFiles; count++) {
			fclose(fopen(argv[count], "w")); 
		}
	}

	while (fscanf(stdin, "%s", in) == 1) {
		fprintf(stdout, "%s\n", in);
		for (count = 0; count < numFiles; count++) {
			//Append to all the files all the info that comes in from fscanf
			writeFile = fopen(argv[count], "a");
			fprintf(writeFile, "%s\n", in);	
			fclose(writeFile);
			
		}
	}

}

/**
3. I ran into a weirdly specific bug in this program. I had forgotten that argv and argCount
also include the name of the file being executed. So, when I was opening and closing the file
I would get a strange error the second time the program ran where I would execute the last commands
as if they were unix commands. I still don't know exactly why doing this with the file running caused
that but. Incrementing the argv pointer solved it. However, it took me awhile to pinpoint the cause of
this issue. If I had been testing in smaller pieces I would have found the issue sooner
*/

/**
4. THe professional solution uses strucutre and has much more robust error messaging than mine.
*/

