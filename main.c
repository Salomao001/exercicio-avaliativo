#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USUARIOS 1000


typedef struct {
    int id;
    char nome[50];
    char email[50];
    char sexo[15];
    char endereco[100];
    double altura;
    int vacina;
} Usuario;

// Declaração das funções
void menu();
void cadastrarUsuario(Usuario usuarios[], int *numUsuarios);
void editarUsuario(Usuario usuarios[], int numUsuarios);
void excluirUsuario(Usuario usuarios[], int *numUsuarios);
void buscarUsuarioPorEmail(Usuario usuarios[], int numUsuarios);
void imprimirTodosUsuarios(Usuario usuarios[], int numUsuarios);
void fazerBackup(Usuario usuarios[], int numUsuarios);
void restaurarBackup(Usuario usuarios[], int *numUsuarios);

int main() {
    Usuario usuarios[MAX_USUARIOS];
    int numUsuarios = 0;
    char opcao;

    do {
        menu();
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                cadastrarUsuario(usuarios, &numUsuarios);
                break;
            case '2':
                editarUsuario(usuarios, numUsuarios);
                break;
            case '3':
                excluirUsuario(usuarios, &numUsuarios);
                break;
            case '4':
                buscarUsuarioPorEmail(usuarios, numUsuarios);
                break;
            case '5':
                imprimirTodosUsuarios(usuarios, numUsuarios);
                break;
            case '6':
                fazerBackup(usuarios, numUsuarios);
                break;
            case '7':
                restaurarBackup(usuarios, &numUsuarios);
                break;
            case '0':
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

        printf("\n");
    } while (opcao != '0');

    return 0;
}

