#ifndef DLIST_H
#define DLIST_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef struct _node
{
        struct _node *fwd;
        struct _node *bwd;
        int          value;
}node_t;

int dl_insert(node_t **proot, int new_value);

void dl_list_test(void);


#ifdef __cplusplus
}
#endif

#endif // DLIST_H
