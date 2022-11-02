#include <stdlib.h>
#include "loja.h"
#define MAX 100

int main(int argc, char *argv[]) {	
	int saida = 0, opcao;
	int voltar1 = 0, opcao1;
	int voltar2 = 0, opcao2;
	Produto* produtos[MAX];
	Carrinho* carrinhos[MAX]; 
	int qtd_produtos, aux, aux2, aux3;
	int qtd_produtos_c, aux_c, aux_c2, aux_c3, aux_c4;
	iniVet(produtos);
	iniCar(carrinhos);
	
	aux = incluirProdInic(produtos);
	aux2 = aux;
	aux3 = aux;
	
	qtd_produtos_c = 0;
	
	
	
	do{
		system("cls");
		printf("\n      Loja de Produtos");
		printf("\n(1) Gerenciar produtos");
		printf("\n(2) Registrar Pedido de Compra");	
		printf("\n(3) Sair\n");
		printf("\nSelecione a opcao desejada: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
	
				do{					
					system("cls");
					printf("\n     Gerenciar Produtos");
					printf("\n1) Incluir");
					printf("\n2) Alterar");	
					printf("\n3) Excluir");
					printf("\n4) Consultar");
					printf("\n5) Listar");
					printf("\n6) Voltar\n");
					printf("\nSelecione a opcao desejada: ");
					scanf("%d", &opcao1);
					
					switch(opcao1){
						case 1:
							system("cls");
							qtd_produtos = incluiPdotutos(produtos, aux3);
							aux2 = qtd_produtos;
							aux3 = qtd_produtos;
							break;
						case 2:
							system("cls");
							alteraProdutos(aux2, produtos);
							break;
						case 3:
							system("cls");
							listaProdutos(aux3, produtos, qtd_produtos_c);
							aux3 = excluir_produtos(produtos, aux2);
							getch();
							break;
						case 4:
							system("cls");
							consultar_produtos(produtos, aux3);
							getch();
							break;
						case 5:
							system("cls");
							listaProdutos(aux3, produtos, qtd_produtos_c); 
							getch();
						case 6:
							voltar1 = 1;	
							
					}
				}while(!voltar1);			
				break;
				
			case 2:
				system("cls");
				do{					
					system("cls");
					printf("\n                           Carrinho");
					printf("\n1) Adicionar produto");
					printf("\n2) Consultar carrinho de compras");	
					printf("\n3) Remover um produto do carrinho de compras");
					printf("\n4) Alterar a quantidade de um produto do carrinho de compras");
					printf("\n5) Finalizar pedido");
					printf("\n6) Voltar\n");
					printf("\nSelecione a opcao desejada: ");
					scanf("%d", &opcao1);
					
					switch(opcao1){
						case 1:
							system("cls");
							listaProdutos(aux3, produtos, qtd_produtos_c);
							qtd_produtos_c = adicionaCarrinho(carrinhos, produtos, aux_c3);
							aux_c = qtd_produtos_c;
							aux_c2 = qtd_produtos_c;
							aux_c3 = qtd_produtos_c;
							aux_c4 = qtd_produtos_c;
							getch();
							break;
						case 2:
							system("cls");
							listaCarrinho(aux_c4, carrinhos);
							getch();
							break;
						case 3:
							aux_c2 = excluiCarrinho(carrinhos, aux_c4);
							aux_c4 = aux_c2;
							getch();
							break;
						case 4:
							listaCarrinho(aux_c4, carrinhos);
							aux_c3 = alteraCarrinho(carrinhos, aux_c4);
							aux_c4 = aux_c3;
							break;
						case 5:
							system("cls");
							finalizaPedido(carrinhos, aux_c4, produtos);
							getch();
							break;                        
						case 6:
							voltar2 = 1;	
							
					}
				}while(!voltar2);			
				break;
			
			case 3:
				saida = 1;
				break;	
				
			default:
				printf("\nOpcao invalida!");
				getch();			
		}			

	}while(!saida);	
	
	system("PAUSE"); /* Aguarda pressionar <Enter> */
	
	return 0;
}




