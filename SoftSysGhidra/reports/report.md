# A Quick-Start Guide to Reverse Engineering with Ghidra
*Caitlin Coffey, Zoë McGinnis*

## Links

---

Website: [https://sites.google.com/view/ghidra-reverse-engineering/home](https://sites.google.com/view/ghidra-reverse-engineering/home)

Zine: [https://docs.google.com/document/d/1uGDr5cft-I-VSU9sT8QRybdStJELB7Jgy5nTU16aZ1M/edit?usp=sharing](https://docs.google.com/document/d/1uGDr5cft-I-VSU9sT8QRybdStJELB7Jgy5nTU16aZ1M/edit?usp=sharing)

Exercises: [https://github.com/SoftSysGhidra/main](https://github.com/SoftSysGhidra/main)

## Background

---

Ghidra is a reverse engineering tool developed by the National Security Administration. It is free and open source, making it accessible to those who are interested in reverse engineering.

Our goal was to develop an educational resource for other reverse-engineering amateurs to reference when exploring Ghidra. What we produced is a resource that covers how decompilers work, how disassemblers work, how to use Ghidra, and how to analyze decompiled code. We originally planned to just make a [zine](https://docs.google.com/document/d/1uGDr5cft-I-VSU9sT8QRybdStJELB7Jgy5nTU16aZ1M/edit?usp=sharing), but we were able to go beyond our original goal and publish our information [on a website](https://sites.google.com/view/ghidra-reverse-engineering/home) as well. Our target audience for this resource is current (or former) Software Systems students. We recommend that the reader have a basic knowledge in C and the memory hierarchy.

## Learning Goals

---

Collectively, our learning goals are to understand how Ghidra works and how to use it. Furthermore, we want to make Ghidra more accessible to students that are new to C and assembly coding.

- Zoë specifically wants to learn how to use Ghidra to analyze recompiled code using more advanced tools within Ghidra.
- Caitlin is interested in learning more about the process of how Ghidra decompiles an executable file and translates it into (somewhat) legible C code.

## Implementation

---

### Making the Educational Resource

One design decision we made was to walk through how a disassembler works before walking through how a decompiler works. We made this decision because decompilers are more complicated than disassemblers, and we felt like introducing disassemblers first would allow people to wade into reverse engineering (rather than being pushed off a diving board). 

We also felt it was important to compile a list of Ghidra's features that would be most useful to beginners and explain in detail how to use them rather than giving a less detailed overview of all of Ghidra's features. It is important to thoroughly understand how and when to use Ghidra's simpler tools in order to be able to effectively use the more advanced tools. Although there are a few videos that document Ghidra's simple functionality, we wanted to create documentation that could be more easily referenced than a video.  

In the Fundamental Tools section of our resource, we highlighted some features of Ghidra that do not appear by default in the CodeBrowser window, such as the Function Call Graph, Bytes window, and Defined Strings window. While solving CrackMes, Zoë often finds these tools useful: the Function Call Graph is a good way of visualizing function calls within a program, the bytes tool is helpful when investigating errors that happened during decompilation, and the Defined Strings tools can provide insight into string usage throughout the program.

The Listing window part of Fundamental Tools section goes particularly in-depth, breaking the Listing window into its components and introducing the XRefs tool. The XRefs tool is arguably one of the most useful tools Ghidra offers to users at any level, as it provides the user with a list of other places a variable or function is used within the program. We took care to highlight it as it is often underutilized and underexplained in tutorials. It is also easy to miss for users exploring Ghidra on their own.

The sectional breakdown of the Listing window was meant to explain some of the jumbled mix of assembly-like instructions and C-like code that is given with very little context in Ghidra's interface. It is clear there is a certain organization to the different sections as they are spaced intentionally and color-coded, but it took some research to understand what each section does. Diagrams of the Listing window's breakdown by section were scarce; the ones we did find were overcomplicated and sometimes inaccurate, so we decided to create our own. Below is our original figure showing the breakdown of the Listing window.

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3aa83c7b-4e1f-45ff-a680-21a7b42a955b/listing_breakdown.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3aa83c7b-4e1f-45ff-a680-21a7b42a955b/listing_breakdown.png)

### Making the Exercises

We decided to make two exercises: one for exploring the limits of Ghidra's decompiler, and one for solving a simple CrackMe. We separated the CrackMe from the C code snippets because having them all in one exercise was a little too overwhelming. 

In our first example exercise, we walk through some of the limitations of Ghidra's decompiler. There are some limitations Ghidra has with recreating the control flow, variable types, function types, and data in memory (especially in the heap/globals). Here is part of our `main` function in our example code C code that contains data in every section of memory:

```c
int main () {
   /* Global variable */
   extern int global_var;
   printf("Global variable: %d\n", global_var);

   /* Calling the stack function */
   stack();

   /* String Literal */
   char *string_literal = "Some things never change...\n";
   printf("String literal: %s", string_literal);

   char *str;
   /* Initial memory allocation in the heap */
   str = (char *) malloc(15);
   strcpy(str, "testing");
   printf("Dynamically allocated string = %s\n", str);

...

   return(0);
}
```

In this example, we have a global variable being used in `main()`, a string literal, a variable assigned in the function `stack()`, and a string being dynamically allocated to the heap. 

When the user compiles the file onto their machine, then loads the executable into Ghidra, this is what the recompiled `main` function looks like:

```c
undefined8 main(void) {
  char cVar1;
  undefined8 *__ptr;
  char *__ptr_00;
...
  
  bVar4 = 0;
  printf("Global variable: %d\n",(ulong)global_var);
  stack();
  printf("String literal: %s","Some things never change...\n");
  __ptr = (undefined8 *)malloc(0xf);
  *__ptr = 0x676e6974736574;
  printf("Dynamically allocated string = %s\n",__ptr);
...
  return 0;
}
```

People who try this exercise can see that Ghidra successfully included the `malloc()` call (and other calls). However, Ghidra did not actually define `global_var` anywhere beyond main in the decompiled code. This requires people to look at Ghidra's disassembler to figure out if global_var was assigned to the correct value. 

By looking at small snippets of C code, we can cross-reference the source file with the regenerated code and pinpoint Ghidra's behavior to specific lines of code. It is good preparation for some of the mischievous things that Ghidra's decompiler can do. 

For our CrackMe exercise, we wanted to make sure the program was simple to figure out. We included strings/characters so that the user could clearly see what the program was comparing the incoming argument to. Another design decision we made was to check for individual characters in the password out of order (as shown below):

```c
if (length == 5) {
            if ((argv[1][4] == 't')
                && (argv[1][0] == 'b')
                && (argv[1][2] == 'r')
                && (argv[1][1] == 'o')
                && (argv[1][3] == 'a')) {
                printf("Very nice!\n Pass: {%s}\n", argv[1]);
            }
```

While we could have just checked if the correct string were entered, we decided to make it a bit more difficult (and fun). We were inspired by the fact that malware is purposefully written in a convoluted way, which makes it harder to reverse engineer. As a hint, we also added in an if statement to check the length of the password, so that even if the person solving the CrackMe was confused by the out of order character checking, they would be able to infer that the length of that particular string was significant. As an additional hint, we included `printf("Very nice!\n Pass: {%s}\n", argv[1]);` to indicate success, so that they would know they were getting close to the solution.

## Reflection

---

Over the course of the project, we were able to meet all of our MVP requirements and several of our stretch goals. We would consider our project to be middle to upper-bound. 

Our MVP was to create a fully developed educational resource with an example reverse engineering exercise for people to tackle. We wanted our resource to contain information about how Ghidra works, how to install Ghidra, how to use Ghidra, and how to analyze the decompiled code. Our educational resource covers all of these topics in detail.

Moving forward with our stretch goals, we managed to write enough information for two exercises, one being a CrackMe and the other being snippets of code to test the limitations of Ghidra's decompiler. We also opted to make our resource into a website so that it is accessible to people outside of Software Systems and Olin College. It also acts as a permanent presentation of the product we created that can be referenced in the future.

One stretch goal we did not get to was analyzing malware using Ghidra in a virtual machine. In the end, we opted to further build out the other sections of the educational resource such as the disassembler section and the features of Ghidra. We also wanted to spend time making our website.

## Resources

---

Because of the depth of our educational resource, we ended up consulting several resources. We found Tsviatko Yovtchev's talk on how to build a decompiler particularly useful, as there was not a lot of information out there online beyond his video. The video is about 45 minutes long, but it could be fun to watch some of the highlights of it in Software Systems.

- itskawal2000. “Software Engineering: Reverse Engineering.” *GeeksforGeeks,* GeeksforGeeks, 26 Feb. 2021, [www.geeksforgeeks.org/software-engineering-reverse-engineering/](http://www.google.com/url?q=http%3A%2F%2Fwww.geeksforgeeks.org%2Fsoftware-engineering-reverse-engineering%2F&sa=D&sntz=1&usg=AFQjCNFifAfaLMV15491LbCvL34a3LN_Dw).
- Beginner's Start. “098 What Is the Difference between Disassembler and Decompilers.” *YouTube*, YouTube, 20 Dec. 2018, [www.youtube.com/watch?v=aw-xzxb7Bqw](http://www.youtube.com/watch?v=aw-xzxb7Bqw).
- Duke Nukem, et al. “How Does a Disassembler Really Work?” *Reverse Engineering Stack Exchange*, Stack Exchange Inc., 6 Dec. 2015, [reverseengineering.stackexchange.com/questions/11466/how-does-disassembler-really-work](https://www.google.com/url?q=https%3A%2F%2Freverseengineering.stackexchange.com%2Fquestions%2F11466%2Fhow-does-disassembler-really-work&sa=D&sntz=1&usg=AFQjCNGuXVjJabYcmU-Xekh4vv_f7rZolQ).
- Lukan, Dejan. “Linear Sweep vs Recursive Disassembling Algorithm.” *Infosec*, Infosec Resources, 18 Feb. 2013, [resources.infosecinstitute.com/topic/linear-sweep-vs-recursive-disassembling-algorithm/](https://www.google.com/url?q=https%3A%2F%2Fresources.infosecinstitute.com%2Ftopic%2Flinear-sweep-vs-recursive-disassembling-algorithm%2F&sa=D&sntz=1&usg=AFQjCNHSjPX4ocOmvkkWbv1SYWwZxliZIg).
- Shabeer Sher. “What Is a Compiler and a Decompiler?” *YouTube*, YouTube, 29 Jan. 2019, [www.youtube.com/watch?v=YakeUg_Gcno.](http://www.youtube.com/watch?v=YakeUg_Gcno.)
- Yovtchev, Tsviatko. “How to Build A Decompiler.” *YouTube*, YouTube, 7 Nov. 2019, [www.youtube.com/watch?v=uYZZbteb8Gc](http://www.youtube.com/watch?v=uYZZbteb8Gc).
- “Abstract Syntax Tree.” *Wikipedia*, Wikimedia Foundation, 8 Apr. 2021, [en.wikipedia.org/wiki/Abstract_syntax_tree](https://www.google.com/url?q=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FAbstract_syntax_tree&sa=D&sntz=1&usg=AFQjCNEQyzTPj51IXjVJ4Abz5_3BRPJ4fA).
- “Static Single Assignment Form.” *Wikipedia*, Wikimedia Foundation, 20 Apr. 2021, [en.wikipedia.org/wiki/Static_single_assignment_form](https://www.google.com/url?q=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FStatic_single_assignment_form&sa=D&sntz=1&usg=AFQjCNF9OQt-8ev9binbOGSS4bw8ZrQz2A).
- pp_pankaj. “Software Engineering: Control Flow Graph (CFG).” *GeeksforGeeks*, GeeksforGeeks, 15 May 2019, [www.geeksforgeeks.org/software-engineering-control-flow-graph-cfg/](http://www.google.com/url?q=http%3A%2F%2Fwww.geeksforgeeks.org%2Fsoftware-engineering-control-flow-graph-cfg%2F&sa=D&sntz=1&usg=AFQjCNGv2BkASuEDFkKRuCr06VLi2dWY5w).
- Rider, Chris. “What Is Ghidra?” *YouTube*, YouTube, 29 Apr. 2019, [www.youtube.com/watch?v=z57WM9jr82Y](http://www.youtube.com/watch?v=z57WM9jr82Y)
- Flynn, Colin. “ECED4406 - 0x407 Introducing Ghidra.” *YouTube*, YouTube, 9 Nov. 2020, [www.youtube.com/watch?v=H1sff4Dpo8c](http://www.youtube.com/watch?v=H1sff4Dpo8c).
- Patterson, Steven. “Here Be Dragons: Reverse Engineering with Ghidra - Part 0 [Main Windows & CrackMe].” *Shogun Lab*, Shogun Lab, 12 Apr. 2019, [https://www.shogunlab.com/blog/2019/04/12/here-be-dragons-ghidra-0.html](https://www.shogunlab.com/blog/2019/04/12/here-be-dragons-ghidra-0.html).
- Darwish, Omar. “What're you telling me, Ghidra?” *Byte.how,* Byte.how, [https://byte.how/posts/what-are-you-telling-me-ghidra/](https://byte.how/posts/what-are-you-telling-me-ghidra/).
- stacksmashing. “Ghidra quickstart & tutorial: Solving a simple crackme.” *Youtube*, Youtube, 8 Mar. 2019, [https://www.youtube.com/watch?v=fTGTnrgjuGA](https://www.youtube.com/watch?v=fTGTnrgjuGA).
