# CST-315-Assignment 1 (Producer and Consumer)
**Course:** CST 315 Operating Systems
**Programmer:** Komal Khan 

# Producer and Consumer program in C **[Assignment-1.c](Assignment-1.c)**

## How to run
### Prerequisites
- Kate text editor
- Ubuntu Linux (24.04.1)

### Steps
1. Write the code in Kate text editor then save the file in the directory as Assignment-1.cpp
2. Use the gcc (C compiler to run the code)
3. In Linux type:
   gcc Assignment-1.c -o Assignment-1 -pthread (gcc is compiler, Assignment-1.c is the source file, -o is the output the executable file)
   ./ Assignment-1  (specify the path where the file is located)
4. Enter number of Producers and then enter the number of consumers after output being displayed press Ctrl + C 

### Output:

Enter the number of Producers: 5

Enter the number of Consumers: 5
Producer Thread 127197278893760 produced item 1 at slot 0 | Total in buffer: 1
Producer Thread 127197270501056 produced item 1 at slot 1 | Total in buffer: 2
Producer Thread 127197262108352 produced item 1 at slot 2 | Total in buffer: 3
Producer Thread 127197253715648 produced item 1 at slot 3 | Total in buffer: 4
Producer Thread 127197245322944 produced item 1 at slot 4 | Total in buffer: 5
Consumer Thread 127197236930240 consumed item 1 from slot 0 | Total in buffer: 4
Consumer Thread 127197228537536 consumed item 1 from slot 1 | Total in buffer: 3
Consumer Thread 127197220144832 consumed item 1 from slot 2 | Total in buffer: 2
Consumer Thread 127197211752128 consumed item 1 from slot 3 | Total in buffer: 1
Consumer Thread 127197203359424 consumed item 1 from slot 4 | Total in buffer: 0








