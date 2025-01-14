#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por strings 


int registro() //fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variavel/string
	
	printf("Digite o CPF que ser� cadastrado:"); //coletando informa��es de usu�rio
	scanf("%s", cpf); //%s refere-s a string/armazenando string
	
	strcpy(arquivo, cpf); // responsavel por copiaro valor da strings 
	
	FILE *file; //cria o arquivo no banco de dados 
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" cria uma nova de e escreve
	fprintf(file, cpf ); // salva o valor da variavel
	fclose (file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre um arquivo, "a" atualiza a esccrita do arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:\n");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:\n");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:\n");
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");  // Definindo a Linguagem
    
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
    }
    
    while(fgets(conteudo, 200, file) != NULL);

    {
     printf("\nEssas s�o as informa��es do usu�rio: ");
     printf("%s", conteudo);
     printf("\n\n");
     }
     
    printf(" Voc� escolheu a Conculta de nomes!\n");
	system("pause");
}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado! ");
	scanf("%s" ,cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file==NULL)
	{
		printf("O usuario n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	
	
	
	printf(" Voc� escolhei a Dele��o de nomes!\n");
	system("pause");
}

int main()
{
	
	int opcao=0; //Definindo vari�veis
	int Laco=1;

	for(Laco=1;Laco==1;)	
{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
	
		printf(" Cart�rio da EBAC \n\n"); // In�cio do Menu
		printf("Escolha as op��o no menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o:"); // Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); // responsavel por limpar o texto da tela
		
		switch(opcao) //In�cio da sele��o do menu
	{
		case 1:
			registro(); //chamada de fun��es
			break;
		case 2:
			consulta();
			break;
		case 3:
			deletar();
			break;
		case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
		default:
			printf(" Essa op��o n�o est� disponivel, Selecione uma opc�o v�lida!\n"); // Fim da sele��o
			system("pause");
			break;
				
	}	
}

}
