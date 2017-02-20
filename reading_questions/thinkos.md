## Chapter 1


### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Dyanamic typing

2) Name two advantages of static typing over dynamic typing.

More errors are caught by the compiler

Easier to debug, you don't have to worry that you are accidentally adding an integer to a boolean

3) Give an example of a static semantic error.

myArray[3.14]

4) What are two reasons you might want to turn off code optimization?

Debugging might become harder and bugs might become less obvious. 
If the program is large it might take significantly longer to compile

5) When you run `gcc` with `-S`, why might the results look different on different computers?

-S compiles C into assembly code which is architecture dependant. If a computer is running an x64
processor it will require different assembly than one running x86

6) If you spell a variable name wrong, or if you spell a function name wrong, 
the error messages you get might look very different.  Why?

Functions that are not defined will be caught by the linker. A variable name that is spelled
incorrectly will appear as the syntax error and will be caught by the compiler

7) What is a segmentation fault?
A segmentation fault occurs when a program attempts to access memory that it is not allowed
to have access too.


## Chapter 2


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

Amazon EC2 nodes. While not explictly thought of as a VM, they are in reality VMs on large servers
in Amazon data centers

2) What is the difference between a program and a process?

A process is the actual execution of a program. A program is a set of instructions to be executed
a process is an a OS concept than can execute any arbitrary program.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?

Processes allow you to interact with network hardware as if you are the only thing interact with it.
In reality there are several processes trying to interact with the hardware at the same time, but
processes abstract this away so to the programmer it appears like it is only them interacting. This abstraction
also applies to virtual memory. The illusion created is that the single process the program is running
is the only process being run on the computer. 

4) What is the kernel?

THe kernal is the part of the OS responsible for core capabilities

5) What is a daemon?
 
 A daemon is a process that runs in the background and provides core OS functionality.

## Chapter 3


### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?  

2^6. 

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.   

Ignoring the details of the encoding scheme, how many different characters can be represented?
4294967296

3) What is the difference between "memory" and "storage" as defined in Think OS? 

Storage refers to HDD space. Memory refers to RAM.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes? 

A GiB is a gibibyte which is 2^30 bytes. a GB is a gigbyte and is 10^9 bytes. x-bibytes always is a
base 2.

5) How does the virtual memory system help isolate processes from each other? 

Each process gets allocated its own chunk of physical memory. It can refer to these addresses by 
virtual memory addresses. There are no virtual memory addresses that map to physical addresses of 
the memory used by a different process so they can not interfere with each other.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space? 

The stack grows down and the heap grows up. Putting them at opposite ends allows the most memory to be 
utilized by the program

7) What Python data structure would you use to represent a sparse array? 

dictionary

8) What is a context switch?
 
A context switch occurs when an OS interrupts a running process, pauses it and switches to 
another process

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.

My results:
Address of main is   0x   10515be90
Address of global is 0x   10515c020
Address of local is  0x7fff5aaa4a68
Address of p is      0x7fc13fc027f0

Allen's results:
Address of main is   0x      40057c
Address of global is 0x      60104c
Address of local is  0x7fffd26139c4
Address of p is      0x     1c3b010
  
1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses). 

Address of main is   0x   10ad8ae60 

Address of global is 0x   10ad8b020 

Address of local is  0x7fff54e75a68 

Address of p is      0x7f85fdc027f0 

Address of q is      0x7f85fdc02870 


The heap is growing up towards larger address, q was allocated after p.

2) Add a function that prints the address of a local variable, and check whether the stack grows down.  

Address of main is 0x1059abe20 

Address of global is 0x1059ac020 

Address of local is 0x7fff5a254a68 

Address of local2 is 0x7fff5a254a64 

Address of p is 0x7fa6694027f0 

Address of q is 0x7fa669402870 


The stack is growing down towards smaller numbers 

3) Choose a random number between 1 and 32, and allocate two chunks with that size.   How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers. 

There are 8 bytes between them.

## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically true about files systems but not true of their implementations.

File systems allow users to not think og teh complexity of writing to a HDD or SSD. They can just assume
data is located in "/Users/cwallace/" rather than what physical block of storage it is written to. One primary difference between file systems and their actual implemtations is that file systems act as if they are byte based. Their implementations are block based. 

2) What information do you imagine is stored in an `OpenFileTableEntry`? 

I woud expect the openFileTableEntry to store how much of the file has presently been read.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

OSs do the following:

- Block Transfers: It is only amrginally more expensive to load 8kb as obbosed to 1 byte. The OS will load larger blocks in hope that it will be needed.

- Prefetching: OS loads blocks that are not explicitly called for but are likely to be used in the future

- Buffering: System stores contents of what to write in a buffer that it writes at the end of the program. That way if the value changes several times it only needs to write once

- Caching: Keep copies of recently used blocks in memory

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

The data was not actually written. It was stored in a buffer waiting for other data so that it could write a larger block and function much more efficiently. 

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

FAT has less overhead than inode. An inode based system has to store an indirection block for each file that stores pointers to other blocks of memory for the file to use, if the file is too large for one indirection block a secondary indirection block must be used. A FAT system just functions as a list list. If another block is needed for that file the last pointer in the list just changes to point at a new block of memory. 

6) What is overhead?  What is fragmentation?

Fragmentation: When some blocks are left unused or partially used
Overhead: The amount of space the allocator needs to allocate blocks.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

This principle is a good idea because it allows programs to be more versatile. What works for a file should work for a network socket or a process pipe. However, it might make it so that people who are writing the programs to not understand the different performance implications associated with different implementations of "everything is a file"

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.



## Chapter 6


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

b) Writing to unallocated memory.

c) Reading from a freed chunk.

d) Writing to a freed chunk.

e) Failing to free a chunk that is no longer needed.


3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

2) What is the fundamental problem caches are meant to solve?

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?


## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

3) What is the difference between an interrupt and a context switch?

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

5) Why might a scheduler want to give higher priority to an I/O bound process?

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)



## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

2) What does the `gcc flag -lpthread` do?

3) What does the argument of `pthread_exit` do?

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

5) What goes wrong if several threads try to increment a shared integer at the same time?

6) What does it mean to "lock a mutex"?



## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

6) What happens if you signal a condition variable when there are no waiting threads?

7) Do you have to lock the mutex to signal a condition variable?

8) Does the condition have to be true when you signal a condition variable?


 
## Chapter 11


### Semaphores in C
