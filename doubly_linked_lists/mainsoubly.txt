#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOME 40

typedef struct _pessoa Pessoa;

struct _pessoa {
  int id;
  char nome[NOME + 1];
  Pessoa *prev;
  Pessoa *next;
};

typedef struct {
  Pessoa *head;
  Pessoa *tail;
} Lista;

int isEmpty(Lista *lista);
void showList(Lista *lista);
void showListReverse(Lista *lista);
Pessoa *setPessoa();
void appendPessoa(Lista *lista, Pessoa *new);
void pushPessoa(Lista *lista, Pessoa *new);
void insertAfterPessoa(Lista *lista, Pessoa *new, int id);
void deletePessoa(Lista *lista, int id);

Lista *intersec(Lista *lista1, Lista *lista2);

// exercicios da internet

Pessoa *entraDados(int id, char *nome);
void reverseList(Lista *lista);
void removeDuplicatedElement(Lista *lista);

int main() {
  Lista *lista;
  lista = (Lista *)malloc(sizeof(Lista));
  lista->head = NULL;
  lista->tail = NULL;

  appendPessoa(lista, entraDados(1, "luiz"));
  appendPessoa(lista, entraDados(2, "joao"));
  appendPessoa(lista, entraDados(1, "luiz"));
  appendPessoa(lista, entraDados(3, "lenisson"));
  appendPessoa(lista, entraDados(1, "luiz"));
  appendPessoa(lista, entraDados(1, "luiz"));

  printf("lista 1 ----------\n");
  showList(lista);

  //  printf("a ordem da lista foi invertida\n");
  //  reverseList(lista);
  //  printf("lista invertida ---\n");
  //  showList(lista);

  removeDuplicatedElement(lista);
  printf("print lista limpa\n");
  printf("lista 1 ----------\n");
  showList(lista);
  return 0;
}

int main2() {
  Lista *lista1, *lista2, *lista3;
  lista1 = (Lista *)malloc(sizeof(Lista));
  lista1->head = NULL;
  lista1->tail = NULL;
  lista2 = (Lista *)malloc(sizeof(Lista));
  lista2->head = NULL;
  lista2->tail = NULL;
  // lista3 = (Lista *)malloc(sizeof(Lista));

  // populando lista 1
  printf("lista 1 ----------\n");
  showList(lista1);
  appendPessoa(lista1, setPessoa());
  appendPessoa(lista1, setPessoa());
  showList(lista1);

  // populando lista 2
  printf("lista 2 ----------\n");
  showList(lista2);
  appendPessoa(lista2, setPessoa());
  appendPessoa(lista2, setPessoa());
  showList(lista2);

  // fazendo intersessao
  printf("lista 3 ----------\n");
  lista3 = intersec(lista1, lista2);
  showList(lista3);

  // confirmando tudo
  printf("lista 1\n");
  showList(lista1);

  printf("lista 2\n");
  showList(lista2);

  printf("lista 3\n");
  showList(lista3);

  return 0;
}
int main1() {
  int acao, id;
  Lista *lista;
  lista = (Lista *)malloc(sizeof(Lista));
  lista->head = NULL;
  lista->tail = NULL;

  while (1) {
    if (lista->head != NULL && lista->tail != NULL)
      printf("lista->head->name: %s\nlista->tail->nome: %s\n",
             lista->head->nome, lista->tail->nome);
    printf("acao:\n");
    scanf("%d", &acao);

    if (acao == 1) {
      showList(lista);
    } else if (acao == -1) {
      showListReverse(lista);
    } else if (acao == 2) {
      appendPessoa(lista, setPessoa());
    } else if (acao == 3) {
      pushPessoa(lista, setPessoa());
    } else if (acao == 4) {
      printf("inserir pessoa apos id:\n");
      scanf("%d", &id);
      insertAfterPessoa(lista, setPessoa(), id);
    } else if (acao == 5) {
      printf("deletar id:\n");
      scanf("%d", &id);
      deletePessoa(lista, id);
    } else if (acao == 6) {
      printf("saindo\n");
      break;
    }
  }
  return 0;
}

int isEmpty(Lista *lista) {
  int is = 0;
  if (lista->head == NULL)
    is++;
  return is;
}

void showList(Lista *lista) {
  Pessoa *aux;
  if (isEmpty(lista)) {
    printf("lista vazia!\n");
    return;
  }
  for (aux = lista->head; aux != NULL; aux = aux->next)
    printf("---\nid: %d\nnome: %s\n---\n", aux->id, aux->nome);
}

