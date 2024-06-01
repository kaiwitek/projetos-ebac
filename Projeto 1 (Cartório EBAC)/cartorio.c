#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidas das string

int registro(){ //Pagina respons�vel por cadastrar usu�rios
	
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	system("cls");
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	printf("\nDigite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	printf("\nDigite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	
	printf("\nDigite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores das string
	
	printf("\nConfirmar cadastro?\n");
	printf("\nDigite (s) para confirmar ou digite (n) para cancelar\n\n");
	
	char opcao;
	getchar();
	opcao = getchar();
	
	if(opcao == 's' ||opcao == 'S'){
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Abre o arquivo
	fprintf(file,cpf);//Salvo o valor da vari�vel (cpf)
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);

	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("cls");
	
	printf("\nCadastro realizado com sucesso!\n\n");
	system("pause");
	
	escolha();
	}	 
	
	if(opcao == 'n' ||opcao == 'N'){
	system("cls");
	printf("\nCadastro cancelado\n\n");
	system("pause");
	}
}

int escolha(){ //P�gina para continuar cadastrando ou n�o
	system("cls");
	printf("\nDeseja cadastrar mais usu�rios?\n\n");
	printf("Digite (s) para confirmar ou digite (n) para cancelar\n\n");
	
	char opcao;
	getchar();
	opcao = getchar();
	
	if(opcao == 's' ||opcao == 'S'){
		registro();
	}
	if(opcao =='n' ||opcao == 'N'){
		return 0;
	}
	
}

int consulta(){ //Pagina respons�vel por consultar dados de usu�rios
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usu�rio a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");

	
	if(file == NULL){
		printf("\nUsu�rio n�o encontrado.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		fclose(file);
	
	system("pause");
}

int deletar(){ //Pagina respons�vel por deletar usu�rios
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL){
		system("cls");
		printf("Usu�rio n�o encontrado.\n\n");
		system("pause");
	}
	else{
		system("cls");
		
		printf("\nUsu�rio encontrado, deseja deletar este usu�rio?\n\n");
		printf("Digite (s) para confirmar ou digite (n) para cancelar\n\n");
		
		char opcao;	
		getchar();
		opcao = getchar();
		
		if(opcao == 's' ||opcao == 'S'){
			remove(cpf);
			system("cls");
			printf("Usu�rio deltado com sucesso!\n\n");
			system("pause");
		}
		if(opcao == 'n' ||opcao == 'N'){
			system("cls");
			printf("Opera��o cancelada.\n\n");
			system("pause");
		}
	}
}


int sair(){
	printf("\nDeseja encerrar o programa?\n\n");
	printf("Digite (s) para confirmar ou digite (n) para cancelar\n\n");
	
	char opcao;
	getchar();
	opcao = getchar();
	
	if(opcao == 's' ||opcao == 'S'){
		system("cls");
		printf("Obrigado por utilizar esse sistema!\n\n");
		exit(0);
	}
	if(opcao == 'n' ||opcao == 'N'){
		system("cls");
		return 0;
	}
}
int main(){
	int opcao=0; //Definindo as vari�veis
	int laco=1;
		
	for(laco=1;laco=1;){
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("\tCart�rio da EBAC\n\n"); //Inicio do menu
		printf(" Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar usu�rio\n");
		printf("\t2 - Consultar dados de usu�rio\n");
		printf("\t3 - Deletar usu�rio\n");
		printf("\t4 - Sair\n\n");
		printf(" Op��o: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls"); //Limpando a tela ap�s a escolha
		
		switch(opcao){ //Programando as op��es em switch para otimizar o c�digo
			case 1:
				registro();
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;	
			
			case 4:
				sair();
			break;
			
			default:
				printf("Essa op��o n�o est� dispon�vel!\n\n");
				system("pause");
			break;
			
		}
		
	} 
}

