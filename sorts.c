#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *, int);
void print_table(int *, int);
void insert_sort(int *, int);
void quick_sort(int *, int, int);
int partition(int *, int, int);

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);

int main() {
    int tab[7] = {-4, 2, -11, 44, 66, -88, 100};
    
    quick_sort(tab, 0, 6);
    print_table(tab, 7);
    printf("\n");

    int tab1[7] = {-4, 2, -11, 44, 66, -88, 100};
    insert_sort(tab1, 7);
    print_table(tab1, 7);
    printf("\n");

    int tab2[7] = {-4, 2, -11, 44, 66, -88, 100};
    bubble_sort(tab2, 7);
    print_table(tab2, 7);
    printf("\n");

    int tab3[7] = {-4, 2, -11, 44, 66, -88, 100};
    merge_sort(tab3, 7);
    print_table(tab3, 7);
    printf("\n");

    return 0;
}

// https://youtu.be/LeWuki7AQLo
void merge_sort(int a[], int length)
{
  merge_sort_recursion(a, 0, length - 1);
}

void merge_sort_recursion(int a[], int l, int r)
{
  if (l < r)
  {
    // find the midpoint of l and r
    int m = l + (r - l) / 2;
  
    // apply the function recursively to the left and right portions split 
    // at the midpoint
    merge_sort_recursion(a, l, m);
    merge_sort_recursion(a, m + 1, r);
  
    // at this point both portions of the array have been sorted, and we now 
    // merge the sorted portions of the array
    merge_sorted_arrays(a, l, m, r);
  }
}

//merges the two sorted portions of the array a between the indexes l ... m
//and m + 1 ... r
void merge_sorted_arrays(int a[], int l, int m, int r)
{
  int left_length = m - l + 1;
  int right_length = r - m;
  
  int temp_left[left_length];
  int temp_right[right_length];
  
  int i, j, k;
  
  for (int i = 0; i < left_length; i++)
    temp_left[i] = a[l + i];
  
  for (int i = 0; i < right_length; i++)
    temp_right[i] = a[m + 1 + i];
  

  for (i = 0, j = 0, k = l; k <= r; k++)
  {
    // so long as we have not already reached the end of the temp_left array 
    // with our variable i, then if the next element in the left_temp array 
    // is smaller OR if we have reached the end of the temp_right array, 
    // then store the next element from temp_left into the next element in 
    // the array a
    if ((i < left_length) &&
        (j >= right_length || temp_left[i] <= temp_right[j]))
    {
      a[k] = temp_left[i];
      i++;
    }
    // otherwise if the next element in temp_right than the next element in 
    // temp_left OR we have reached the end of temp_left, store the next 
    // element from the temp_right array into the next element in array a
    else
    {
      a[k] = temp_right[j];
      j++;
    }
  }  
}

// https://youtu.be/Vtckgz38QHs
void quick_sort(int *tab, int start, int end)
{
    if(end <= start) return; // base case, not able to divide more

    int pivot = partition(tab, start, end);
    quick_sort(tab, start, pivot - 1);
    quick_sort(tab, pivot + 1, end); // pivot already in place

}
int partition(int *tab, int start, int end)
{
    int pivot = tab[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++)
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

    int temp = tab[i];
    tab[i] = tab[end];
    tab[end] = temp;
    return i; // location of pivot
}

// https://www.geeksforgeeks.org/bubble-sort/
void bubble_sort(int *tab, int size) {
    for(int i = 1; i < size; i++)
    {
        for(int j = 1; j < size - i; j++)
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

// https://www.geeksforgeeks.org/insertion-sort/
void insert_sort(int *tab, int size)
{
    for(int i = 1; i < size; i++)
    {
        int j = i;
        while(tab[j] < tab[j - 1] && j > 0)
        {
            int temp = tab[j - 1];
            tab[j - 1] = tab[j];
            tab[j] = temp;
            j--;
        }

    }
}


void print_table(int *tab, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
}


