#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int global_var = 69;

int stack() {
  char stack_variable[90];
  strcpy(stack_variable, "Hello world!");
  printf("Stack variable: %s\n", stack_variable);
  return 0;
}

int main () {
   /* Global variable */
   extern int global_var;
   printf("Global variable: %d\n", global_var);

   /* Calling the stack */
   stack();

   /* String Literal */
   char *string_literal = "Some things never change...\n";
   printf("String literal: %s", string_literal);

   char *str;
   /* Initial memory allocation in the heap */
   str = (char *) malloc(15);
   strcpy(str, "testing");
   printf("Dynamically allocated string = %s\n", str);

   /* Reallocating memory in the heap */
   str = (char *) realloc(str, 25);
   strcat(str, "123");
   printf("Reallocated string = %s\n", str);

   /* Freeing Memory */
   free(str);

   return(0);
}
