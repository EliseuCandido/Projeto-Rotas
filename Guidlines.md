# Guidelines

## Compilação

* O programa deve ser compilado usando o comando `make`.
* O compilador não deve apresentar erros ou avisos ("warnings").
* Recomenda-se usar a versão 7, ou superior, do compilador (consulte `gcc --version`).

## Formatação

* A formatação do código deve ser **consistente**. Recomenda-se a utilização de um editor de texto com indentação automática.
* Abrir cada chaveta na mesma linha do cabeçalho da função **ou** na linha a seguir, alinhada com o cabeçalho.
Fechar cada chaveta numa linha nova, também alinhada com o cabeçalho. O mesmo aplica-se às chavetas associadas aos comandos `for`, `if`, `switch`, e `while`.

## Comentários

* O código deve que ser adequadamente comentado. Comentários em excesso devem ser evitados.
Por exemplo, não é necessário comentar sobre uma variável que representa um contador de um ciclo.
* Cada ficheiro deve ter um comentário, no início, com uma descrição sucinta e o(s) nome(s) do(s) autor(es).
* Cada função deve ter um comentário, antes do cabeçalho, com uma descrição sucinta.
* Cada variável global e/ou estática deve ter um comentário com uma descrição sucinta. O comentário pode ser colocado na mesma linha da declaração da variável, ou na linha antes.

## Organização do código

* Não deve haver repetição de código (código repetido deveria ser colocado numa função).
* Evite funções demasiado grandes (e pouco legíveis).
* Recomenda-se usar a ferramenta [lizard](http://www.lizard.ws/) para calcular a complexidade ciclométrica. A ferramenta não deve emitir avisos.

## Constantes

* Constantes (números, strings) nunca devem que aparecer directamente no código. Usem a directiva `#define` no início dos ficheiros ou num ficheiro `.h` separado.

## Exemplo

```c
/*
 * File:  ex.c
 * Author:  xpto
 * Description: A program exemplifying the use of comments and formatting in C.
*/
#include<stdio.h>

/* The maximum number of values stored. */
#define SZ 100

/* Array of values. */
int vals[SZ];
/* The number of values stored. */
int count;

/* Adds a given value to the global vector returns the new count of values. */
int add(int val) {
    vals[count] = val;
    return ++count;
}

/* Reads n values from stdin and inserts them into the vector vals. */
int main() {
    int n, v;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &v);
        add(v);
    }
    return 0;
}
```

## Valgrind

É aconselhável analisar o projecto usando a ferramenta Valgrind. Para instalar no Ubuntu:

    $ sudo apt-get install valgrind 

1. executar o projecto compilado com o Valgrind usando o teste como standard input, e.g.

    $ valgrind ./SGO_API < testes/testeX_X.in

2. Podem também ignorar o output do projecto da seguinte forma:

    $ valgrind ./SGO_API < testes/testeX_X.in > /dev/null


