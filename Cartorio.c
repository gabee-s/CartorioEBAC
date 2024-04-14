#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar()
{
	char arquivo[40];
	char nome[40];
	char sobrenome[40];
	char cpf[40];
	char cargo [40];
	
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy( arquivo, cpf); // respos�vel por copiar os valores das strings 
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file ,",");
	fclose(file);
	
	printf("Digite o nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese"); // definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("N�o foi poss�vel abrir esse arquivo\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	system("pause");
	
}
int deletar()
{
	setlocale(LC_ALL,"Portuguese"); // definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF a ser removido: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		
		printf("CPF n�o encontrado! Tente Novamente\n");
		system("pause");
		
	}
	
	else{
		fclose(file);
		remove(cpf);
		printf("CPF removido com sucesso!\n");
		system("pause");
	}
	
}

int main()
{
	setlocale(LC_ALL,"Portuguese");
	int opcao = 0;
	int laco = 1;
	char senhadigitada[] = "a";
	char comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de Admnistrador!\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if (comparacao == 0){
		
		system("cls");
	
		for (laco=1;laco=1;)
		{
			system("cls");
		
			setlocale(LC_ALL,"Portuguese"); // definindo a linguagem
	
			printf("### Cart�rio da EBAC ###\n\n");
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1-Registrar Nomes\n\t2-Consultar nomes\n\t3-Deletar nomes\n\t4-Encerrar Sistema\n\n");
			printf("Esse Software � de livre uso dos alunos!\n");
			printf("Op��o: "); // fim do menu
		
			scanf("%d", &opcao); // armazenando a escolha do usu�rio
		
			system("cls");
			
			switch(opcao)
			{
				
				case 1:
					registrar();
					break;
					
				case 2:
					consultar();
					break;
					
				case 3:
					deletar();
					break;
					
				case 4:
					printf("Obrigado por utilizar o Sistema!");
					return 0;
					break;
					
				default:
					printf("Op��o n�o dispon�vel\n");
					system("pause");
					break;
			}
		}
	}
	else{
		printf("Senha Incorreta!");
	}
}
// fim do programa
