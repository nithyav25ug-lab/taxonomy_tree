#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Taxon {
    char name[50];
    int lifespan;
    struct Taxon *parent_group; 
} Taxon;

Taxon* create_taxon(const char *name, int lifespan)
{
    struct Taxon* ptr = (struct Taxon*)malloc(sizeof(struct Taxon));
    if (ptr==NULL)
    {
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    strncpy(ptr->name, name, sizeof(ptr->name)-1);
    ptr->name[sizeof(ptr->name)-1]= '\0';
    ptr->lifespan=lifespan;
    ptr->parent_group=NULL;
    return ptr;
}

void read_taxon_info(const char *label, char *name_out, int *lifespan_out)
{
        printf("\nEnter name for %9s: ", label);
        scanf("%9s", name_out);
        printf("\nEnter lifespan for Species %9s: ", name_out);
        scanf("%d", lifespan_out);
}

int main (void)
{
    char name[100];
    int lifespan;
    static char label [7][25]={"Family", "Genera 1", "Genera 2", "Species 1", "Species 2", "Species 3", "Species 4"};
    Taxon* last_created = NULL;
    Taxon* current = create_taxon(name, lifespan);
    for (int i=0; i<7; i++)
    {
        read_taxon_info(label[i], name, &lifespan);
        current->parent_group = last_created;
        last_created = current;
    }
    Taxon* ans=create_taxon(name, lifespan);
}

