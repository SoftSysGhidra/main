# Exercise 1: Getting Started with Ghidra

This Exercise will introduce you to some of the most essential features of Ghidra.
We will also explore the limits of decompilers and solve a simple CrackMe exercise.

## Trouble with Types
The goal of this exercise is to explore some of the limitations of Ghidra with
recognizing variable types and function return types.

1) Read through *Think Reverse Engineering* to install Ghidra, become familiar with
the layout of Ghidra, and get a sense of some the limitations of decompilers.

2) Run `gcc trouble_with_types.c -o trouble_with_types` to get the executable file.
You can run it and look at the source code as well to get a sense of what's going on.

3) Create a new Ghidra project (if you haven't done so already) and name it
whatever you'd like (we suggest a short, memorable name).

4) Once you've created your project, go to 'File' and 'Import File' to import the
newly-created executable file `trouble_with_types`. If you import the .c file,
it will be less fun!

5) Click on the green dragon icon to go to the CodeBrowser. In CodeBrowser, use
the Functions window and the Decompiler window to take a look at how
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

CrackMe exercises are common software reverse engineering exercises where one
finds a password or a 'flag' from the executable file.

You might ask, how will I know when I've found the flag? In our example, the flag
will be the password that the program is looking for (in other words, it is the string
  that the user can input which will move past the 'Enter Password' dialogue).

1) Go to the exercise_crackme folder in the SoftSysGhidra repository (using `cd .. && cd exercise_crackme`).

2) Run `gcc crackme.c -o crackme` to get the executable file. Optionally, you can
use the executable files in the exercise_crackme folder and skip this step.

3) Open Ghidra, and using either a new project or an existing project, go to 'File'
and import the executable file (should be named `crackme`).

4) When you think you've found the flag, try running the executable file and
see if it's what the program is looking for. If the password is correct, congrats!
If it didn't work, try again!
