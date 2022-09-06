#include <stdio.h>
#include <stdlib.h>

typedef struct _pessoa Pessoa;
struct _pessoa {
  int id;
  Pessoa *next;
};

Pessoa *setPessoa(int id);
Pessoa *orderedInsertion(Pessoa *head, Pessoa *new);
void list(Pessoa *head);
Pessoa *find(Pessoa *head, int id);
void alterarPessoa(Pessoa *aux);
void atualizarIdSistema(Pessoa *aux);

Pessoa *clearPessoas(Pessoa *head, int *count);

int main() {
  Pessoa *head = (Pessoa *)malloc(sizeof(Pessoa));
  head = NULL;

  printf("estammos aqui\n");
  head = orderedInsertion(head, setPessoa(1));
  head = orderedInsertion(head, setPessoa(2));

//  atualizarIdSistema(head);
  head = orderedInsertion(head, setPessoa(7));
  head = orderedInsertion(head, setPessoa(9));
  head = orderedInsertion(head, setPessoa(8));
  head = orderedInsertion(head, setPessoa(2));

  list(head);

//  head = find(head, 5);
//  printf("valor : %s\n", head == NULL ? "nulo" : "valido");

  int count = 0;
 // head = clearPessoas(head, &count);
  printf("%d pessoas foram removidas\n", count);
/*
  Pessoa *teste = malloc(sizeof(Pessoa));
  //teste = orderedInsertion(head, setPessoa(5));
  alterarPessoa(head);

  list(head);
  */
}

Pessoa *setPessoa(int id) {
  Pessoa *new = (Pessoa *)malloc(sizeof(Pessoa));
  new->id = id;
  new->next = NULL;

  return new;
}

Pessoa *orderedInsertion(Pessoa *head, Pessoa *new) {
  if(new->id == 7) {
    printf("troque o id 7 para 88\n");
    scanf("%d", &new->id);
  }
  if (head == NULL)
    head = new;
  else {
    Pessoa *aux, *prev;
    for (aux = head; aux->id < new->id && aux->next != NULL; aux = aux->next) {
      prev = aux;
    }
    // se for a primeira pessoa
    if (aux == head) {
      if (aux->id < new->id)
        aux->next = new;
      else {
        new->next = aux;
        head = new;
      }
    }
    // se for o ultimo
    else if (aux->next == NULL) {
      if (aux->id < new->id)
        aux->next = new;
      else {
        new->next = aux;
        prev->next = new;
      }
    }
    else {
      //new->next = aux->next;
      //aux->next = new;
      new->next = aux;
      prev->next = new;
    }
  }
  return head;
}

void list(Pessoa *head) {
  for(; head != NULL; head = head->next){
    printf("id: %d\n", head->id);
  }
}

Pessoa *find(Pessoa *head, int id) {
  for(; head != NULL; head = head->next)
    if (head->id == id)
      break;
  
  return head;
}

void alterarPessoa(Pessoa *aux) {
  printf("entre um novo id para a pessoa: \n");
  scanf("%d", &aux->id);
}

void atualizarIdSistema(Pessoa *aux) {
  aux->id = 777;
}

Pessoa *clearPessoas(Pessoa *head, int *count) {
  if (head == NULL)
    return head;
  clearPessoas(head->next, count);
  (*count)++;
}
