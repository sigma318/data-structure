/*
** create in 20171003 by liaokunnan
**/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
** insert a new value to a list by ascending order
**/
int sl_insert_up(snode_t **proot, int new_value)
{
    snode_t *new_node = NULL;
    snode_t *cur_node = NULL;

    cur_node = *proot;

    /*
    ** search a correct position in sequence, then insert the new node to the position
    **/
    while(cur_node != NULL && cur_node->value < new_value)
    {
        proot = &cur_node->next;
        cur_node = *proot;
    }

    /*
    ** malloc memory for the new node, if malloc failure then reutrn -1, otherwise 0
    **/
    new_node = (snode_t *)malloc(sizeof(snode_t));
    if(NULL == new_node)
    {
        printf("malloc failure\n");
        return -1;
    }

    /*
    ** insert the new node to the list and return 0
    **/
    new_node->next = cur_node;
    new_node->value = new_value;
    *proot = new_node;

    printf("insert success\n");
    return 0;
}

/*
** insert a value to a list by descending order
**/
int sl_insert_down(snode_t **proot, int value)
{
    snode_t *cur_node = *proot;
    snode_t *new_node = NULL;

    /*
    ** search a node that can insert the new node
    **/
    while(NULL != cur_node && cur_node->value > value)
    {
        proot = &cur_node->next;
        cur_node = *proot;
    }

    new_node = (snode_t *)malloc(sizeof(snode_t));
    if(NULL == new_node)
    {
        printf("malloc failure");
        return -1;
    }

    new_node->next = cur_node;
    new_node->value = value;

    *proot = new_node;

    return 0;
}

/*
** insert a value to a list tail
**/
int sl_insert_tail(snode_t **proot, int value)
{
    snode_t *cur_node = *proot;
    snode_t *new_node = NULL;
    //snode_t *pre_node = NULL;

    /*
    ** search a node that can insert the new node
//    **/
//    while(NULL != cur_node)
//    {
//        proot = &cur_node->next;
//        cur_node = *proot;
//    }

    new_node = (snode_t *)malloc(sizeof(snode_t));
    if(NULL == new_node)
    {
        printf("malloc failure");
        return -1;
    }

    new_node->next = NULL;
    new_node->value = value;

    if(*proot == NULL)
    {
        *proot = new_node;
        return 0;
    }
    while(NULL != cur_node->next)
    {
        //pre_node = cur_node;
        cur_node = cur_node->next;

    }
    //pre_node->next = new_node;
    cur_node->next = new_node;
//
//    *proot = new_node;

    return 0;
}


/*
** insert a value to a list head
**/
int sl_insert_head(snode_t **proot, int value)
{
    snode_t *new_node = NULL;

    new_node = (snode_t *)malloc(sizeof(snode_t));
    if(NULL == new_node)
    {
        printf("malloc failure");
        return -1;
    }

    new_node->next = *proot;
    new_node->value = value;

    *proot = new_node;

    return 0;
}

/*
** delete a node from a list which designated by *proot
**/
int sl_delete(snode_t **proot, int value)
{
    snode_t *cur_node = *proot;

    /*
    ** search the matched node in list
    **/
    while(cur_node != NULL)
    {
        if(cur_node->value == value)
        {
            printf("delete node success\n");
            *proot = cur_node->next;
            free(cur_node);
            return 0;
        }
        proot = &cur_node->next;
        cur_node = *proot;
    }

    printf("delete node failure\n");
    return -1;
}

/*
** print all node value in the list designated by proot
**/
int sl_print_list(snode_t **proot)
{
    snode_t *cur = *proot;

    while(NULL != cur)
    {
        printf("node:%p, value:%d\n", cur, cur->value);
        cur = cur->next;
    }

    return 0;
}

#ifdef SL_TEST
/*
** test the single list
**/
int sl_test(void)
{
    snode_t *rootup = NULL;
    snode_t *rootdown = NULL;
    snode_t *roottail = NULL;
    snode_t *roothead = NULL;
    int i = 0;

//    printf("test up insert\n");
//    for(i = 0; i < 10; i++)
//    {
//        sl_insert(up, &rootup, i);
//    }
//    sl_print_list(&rootup);
//    sl_delete(&rootup, 0);
//    sl_print_list(&rootup);
//    sl_delete(&rootup, 5);
//    sl_print_list(&rootup);
//
//    printf("test down insert\n");
//    for(i = 10; i < 20; i++)
//    {
//        sl_insert(down, &rootdown, i);
//    }
//    sl_print_list(&rootdown);
//    sl_delete(&rootdown, 10);
//    sl_print_list(&rootdown);
//    sl_delete(&rootdown, 15);
//    sl_print_list(&rootdown);

    printf("test down tail\n");
    for(i = 30; i < 40; i++)
    {
        sl_insert(tail, &roottail, i);
    }
    sl_insert(tail, &roottail, i);
    sl_print_list(&roottail);
    sl_delete(&roottail, 30);
    sl_print_list(&roottail);
    sl_delete(&roottail, 35);
    sl_print_list(&roottail);

    sl_insert(tail, &roottail, 100);
    sl_print_list(&roottail);
    sl_insert(tail, &roottail, 0);
    sl_print_list(&roottail);
//
//    printf("test insert head\n");
//    for(i = 50; i < 60; i++)
//    {
//        sl_insert(head, &roothead, i);
//    }
//    sl_print_list(&roothead);
//    sl_delete(&roothead, 50);
//    sl_print_list(&roothead);
//    sl_delete(&roothead, 55);
//    sl_print_list(&roothead);
//    sl_insert(head, &roothead, 70);
//    sl_print_list(&roothead);

    return 0;
}

#endif // SL_TEST
