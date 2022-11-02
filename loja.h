typedef struct produto{
	int codigo;
	int qtd_estoque;
	char descricao[50];	
	float preco;
}Produto, *PProduto, **ppProd;

typedef struct carrinho{
	int codigo;
	int qtd_estoque;
	char descricao[50];
	float preco;
	int receita;
}Carrinho, *PCarrinho, **ppCarrinho;

int incluirProdInic(ppProd ppp);
/*Fun��o: Incluir produtos inicialmente
Entrada: ppp = vetor de produtos
Sa�da: retorna o n�mero de produtos
*/

int incluiPdotutos(ppProd ppp, int aux);
/*Fun��o: Incluir produtos no menu Gerenciar Produtos
Entrada: ppp = vetor de produtos
		 aux = n�mero de produtos inseridos inicialmente
Sa�da: aux = novo n�mero de produtos
*/

void alteraProdutos(int numProdutos, ppProd ppp);
/*Fun��o: Alterar produtos j� inseridos
Entrada: numProdutos = n�mero de produtos j� inseridos
    	 ppp = vetor de produtos
Sa�da: --
*/

int excluir_produtos(ppProd ppp, int numProdutos);
/*Fun��o: Excluir produtos j� inseridos
Entrada: ppp = vetor de produtos 
         numProdutos = n�mero de produtos j� inseridos
Sa�da: Retorna o n�mero de produtos menos 1 (um foi excluido)
*/

void consultar_produtos(ppProd ppp, int numProdutos);
/*Fun��o: Buscar e apresentar em tela as informa�oes do produto desejado
Entrada: ppp = vetor de produtos
         numProdutos = n�mero de produtos j� inseridos
Sa�da: --
*/

void listaProdutos(int numProdutos, ppProd ppp, int qtd_produtos_c);
/*Fun��o: Apresentar em tela todos os produtos j� inseridos
Entrada: numProdutos = n�mero de produtos j� inseridos
    	 ppp = vetor de produtos
    	 qtd_produtos_c = quantidade de produtos no carrinho
Sa�da: --
*/

int adicionaCarrinho(ppCarrinho ppc, ppProd ppp, int qtd_produtos_c);
/*Fun��o: Adicionar produtos no carrinho
Entrada: ppc = vetor do carrinho
         ppp = vetor de produtos 
         qtd_produtos_c = quantidade de produtos no carrinho
Sa�da: Nova quantidade de produtos no carrinho
*/

void listaCarrinho(int qtd_produtos_c, ppCarrinho ppc);
/*Fun��o: Listar os produtos presentes no carrinho
Entrada: qtd_produtos_c = quantidade de produtos no carrinho
		 ppc = vetor do carrinho
Sa�da: --
*/

int excluiCarrinho(ppCarrinho ppc, int qtd_produtos_c);
/*Fun��o: Buscar e excluir produto do carrinho 
Entrada: ppc = vetor do carrinho
		 qtd_produtos_c = quantidade de produtos no carrinho
Sa�da: Quantidade de produtos no carrinho - 1 (um foi excluido)
*/

int alteraCarrinho(ppCarrinho ppc, int qtd_produtos_c);
/*Fun��o: Alterar a quantidade de um produto no carrinho
Entrada: ppc = vetor do carrinho
		 qtd_produtos_c = quantidade de produtos no carrinho
Sa�da: Nova quantidade de produtos no carrinho
*/

void finalizaPedido(ppCarrinho ppc, int qtd_produtos_c, ppProd ppp);
/*Fun��o: Realiza as opera��es necess�rias com o estoque e gera nota de compra
Entrada: ppc = vetor do carrinho
		 qtd_produtos_c = quantidade de produtos no carrinho
Sa�da: --
*/

