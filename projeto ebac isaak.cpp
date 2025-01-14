#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por strings 


int registro() //função responsavel por cadastrar os usuarios no sistema
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variavel/string
	
	printf("Digite o CPF que será cadastrado:"); //coletando informações de usuário
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
    printf("Não foi possivel abrir o arquivo, não localizado!. \n");
    }
    
    while(fgets(conteudo, 200, file) != NULL);

    {
     printf("\nEssas são as informações do usuário: ");
     printf("%s", conteudo);
     printf("\n\n");
     }
     
    printf(" Você escolheu a Conculta de nomes!\n");
	system("pause");
}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado! ");
	scanf("%s" ,cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file==NULL)
	{
		printf("O usuario não se encontra no sistema!.\n");
		system("pause");
	}
	
	
	
	
	printf(" Você escolhei a Deleção de nomes!\n");
	system("pause");
}

int main()
{
	
	int opcao=0; //Definindo variáveis
	int Laco=1;

	for(Laco=1;Laco==1;)	
{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
	
		printf(" Cartório da EBAC \n\n"); // Início do Menu
		printf("Escolha as opção no menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção:"); // Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); // responsavel por limpar o texto da tela
		
		switch(opcao) //Início da seleção do menu
	{
		case 1:
			registro(); //chamada de funções
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
			printf(" Essa opção não está disponivel, Selecione uma opcão válida!\n"); // Fim da seleção
			system("pause");
			break;
				
	}	
}

}
