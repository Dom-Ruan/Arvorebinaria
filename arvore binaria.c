#include<stdio.h>
#include<stdlib.h>
typedef struct Arvore{
	int dado;
	struct Arvore *esq,*dir;
}arvore;

main(){
	int opt,num;
	arvore *a = NULL;
	do{
        printf("\n\n1-Inserir;\n2-Mostrar arvore;\n3-Profundidade da arvore;\n4-Deletar\n5-Numero de nos\n6-Caminhos\n0-Fechar programa\n");
        scanf("%d",&opt);
        switch(opt){
        	case 1: 
		printf("Digite o numero que deseja inserir: ");
		scanf("%d", &num);
				inserir(&a,num);
        			break;
        case 2:	mostrar(a);
        		break;
        case 3: printf("\nA profundidade e %d\n",profundidade(a));
        		break;
        case 4:
				if(a==NULL)
					printf("Arvore vazia\n");
				else{
			printf("Digite o numero que deseja deletar: ");
		scanf("%d", &num);
				deletar(&a,num);
			}
        			break;
        case 5: printf("A arvore possui %d nos",numnos(a));
        		break;
        case 6: caminho(a,0);
        		break;

        case 0: break;
        default: printf("Opcao invalida\n");
        			break;
        }
	}while(opt!=0);
}

void inserir(arvore **a,int num){
		if(*a==NULL){
			*a = (arvore *)malloc(sizeof(arvore));
			(*a)->dado = num;
			(*a)->esq = (*a)->dir = NULL;
			if(*a!=NULL){
			printf("\n\nDado %d inserido com sucesso\n\n",(*a)->dado);
		}
		}
		else{
			if(num<(*a)->dado)
				inserir(&((*a)->esq),num);
			else if(num>(*a)->dado)
				inserir(&((*a)->dir),num);
		}
}

int profundidade (arvore *a) {
   if (a==NULL) 
      return -1;
   else {
      int esq = profundidade(a->esq);
      int dir = profundidade(a->dir);
      if (esq<dir) 
	  return dir + 1;
      else 
	  	return esq + 1;
   }
}
void deletar(arvore **a,int num){
		if((*a)->dado>num)
			deletar(&((*a)->esq),num);
		else if((*a)->dado<num)
			deletar(&((*a)->dir),num);
		else{
			if((*a)->esq==NULL&&(*a)->dir==NULL){
				free(*a);
				*a = NULL;
			}
			else if((*a)->esq==NULL){
				arvore *x = *a;
				*a = (*a)->dir;
				free(x);
			}
			else if((*a)->dir==NULL){
				arvore *x = (*a);
				(*a) = (*a)->esq;
				free(x);
			}
			else{
				//arvore *x = (*a);
				arvore *y = (*a)->esq;
				while(y->dir!=NULL){
					//x = y;
					y = y->dir;
				}
				(*a)->dado = y->dado;
				y->dado = num;
				deletar(&((*a)->esq),num);
			}
		}
}
void mostrar(arvore *a){
		if(a!=NULL){
		printf("\nPre-order: ");
		pre_order(a);
		printf("\n");
		printf("\nIn-order: ");
		in_order(a);
		printf("\n");
		printf("\nPos order: ");
		pos_order(a);
	}
	else{
		printf("Arvore vazia\n");
	}
}
void pre_order (arvore *a){
	if(a!=NULL){
		printf("%d\t",a->dado);
		pre_order(a->esq);
		pre_order(a->dir);
	}
}

void in_order (arvore *a){
	if(a!=NULL){
		in_order(a->esq);
		printf("%d\t",a->dado);
		in_order(a->dir);
	}
}

void pos_order (arvore *a){
	if(a!=NULL){
		 pos_order(a->esq);
		 pos_order(a->dir);
		printf("%d\t",a->dado);
	}
}

int numnos (arvore *a) { 
    if (a==NULL) 
		return 0;
    else {          
        int numesq = numnos(a->esq);         
        int numdir = numnos(a->dir); 
        return numesq+numdir+1;   
    }
}
void caminho(arvore *x, int b) {
    if (x == NULL) {
        return;
    }
    caminho(x->esq, b+1);    
    printnode(x->dado, b);
    caminho(x->dir, b+1);   
}
void printnode(int c, int b) {
    int i;
    for (i=0;i<b; i++) 
		printf("   ");
    printf("%d\n", c);
}
