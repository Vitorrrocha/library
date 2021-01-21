#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <dos.h>

/* Aluno: Vitor Augusto Batista Rocha, 18824255 
   Curso: Sistemas para Internet
*/
struct livro					//struct de livro com seus atributos.
{
    char obra[50];
    char autor[50];
    char editora[50];
    int cod;
};

struct livro vetor[5];			//declarei o struct dentro de um escopo global.

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	// variaveis 
	int controle = 999;        //variavel que serve como o controle.
	int qtdLivros = 0;			//Armazena a quantidade de livros.
	
	//tela menu
	do{
		
		printf("\n");
		printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
		printf("-_-_-_-_-_-_-_-_         Sistema Biblioteca           -_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
		printf("-_-_-_-_-_-_-_-_              MENU                    -_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
		printf("-_-_-_-_-_-_-_-_  1 - Inserir novo cadastro:          -_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
		printf("-_-_-_-_-_-_-_-_  2 - Mostrar todos os cadastros:     -_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
		printf("-_-_-_-_-_-_-_-_  0 - Finalizar programa:             -_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
		printf("-_-_-_-_-_-_-_-_                                      -_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
		printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
	 	printf("\n ...Digite o numero conforme a instrução: \n");
	 	
		scanf("%d", &controle);     //faz o input e guarda na variavel &controle.
		system("CLS");
		//condições
		if (controle != 1 && controle != 2 && controle != 0){     // se controle for diferente de 1,2 e 3, o programa exibe uma alerta.
			system("CLS");
			printf("\nErro opção invalida!\n");
			printf("\n\nDigite somente os valores disponiveis no menu!\n\n");	
		}
		
		
		if (controle == 1 && qtdLivros<5){                                       // esse if só pedera ocorrer caso o numero de livro seja menor que 5.
			
    		printf("-_-_-_-_-_-_-_-_   INSERIR UM NOVO CADASTRO:   -_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n");
		    int i;
		    for(i=qtdLivros;i<5;i++){
		        printf("Digite o nome da Obra/Livro: ");
		        scanf(" %[^\n]s", &vetor[i].obra);        // o scanf("%[^\n]s") permite ler uma string mesmo com espaços.
		        printf("Digite o Autor(a): ");
		        scanf(" %[^\n]s", &vetor[i].autor); 
		        printf("Digite a Editor(a): ");
		        scanf(" %[^\n]s", &vetor[i].editora); 
				vetor[i].cod = qtdLivros +1;
				qtdLivros++;									//acresenta mais um a quantidade de livros.
			break;	        				
		    }

		}	
		else if(controle== 1 && qtdLivros==5){              // se o usuario tentar cadastrar mais de 5 livros o sistema exibe um alerta.
   	    	system("CLS");
			printf("Sistema de cadastro lotado. Não é possível armazenar mais informações!\n \n");
			printf("Voltando ao sistema em: \n");
			Sleep(1000);
			printf("4...");
			Sleep(1000);
			printf("3...");
			Sleep(1000);
			printf("2...");
			Sleep(1000);
			printf("1...");
			Sleep(1000);
			system("CLS");  
		}

		if (controle == 2){
			if(qtdLivros==0){          // se a quantidade de livros for igual a zero exibe a mensagem "Lista vazia!".
			    
			system("CLS"); 
			printf("-_-_-_-_-_-_-_-_   LIVROS CADASTRADOS   -_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n");
			printf("  Lista vazia! \n \n");
			printf("Voltando ao sistema em: \n");
			Sleep(1000);
			printf("4...");
			Sleep(1000);
			printf("3...");
			Sleep(1000);
			printf("2...");
			Sleep(1000);
			printf("1...");
			Sleep(1000);
			system("CLS"); 

			}else{											// mostra todos os livros cadastrados.
				int tamanho = qtdLivros;          			// recebe o numero de livros para que o for mostre somente a quantidade de livros cadastrados.
				int i;
				printf("-_-_-_-_-_-_-_-_   LIVROS CADASTRADOS   -_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n");
				for(i=0;i<tamanho;i++){						//faz a leitura do vetor struct livro. 
				printf("Nome do Livro/Obra: %s \n -Autor(a): %s \n -Editor(a): %s \n -Codigo: %d \n\n", vetor[i].obra, vetor[i].autor, vetor[i].editora, vetor[i].cod);		
		    }
				system("pause"); 
				system("CLS"); 

			}
		}
		
	} while(controle != 0);
	system("CLS");
	printf("********************Programa finalizado com sucesso.****************\n");
	
	return 0;
}
