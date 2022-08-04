#include <stdlib.h>
#include <string.h>
#include "srt.h"

void heapify(char *base, size_t nelem, size_t size, size_t parent, int (*compar)(const void *, const void *));

void srtheap(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *))
{
    size_t i;

    for (i = nelem / 2; i >= 1; i--)
    {
        heapify(base, nelem, size, i, compar);
    }

    /* sort */
    for (i = nelem; i > 1; i--)
    {
        /* move the largest one to the last position */
        swap(base + size, base + i * size, size);
        heapify(base, i - 1, size, 1, compar);
    }
}

void heapify(char *base, size_t nelem, size_t size, size_t parent, int (*compar)(const void *, const void *))
{
    size_t child;
    while ((child = 2 * parent) <= nelem)
    {
        if (child + 1 <= nelem && compar(base + child * size, base + (child + 1) * size) < 0)
        {
            child = child + 1; /* right child is larger */
        }
        if (compar(base + parent * size, base + child * size) < 0)
        {
            swap(base + parent * size, base + child * size, size); /* child is larger, swap */
            parent = child;
        }
        else
        {
            break;
        }
    }
}