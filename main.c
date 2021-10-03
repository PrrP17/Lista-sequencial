#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "ListaSequencial.h"

Lista* li;
struct aluno al;
int resp;

int main()
{

    li = criar_lista();
    printf("Lista criada.\n");

    if(lista_cheia(li))
        printf("Lista cheia.\n");

    int  x;
    do
    {
        printf("\n ___________________________________________");
        printf("\n|             Programa Controle             |");
        printf("\n|                                           |");
        printf("\n|   1 - Cadastro de Alunos                  |");
        printf("\n|   2 - Remover Alunos                      |");
        printf("\n|   3 - Imprimir                            |");
        printf("\n|   4 - Gravar                              |");
        printf("\n|___________________________________________|");
        printf("\n ___________________________________________");
        printf("\n|                                           |");
        printf("\n|   1 - Para continuar                      |");
        printf("\n|   0 - Para Sair                           |");
        printf("\n|___________________________________________|");
        scanf("%d", &x);
        getchar();
        switch (x)
        {
            case 1: {
                int op;
                do{
                    printf("\n-Nome: ");
                    fgets(al.nome, sizeof(al.nome), stdin);
                    printf("\n-Digite a Matricula: ");
                    scanf("%d", &al.matricula);
                    for (int i = 0; i < 3; ++i) {
                        printf("Digite a nota %d: \n", i);
                        scanf("%f", &al.notas[i]);
                    }
                    inserir_lista_ordenada(li, al);

                    printf("\n-Continuar cadastro: ");

                    printf("\n ___________________________________________");
                    printf("\n|                                           |");
                    printf("\n|   1 - Para continuar                      |");
                    printf("\n|   0 - Para Sair                           |");
                    printf("\n|___________________________________________|");
                    scanf("%d", &op);
                    getchar();

            } while (op != 0);
            }

                break;

            case 2: {
                int op;
                do{printf("\n-Numero de matriculas no sistema: ");
                    tamanho_lista(li);
                    printf("\n-Digite a Matricula: ");
                    remover_lista(li, al.matricula);
                    int sis = remover_lista(li,al.matricula);
                    if(sis == 1)
                        printf("\n-Matricula removida!");
                    else{
                        printf("\n-Erro ao matricula removida!");
                    }
                    printf("\n-Continuar Removendo: ");

                    printf("\n ___________________________________________");
                    printf("\n|                                           |");
                    printf("\n|   1 - Para continuar                      |");
                    printf("\n|   0 - Para Sair                           |");
                    printf("\n|___________________________________________|");
                    scanf("%d", &op);
                    getchar();
                }
                while (op != 0);
            }

                break;
            case 3:

                imprimir_lista(li);

                break;
            case 4:
                salvar_arquivo(li);
                break;
                default:
                    break;
        }
    }while(x != 0);


    return 0;
}