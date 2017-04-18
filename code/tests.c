/**
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "anf.h"
#include "utils.h"

int emptyAnfs() {

    tANFBundle* bundle = createANFBundle(10, 0.7);
    if (bundle == NULL) {
        return ERROR;
    }

    tAnf* anf1 = createEmptyAnf();
    if (anf1 == NULL) {
        freeANFBundle(bundle);
        return ERROR;
    }

    printAnf(anf1);

    tAnf* anf2 = createEmptyAnfInBundle(bundle);
    if (anf2 == NULL) {
        freeAnf(anf1);
        freeANFBundle(bundle);
        return ERROR;
    }

    printAnf(anf2);

    printBundle(bundle);

    if (addAnfToBundle(bundle, anf1) != OK) {
        freeAnf(anf1);
        freeAnf(anf2);
        freeANFBundle(bundle);
        return ERROR;
    }

    printBundle(bundle);

    freeAnf(anf1);
    freeAnf(anf2);

    freeANFBundle(bundle);
    return OK;
}

int main(int argc, char* argv[]) {

    printf("TEST 01: %d\n", emptyAnfs());

}