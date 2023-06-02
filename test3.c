#include <stdio.h>
#include <stdlib.h>

//Zadanie typu:
//-stwórz tablicę o dynamicznej wielkości (wielkość podaje użytkownik) - create_array
//-wyświetl ją - print_array
//-posortuj ją bubble
//-wyświetl ją - print_array
//wyszukaj binarnie i liniowo
//wrzuć do stosu - pop i push do wyświetlenia

struct stos {
    struct stos *pointer;
    int value;
};

int * create_array(int size);
void print_array(int *arr, int size);

void bubble_sort(int *arr, int size);

int binary_search(int *arr, int size, int number);
int linear_search(int *arr, int size, int number);

int pop(struct stos **top);
void push(struct stos **top, int number);

int main() {
    int *arr;
    int size;
    printf("Podaj rozmiar: \n");
    scanf("%d", &size);

    arr = create_array(size);
    print_array(arr, size);

    bubble_sort(arr, size);
    print_array(arr, size);
    printf("\n Indeks liczby 8 to: %d", binary_search(arr, size, 8));

    struct stos *gora = NULL;

    for (int i = 0; i < size; i++)
    {
        push(&gora, arr[i]);
    }

    printf("\n STOS:");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", pop(&gora));
    }
    
    return 0;
}

int * create_array(int size) 
{
    int *arr = malloc(size*sizeof(int)); 

    for(int i = 0; i < size; i++)
    {
        arr[i] = rand()%100;
    }
    
    return arr;
}

void print_array(int *arr, int size) 
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void bubble_sort(int *tab, int size) {
    for(int i = 1; i < size; i++)
    {
        for(int j = 1; j <= size - i; j++)
        {
            if(tab[j] < tab[j-1])
            {
                int temp = tab[j - 1];
                tab[j - 1] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

int binary_search(int *arr, int size, int number)
{
    int leftIndex = 0;
    int rightIndex = size -1;
    while (leftIndex <= rightIndex)
    {
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2 ;
        if(arr[midIndex] == number)
            return midIndex;
        else if (arr[midIndex] < number)
            leftIndex = midIndex + 1;
        else
            rightIndex = midIndex - 1;
    }
    
    return -1;
} 

int linear_search(int *arr, int size, int number)
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == number)
        {
            return i;
        }
    }

    return -1;
}

int pop(struct stos **top)
{
    if(*top == NULL)
    {
        return -1;
    }
    else
    {
        int wartosc = (*top)->value;
        struct stos *temp = *top;
        *top = temp->pointer; 
        free(temp);
        return wartosc;
    }
}

void push(struct stos **top, int number)
{
    struct stos *nowy = malloc(sizeof(struct stos));

    nowy->value = number;
    nowy->pointer = NULL;

    if(*top != NULL)
    {
        nowy->pointer = *top;
    }
    
    *top = nowy;
}