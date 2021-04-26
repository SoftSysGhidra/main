/* Exercise meant to explore the difficulty of recognizing
variable types for decompilers */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getting_char(char *I_am_not_param_1) {
  char character;
  printf("\nPlease type a character in the terminal:\n ");
  scanf(" %c", &character);
  printf("Here's your character: %c", character);
  return I_am_not_param_1; // we're not using this return value
}

char *getting_str(char *I_am_also_not_param_1) {
  printf("\nAlso, I just want to say a few words... %s\n",I_am_also_not_param_1);
  return I_am_also_not_param_1; // we're not using this return value either
}

int returning_int() {
  printf("\nGhidra is great at recognizing my variable type, but not my return type.\n");
  return 0; // Wow Ghidra knows this!
}

void doing_nothing() {
  printf("\nGhidra is great at recognizing me... do_nothing()... mwahaha!\n");
}

int main(int argc, char *argv[]) {
  int ghidra_pretends_i_dont_exist = 0;
  getting_char("\nGhidra is great at picking up what strings say, but not my type.\n");
  getting_str("\nGhidra can't recognize anything... it's so rude!\n");
  returning_int();
  doing_nothing();
  return ghidra_pretends_i_dont_exist;
}
