#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME 40

typedef struct _pessoa Pessoa;
struct _pessoa {
  int id;
  char nome[NOME + 1];
  Pessoa *next;
};

void listPessoas(Pessoa *head);
void inverseListPessoas(Pessoa *head);
Pessoa *setPessoa(int id, char *nome);
Pessoa *appendPessoa(Pessoa *head, Pessoa *new);
Pessoa *pushPessoa(Pessoa *head, Pessoa *new);
Pessoa *insertAfter(Pessoa *head, int id, Pessoa *new);
Pessoa *insertBefore(Pessoa *head, int id, Pessoa *new);
Pessoa *deletePessoa(Pessoa *head, int id);
Pessoa *quit(Pessoa *head);

// trabalhando com mais de uma lista
Pessoa *intersec(Pessoa *head1, Pessoa *head2);

// exercicios da internet
void getNhNode(Pessoa *head, int n);  // encontrar enesimo elemento de uma lista
Pessoa *copyEntireList(Pessoa *head); // duplica uma lista inteira - ERRATA
                                      // copia somente o elemento head;
Pessoa *duplicateList(Pessoa *head);  // em tese realmente duplica toda a lista
Pessoa *reverseList(Pessoa *head);

int main5() {
  Pessoa *head;
  head = (Pessoa *)malloc(sizeof(Pessoa));
  head = NULL;
  head = appendPessoa(head, setPessoa(1, "2luiz"));
  head = appendPessoa(head, setPessoa(2, "2andre"));
  head = appendPessoa(head, setPessoa(3, "2filipe"));
  head = appendPessoa(head, setPessoa(4, "2joao"));
  head = appendPessoa(head, setPessoa(5, "2gustavo"));
  printf("listando pessoas da lista:\n");
  listPessoas(head);
  printf("---------------------------------------------\n");

  printf("lista foi invertida: \n");
  head = reverseList(head);
  printf("listando lista invertida:\n");
  listPessoas(head);
  printf("---------------------------------------------\n");

  return 0;
}
int main4() {
  Pessoa *head;
  head = (Pessoa *)malloc(sizeof(Pessoa));
  head = NULL;
  head = appendPessoa(head, setPessoa(1, "2luiz"));
  head = appendPessoa(head, setPessoa(2, "2andre"));
  head = appendPessoa(head, setPessoa(3, "2filipe"));
  head = appendPessoa(head, setPessoa(4, "2joao"));
  head = appendPessoa(head, setPessoa(5, "2gustavo"));
  printf("listando pessoas da lista:\n");
  listPessoas(head);
  printf("---------------------------------------------\n");

  printf("criando nova lista\n");
  Pessoa *newHead;
  newHead = duplicateList(head);
  printf("listando conteudo da nova lista new head:\n");
  listPessoas(newHead);
  printf("---------------------------------------------\n");

  printf("deletando completamente toda a lista original:\n");
  head = quit(head);
  printf("---------------------------------------------\n");
  printf("listando pessoas da lista:\n");
  listPessoas(head);
  printf("---------------------------------------------\n");

  printf("listando novamente a newHead:\n");
  listPessoas(newHead);
  printf("---------------------------------------------\n");

  return 0;
}
int main3() {
  Pessoa *head;
  head = (Pessoa *)malloc(sizeof(Pessoa));
  head = NULL;
  head = appendPessoa(head, setPessoa(1, "luiz"));
  head = appendPessoa(head, setPessoa(2, "andre"));
  head = appendPessoa(head, setPessoa(3, "filipe"));
  head = appendPessoa(head, setPessoa(4, "joao"));
  head = appendPessoa(head, setPessoa(5, "gustavo"));
  printf("listando pessoas da lista:\n");
  listPessoas(head);
  printf("---------------------------------------------\n");

  printf("buscando a terceira pessoa da lista: \n");
  getNhNode(head, 3);
  printf("---------------------------------------------\n");

  printf("criando nova lista newHead\n");
  Pessoa *newHead;
  newHead = copyEntireList(head);
  printf("listando pessoas da completamente nova lista:\n");
  listPessoas(newHead);
  printf("---------------------------------------------\n");

  printf("deletando completamente toda a lista original:\n");
  head = quit(head);
  printf("---------------------------------------------\n");
  printf("listando pessoas da lista:\n");
  listPessoas(head);
  printf("---------------------------------------------\n");

  printf("listando novamente a newHead:\n");
  listPessoas(newHead);
  printf("---------------------------------------------\n");
  return 0;
}

