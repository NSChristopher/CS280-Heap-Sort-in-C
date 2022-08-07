#include <stdlib.h>
#include <string.h>
#include "srt.h"

void heapify(void *base, size_t nelem, size_t size, size_t parent, int (*compar)(const void *, const void *));

void srtheap(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *))
{
    size_t i;

    for (i = (nelem / 2) - 1; i > 0; i--)
    {
        heapify(base, nelem - 1, size, i, compar);
    }

    heapify(base, nelem - 1, size, 0, compar);
    

    for (i = nelem - 1; i > 0; i--)
    {
        swap(base, base + i * size, size);
        heapify(base, i - 1, size, 0, compar);
    }
}

void heapify(void *base, size_t nelem, size_t size, size_t parent, int (*compar)(const void *, const void *))
{
    size_t child;
    while ((child = 2 * parent + 1) <= nelem)
    {
        if (child + 1 <= nelem && compar(base + child * size, base + (child + 1) * size) < 0)
        {
            child = 2 * parent + 2;
        }
        
        if (compar(base + parent * size, base + child * size) < 0)
        {
            swap(base + parent * size, base + child * size, size);
            parent = child;
        }
        else
        {
            break;
        }
    }
}