###Sprint Reflection

Overall, I think that the first sprint went very well for our team. We have found a lot of
really interesting content to explore and attempt to comprehend. We also managed to work at
a good pace and finished the sprint with a much better understanding of explitations in c. 

The one issue we ran into that may impact us more as we go forward in this class is that
we did not have a very successful knowledge sharing mechanism. In this sprint we did not
experience too many downsides with this because the material that we were covering independently
was fairly straightforward so a brief readover of a write up would explain the topic. However,
as we move forward we are going to be looking at more complicated exploits that we will have to
help each other understand. We need to ensure that we have a proper knowledge sharing mechanism to 
do this. 

In terms of personal learning goals, I got back into c code which was helpful for remembering some
of the gotchas I ran into last time I worked with C and I learned several simple exploit techniques.
I have found so far that I am exceeding my learning goals and a lot fo these exploits are much more
comprehendable than I initially expected.

###Headfirst C Excercises

[Excercise 1](https://github.com/cwallac/ExercisesInC/tree/master/exercises/ex01)

[Excercise 2](https://github.com/cwallac/ExercisesInC/tree/master/exercises/ex02)

[Excercise 2.5](https://github.com/cwallac/ExercisesInC/tree/master/exercises/ex02.5)

###ThinkOS Exercies

[ThinkOS](https://github.com/cwallac/ExercisesInC/tree/master/reading_questions/thinkos.md])

###Exam Question
```
void method1() {
	int x = 5;
	int y = 5;
	printf("Method 1 y address %p\n", &y);
}

void method2() {
	int y = 5;
	printf("Method 2 y address %p\n", &y);
}

int main() {
	method2();
	method1();
	
}
```
Examine the above code sample. Assuming an int is 4 bytes, how many bytes apart is the memory address for 
the variable y in method1 and method2?  

Answer: 4 bytes. Since the stack gets cleared after each function call int x is initialized in the same address that y in method2 was
initialized in. This means that y in method1 will be initialized 4 bytes after int x. 

