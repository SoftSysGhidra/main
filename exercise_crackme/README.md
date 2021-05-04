# CrackMe Exercise

In this exercise, we will use Ghidra to solve a simple CrackMe!

CrackMe exercises are common software reverse engineering exercises where one
finds a password or a 'flag' from the executable file.

You might ask yourself, "how will I know when I've found the flag"? In our example, the flag
will be the password that the program is looking for (in other words, it is the string that 
the user can input which will move past the 'Enter Password' dialogue).

1) Go to the exercise_crackme folder in the SoftSysGhidra repository (using `cd .. && cd exercise_crackme`).

2) Run `gcc crackme.c -o crackme` to get the executable file. Optionally, you can
use the executable files in the exercise_crackme folder and skip this step.

3) Open Ghidra, and using either a new project or an existing project, go to 'File'
and import the executable file (should be named `crackme`).

4) When you think you've found the flag, try running the executable file and
see if it's what the program is looking for. If the password is correct, congrats!
If it didn't work, try again!


Website: https://sites.google.com/view/ghidra-reverse-engineering/home
