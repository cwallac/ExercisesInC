/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/*
This function is attempting to create an array of size 5 that contains entirely 42s
However, since it is being declared in the stack it will be cleared when the function
is done running.
*/
int *foo() {
    int i;
    int array[SIZE];

    //This value will be a pointer to where array was allocated to.
    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
    //Assign each chunk of memeory from array to array + 5*4 to 42
	array[i] = 42;

    }
    //Return the pointer to array. However, this is decalred on foo()'s stack. So the memory will get cleared
    //after this function is run. This will not work as expected
    return array;
}

/*
This function is then attempting to create an array of size 5 and then set its values to 0-4
It does not return anything, and again all values will be cleared when this function is done running
*/
void bar() {
    int i;
    //Declare array of size five on bar()s stack.
    int array[SIZE];
    
    printf("%p\n", array);
    //Set them equal to 0-4
    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}

int main()
{
    int i;
    //Allocates a pointer on the stack for *array which will be the output of foo()
    int *array = foo();
    //Foos stack is now cleared. 
    //I and the array within 
    bar();
    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
//since array has been cleared by the stack none of these will be 42 like you would think from reading foo()
//The second value in the array reads off as a number. My present thought is that this is the return address for
//The main function?
	printf("%d\n", array[i]);
    } 
    return 0;
}