int main() {
  Pessoa *head1, *head2, *head3;
  head1 = (Pessoa *)malloc(sizeof(Pessoa));
  head2 = (Pessoa *)malloc(sizeof(Pessoa));
  head1 = NULL;
  head2 = NULL;

  head1 = appendPessoa(head1, setPessoa(2, "luiz"));
  head1 = appendPessoa(head1, setPessoa(2, "andre"));
  head1 = appendPessoa(head1, setPessoa(3, "joao"));
  printf("listando pessoas primeira lista:\n");
  listPessoas(head1);
  printf("---------------------------------------------\n");

  head2 = appendPessoa(head2, setPessoa(2, "lluiz"));
  head2 = appendPessoa(head2, setPessoa(2, "andre"));
  head2 = appendPessoa(head2, setPessoa(3, "jjoao"));
  printf("listando pessoas: segunda lista\n");
  listPessoas(head2);
  printf("---------------------------------------------\n");

  head3 = intersec(head1, head2);
  printf("listando pessoas terceira lista:\n");
  listPessoas(head3);
  printf("---------------------------------------------\n");

  printf("retirando segundo elemento da primeira lista\n");
  head1 = quit(head1);
  printf("retirando segundo elemento da segunda lista\n");
  head2 = quit(head2);

  printf("listando pessoas primeira lista:\n");
  listPessoas(head1);
  printf("---------------------------------------------\n");
  printf("listando pessoas: segunda lista\n");
  listPessoas(head2);
  printf("---------------------------------------------\n");
  printf("listando pessoas terceira lista:\n");
  listPessoas(head3);
  printf("---------------------------------------------\n");
  return 0;
}

int main1() {
  Pessoa *head;
  head = (Pessoa *)malloc(sizeof(Pessoa));
  head = NULL;
  // populando a lista;
  head = appendPessoa(head, setPessoa(1, "luiz"));
  head = appendPessoa(head, setPessoa(2, "andre"));

  printf("listando pessoas:\n");
  listPessoas(head);
  printf("lista inversa:\n");
  inverseListPessoas(head);
  printf("---------------------------------------------\n");

  head = pushPessoa(head, setPessoa(3, "joao"));
  printf("listando pessoas:\n");
  listPessoas(head);
  printf("---------------------------------------------\n");

  head = insertAfter(head, 1, setPessoa(4, "filipe"));
  head = insertAfter(head, 2, setPessoa(4, "filipe"));
  head = insertAfter(head, 3, setPessoa(4, "filipe"));
  printf("listando pessoas:\n");
  listPessoas(head);
  printf("---------------------------------------------\n");

  head = insertBefore(head, 1, setPessoa(5, "vlaspatta"));
  head = insertBefore(head, head->id, setPessoa(5, "vlaspatta"));
  head = insertBefore(head, 4, setPessoa(5, "vlaspatta"));
  printf("listando pessoas:\n");
  listPessoas(head);
  printf("---------------------------------------------\n");

  /*
  head = deletePessoa(head, 1);
  head = deletePessoa(head, 2);
  head = deletePessoa(head, 3);
  head = deletePessoa(head, 4);
  head = deletePessoa(head, 5);
  printf("listando pessoas:\n");
  listPessoas(head);
  printf("---------------------------------------------\n");
  */

  head = quit(head);
  printf("listando pessoas:\n");
  listPessoas(head);
  printf("---------------------------------------------\n");
  return 0;
}

void listPessoas(Pessoa *head) {
  Pessoa *aux;
  for (aux = head; aux != NULL; aux = aux->next)
    printf("---\nid: %d\nnome: %s\n[end = %p]\n---\n", aux->id, aux->nome, aux);
  if (head == NULL)
    printf("lista vazia!\n");
}

void inverseListPessoas(Pessoa *head) {
  if (head == NULL)
    return;
  inverseListPessoas(head->next);
  printf("---\nid: %d\nnome: %s\n---\n", head->id, head->nome);
}

Pessoa *setPessoa(int id, char *nome) {
  Pessoa *new = (Pessoa *)malloc(sizeof(Pessoa));
  new->id = id;
  strcpy(new->nome, nome);
  new->next = NULL;
  return new;
}

Pessoa *appendPessoa(Pessoa *head, Pessoa *new) {
  Pessoa *aux;
  if (head == NULL) {
    head = new;
    return head;
  }
  for (aux = head; aux->next != NULL; aux = aux->next)
    ;
  aux->next = new;
  return head;
}

Pessoa *pushPessoa(Pessoa *head, Pessoa *new) {
  if (head == NULL)
    head = new;
  else {
    new->next = head;
    head = new;
  }
  return head;
}

