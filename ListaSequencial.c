//
// Created by Paulo Roberto on 02/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "ListaSequencial.h"

typedef struct File File;
struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista* criar_lista(){
    Lista* li;
    li = (Lista*) malloc (sizeof(struct lista));
    if (li != NULL)
        li->qtd = 0;
    return li;
}

void liberar_lista(Lista* li){
    free(li);
}

int tamanho_lista(Lista *li){
    if (li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_vazia(Lista *li){
    if(li == NULL)
        return - 1;
    else
        return (li->qtd == 0);
}

int lista_cheia(Lista *li){
    if(li == NULL)
        return -1;
    else
        return (li->qtd == MAX);
}

int inserir_lista_inicio(Lista *li, struct aluno al){
    if (li == NULL)
        return 0;
    if(li->qtd == MAX)
        return 0;
    int i;
    for(i=li->qtd-1; i>=0; i--)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int inserir_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int inserir_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)
        return 0;
    int i,k = 0;
    while(i < li->qtd && li->dados[i].matricula < al.matricula)
        i++;
    for(k=li->qtd-1; k>=1; k--)
        li->dados[k+1] = li->dados[k];
    li->dados[i] = al;
    li->qtd++;
    return 1;
}

//ATV

int remover_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int i = 0;
    for ( i = 0; i < li->qtd -1; ++i)
        li->dados[i] = li->dados[i+1];
    li->qtd--;
    return 1;
}

int remover_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int i = 0,k = 0;
    while ( i < li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)
        return 0;
    for (k = 0; k < li->qtd-1; ++k)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remover_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    li->qtd--;
    return 1;
}

int buscar_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0 || pos > li->qtd)
        return 0;
    *al = li->dados[pos-1];
    return 1;
}

int inserir_nota_mat(Lista* li, int mat, const float notas[]){
    if(li == NULL)
        return -1;
    int i = 0;
    int j;
    while(i < li->qtd &&  li->dados[i].matricula != mat)
        i++;
    for(j = 0; j < 3; j++)
        li->dados[i].notas[j] = notas[j];
    return 1;
}

int inserir_nota_nome(Lista* li, const char *nome, const float notas[]){
    if(li == NULL)
        return -1;
    int i = 0;
    int j;
    while(i < li->qtd && li->dados[i].nome != nome)
        i++;
    for(j = 0; j < 3; j++)
        li->dados[i].notas[j] = notas[j];
    return 1;
}

float calcular_media(Lista* li, int mat){
    if(li == NULL)
        return -1;
    int i = 0;
    int j;
    float media, soma = 0;
    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)
        return 0;
    for(j = 0; j < 3;j++){
        soma+=li->dados[i].notas[j];
    }
    media = soma/3;
    return media;
}

//fim ATV


void imprimir_lista(Lista *li){
    int i;
    printf("-------------\n");
    for(i=0;i < li->qtd; i++){
        printf("Matricula: %d\n", li->dados[i].matricula);
        printf("Nome: %s\n",li->dados[i].nome);
        for (int j = 0; j < 3; ++j) {
            printf("Nome: %.2f\n",li->dados[i].notas[j]);
        }
        printf("Media %.2f: \n", calcular_media(li,li->dados[i].matricula));
        //float m = calcular_media(li,al.matricula);
        if(calcular_media(li,li->dados[i].matricula) >= 7){
            printf("O aluno %s esta Aprovado! \n", li->dados[i].nome);
        }else{
            printf("O aluno %s esta Reprovado! \n", li->dados[i].nome);
        }

        printf("-------------\n");
    }
}

void salvar_arquivo(Lista *li){
    File *arquivo;
    arquivo = (File *) fopen("Dados", "w");
    int i;
    for(i=0;i < li->qtd; i++){
        fprintf((FILE *) arquivo, "Matricula: %d\n", li->dados[i].matricula);
        fprintf((FILE *) arquivo, "Nome: %s\n", li->dados[i].nome);
        for (int j = 0; j < 3; ++j) {
            fprintf((FILE *) arquivo, "Nome: %.2f\n", li->dados[i].notas[j]);
        }
        fprintf((FILE *) arquivo, "Media %.2f: \n", calcular_media(li, li->dados[i].matricula));
        //float m = calcular_media(li,al.matricula);
        if(calcular_media(li,li->dados[i].matricula) >= 7){
            fprintf((FILE *) arquivo, "O aluno %s esta Aprovado! \n", li->dados[i].nome);
        }else{
            fprintf((FILE *) arquivo, "O aluno %s esta Reprovado! \n", li->dados[i].nome);
        }

        fclose((FILE *) arquivo);
    }
}

