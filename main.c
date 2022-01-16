/*
Este projeto iniciante em C é útil para as indústrias de pequena e grande escala. O administrador pode adicionar todos os detalhes sobre o funcionário e pode atualizá-los e excluí-los.
 O tratamento de arquivos é usado para armazenar os dados dos funcionários.
*/
#include <stdio.h>

typedef struct
{
    int Codigo;
    char Nome[40];
    int Idade;
    char RegistroGeral[40];
    int Numero;
    char Sexo[40];
} Funcionario;

void menu();
void AdicionarFuncionario(FILE *arquivo);
void VisualizarFuncionario (FILE *arquivo);
void AlterarFuncionario(FILE *arquivo);
Funcionario PegarFuncionario(FILE *arquivo, int codigo);

int main()
{
    int Menu;
    FILE *arquivo;

    if ( (arquivo = fopen("Clientes.dat", "a+")) == NULL)
    {
        printf("Arquivo nao pode ser aberto\n");
        return -1;
    }
    
    do
    {
        rewind(arquivo);
        menu();

        scanf("%d", &Menu); 

        switch (Menu)
        {
        case 1:
            AdicionarFuncionario(arquivo);
            break;
        case 2:
            AlterarFuncionario(arquivo);
            break;
        case 3:
            VisualizarFuncionario(arquivo);
            break;
        case 4:
            printf("\nExcluir nao implementado ainda\n");
            break;
        case 9:
            printf("\nFim do Programa\n");
            break;
        default:
            printf("\nOpcao invalida\n");
            break;
        }

    } while (Menu != 9);

    return 0;
}

void menu()
{
    printf("\n-----------------------\n");
    printf("         Menu");
    printf("\n-----------------------\n");
    printf("1 - Adicionar\n");
    printf("2 - Atualizar\n");
    printf("3 - Visualizar\n");
    printf("4 - Excluir\n");
    printf("9 - Sair");
    printf("\n-----------------------\n");
    printf("Opcao: ");
}

void AdicionarFuncionario(FILE *arquivo)
{
    Funcionario funcionario;

    printf("\n-----------------------\n");
    printf("\n-Adicionar Funcionario-\n");
    printf("\n-----------------------\n");

    printf("Codigo: ");
    scanf("%d", &funcionario.Codigo);
    printf("Nome: ");
    scanf("%s", funcionario.Nome);
    printf("Idade: ");
    scanf("%d", &funcionario.Idade);
    printf("RG: ");
    scanf("%s", funcionario.RegistroGeral);
    printf("Numero: ");
    scanf("%d", &funcionario.Numero);
    printf("Sexo: ");
    scanf("%s", funcionario.Sexo);
   
    fprintf(arquivo, "%d %s %d %s %d %s\n", funcionario.Codigo, funcionario.Nome, funcionario.Idade, funcionario.RegistroGeral, funcionario.Numero, funcionario.Sexo);

    printf("\nContato Adicionado\n");
}

void VisualizarFuncionario (FILE *arquivo)
{
    Funcionario funcionario;

    printf("\n-----------------------\n");
    printf("\n-Visualizar Funcionarios-\n");
    printf("\n-----------------------\n");

    printf("\n%6s %20s %5s %13s %9s %9s\n", "Codigo", "Nome", "Idade", "RegistroGeral", "Celular", "Sexo");
    
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d %s %d %s %d %s\n", &funcionario.Codigo, funcionario.Nome, &funcionario.Idade, funcionario.RegistroGeral, &funcionario.Numero, funcionario.Sexo);
        printf("%6d %20s %5d %13s %9d %9s\n", funcionario.Codigo, funcionario.Nome, funcionario.Idade, funcionario.RegistroGeral, funcionario.Numero, funcionario.Sexo);
    }
}

void AlterarFuncionario(FILE *arquivo) // primeiro tem que mostrar os funcionarios que ja tem
{                                      // depois escolher oque quero mudar, e mudar 
    arquivo = fopen("Clientes.dat", "rt+");

    Funcionario funcionario;

    int codigo;

    printf("\n-----------------------\n");
    printf("\n-Atualizar Funcionarios-\n");
    printf("\n-----------------------\n");

    printf("\n%6s %20s %5s %13s %9s %9s\n", "Codigo", "Nome", "Idade", "RegistroGeral", "Celular", "Sexo");             //fazer uma função para mostrar os funcionarios que tem !!

while (!feof(arquivo))                
    {
        fscanf(arquivo, "%d %s %d %s %d %s\n", &funcionario.Codigo, funcionario.Nome, &funcionario.Idade, funcionario.RegistroGeral, &funcionario.Numero, funcionario.Sexo);
        printf("%6d %20s %5d %13s %9d %9s\n", funcionario.Codigo, funcionario.Nome, funcionario.Idade, funcionario.RegistroGeral, funcionario.Numero, funcionario.Sexo);
    }
    
    printf("\nDigite o codigo do funcionario que deseja Atualizar: ");
    scanf("%d", &codigo);

    funcionario = PegarFuncionario(arquivo, codigo); 

    if (codigo == funcionario.Codigo)
    {
        printf("Codigo: %d\n", funcionario.Codigo);
        printf("Nome: %s\n", funcionario.Nome);
        printf("Idade: %d\n", funcionario.Idade);
        printf("RG: %s\n", funcionario.RegistroGeral);
        printf("Numero: %d\n", funcionario.Numero);
        printf("Sexo: %s\n", funcionario.Sexo);
    }else
    {
        printf("Contato nao foi localizado!");
    }
    
    printf("\n-----------------------------------------\n");  //agora falta so a parte de atualizar os dados, ja consegui pegar o funcionario.
}

Funcionario PegarFuncionario(FILE *arquivo, int codigo)
{
    Funcionario funcionario;
    rewind(arquivo);

    while (!feof(arquivo) && funcionario.Codigo != codigo)                  
    {                                                              
        fscanf(arquivo, "%d %s %d %s %d %s\n", &funcionario.Codigo, funcionario.Nome, &funcionario.Idade, funcionario.RegistroGeral, &funcionario.Numero, funcionario.Sexo);
    }

    return funcionario;
}

void ExcluirFuncionario(FILE *arquivo)
{
    Funcionario funcionario;

    printf("\n-----------------------\n");     // a parte de excluir funcionario tambem falta.
    printf("\n-Excluir Funcionarios-\n");
    printf("\n-----------------------\n");
    //fread();
}