Pessoa *insertAfter(Pessoa *head, int id, Pessoa *new) {
  Pessoa *aux;
  if (head == NULL) {
    head = new;
    printf("nao havia ninguem na lista!\n");
    return head;
  }
  for (aux = head; aux != NULL; aux = aux->next)
    if (aux->id == id)
      break;

  if (aux == NULL)
    appendPessoa(head, new);
  else {
    new->next = aux->next;
    aux->next = new;
  }

  return head;
}

Pessoa *insertBefore(Pessoa *head, int id, Pessoa *new) {
  Pessoa *aux = head;
  Pessoa *aux_prev;
  if (head == NULL) {
    head = new;
    return head;
  }

  while (aux != NULL) {
    if (aux->id == id) {
      if (aux == head) {
        head = pushPessoa(head, new);
      } else {
        new->next = aux;
        aux_prev->next = new;
        break;
      }
    }
    aux_prev = aux;
    aux = aux->next;
  }
  return head;
}

Pessoa *deletePessoa(Pessoa *head, int id) {
  Pessoa *aux, *aux_prev;
  aux = head;
  if (head == NULL) {
    printf("a lista esta vazia, nada para deletar!\n");
    return head;
  }

  while (aux != NULL) {
    if (aux->id == id) {
      if (aux == head) {
        head = aux->next;
        free(aux);
        aux = head;
        continue;
      } else {
        aux_prev->next = aux->next;
        free(aux);
        aux = aux_prev;
      }
    }
    aux_prev = aux;
    aux = aux->next;
  }
  return head;
}

Pessoa *quit(Pessoa *head) {
  if (head == NULL)
    return head;
  quit(head->next);
  free(head);
}

Pessoa *intersec(Pessoa *head1, Pessoa *head2) {
  Pessoa *aux1, *aux2, *aux3, *head3;
  int same_name;
  head3 = (Pessoa *)malloc(sizeof(Pessoa));
  head3 = NULL;
  for (aux1 = head1; aux1 != NULL; aux1 = aux1->next)
    for (aux2 = head2; aux2 != NULL; aux2 = aux2->next) {
      same_name = strcmp(aux1->nome, aux2->nome);
      if (aux1->id == aux2->id && same_name == 0) {
        printf("estou chegando aqui\n");
        aux3 = (Pessoa *)malloc(sizeof(Pessoa));
        *aux3 = *aux1;
        aux3->next = NULL;
        head3 = appendPessoa(head3, aux3);
      }
    }
  return head3;
}

void getNhNode(Pessoa *head, int n) {
  Pessoa *aux = head;
  for (n--; n >= 0; n--) {
    if (n == 0) {
      printf("enesimo elemento da lista: \n---\n%d\n%s\n---\n", aux->id,
             aux->nome);
      break;
    } else if (aux->next != NULL) {
      aux = aux->next;
    } else {
      printf("a lista nao tem o enesimo elemento entrado. fim da lista\n");
    }
  }
}

Pessoa *copyEntireList(Pessoa *head) {
  Pessoa *newHead;
  newHead = (Pessoa *)malloc(sizeof(Pessoa));
  *newHead = *head;
  return newHead;
}
Pessoa *appendFromDuplicatedList(Pessoa *head, Pessoa *new) {
  Pessoa *aux;
  if (head == NULL) {
    head = new;
    return head;
  }
  // chegamos assim ao ultimo elemento da lista sem sair da lista
  for (aux = head; aux->next != NULL; aux = aux->next)
    ;
  aux->next = new;

  return head;
}

Pessoa *duplicateList(Pessoa *head) {
  Pessoa *newLista, *aux, *newAux;
  newLista = (Pessoa *)malloc(sizeof(Pessoa));
  newLista = NULL;

  for (aux = head; aux != NULL; aux = aux->next) {
    newAux = (Pessoa *)malloc(sizeof(Pessoa));
    *newAux = *aux;
    newAux->next = NULL;
    newLista = appendFromDuplicatedList(newLista, newAux);
  }

  return newLista;
}

Pessoa *reverseList(Pessoa *head) {
  Pessoa *aux, *prev, *cur, *next;
  // se a lista estiver vazia
  if (head == NULL) {
    printf("lista vazia, nao eh possivel invertela!\n");
    // se a lista tiver somente um elemento
  } else if (head->next == NULL) {
    printf("somente um elemento na lista, ela esta invertida!\n");
    // lista com dois elementos
  } else if (head->next->next == NULL) {
    printf("a lista tinha somente dois elementos. sua ordem foi alterada!\n");
    head->next->next = head;
    head = head->next->next;
    // lista com tres ou mais elementos
  } else {

    prev = NULL;
    cur = head;
    next = NULL;
    while (cur != NULL) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    head = prev;
  }
  return head;
}