void menu() {
    printf("----------- MENU -----------\n");
    printf("1. Cadastrar usuario\n");
    printf("2. Editar usuario\n");
    printf("3. Excluir usuario\n");
    printf("4. Buscar usuario por email\n");
    printf("5. Imprimir usuarios\n");
    printf("6. Fazer backup\n");
    printf("7. Restaurar backup\n");
    printf("0. Sair\n");
    printf("Opcao: ");
}
void cadastrarUsuario(Usuario usuarios[], int *qtdUsuarios) {

    if (*qtdUsuarios >= 1000) {
        printf("Limite de usuários cadastrados atingido.\n");
        return;
    }

    Usuario novoUsuario;

    printf("Preencha os dados do novo usuário:\n");
    novoUsuario.id = rand() % 1000 + 1;

    getchar(); 

    printf("Nome completo: ");
    fgets(novoUsuario.nome, sizeof(novoUsuario.nome), stdin);
    do {
        printf("Email: ");
        fgets(novoUsuario.email, sizeof(novoUsuario.email), stdin);
    } while (strchr(novoUsuario.email, '@') == NULL);
    printf("Sexo (Feminino/Masculino/Indiferente): ");
    fgets(novoUsuario.sexo, sizeof(novoUsuario.sexo), stdin);
    printf("Endereço: ");
    fgets(novoUsuario.endereco, sizeof(novoUsuario.endereco), stdin);
    do {
        printf("Altura (m): ");
        scanf("%lf", &novoUsuario.altura);
    } while (novoUsuario.altura < 1 || novoUsuario.altura > 2);
    do {
        printf("Já tomou a vacina? (1 - Sim / 0 - Não): ");
        scanf("%d", &novoUsuario.vacina);
    } while (novoUsuario.vacina != 0 && novoUsuario.vacina != 1);
    getchar(); 
    usuarios[*qtdUsuarios] = novoUsuario;
    (*qtdUsuarios)++;

    printf("Usuário cadastrado com sucesso!\n");
}
void editarUsuario(Usuario usuarios[], int numUsuarios) {
    char email[50];
    int i, encontrado = 0;

    getchar(); 

    printf("Digite o email do usuário que deseja editar: ");
    fgets(email, sizeof(email), stdin);

    for (i = 0; i < numUsuarios; i++) {
        if (strcmp(email, usuarios[i].email) == 0) {
            encontrado = 1;

            printf("Digite os novos dados do usuário:\n");
            printf("Nome completo: ");
            fgets(usuarios[i].nome, sizeof(usuarios[i].nome), stdin);
            do {
                printf("Email: ");
                fgets(usuarios[i].email, sizeof(usuarios[i].email), stdin);
            } while (strchr(usuarios[i].email, '@') == NULL);
            printf("Sexo (Feminino/Masculino/Indiferente): ");
            fgets(usuarios[i].sexo, sizeof(usuarios[i].sexo), stdin);
            printf("Endereço: ");
            fgets(usuarios[i].endereco, sizeof(usuarios[i].endereco), stdin);
            do {
                printf("Altura (m): ");
                scanf("%lf", &usuarios[i].altura);
            } while (usuarios[i].altura < 1 || usuarios[i].altura > 2);
            do {
                printf("Já tomou a vacina? (1 - Sim / 0 - Não): ");
                scanf("%d", &usuarios[i].vacina);
            } while (usuarios[i].vacina != 0 && usuarios[i].vacina != 1);
            getchar(); 

            printf("Usuário editado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário não encontrado.\n");
    }
}
void excluirUsuario(Usuario usuarios[], int *numUsuarios) {
    char email[50];
    int i, encontrado = 0;

    getchar();

    printf("Digite o email do usuário que deseja excluir: ");
    fgets(email, sizeof(email), stdin);

    for (i = 0; i < *numUsuarios; i++) {
        if (strcmp(email, usuarios[i].email) == 0) {
            encontrado = 1;

            for (int j = i; j < *numUsuarios - 1; j++) {
                usuarios[j] = usuarios[j+1];
            }

            (*numUsuarios)--;

            printf("Usuário excluído com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário não encontrado.\n");
    }
}
void buscarUsuarioPorEmail(Usuario usuarios[], int numUsuarios) {
    char email[50];
    int i, encontrado = 0;

    getchar();

    printf("Digite o email do usuário que deseja buscar: ");
    fgets(email, sizeof(email), stdin);

    for (i = 0; i < numUsuarios; i++) {
        if (strcmp(email, usuarios[i].email) == 0) {
            encontrado = 1;

            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s", usuarios[i].nome);
            printf("Email: %s", usuarios[i].email);
            printf("Sexo: %s", usuarios[i].sexo);
            printf("Endereço: %s", usuarios[i].endereco);
            printf("Altura: %.2lfm\n", usuarios[i].altura);
            printf("Vacina: %s\n", usuarios[i].vacina == 1 ? "Sim" : "Não");
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário não encontrado.\n");
    }
}
void imprimirTodosUsuarios(Usuario usuarios[], int numUsuarios) {
    int i;
    for (i = 0; i < numUsuarios; i++) {
    printf("ID: %d\n", usuarios[i].id);
    printf("Nome: %s", usuarios[i].nome);
    printf("Email: %s", usuarios[i].email);
    printf("Sexo: %s", usuarios[i].sexo);
    printf("Endereco: %s", usuarios[i].endereco);
    printf("Altura: %.2lf\n", usuarios[i].altura);
    printf("Vacina: %s\n", usuarios[i].vacina == 1 ? "Sim" : "Não");
    printf("----------------------------------------\n");
    } 
}
void fazerBackup(Usuario usuarios[], int numUsuarios) {
FILE *arquivo;
int i;

arquivo = fopen("backup.txt", "w");


if (arquivo == NULL) {
    printf("Erro ao criar arquivo de backup!\n");
    return;
}


for (i = 0; i < numUsuarios; i++) {
    fprintf(arquivo, "%d\n", usuarios[i].id);
    fprintf(arquivo, "%s", usuarios[i].nome);
    fprintf(arquivo, "%s", usuarios[i].email);
    fprintf(arquivo, "%s", usuarios[i].sexo);
    fprintf(arquivo, "%s", usuarios[i].endereco);
    fprintf(arquivo, "%.2lf\n", usuarios[i].altura);
    fprintf(arquivo, "%d\n", usuarios[i].vacina);
}


fclose(arquivo);

printf("Backup realizado com sucesso!\n");
}
void restaurarBackup(Usuario usuarios[], int *numUsuarios) {
    FILE *arquivo;
    int i = 0;


    arquivo = fopen("backup.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de backup!\n");
        return;
    }


    while (fscanf(arquivo, "%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%lf\n%d\n", &usuarios[i].id, usuarios[i].nome, usuarios[i].email, usuarios[i].sexo, usuarios[i].endereco, &usuarios[i].altura, &usuarios[i].vacina) == 7) {
        i++;
    }

    *numUsuarios = i;

    fclose(arquivo);

    printf("Backup restaurado com sucesso!\n");
}