#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

// Registro do Produto
typedef struct {
    char tipo[20] ; char nome[30];
    float preco;
    int tamanho; int codigo; int quantidade;
    char fabricante[40];
} Produto;


void infoProduto(Produto prod); void DescricaoDetalhada(Produto prod); void Descricao(); void menu(); void cadastrarProduto(); void ListarProdutos(); void exclusao(); void alteracao();

static int contador_produto = 0;
static Produto produtos[50];
static int codigo;


void infoProduto(Produto prod){
    printf("Nome do parafuso: %s\nPreco: R$%.2f \nCodigo: %d\n",strtok(prod.nome, "\n"),prod.preco, prod.codigo);
}

void DescricaoDetalhada(Produto prod){
    printf("Nome do parafuso: %s \nTamanho[mm]: %d \nQuantidade: %d\nPreco: %.2f \nTipo: %s\nFabricante: %s\n",strtok(prod.nome, "\n"), prod.tamanho,prod.quantidade, prod.preco, strtok(prod.tipo, "\n"), strtok(prod.fabricante, "n"));

}

void exclusao(){
    int total = contador_produto;
    printf("\nCodigo do produto a ser excluido: ");
    scanf("%d", &codigo);

    for (int i = 0; i < total; i++){
        if (codigo == produtos[i].codigo){
            for(int j = i; j < total - 1; j++){ //
                produtos[j] = produtos[j+1];
            }
            total = total + 1;
            printf("\nProduto excluido com sucesso!\n");
            menu();
        }
    }
    printf("\nERRO: Produto nao cadastrado!\n");
    menu();
}

void menu(){
    printf("- - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\n");
    printf("            LOJA DE PARAFUSOS LG              \n");
    printf("\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - -\n");

    printf("Selecione uma opcao abaixo: \n");
    printf("* * * * * * * * * * * * * *\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar Produtos\n");
    printf("3 - Descricao do parafuso: \n");
    printf("4 - Exluir produto\n");
    printf("5 - Alterar produto\n");
    printf("6 - Sair do sistema\n");

    int opcao;
    scanf("\n%d", &opcao);
    getchar(); 

    switch (opcao){
        case 1:
            cadastrarProduto();
            break;
        case 2:
            ListarProdutos();
            break;
        case 3:
            Descricao();
            break;
        case 4:
            exclusao();
            break;
        case 5:
            alteracao();
        case 6:
            printf("Obrigado pela preferencia\n");
            Sleep(2);
            exit(0);
            break;
        default:
            printf("Opcao invalida!\n");
            Sleep(2);
            menu();
            break;
    }
}

void cadastrarProduto(){
    
        printf("\nCADASTRO DE PARAFUSOS\n");
        printf("\n");

        printf("Nome: ");
        fgets(produtos[contador_produto].nome, 30, stdin);

        printf(". . . . . . . .\n");
        printf("Tipos: P/Madeira, Frances, Sextravado, Allen, Rosca Soberba, Auto Atarraxante, Auto Brocante, Fixer, Maquina, Plastic.\n");
        printf(". . . . . . . .\n");

        printf("Informe o Tipo de parafuso:[Escreva como esta acima]\n");
        fgets(produtos[contador_produto].tipo, 40, stdin);

        printf("Fabricante: ");
        fgets(produtos[contador_produto].fabricante, 40, stdin);

        printf("Tamanho[mm]: ");
        scanf("%d", &produtos[contador_produto].tamanho);

        printf("Quantidade: ");
        scanf("%d", &produtos[contador_produto].quantidade);

        printf("Informe o preco: ");
        scanf("%f", &produtos[contador_produto].preco);

        produtos[contador_produto].codigo = (contador_produto + 1);

    contador_produto++;
    menu();
    
}

void ListarProdutos(){
    char resposta[5];
    if(contador_produto > 0){
        printf("\nLISTAGEM \n");
        printf("- - - - - - - - - - -\n");
        for(int i = 0; i < contador_produto; i++){
            if (produtos[i].codigo != produtos[i - 1].codigo){
                infoProduto(produtos[i]);
                printf("- - - - - - - - - \n");
                Sleep(1); 
            }
        }
    }
    else{
        printf("Sem produtos cadastrados.\n");
    }
    printf("Voltar para o menu? [S/N]\n");
    scanf("%s", &resposta[5]);

    if(resposta[5] == 's' || resposta[5] == "sim" || resposta[5] == 'S' || resposta[5] == "SIM"){
        menu();
    }
    else{
        if(resposta[5] == 'n' || resposta[5] == "nao" || resposta[5] == 'N' || resposta[5] == "NAO"){
            printf("Ate a proxima!!");
        }
        else{
            printf("Opcao nao identificada");
        }
    }
}

void alteracao(){
    printf("\nALTERACAO\n"); printf(". . . . . . . . .\n");
    printf("\ncodigo: ");
    scanf("%d", &codigo);

    for (int i= 0; i < contador_produto; i++){
        if (codigo == produtos[i].codigo){
            printf("Nome: ");
            scanf("%s", &produtos[i].nome);

            printf(". . . . . . . .\n");
            printf("Tipos: P/Madeira, Frances, Sextravado, Allen, Rosca Soberba, Auto Atarraxante, Auto Brocante, Fixer, Maquina, Plastic.\n");
            printf(". . . . . . . .\n");

            printf("Informe o Tipo de parafuso: \n");
            scanf("%s", &produtos[i].tipo);

            printf("Quantidade: \n");
            scanf("%d", &produtos[i].quantidade);

            printf("Fabricante: \n");
            scanf("%s", &produtos[i].fabricante);

            printf("Tamanho[mm]: \n");
            scanf("%d", &produtos[i].tamanho);

            printf("Informe o preco: \n");
            scanf("%f", &produtos[i].preco);
            menu();
        }
    }
    printf("\nERRO: Produto nao cadastrado!\n");
}

void Descricao(){
    int codigo;
    printf("Codigo do produto: ");
    scanf("%d", &codigo);
    printf("\nDESCRICAO\n"); printf(". . . . . . . . .\n");
    for (int i = 0; i < contador_produto; i++){
        if (produtos[i].codigo != produtos[i - 1].codigo)
            if (codigo == produtos[i].codigo){
            DescricaoDetalhada(produtos[i]);
            }
    }
    menu();

}

int main(){
    menu();
    return 0;
}

