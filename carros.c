#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carros.h"

/*
! Funções Auxiliares
*/

/**
 * Procura slot vazia no array carros.
 * devolve o índice
 */
int get_first_free_slot(Garagem *g)
{
    for (int i = 0; i < g->max_carros - 1; i++)
    {
        if (g->carros[i] == NULL)
            return i;
    }
    return -1;
}

/*
! Funções Públicas
*/

/**
 * Criar uma garagem para n Carros
 * @param dim dimensão da garagem. Nº de carros máximo
 * @return ponteiro para garagem
 */
Garagem *newGaragem(int dim, char *nome)
{
    Garagem *g = malloc(sizeof(Garagem));
    g->max_carros = dim;
    g->carros = 0;
    g->valor_total = 0.0;
    g->next_id = 1; // primeiro carro do sistema
    g->nome = malloc(strlen(nome) + 1);
    memset(g->nome, '\0', strlen(nome) + 1);
    strcpy(g->nome, nome);
    g->carros = malloc(sizeof(Carro *) * dim);

    // Coclocar todos os ponteiros a NULL
    for (int i = 0; i < dim; i++)
        g->carros[i] = NULL;
    return g;
}

/**
 * Limpa a memória da garagem
 * @param g ponteiro para garagem
 */
void free_garagem(Garagem *g)
{
}

/**
 * Escreve no ecrá informação da garagem
 * (Nome da garagem)
 * (Número de carros existentes)
 * (Valor dos carros existentes)
 * (lugares vagos na garagem)
 * (vosso critério imprimir lista de carros existentes - info reduzida)
 * @param g ponteiro para garagem
 */
void print_info_garagem(Garagem *g)
{
    puts("---Info da Garagem---");
    printf("### %s ###\n", g->nome);
    printf("Valor: %.2lf, Carros:%d\n", g->valor_total, g->num_carros);
    for (int i = 0; i < g->max_carros - 1; i++)
    {
        if(g->carros[i])// != NULL
            printf("-[%d] %s | %s\n",g->carros[i]->id,g->carros[i]->matricula,g->carros[i]->marca);
    }
}

/**
 * Insere um carro se a garagem tiver vaga. Se não tiver não insere e dá erro
 * @param g Garagem
 * @param matricula do carro
 * etc
 */
void inserir_carro(Garagem *g, char *matricula, char *marca, char *modelo, int ano, double valor)
{
    // ver se há espaço
    if (g->num_carros == g->max_carros)
    {
        // Caso não haja dá erro e sai
        puts("Erro a garagem está cheia!!!");
        return;
    }

    // Se houver espaço procurar o lugar
    int indice = get_first_free_slot(g);
    // criar a estrutura carro
    Carro *c = malloc(sizeof(Carro));
    g->carros[indice] = c;
    // vou inicializar as variaveis carro
    c->id = g->next_id;
    c->ano = ano;
    c->valor = valor;
    c->matricula = malloc(sizeof(char) * TEXT_LEN);
    memset(c->matricula, '\0', TEXT_LEN);
    strncpy(c->matricula, matricula, TEXT_LEN);

    c->marca = malloc(sizeof(char) * TEXT_LEN);
    memset(c->marca, '\0', TEXT_LEN);
    strncpy(c->marca, marca, TEXT_LEN);

    c->modelo = malloc(sizeof(char) * TEXT_LEN);
    memset(c->modelo, '\0', TEXT_LEN);
    strncpy(c->modelo, modelo, TEXT_LEN);

    // vou atualizar a info da garagem
    g->valor_total += valor;
    g->next_id++;
    g->num_carros++;
    printf("Viatura ID: %d e matricula %s inserida com sucesso!\n", c->id, c->matricula);
}

/**
 * Se carro existir apaga e escreve a matricula apagada
 * Se carro não existir dá mensagem de erro
 */
void apagar_carro(Garagem *g, int id)
{
}

/**
 * Se carro existir substitui o modelo
 * Se carro não existir (id) dá mensagem de erro
 */
void editar_modelo(Garagem *g, int id, char *modelo)
{
}

/**
 * strstr()
 * Imprime lista de carros que correspondem à pesquisa
 */
void pesquisar_marca(Garagem *g, char *pesquisa)
{
}

/**
 * Imprime todos os campos da estrutura carro.
 * Se o carro com o ida existir imprime a ficha.
 * Caso contrario dá erro
 */
void ficha_carro(Garagem *g, int id)
{
}

/**
 * strstr()
 * Imprime lista de carros do ano em causa
 */
void pesquisar_ano(Garagem *g, int ano)
{
}
