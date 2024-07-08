# Interprocess communication using named pipes

## Description

The program utilizes named pipes to enable two processess to communicate. You can run the same program on two separete terminals and have them pass messages between them.

## Usage

Compile the main.c into a binary called main.

```c
cc -o main main.c
```

run the first program

```c
./main
```

open a new terminal in the same folder and run the same binary

```c
./main
```

There is a protocol used to communicate between the two processes. 
+ write - if you prepend write before any string you enter as input, it means you are acting as the process sending the message.
+ read - if you simply type read in the other terminal, you can receive the input sent by the writer
+ exit - used to clean-up resources and to exit

You will need to enter input in the waiting repl once you have run the program. Note that the >_ is not part of the message, it is the representation of the command prompt cursor.

An example write operation would be
```plaintext
>_write Hello there
```

In the other terminal, one can receive(read) this message using

```plaintext
>_read
```

***NOTE**

This is a project in progress and changes will keep occuring...
