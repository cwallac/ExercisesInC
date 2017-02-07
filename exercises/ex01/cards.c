/*
@Author Chris Wallace
Program to accept user input and determine the card counting score from
that series of inputs.
*/
#include <stdio.h>
#include <stdlib.h>

/* Applies the card counting logic to whatever the present count is

   presentCount: the present count of the game
   val: the value of the card
*/
int countingLogic(int presentCount, int val) {
	if ((val > 2) && (val < 7)) {
		presentCount++;
	} else if (val == 10) {
		presentCount--;
	}
	return presentCount;
}

/* Parses the character string and returns a numeric value corresponding
with the card's value. Returns 0 if the string is not a valid card
	cardName: The string representation of the card
*/
int determineCardValue(char cardName[3]) {
	int val = 0;
	switch (cardName[0]) {
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		default:
			val = atoi(cardName);
			if ((val < 1) || val > 10) {
				puts("I don't understand that value");
				return 0;
			}

	}
	return val;
}

/*
Runs the card counting program. Accepts user input and translates
that input into a value for card counting. Displays the count of the game
Exits if 'X' is entered.
*/
int main() 
{
	char cardName[3];
	int count = 0;
	int val;
	while (cardName[0] != 'X') {
		puts("Enter the card name:");
		scanf("%2s",cardName);
		if (cardName[0] == 'X') {
			continue;
		}
		val = determineCardValue(cardName);

		
		count = countingLogic(count, val);
		
		printf("Current count: %i\n", count);
	}
	return 0;
}
