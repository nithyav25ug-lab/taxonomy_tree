#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Taxon {
    char name[50];
    int lifespan;
    struct Taxon *parent_group; 
} Taxon;
