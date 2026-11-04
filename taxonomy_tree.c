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
        printf("\nEnter name for %s: ", label);
        scanf("%s", name_out);
        printf("Enter lifespan for Species %s: ", name_out);
        scanf("%d", lifespan_out);
}

void link_parent(Taxon *child, Taxon *parent)
{
    child->parent_group=parent;
}

void print_taxonomy(Taxon *species_list[], int species_count)
{
    int no=1;
    printf("=== SPECIES CLASSIFICATION HIERARCHY ===\n");
    for (int i = 0; i < species_count; i++)
    {
        Taxon *species = species_list[i];
        if (species == NULL)
        {
            continue;
        }
        printf("%d. SPECIES %d: %s\n", no, no, species->name);
        no++;
        printf("   - Average Lifespan: %d years\n", species->lifespan);
        Taxon *genus = species->parent_group;
        if (genus != NULL)
        {
            printf("   - Belongs to Genus: %s (Lifespan: %d yrs)\n", genus->name, genus->lifespan);
            Taxon *family = genus->parent_group;
            if (family!=NULL)
            {
                printf("   - Belongs to Family: %s (Lifespan: %d yrs)\n", family->name, family->lifespan);
            }
        }
    }
}



int main (void)
{
    Taxon* group[7];
    char name[100];
    int lifespan;
    static char label [7][25]={"Family", "Genera 1", "Genera 2", "Species 1", "Species 2", "Species 3", "Species 4"};

    for (int i=0; i<7; i++)
    {
        read_taxon_info(label[i], name, &lifespan);
        group[i]=create_taxon(name, lifespan);
    }
    Taxon* ans=create_taxon(name, lifespan);

    link_parent(group[1], group[0]);
    link_parent(group[2], group[0]);
    link_parent(group[3], group[1]);
    link_parent(group[4], group[1]);
    link_parent(group[5], group[2]);
    link_parent(group[6], group[2]);
    link_parent(group[0], NULL);

    Taxon* species_list[4] = { group[3], group[4], group[5], group[6] };
    print_taxonomy(species_list, 4);
}

