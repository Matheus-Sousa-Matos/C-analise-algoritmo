#include <stdio.h>
#include <stdlib.h>

typedef struct no {

     int chave;

     struct no *prox;

} node;

int main(){

    node node[10];
   
    for (int i = 0; i < 10; i++)
    {
        node[i].chave = 10+i;
        printf("valor chave: %d\n",node[i].chave);
    }

    func(node);

    return 0;
}

int func(node *p) {

  int ret=0;

  if (p != NULL) {

    ret = func(p->prox)+1;

    printf("%d", p->chave);

    for(int i=0;i<ret;i++)

       printf("%c",'*');

  }

  return ret;

}