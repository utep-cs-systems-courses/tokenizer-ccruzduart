#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c) {
  return((c == '\t' || c == ' ') && c);
}

int non_space_char(char c) {
  return (!space_char(c) && c);
}

char *word_start(char *str) {
  while (space_char(*str)) str++;
  return str;
}

char *word_terminator(char *word) {
  while(non_space_char(*word)) word++;
  return word;
}

int count_words(char *str) {
  int count = 0;
  while(non_space_char(*str)) {
    str = word_terminator(str);
    str = word_start(str);
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len) {
  char *copy = malloc((len+1)*sizeof(char));
  for (int i = 0; i < len; i++) {
    copy[i] = inStr[i];
  }
  return copy;
}

char **tokenize(char *str) {
  int words = count_words(str);
  char **tokens = malloc((words+1)*sizeof(char*));
  for(int i = 0; i < words; i++) {
    str = word_start(str);
    int length = (word_terminator(str) - word_start(str));
    tokens[i] = copy_str(str,length);
    str = word_terminator(str);
  }
  return tokens;
}

void print_tokens(char **tokens) {
  for(int i = 0; tokens[i]; i++) {
    printf("Token[%d]: %s\n",i,tokens[i]);
  }
}

void free_tokens(char **tokens) {
  for(int i = 0; tokens[i]; i++) {
    free(tokens[i]);
  }
  free(tokens);
}
