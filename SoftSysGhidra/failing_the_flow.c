#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char greeting[100];
  char say_anything[80];
  char grade;


  printf("Hello there! Enter a greeting in the terminal:\n ");
  scanf("%[^\n]%*c", greeting);

  if (strcmp(greeting, "good evening") == 0) {
    printf("I'll take that. Good evening to you too!\n");
    }
  else if (strcmp(greeting, "good morning") != 0) {
      printf("That's not what I wanted you to say!\n");
      while (strcmp(say_anything, "anything") != 0) {
        printf("Say anything:\n ");
        scanf("%[^\n]%*c", say_anything);
      }
  }
  else {
    printf("That's exactly what I want to hear. Good morning to you too!\n");
  }

  printf("Alright now give me a letter grade you think you'll get on this assignment:\n");
  scanf(" %c", &grade);

   switch(grade) {
      case 'A' :
      case 'a':
         printf("Excellent! I think so too.\n" );
         break;
      case 'B' :
      case 'b':
      case 'C' :
      case 'c':
         printf("I think you'll do better than that.\n" );
         break;
      case 'D' :
      case 'd':
      case 'F' :
      case 'f':
         printf("Relax! You're going to do great.\n");
         break;
      default :
         printf("Give me a letter grade!\n" );
   }

   int a;
   printf("It's time for an example for loop!\n");
   for (a = 10; a < 20; a = a + 1) {
     printf("Value of a: %d\n", a);
   }

  return 0;

}
