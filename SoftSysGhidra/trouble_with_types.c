/* Exercise meant to explore the difficulty of recognizing
variable types for decompilers */

#include <stdio.h>
#include <stdlib.h>

char *getting_char(char *I_am_not_param_1) {
  char character;
  printf("\nPlease type a character in the terminal:\n ");
  scanf(" %c", &character);
  printf("Here's your character: %c\n", character);
  printf("Hello! %s", I_am_not_param_1);
  return I_am_not_param_1; // we're not using this return value
}

char *getting_str(char *I_am_also_not_param_1) {
  printf("\nHey! %s\n",I_am_also_not_param_1);
  return I_am_also_not_param_1; // we're not using this return value either
}

int returning_int() {
  printf("\nreturning_int() here! Does Ghidra think I'm returning an int? Am I undefined8??? I'm having an identity crisis...\n");
  return 2;
}

int multiple_params(int num1, int num2) {
  printf("\nmultiple_params() here! I'm using multiple parameters! Can you figure out which ones?\n");
  return num1 + num2;
}

void doing_nothing() {
  printf("\nGhidra is great at recognizing me... do_nothing()... mwahaha!\n");
}

int main(int argc, char *argv[]) {
  getting_char("getting_char() here... Ghidra is great at picking up what strings say, but not my type.\n");
  getting_str("getting_str() here... Ghidra can't recognize anything... it's so rude!\n");
  int two = returning_int();
  int one = 1;
  int three = multiple_params(one, two);
  printf("\nmultiple_params() here again... can Ghidra recognize my parameters in main()?\n");
  doing_nothing();
  return 0;
}
