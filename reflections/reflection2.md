###Sprint Reflection

Our last sprint kaizen was to create a better means of knowledge transfer when working on independant work.
I think that so far we have been successful in doing this. Deniz shared some helpful sources he found for 
understanding the dirtyCow exploit. In addition to that Sawyer and I both walked through the Nebula/Protostar
exercises we did with those who did not do them on the team. We have also been spending more time writing up
what we have completed which is a good mechaniam not just for knowledge share, but also for verifying that 
we understand the material in the first place.

Our biggest weakness this sprint was velocity. We think as team that a lot fo the reason for that was the snow day,
since we didn't have class we didn't meet and we didn't assign new tasks for the next class session and instead just
carried our previous tasks to the next class. This dramaticallly slowed down our velocity.

In terms of personal learning goals, I have been incredibly interested by the Nebula/Protostar exploits. These examples
are much more real world than any of the demonstrations we had made up until this point. Its very interesting to learn
how to exploit vulnerabilities in C. Learning these vulnerabilities is giving me a very good understanding of how C code interacts
with memory. It is also interesting to learn how to use some tools like `gdb` that give you a very low level look at what is
going on in the code.

###Headfirst C Excercises


[Excercise 3](https://github.com/cwallac/ExercisesInC/tree/master/exercises/ex03)

[Excercise 4](https://github.com/cwallac/ExercisesInC/tree/master/exercises/ex04)

###ThinkOS Exercies

[ThinkOS Chapters 3 and 4](https://github.com/cwallac/ExercisesInC/tree/master/reading_questions/thinkos.md])


###Exam Question

You have two c files. `test.c` and `test.h`
```
//test.c
#include "test.h"

int testFunction() {
	printf("I am running a test function");
	return score;
}

int main () {
	int results = testFunction();
}
```

test.h
```
void testFunction();
int score;
```

You run `gcc test.c` What will happen, why?

Answer:
The code will fail to compile because you have declared `testFunction()` `void` in the header and then defined it to
return `int` in `test.c`. In addition, you are assigning an `int` to the output of `testFunction()` which to the compiler
is `void`. So that will also trigger another error.
