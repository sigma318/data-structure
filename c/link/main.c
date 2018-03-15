#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#include "dlist.h"

void test_p(int **pint)
{
    int *pp = *pint;
    printf("pp:%p, *pint:%p, %d\n", pp, *pint, pint);
}

int main(void)
{
    printf("start here\n");
    sl_test();

    dl_list_test();
    printf("end here\n");

    int *node = NULL;
    int *tmp = node;
    int a = 30;
    int *ppp = 100;

    printf("ppp:%p, &ppp:%d\n", ppp, &ppp);

    printf("node: %p, %d, tmp:%p, %d\n", node, &node, tmp, &tmp);

    test_p(&node);
    node = &a;
    printf("node: %p, %d, tmp:%p, %d\n", node, &node, tmp, &tmp);

    printf("a addr:%d\n", &a);
    test_p(&node);

    return 0;
}
