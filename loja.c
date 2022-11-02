#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.h"

#define MAX 100

void iniVet(ppProd ppp){
	int i;
	for(i=0; i<MAX; i++){     
    	ppp[i] = NULL; 
  	}   
}

void iniCar(ppCarrinho ppc){
	int i;
	for(i = 0; i<MAX; i++){
		ppc[i] = NULL;
	}
}


int incluirProdInic(ppProd ppp){
    int numProdutos, i; 
    
    printf("\n              Bem Vindo a Sofrimento Store");
    printf("\nPara comecar, insira o estoque inicial: ");
    printf("\nInsira a quantidade de produtos a serem inseridos: ");
    scanf("%d",&numProdutos);
        
    for(i=0; i<numProdutos; i++){     
      ppp[i] = (PProduto) malloc(sizeof(Produto));
      if (ppp[i] == NULL){
         printf("\n\n<ERROR>Memoria insuficiente!\n\n");
         exit(1);           
      }
		printf("\n\nInforme o codigo do produto: ");
		scanf("%d", &ppp[i]->codigo);
		printf("\nInforme a descricao do produto: ");
		scanf(" %[^\n]", ppp[i]->descricao);		
		printf("\nInforme a quantidade do produto em estoque: ");
		scanf("%d", &ppp[i]->qtd_estoque);
		printf("\nInforme o preco do produto: ");
		scanf("%f", &ppp[i]->preco);
    }
    // Nesta versão, temos que usar -> para a    
    // pois o vetor  contém ponteiros para estruturas e não as estruturas de fato 
   //ppp = realloc(*ppp, 1*(numProdutos));                
   return numProdutos;  
}

int incluiPdotutos(ppProd ppp, int aux){
    int numProdutos, i; 
    
    printf("\nInforme o numero de produtos a serem incluidos na loja: ");
    scanf("%d",&numProdutos);
        
    for(i=aux; i<numProdutos + aux; i++){     
      ppp[i] = (PProduto) malloc(sizeof(Produto));
      if (ppp[i] == NULL){
         printf("\n\n<ERROR>Memoria insuficiente!\n\n");
         exit(1);           
      }
		printf("\n\nInforme o codigo do produto: ");
		scanf("%d", &ppp[i]->codigo);
		printf("\nInforme a descricao do produto: ");
		scanf(" %[^\n]", ppp[i]->descricao);		
		printf("\nInforme a quantidade do produto em estoque: ");
		scanf("%d", &ppp[i]->qtd_estoque);
		printf("\nInforme o preco do produto: ");
		scanf("%f", &ppp[i]->preco);
    }
    /* Nesta versão, temos que usar -> para a    
     pois o vetor  contém ponteiros para estruturas e não as estruturas de fato */
    aux += numProdutos;               
   return aux;  
}

void alteraProdutos(int numProdutos, ppProd ppp){
	int i;

    listaProdutos(numProdutos, ppp, numProdutos);
    printf("\n\nInforme a posicao do produto a ser alterado: ");
    scanf("%d", &i);
    printf("\nInforme o codigo do produto: ");
    scanf("%d", &ppp[i]->codigo);
    printf("\nInforme a descricao do produto: ");
    scanf(" %[^\n]", ppp[i]->descricao);
    printf("\nInforme a quantidade do produto em estoque: ");
    scanf("%d", &ppp[i]->qtd_estoque);
    printf("\nInforme o preco do produto: ");
    scanf("%f", &ppp[i]->preco);
    printf("\n              Produto alterado com sucesso!");
}

int excluir_produtos(ppProd ppp, int numProdutos){
	int i, j;

    printf("\nInforme o indice do produto a ser excluido: ");
    scanf("%d", &i);
    if(numProdutos == 2 && i == 1){
		return (numProdutos - 1);
	}else if(numProdutos == 2 && i == 0){
		for(j = i; j < numProdutos; j++){
			ppp[j] = ppp[j+1];
		}
		return (numProdutos - 1);
	}else if(i == numProdutos - 1 && i != 0){
		return (numProdutos - 1);
	}else if(i == numProdutos - 1 && i == 0){
		return (numProdutos - 1);
	}else{
		for(j = i; j < numProdutos - 1; j++){
    		ppp[j] = ppp[j+1];
		}
		return (numProdutos - 1);
	}
	
}

