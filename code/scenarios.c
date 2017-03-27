
// NAPLNENIE HASHMAPY VELKYM POCTOM HODNOT

for (int i = 0; i < 1300; i++) {
    
    int length = snprintf(NULL, 0, "%d", i);
    char* str = malloc(length + 1);
    snprintf(str, length + 1, "%d", i);
    createVarInBundle(bundle, str, true);        
    free(str);
}

