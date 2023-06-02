#include <stdio.h>
#include <stdlib.h>

//Zadanie typu:
//-stwórz tablicę o dynamicznej wielkości (wielkość podaje użytkownik) - create_array
//-wyświetl ją - print_array
//-posortuj ją insert i quick
//-wyświetl ją - print_array
//wyszukaj binarnie
//wrzuć do stosu - pop i push do wyświetlenia

struct stos {
    struct stos *pointer;
    int value;
};


int * create_array(int size);
void print_array(int *tab, int size);

void insert_sort(int *tab, int size);
void quick_sort(int *tab, int leftIndex, int rightIndex);
int partition(int *tab, int leftIndex, int rightIndex);

int binary_search(int *tab, int size, int number);

void push(struct stos **top, int number);
int pop(struct stos **top);

int main() {
    int *tab;
    int size;
    printf("Podaj rozmiar: \n");
    scanf("%d", &size);

    tab = create_array(size);
    print_array(tab, size);

    quick_sort(tab, 0, size -1);
    print_array(tab, size);

    printf("\n Indeks szukanej liczby to: %d ", binary_search(tab, size, 1));

    struct stos *top = NULL;

    for (int i = 0; i < size; i++)
    {
        push(&top, tab[i]);
    }

    printf("\n STOS:");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", pop(&top));
    }
    

    return 0;
}

int * create_array(int size)
{
    int *arr = (int *) malloc(size*sizeof(int));
    
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand()%100;
    }
    
    return arr;
}

void print_array(int *tab, int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
    
}

void insert_sort(int *tab, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && tab[j] < tab[j-1])
        {
            int temp = tab[j];
            tab[j] = tab[j-1];
            tab[j-1] = temp;
            j--;
        }
    }    
}

void quick_sort(int *tab, int leftIndex, int rightIndex)
{
    if(leftIndex >= rightIndex) return;

    int pivot = partition(tab, leftIndex, rightIndex);
    
    quick_sort(tab, leftIndex, pivot - 1);
    quick_sort(tab, pivot + 1, rightIndex);
}

int partition(int *tab, int leftIndex, int rightIndex)
{
    int pivot = tab[rightIndex];

    int i = leftIndex -1;

    for (int j = leftIndex; j <= rightIndex - 1; j++)
    {
        if(tab[j] < pivot)
        {
            i++;
            int temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
    }

    i++;
    int temp = tab[rightIndex];
    tab[rightIndex] = tab[i];
    tab[i] = temp;

    return i;
}

int binary_search(int *tab, int size, int number)
{
    int leftIndex = 0;
    int rightIndex = size - 1;
    while(leftIndex <= rightIndex) 
    {
        int mid = leftIndex + (rightIndex - leftIndex) / 2;
        if(tab[mid] == number)
            return mid;
        else if (tab[mid] > number)
            rightIndex = mid - 1;
        else
            leftIndex = mid + 1;
    }

    return -1;
}

void push(struct stos **top, int number)
{
    struct stos *new = (struct stos *) malloc(sizeof(struct stos));

    new->value = number;
    new->pointer = NULL;

    if(*top != NULL)
        new->pointer = *top;

    *top = new;
}

int pop(struct stos **top)
{
    if(*top == NULL)
        return -1;
    
    int value = (*top)->value;

    struct stos *temp = *top;
    *top = temp->pointer;
    free(temp);
    return value;
}