void consultar_produtos(ppProd ppp, int numProdutos){
	int i, j, k, sair;
	printf("\nNumero  Descricao\n");
	for(i=0; i<numProdutos; i++){    
    	printf("\n%d	%s			 \n", i,	ppp[i]->descricao);
  	}
  	printf("\nInforme o indice do produto a ser consultado: ");
  	scanf("%d", &j);
  	do{
  		system("cls");
  		printf("\nCodigo                (1)\n");		
		printf("\nQuantidade em estoque (2)\n");	
		printf("\nValor                 (3)\n");
		printf("\nSair                  (4)\n");
  		printf("\n\nEscolha a alternativa para detalhes: ");
  		scanf("%d", &k);
	  	switch(k){
	  		case 1:
	  			printf("\nCODIGO: %d", ppp[j]->codigo);
	  			getch();
	  			system("cls");
	  			break;
	  		case 2:
	  			printf("\nQUANTIDADE: %d", ppp[j]->qtd_estoque);
	  			getch();
	  			system("cls");
	  			break;
	  		case 3:
	  			printf("\nVALOR: %.2f", ppp[j]->preco);
	  			getch();
	  			system("cls");
	  			break;
	  		case 4:
	  			sair = 1;
	  			break;
		}
  	}while(sair == 0);	
}

void listaProdutos(int numProdutos, ppProd ppp, int qtd_produtos_c){
	//if(ppp->qtd_estoque != NULL)
  printf("\nNumero	Codigo	Descricao	Quantidade em estoque	Valor\n");
  int i, j;
  for(i=0; i<numProdutos; i++){    
    printf("\n%d	%d	%s			%d		%.2f \n", i,	ppp[i]->codigo, ppp[i]->descricao, ppp[i]->qtd_estoque, ppp[i]->preco);
  }                                         
}

int adicionaCarrinho(ppCarrinho ppc, ppProd ppp, int qtd_produtos_c){
	int i, escolha, escolha2, aux, aux2; 
	int aux_c = 0;
	int j = 0;
	printf("\nInforme o indice do produto a ser adicionado ao carrinho: ");
	scanf("%d", &escolha);
	printf("\nInforme a quantidade deste produto a ser adicionado: ");
	scanf("%d", &escolha2);
	
	int x = 0;
	for(i=0;i<qtd_produtos_c;i++){
		if(ppc[i]->codigo==ppp[escolha]->codigo){
			x = x + 1;
		}
	}

	if(ppp[escolha]->qtd_estoque >= (escolha2+x)){
		escolha2 = escolha2 + qtd_produtos_c;
		if(qtd_produtos_c == 1){
			for(i = 0; i < escolha2; i++){
				ppc[i] = (PCarrinho) malloc(sizeof(Carrinho));
				ppc[i]->codigo = ppp[escolha]->codigo;
				strcpy(ppc[i]->descricao, ppp[escolha]->descricao);
				ppc[i]->qtd_estoque = ppp[escolha]->qtd_estoque;
				ppc[i]->preco = ppp[escolha]->preco;
			}
		}else{
			for(i = qtd_produtos_c; i < escolha2; i++){
				ppc[i] = (PCarrinho) malloc(sizeof(Carrinho));
				ppc[i]->codigo = ppp[escolha]->codigo;
				strcpy(ppc[i]->descricao, ppp[escolha]->descricao);
				ppc[i]->qtd_estoque = ppp[escolha]->qtd_estoque;
				ppc[i]->preco = ppp[escolha]->preco;
			}
		}
	}else{
		printf("\n<<Estoque indispon�vel!!!>>");
	}
	getch();
	return escolha2;
}

void listaCarrinho(int qtd_produtos_c, ppCarrinho ppc){
	printf("\nNumero	Codigo	Descricao	Valor\n");
	int i, j; 
	float soma = 0;
	           
	for(i=0; i<qtd_produtos_c; i++){
		if(ppc[i]->preco )    
    printf("\n%d	%d	%s	        %.2f \n", i,	ppc[i]->codigo, ppc[i]->descricao, ppc[i]->preco);
    	soma = soma + ppc[i]->preco;
	}
	printf("\n\nPRECO DO CARRINHO: %.2f", soma);
}

