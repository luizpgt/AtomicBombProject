#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINK 60

typedef struct _link Link;
struct _link {
  char link[MAX_LINK + 1];
  Link *next;
};

Link *setLink(char *link);
Link *push(Link *top, Link *new);
Link *printAndFree(Link *link);
Link *quit2(Link *top);

int main() {
  Link *top = (Link *)malloc(sizeof(Link));
  top = NULL;

  char choice[MAX_LINK + 1];
  int should_quit = 0;
  while (!should_quit) {
    scanf("%s", choice);
    if (strcmp(choice, "B") == 0)
      top = printAndFree(top);
    else if (strcmp(choice, "E") == 0) {
      if (top != NULL)
        top = quit2(top);
      else
        printf("!\n");
      should_quit++;
    } else
      top = push(top, setLink(choice));
  }
  return 0;
}

Link *setLink(char *link) {
  Link *new = (Link *)malloc(sizeof(Link));
  snprintf(new->link, MAX_LINK, "%s", link);
  new->next = NULL;

  return new;
}

Link *push(Link *top, Link *new) {
  new->next = top;
  top = new;
  return top;
}

Link *printAndFree(Link *link) {
  Link *top;
  if (link == NULL) {
    printf("Vazio\n");
    return NULL;
  }
  top = link->next;

  printf("%s\n", link->link);
  free(link);
  return top;
}

Link *quit2(Link *top) {
  if (top == NULL)
    return top;
  quit2(top->next);
  free(top);
  printf("@\n");
}
