/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include "anf.h"

anf createAnf() {

    anf anf;
    anf.length = 0;
    return anf;
}

anf createAnfWithNodes(node nodes[], int size) {

    anf anf;
    anf.length = 0;

    for (int i = 0; i < size; i++) {
        anf.nodes[i] = nodes[i];
        anf.length++;
    }
    return anf;
}

void addNodeToAnf(node node, anf* anf) {

    int length = anf->length;

    anf->nodes[length] = node;
    anf->length++;
}

void printAnf(anf anf) {

    printf("********************************\nANF:\n @ ");
    for (int i = 0; i < anf.length; i++) {
        for (int j = 0; j < anf.nodes[i].length; j++) {
        
            printf("%s",anf.nodes[i].variables[j]);
            if (anf.nodes[i].length - j > 1) {
                printf(" & ");
            }
            // printf("\n");
        }
        if (anf.length - i > 1) {
            printf(" XOR \n @ ");
        }
    }
    // printf("\n");

    printf("\nPocet uzlov: %d\n", anf.length);
    printf("********************************\n");
}
