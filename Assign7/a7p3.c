#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int value;
    int index;
} Element;
int compare(const void* a, const void* b)
{
    Element* elementA = (Element*)a;
    Element* elementB = (Element*)b;
    return elementA->value - elementB->value;
}
int main()
{
    int n;
    scanf("%d", &n);
    Element elements[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elements[i].value);
        elements[i].index = i + 1;
    }
    qsort(elements, n, sizeof(Element), compare);
    for (int i = 0; i < n; i++)
        printf("%d ", elements[i].value);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", elements[i].index);
    return 0;
}