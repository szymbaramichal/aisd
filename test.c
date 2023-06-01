#include <stdio.h>
#include <stdlib.h>

//Zadanie typu:
//-stwórz tablicę o dynamicznej wielkośći (wielkość podaje użytkownik) - create_array
//-wyświetl ją - print_array
//-posortuj ją quick sortem
//-wyświetl ją - print_array
//wyszukaj binarnie 
//wrzuć do stosu - pop i push do wyświetlenia

struct stos {
    struct stos *pointer;
    int number;
};

int * create_array(int size);
void print_array(int *tab, int size);
void quick_sort(int *tab, int startIndex, int endIndex);
int partition(int *tab, int startIndex, int endIndex);
void push(struct stos **top, int number);
int binary_search(int *tab, int length, int number);
int pop(struct stos **top);

int main () {
    int size;
    int *arr;
    printf("Podaj rozmiar tablicy: \n");
    scanf("%d", &size);

    arr = create_array(size);
    print_array(arr, size);
    printf("Sortowanie... \n");
    quick_sort(arr, 0, size -1);
    print_array(arr, size);

    printf("%d \n", binary_search(arr, size, 3));

    struct stos *sztos = NULL;
    for(int i = 0; i < size; i++)
    {
        push(&sztos, arr[i]);
    }

    for(int i = 0; i < size; i++)
    {
        int value = pop(&sztos);
        printf("%d", value);
    }

    return 0;
}


int * create_array(int size)
{
    int *tab = (int *) (malloc(size*sizeof(int)));
    for(int i = 0; i < size; i++)
    {
        tab[i] = rand()%100;
    }

    return tab;
} 

void print_array(int *tab, int size)
{
    printf("Oto tablica: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void quick_sort(int *tab, int startIndex, int endIndex)
{
    if(startIndex >= endIndex) return;

    int pivot = partition(tab, startIndex, endIndex);

    quick_sort(tab, startIndex, pivot -1);
    quick_sort(tab, pivot + 1, endIndex);
}

int partition(int *tab, int startIndex, int endIndex)
{
    int pivot = tab[endIndex];

    int i = startIndex -1;

    for (int j = startIndex; j <= endIndex - 1; j++)
    {
        if(tab[j] <= pivot)
        {
            i++;
            int temp = tab[j];
            tab[j] = tab[i];
            tab[i] = temp;
        }
    }
    i++;
    
    int temp = tab[endIndex];
    tab[endIndex] = tab[i];
    tab[i] = temp;

    return i;
}

void push(struct stos **top, int number)
{
    struct stos *new = malloc(sizeof(struct stos)); 
    new->number = number;
    new->pointer = NULL;
    if(*top != NULL)
    {
        new->pointer = *top;
    }

    *top = new;
}

int pop(struct stos **top)
{
    if(*top == NULL)
    {
        printf("PUSTY STOS");
        return 0;
    }
    else
    {
        int value = (*top)->number;
        struct stos *temp = *top;
        *top = temp->pointer;
        free(temp);
        return value;
    }
}

int binary_search(int *tab, int length, int number)
{
    int startIndex = 0;
    int endIndex = length -1;
    while (startIndex <= endIndex) {
    int mid = startIndex + (endIndex - startIndex) / 2;
    if (tab[mid] == number)
        return mid;
    else if (tab[mid] < number)
        startIndex = mid + 1;
    else
        endIndex = mid - 1;
    }
    return -1;
}
