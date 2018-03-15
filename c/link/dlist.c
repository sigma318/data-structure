#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

void dl_list_init(node_t *proot, int value)
{
    proot->bwd = proot;
    proot->fwd = proot;
    proot->value = value;
}

int dl_insert(node_t **proot, int new_value)
{
    node_t *cur = *proot;
    node_t *new_node = NULL;

    new_node = (node_t *)malloc(sizeof(node_t));
    if(NULL == new_node)
    {
        printf("malloc failure\n");
        return -1;
    }
    dl_list_init(new_node, new_value);

    if(NULL == *proot)
    {
        *proot = new_node;
        return 0;
    }

    new_node->fwd = *proot;
    new_node->bwd = (*proot)->bwd;
    (*proot)->bwd->fwd = new_node;
    (*proot)->bwd = new_node;

    return 0;
}

void dl_print_list(node_t **proot)
{
    node_t *cur = *proot;

    for(; cur->fwd != *proot; cur = cur->fwd)
    {
        printf("detect a node, value:%d\n", cur->value);
    }
    printf("detect a node, value:%d\n", cur->value);

}

void dl_list_test(void)
{
    node_t *root;
    int i = 0;

    //dl_list_init(&root);

    printf("test double list start\n");

    for(i = 0; i < 10; i++)
    {
        dl_insert(&root, i);
    }

    dl_print_list(&root);
    dl_insert(&root, 2);
    dl_insert(&root, 9);
    dl_print_list(&root);

    printf("test double list end\n");
}
