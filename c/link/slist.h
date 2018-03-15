#ifndef SLIST_H
#define SLIST_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define SL_TEST

typedef struct _snode
{
    int a;
    struct _node *next;
    int value;
}snode_t;

#define sl_insert(type, root,val) sl_insert_##type((root), (val))

/*
** insert a new value to a list which destinated by  *node
**/
int sl_insert_up(snode_t **proot, int new_value);

/*
** insert a new value to a list which destinated by  *node
**/
int sl_insert_down(snode_t **proot, int new_value);


/*
** insert a value to a list tail
**/
int sl_insert_tail(snode_t **proot, int value);


/*
** insert a value to a list head
**/
int sl_insert_head(snode_t **proot, int value);

/*
** delete a node from a list which designated by *proot
**/
int sl_delete(snode_t **proot, int value);

/*
** print all node value in the list designated by proot
**/
int sl_print_list(snode_t **proot);

#ifdef SL_TEST
int sl_test(void);
#endif // SL_TEST

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LIST_H
