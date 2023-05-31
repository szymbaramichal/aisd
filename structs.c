#include <stdio.h>
#include <stdlib.h>

//Region STOS 
#pragma region Stos
struct stos
{
	struct stos * wsk;
	int x;
};

void push(struct stos **gwsk, int n)
{
    struct stos *y = malloc(sizeof(struct stos));
    y->wsk = NULL;
    y->x = n;
    if (*gwsk != NULL)
    {
        y->wsk = *gwsk;
    }
    *gwsk = y;
}

int pop (struct stos **gwsk)
{
    if (*gwsk == NULL)
    {
        printf("Stos jest pusty\n");
        return 0;
    }
    else
    {
        int wartosc = (*gwsk)->x;
        struct stos *wskTmp = *gwsk;
        *gwsk = wskTmp->wsk;
        free(wskTmp);
        return wartosc;
    }
	
}
#pragma endregion

//Region Lista dwukierunkowa
#pragma region Lista
struct lista_dwukierunkowa
{
    struct lista_dwukierunkowa * lewy;
    int x;
    struct lista_dwukierunkowa * prawy;
};

void pushList (struct lista_dwukierunkowa ** pgwsk, struct lista_dwukierunkowa ** lgwsk, int wartosc)
{
    struct lista_dwukierunkowa * nowy = (struct lista_dwukierunkowa*)malloc(sizeof(struct lista_dwukierunkowa));
    nowy -> prawy = NULL;
    nowy -> x = wartosc;
    nowy -> lewy = *pgwsk;
	if (* pgwsk != NULL)
    { 
        (*pgwsk) -> prawy = nowy;
    }   
    * pgwsk = nowy;
    if (* lgwsk == NULL)
    {
        * lgwsk = nowy;
    }
    
}

int popList (struct lista_dwukierunkowa ** lgwsk)
{
    if (*lgwsk == NULL)
    {
        printf("Lista dwukierunkowa jest pusta");
        return 0;
    }
    else
	{
    	int wartosc;
    	wartosc = (* lgwsk) -> x;
   		struct lista_dwukierunkowa * wskTmp;
    	wskTmp = *lgwsk;
    	if (wskTmp -> prawy)
		{
    		wskTmp -> prawy -> lewy = NULL;
		}
		*lgwsk = wskTmp -> prawy;
    	free (wskTmp);
    	return wartosc;
    }
}

#pragma endregion

int main ()
{
    //Region STOS
    #pragma region Stos
    printf("----------STOS----------- \n");
	struct stos * gwsk = NULL;
	push(&gwsk, 5);
	push(&gwsk, 10);
	push(&gwsk, 15);
	printf("%d\n", gwsk->x);
	printf("%d\n",pop(&gwsk));
	printf("%d\n",pop(&gwsk));
	printf("%d\n",pop(&gwsk));
    printf("----------STOS----------- \n \n");

    #pragma endregion

    //Region lista dwukierunkowa
    #pragma region Lista
    printf("----------LISTA----------- \n");
    struct lista_dwukierunkowa *lgwsk = 0;
    struct lista_dwukierunkowa *pgwsk = 0;
    pushList(&pgwsk, &lgwsk, 5);
    pushList(&pgwsk, &lgwsk, 4);
    pushList(&pgwsk, &lgwsk, 3);
    pushList(&pgwsk, &lgwsk, 2);
	printf(" %d\n", popList(&lgwsk));
	printf(" %d\n", popList(&lgwsk));
	printf(" %d\n", popList(&lgwsk));
	printf(" %d\n", popList(&lgwsk));
	printf(" %d\n", popList(&lgwsk));
    printf("----------LISTA----------- \n");
    #pragma endregion   

	return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// struct lista_dwukierunkowa
// {
//     struct lista_dwukierunkowa * lewy;
//     int x;
//     struct lista_dwukierunkowa * prawy;
// };

// void push (struct lista_dwukierunkowa ** pgwsk, struct lista_dwukierunkowa ** lgwsk, int wartosc)
// {
//     struct lista_dwukierunkowa * nowy = (struct lista_dwukierunkowa*)malloc(sizeof(struct lista_dwukierunkowa));
//     nowy -> prawy = 0;
//     nowy -> x = wartosc;
//     nowy -> lewy = *pgwsk;
// 	if (* pgwsk != 0)
//     { 
//         (*pgwsk) -> prawy = nowy;
//     }   
//     * pgwsk = nowy;
//     if (* lgwsk == 0)
//     {
//         * lgwsk = nowy;
//     }
    
// }

// int pop (struct lista_dwukierunkowa ** lgwsk)
// {
//     if (*lgwsk == 0)
//     {
//         printf("Lista dwukierunkowa jest pusta");
//         return 0;
//     }
//     else
// 	{
//     	int wartosc;
//     	wartosc = (* lgwsk) -> x;
//    		struct lista_dwukierunkowa * wskTmp;
//     	wskTmp = *lgwsk;
//     	if (wskTmp -> prawy)
// 		{
//     		wskTmp -> prawy -> lewy = 0;
// 		}
// 		*lgwsk = wskTmp -> prawy;
//     	free (wskTmp);
//     	return wartosc;
//     }
// }

// int main ()
// {
//     struct lista_dwukierunkowa *lgwsk = 0;
//     struct lista_dwukierunkowa *pgwsk = 0;
//     push(&pgwsk, &lgwsk, 5);
//     push(&pgwsk, &lgwsk, 4);
//     push(&pgwsk, &lgwsk, 3);
//     push(&pgwsk, &lgwsk, 2);
// 	printf(" %d\n", pop(&lgwsk));
// 	printf(" %d\n", pop(&lgwsk));
// 	printf(" %d\n", pop(&lgwsk));
// 	printf(" %d\n", pop(&lgwsk));
// 	printf(" %d\n", pop(&lgwsk));
//     return 0;
// }