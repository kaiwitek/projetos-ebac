#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidas das string

int registro(){ //Pagina responsável por cadastrar usuários
	
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
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das string
	
	printf("\nConfirmar cadastro?\n");
	printf("\nDigite (s) para confirmar ou digite (n) para cancelar\n\n");
	
	char opcao;
	getchar();
	opcao = getchar();
	
	if(opcao == 's' ||opcao == 'S'){
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Abre o arquivo
	fprintf(file,cpf);//Salvo o valor da variável (cpf)
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

int escolha(){ //Página para continuar cadastrando ou não
	system("cls");
	printf("\nDeseja cadastrar mais usuários?\n\n");
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

int consulta(){ //Pagina responsável por consultar dados de usuários
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usuário a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");

	
	if(file == NULL){
		printf("\nUsuário não encontrado.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		fclose(file);
	
	system("pause");
}

int deletar(){ //Pagina responsável por deletar usuários
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL){
		system("cls");
		printf("Usuário não encontrado.\n\n");
		system("pause");
	}
	else{
		system("cls");
		
		printf("\nUsuário encontrado, deseja deletar este usuário?\n\n");
		printf("Digite (s) para confirmar ou digite (n) para cancelar\n\n");
		
		char opcao;	
		getchar();
		opcao = getchar();
		
		if(opcao == 's' ||opcao == 'S'){
			remove(cpf);
			system("cls");
			printf("Usuário deltado com sucesso!\n\n");
			system("pause");
		}
		if(opcao == 'n' ||opcao == 'N'){
			system("cls");
			printf("Operação cancelada.\n\n");
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
	int opcao=0; //Definindo as variáveis
	int laco=1;
		
	for(laco=1;laco=1;){
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("\tCartório da EBAC\n\n"); //Inicio do menu
		printf(" Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar usuário\n");
		printf("\t2 - Consultar dados de usuário\n");
		printf("\t3 - Deletar usuário\n");
		printf("\t4 - Sair\n\n");
		printf(" Opção: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls"); //Limpando a tela após a escolha
		
		switch(opcao){ //Programando as opções em switch para otimizar o código
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
				printf("Essa opção não está disponível!\n\n");
				system("pause");
			break;
			
		}
		
	} 
}

