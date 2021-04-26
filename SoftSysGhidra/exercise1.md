# Exercise 1: Getting Started with Ghidra

This Exercise will introduce you to some of the most essential features of Ghidra.
We will also explore the limits of decompilers and solve a simple CrackMe exercise.

## Trouble with Types
The goal of this exercise is to explore some of the limitations of Ghidra with
recognizing variable types and function return types.

1) Read through *Think Reverse Engineering* to install Ghidra, become familiar with
the layout of Ghidra, and get a sense of some the limitations of decompilers.

2) Run `gcc trouble_with_types.c -o trouble_with_types` to compile
the .c file onto your machine. You can run it and look at the source code
as well to get a sense of what's going on.

3) Create a new Ghidra project (if you haven't done so already) and name it
whatever you'd like (we suggest a short, memorable name). Once you create your
project, click on the Dragon icon under the Tool Chest to open the CodeBrowser program.

4) In the CodeBrowser program, click on 'File' and 'Import File' to import the
newly-created executable file `trouble_with_types`. If you import the .c file,
it will be less fun!

5) Use the Functions window and the Decompiler window to take a look at how
Ghidra recreated `main()`. What looks the same? What looks different?

6) Use the Functions window and the Decompiler window to take a look at the functions
that `main()` calls. What are some of the similarities between how Ghidra interpreted
these functions? What are some differences? (If you want to look at the source code,
  aka `trouble_with_types.c`, feel free to).

7) In 1-2 sentences, explain why Ghidra is generally bad at recreating
function parameter names and types.

8) (Optional) In a short paragraph, explain why Ghidra can sometimes recognize
what a function is returning, but not recognize the function return type.
- Hint: Walk through the steps of how decompilers recreate functions from the stack.
If you get stuck, Google is your friend.

### TODO double check that this isn't too hard/easy. Also make sure the hint was good enough.

## Failing the Flow
The goal of this exercise is to explore to another one of the limitations of Ghidra:
it's somewhat bad at recreating the original syntax of the control flow.

### TODO write

## Mysterious Memory Problems
The goal of this exercise is to explore how Ghidra recognizes data in the heap
and the stack.

### TODO write

## CrackMe
Now that we've learned more about the limitations of Ghidra, we can use Ghidra
to solve a CrackMe exercise!

- Leave Figure Ghidra stuff to the end

### TODO write