int excluiCarrinho(ppCarrinho ppc, int qtd_produtos_c){
	int i, j;

    printf("\nInforme o indice do produto a ser excluido: ");
    scanf("%d", &i);
    if(qtd_produtos_c == 2 && i == 1){
		return (qtd_produtos_c - 1);
	}else if(qtd_produtos_c == 2 && i == 0){
		for(j = i; j < qtd_produtos_c; j++){
			ppc[j] = ppc[j+1];
		}
		return (qtd_produtos_c - 1);
	}else if(i == qtd_produtos_c - 1){
		return (qtd_produtos_c - 1);
	}else{
		for(j = i; j < qtd_produtos_c; j++){
    		ppc[j] = ppc[j+1];
		}
		return (qtd_produtos_c - 1);
	}
}

int alteraCarrinho(ppCarrinho ppc, int qtd_produtos_c){
	int i, j, opcao, qtd, opcao2;

    printf("\n\nInforme a posicao do produto a ser alterado: ");
    scanf("%d", &i);
    printf("\nDeseja aumentar ou diminuir a quantidade do produto (1) - Aumentar / (2) - Diminuir: ");
    scanf("%d", &opcao);
    if(opcao == 1){
    	printf("\nInforme a quantidade que deseja aumentar: ");
    	scanf("%d", &opcao2);
    	opcao2 += qtd_produtos_c;
    	printf("%d", qtd_produtos_c);
    	getch();
	    for(j = qtd_produtos_c; j < opcao2; j++){
	    	ppc[j] = (PCarrinho) malloc(sizeof(Carrinho));
			ppc[j]->codigo = ppc[i]->codigo;
			strcpy(ppc[j]->descricao, ppc[i]->descricao);
			ppc[j]->qtd_estoque = ppc[i]->qtd_estoque;
			ppc[j]->preco = ppc[i]->preco;
		}
		return opcao2;
	}else{
		printf("\nInforme a quantidade que deseja diminuir: ");
		scanf("%d", &opcao2);
			if(qtd_produtos_c == 2 && j == 1){
				return (qtd_produtos_c - opcao2);
			}else if(qtd_produtos_c == 2 && j == 0){
				for(j = i; j < qtd_produtos_c; j++){
					ppc[j] = ppc[j+1];
				}
			}else if(qtd == qtd_produtos_c - 1){
				return (qtd_produtos_c - opcao2);
			}else{
				for(j = i; j < qtd_produtos_c - 1; j++){
    				ppc[j] = ppc[j+1];
				}
				return (qtd_produtos_c - opcao2);
			}
		}
	}


void finalizaPedido(ppCarrinho ppc, int qtd_produtos_c, ppProd ppp){
	int i;
	for(i=0;i<qtd_produtos_c;i++){
		ppp[i]->qtd_estoque -= qtd_produtos_c;
	}
	float soma;
	int valor_rand = rand();
	srand(time(0));
	printf("Pedido %d finalizado!!!!", valor_rand);
	FILE * arq;
	
	arq = fopen("relatorio_vendas.txt","w");
	/*"r" = abrir com permiss�o de leitura: � necess�rio que o arquivo j� exista
	  "w" = abrir com permiss�o de escrita: cria o arquivo se n�o existe e se existe ele ser� recriado
	  "a" = abrir para escrever no final (append) 
	*/
	if(arq == NULL){
		printf("\nErro ao abrir o arquivo!");
		exit(1);
	}	
    fprintf(arq,"\nRECEITA DA COMPRA: %d", valor_rand);
    fprintf(arq,"\nNumero        Codigo        Descricao        Quantidade em estoque        Valor\n");
    for(i=0;i<qtd_produtos_c;i++){
    	//n�o � a ultima linha
		fprintf(arq,"\n%d        %d        %s                        %d                %.2f \n", i, ppc[i]->codigo, ppc[i]->descricao, qtd_produtos_c, ppc[i]->preco);
		soma = soma + ppc[i]->preco;
	}
	fprintf(arq,"TOTAL COMPRADO: %.2f", soma);
	fclose(arq);
}
