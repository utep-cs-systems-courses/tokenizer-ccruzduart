#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history() {
  List *list = malloc(sizeof(List*));
  (*list).root = NULL;
  return list;
}

int str_length(char *str) {
  int length = 0;
  while(*str) {
    str++;
    length++;
  }
  return length;
}

void add_history(List *list, char *str) {
  static int id = 0;
  Item *addStr = malloc(sizeof(Item));
  int length = str_length(str);
  (*addStr).str = copy_str(str,length);
  if((*list).root == NULL) {
    (*addStr).id == id;
    (*list).root = addStr;
    id++;
  }
  else {
    puts("inside else");
    Item *pointer = (*list).root;
    while((*pointer).next) {
      puts("inside while else");
      pointer = (*pointer).next;
      id++;
    }
    (*addStr).id = id;
    (*pointer).next = addStr;
  }
}

char *get_history(List *list,int id) {
  Item *pointer = (*list).root;
  if(pointer == NULL) {
    puts("History is empty");
    return "";
  }
  while(pointer) {
    if((*pointer).id == id) {
      return (*pointer).str;
    }
    pointer = (*pointer).next;
  }
  puts("id not found");
  return "";
}

void print_history(List *list) {
  Item *pointer = (*list).root;
  if(pointer == NULL) {
    puts("History is empty");
  }
  else {
    while(pointer) {
      printf("id: %d, String: %s",(*pointer).id, (*pointer).str);
      pointer = (*pointer).next;
    }
  }
}

void free_history(List *list) {
  Item *pointer;
  Item *first = (*list).root;
  while(first) {
    pointer = first;
    first = (*first).next;
    free(pointer);
  }
  free(list);
}