void showListReverse(Lista *lista) {
  Pessoa *aux;
  if (isEmpty(lista)) {
    printf("lista vazia\n");
    return;
  }
  for (aux = lista->tail; aux != NULL; aux = aux->prev)
    printf("---\nid: %d\nnome: %s\n---\n", aux->id, aux->nome);
}
Pessoa *setPessoa() {
  Pessoa *new = (Pessoa *)malloc(sizeof(Pessoa));
  printf("id:\n");
  scanf("%d", &new->id);
  printf("new name:\n");
  scanf("%s", new->nome);

  new->prev = NULL;
  new->next = NULL;
  return new;
}
void appendPessoa(Lista *lista, Pessoa *new) {
  // if head
  if (isEmpty(lista)) {
    lista->head = new;
    lista->tail = new;
    return;
  }
  // if not head:
  lista->tail->next = new;
  new->prev = lista->tail;
  lista->tail = new;
}

void insertAfterPessoa(Lista *lista, Pessoa *new, int id) {
  Pessoa *aux;
  // if lista is empty OR wants to insert after the last element
  if (isEmpty(lista) || id == lista->tail->id) {
    appendPessoa(lista, new);
    return;
  }
  // percorre lista para encontrar user com id passado
  aux = lista->head;
  while (aux->id != id) {
    aux = aux->next;
    // se nao for encontrado id, append to the list
    if (aux == NULL) {
      appendPessoa(lista, new);
      return;
    }
  }
  new->prev = aux;
  new->next = aux->next;
  aux->next = new;
  new->next->prev = new;
}

void pushPessoa(Lista *lista, Pessoa *new) {
  if (isEmpty(lista)) {
    appendPessoa(lista, new);
    return;
  }
  // se a lista nao estiver vazia
  new->next = lista->head;
  lista->head->prev = new;
  lista->head = new;
}

void deletePessoa(Lista *lista, int id) {
  Pessoa *aux;
  // se a pessoa a ser deletada for um ponteiro importante
  if (isEmpty(lista)) {
    printf("lista vazia!\n");
    return;
  }
  for (aux = lista->head; aux != NULL; aux = aux->next) {
    if (aux->id == id) {
      // se na lista houver somente um elemento
      if (aux == lista->head && aux == lista->tail) {
        lista->head = NULL;
        lista->tail = NULL;
      } else if (aux == lista->head) {
        lista->head = aux->next;
        lista->head->prev = NULL;
      } else if (aux == lista->tail) {
        lista->tail = aux->prev;
        lista->tail->next = NULL;
      } else {
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
      }
      free(aux);
      deletePessoa(lista, id);
      break;
    }
  }
}

Lista *intersec(Lista *lista1, Lista *lista2) {
  Lista *lista3 = (Lista *)malloc(sizeof(Lista));
  lista3->head = NULL;
  lista3->tail = NULL;
  Pessoa *aux1, *aux2, *aux_int;
  int name_equals;

  for (aux1 = lista1->head; aux1 != NULL; aux1 = aux1->next) {
    for (aux2 = lista2->head; aux2 != NULL; aux2 = aux2->next) {
      name_equals = strcmp(aux1->nome, aux2->nome);
      if (aux1->id == aux2->id && name_equals == 0) {
        aux_int = (Pessoa *)malloc(sizeof(Pessoa));
        *aux_int = *aux1;
        aux_int->next = NULL;
        aux_int->prev = NULL;
        appendPessoa(lista3, aux_int);
      }
      /*
      if (aux1->id == aux2->id && aux1->nome == aux2->nome) {
        printf("cheguei aqui, aux1>nome: %s\n", aux1->nome);
        aux_int = (Pessoa *)malloc(sizeof(Pessoa));
        aux_int = aux1;
        aux_int->next = NULL;
        aux_int->prev = NULL;
        printf("informacoes aux_int: %s\n", aux_int->nome);
      }
      */
    }
  }
  printf("printando lista de dentro da func\n");
  showList(lista3);
  return lista3;
}
Pessoa *entraDados(int id, char *nome) {
  Pessoa *new = (Pessoa *)malloc(sizeof(Pessoa));
  new->id = id;
  strcpy(new->nome, nome);

  new->prev = NULL;
  new->next = NULL;
  return new;
}

// void reverseList(Lista *lista) { Pessoa }
void reverseList(Lista *lista) {
  Pessoa *prev, *cur, *next;
  prev = NULL;
  next = NULL;
  cur = lista->head;
  while (cur != NULL) {
    next = cur->next;
    cur->next = prev;
    cur->prev = next;
    prev = cur;
    cur = next;
  }
  lista->head = prev;
}

void removeDuplicatedElement(Lista *lista) {
  Pessoa *aux, *aux2, *dup;
  int is_equal;
  for (aux = lista->head; aux->next != NULL; aux = aux->next)
    for (aux2 = aux->next; aux2->next != NULL; aux2 = aux2->next) {
      is_equal = strcmp(aux->nome, aux2->nome);
      if (aux->id == aux2->id && is_equal == 0) {
        dup = aux2;
        aux2->prev->next = aux2->next;
        aux2->next->prev = aux2->prev;
        aux2 = aux2->prev;
        free(dup);
      }
    }
}
