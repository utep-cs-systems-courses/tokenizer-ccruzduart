#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main() {
  char inStr[100];
  List *history = init_history();
  
  while(1) {
    printf("\nSelect an option \n\na) tokenize \nb) history \nc) select history \nd) exit \n");
    printf(">>");
    int c = getchar();

    switch(c) {
    case 'a':
      printf("\nPlease enter the token \n>>");
      c = getchar();
      fgets(inStr,100,stdin);
      printf("\n");
      char** tokens = tokenize(inStr);
      add_history(history, inStr);
      print_tokens(tokens);
      free_tokens(tokens);
      break;
    case 'b':
      print_history(history);
      c = getchar();
      break;
    case 'c':
      printf("\nPlease enter the id you want to grab \n>>");
      c = getchar();
      int id = getchar();
      char *str = get_history(history,id);
      printf("String for id: %d: %s",id,str);
      break;
    case 'd':
      printf("closing..\n");
      goto done;
    default:
      printf("\nPlease select a valid option, '%c' is not a valid option \n");
      break;
    }
  }
 done:
  return 0;
}
