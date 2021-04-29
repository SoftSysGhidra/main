# Exercise 1: Getting Started with Ghidra

This exercise will introduce you to some of the most essential features of Ghidra.
We will also explore the limits of decompilers and solve a simple CrackMe exercise.

## Trouble with Types
The goal of this exercise is to explore some of the limitations of Ghidra with
recognizing variable types and function return types.

1) Read through *Reverse Engineering with Ghidra* to install Ghidra, become familiar with
the layout of Ghidra, and get a sense of some the limitations of decompilers.

2) Run `gcc trouble_with_types.c -o trouble_with_types` to get the executable file.
You can run it and look at the source code as well to get a sense of what's going on.

3) Create a new Ghidra project (if you haven't done so already) and name it
whatever you'd like (we suggest a short, memorable name).

4) Once you've created your project, go to 'File' and 'Import File' to import the
newly-created executable file `trouble_with_types`. If you import the .c file
into Ghidra, it will be less fun!

5) Click on the green dragon icon to go to the CodeBrowser. In CodeBrowser, use
the Functions window and the Decompiler window to take a look at how
Ghidra recreated `main()`. Open trouble_with_types.c (the source file) in a
text editor or view it in the terminal. What looks the same? What looks different?

6) Use the Functions window and the Decompiler window to take a look at the functions
that `main()` calls (hint: there's 5 of them!). What are some of the similarities
between how Ghidra interpreted these functions? What are some differences? (If
  you want to look at the source code, aka `trouble_with_types.c`, feel free to).

7) In 1-2 sentences, explain why Ghidra is generally bad at recreating
function parameter names and types.

8) In 2-3 sentences, explain why Ghidra can sometimes recognize
what a function is returning, but not recognize the function return type.

9) (Optional) Decompilers can sometimes appear to be black-boxes. In this example, sometimes
`multiple_params()` is shown to take three arguments in `main()`, but in the
function definition, Ghidra defined it as having only two parameters,
`int param1` and `int param2`. Briefly explain your theory/hypothesis as to why
this might have happened.
- Hint: It is usually unclear Walk through the steps of how decompilers recreate functions from the stack.
If you get stuck, Google is your friend.


## Failing the Flow
The goal of this exercise is to explore to another one of the limitations of Ghidra:
it's somewhat bad at recreating the original syntax of the control flow.

1) Run `gcc failing_the_flow.c -o failing_the_flow` to get the executable file.
You can run it and/or look at the source code as well to get a sense of what's going on.

2) Open Ghidra, and using either a new project or an existing project, go to 'File'
and 'Import File' to upload the executable file (should be named `failing_the_flow`).

3) Using the same tools as *Trouble with Types*, take a look at `main()`.
Looking at the source code (failing_the_flow.c) in a different program (such as a
  text editor like VSCode, or in the terminal), comment on some of the differences
  you see.

4) In 1-2 sentences, explain why Ghidra might interpret `for` loops as
while loops.

5) In 3-4 sentences, explain why Ghidra produced a nested `if` statement
in `failing_the_flow`.
- Hint: In CodeBrowser, go to 'Window' and select 'Function Graph', from there you
can see the control flow diagram that Ghidra produced. Notice which assembly instructions
it picked up on. If you get stuck, you can use the strings (such as 'That's not
what I wanted you to say!') as an indicator of where you are in the program. You
can also consult *Reverse Engineering with Ghidra*.

## Mysterious Memory Problems
The goal of this exercise is to explore how Ghidra recognizes data in memory.

1) Run `gcc mysterious_memory_problems.c -o mysterious_memory_problems` to get
the executable file. I highly recommend looking at the source code
(mysterious_memory_problems.c) for this exercise as well, in a text editor such as
 VSCode or Atom.

2) Open Ghidra, and using either a new project or an existing project, go to 'File'
and 'Import File' to upload the executable file (should be named
  `mysterious_memory_problems`).

3) Looking briefly at `main()` and `stack()`, what are some of the differences
you see between what Ghidra created and the actual source code?

4) When we reallocate more memory to `*str` using `realloc()`, what happens? How
does this relate to the way Ghidra interpreted what pointers were being used?

5) In 2-3 sentences, explain what happens when Ghidra processes data on the stack.
Why did we end up losing some information about our local variable in `stack()`?

6) (Optional) Ghidra noticed that a variable assigned in globals exists, but
where did Ghidra define it?
- Hint: You can hover over the variable to see where in the assembly instructions it
was defined.

## CrackMe Exercise
Now that we've learned more about the limitations of Ghidra, we can use Ghidra
to solve a CrackMe exercise!

CrackMe exercises are common software reverse engineering exercises where one
finds a password or a 'flag' from the executable file.

You might ask yourself, "how will I know when I've found the flag"? In our example, the flag
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
