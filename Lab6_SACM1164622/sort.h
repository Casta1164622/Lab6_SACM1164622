#pragma once
#include "Lista.h"
#include "pokemon.h"
class sort
{
    
public:

    sort() 
    {
        
    }

    void selectSortGen(Lista<pokemon> lista)
    {

        int i, j, min_idx;
        pokemon tmp;
        int n = lista.GetCount();

        for (i = 0; i < n - 1; i++)
        {
            min_idx = i;
            for (j = i + 1; j < n; j++)
            {
                if (lista.GetItem(j)->data.getGeneracion() < lista.GetItem(min_idx)->data.getGeneracion())
                {
                    min_idx = j;
                }
                if (lista.GetItem(j)->data.getGeneracion() == lista.GetItem(min_idx)->data.getGeneracion())
                {
                    if (lista.GetItem(j)->data.GetNombre().compare(lista.GetItem(min_idx)->data.GetNombre()) < 0)
                        min_idx = j;
                }
            }
            tmp = lista.GetItem(min_idx)->data;
            lista.GetItem(min_idx)->data = lista.GetItem(i)->data;
            lista.GetItem(i)->data = tmp;
        }
    }
    void selectSortNN(Lista<pokemon> lista)
    {
        int i, j, min_idx;
        pokemon tmp;
        int n = lista.GetCount();

        for (i = 0; i < n - 1; i++)
        {
            min_idx = i;
            for (j = i + 1; j < n; j++)
            {
                if (lista.GetItem(j)->data.getNationalNumber() < lista.GetItem(min_idx)->data.getNationalNumber())
                {
                    min_idx = j;
                }
            }
            tmp = lista.GetItem(min_idx)->data;
            lista.GetItem(min_idx)->data = lista.GetItem(i)->data;
            lista.GetItem(i)->data = tmp;
        }
    }

    void ShellSortGen(Lista<pokemon> lista)
    {
        int i, j, k, intervalo = lista.GetCount() / 2;
        pokemon tmp;
        while (intervalo > 0)
        {
            for (i = intervalo; i < lista.GetCount(); i++)
            {
                j = i - intervalo;
                while (j >= 0)
                {
                    k = j + intervalo;
                    if (lista.GetItem(j)->data.getGeneracion() < lista.GetItem(k)->data.getGeneracion())
                    {
                        j = -1;
                    }
                    else if (lista.GetItem(j)->data.getGeneracion() == lista.GetItem(k)->data.getGeneracion())
                    {
                        if (lista.GetItem(j)->data.GetNombre().compare(lista.GetItem(k)->data.GetNombre()) < 0)
                            j = -1;
                    }
                    else
                    {
                        tmp = lista.GetItem(k)->data;
                        lista.GetItem(k)->data = lista.GetItem(i)->data;
                        lista.GetItem(i)->data = tmp;
                        j -= intervalo;
                    }

                }
            }
            intervalo = intervalo / 2;
        }
    }

    void ShellSortNN(Lista<pokemon> lista)
    {
        int i, j, k, intervalo = lista.GetCount() / 2;
        pokemon tmp;
        while (intervalo > 0)
        {
            for (i = intervalo; i < lista.GetCount(); i++)
            {
                j = i - intervalo;
                while (j >= 0)
                {
                    k = j + intervalo;
                    if (lista.GetItem(j)->data.getNationalNumber() < lista.GetItem(k)->data.getNationalNumber())
                    {
                        j = -1;
                    }
                    else
                    {
                        tmp = lista.GetItem(k)->data;
                        lista.GetItem(k)->data = lista.GetItem(i)->data;
                        lista.GetItem(i)->data = tmp;
                        j -= intervalo;
                    }

                }
            }
            intervalo = intervalo / 2;
        }
    }

    void quicksortGen(Lista<pokemon> lista, int start, int end)
    {
        int pivot;
        if (start < end)
        {
            pivot = divideGen(lista, start, end);

            quicksortGen(lista, start, pivot - 1);
            quicksortGen(lista, pivot + 1, end);
        }
    }

    int divideGen(Lista<pokemon> lista, int start, int end)
    {
        int left, right, pivot;
        pokemon tmp;

        pivot = lista.GetItem(start)->data.getNationalNumber();
        left = start;
        right = end;

        while (left < right)
        {
            if (lista.GetItem(right)->data.getNationalNumber() == pivot)
            {
                string newPivot = lista.GetItem(start)->data.GetNombre();
                while (lista.GetItem(right)->data.GetNombre().compare(newPivot) > 0)
                {
                    right--;
                }

                while ((left < right) && lista.GetItem(right)->data.GetNombre().compare(newPivot) < 0)
                {
                    left++;
                }

                if (left < right)
                {
                    tmp = lista.GetItem(left)->data;
                    lista.GetItem(left)->data = lista.GetItem(right)->data;
                    lista.GetItem(right)->data = tmp;
                }
            }
            else
            {
                while (lista.GetItem(right)->data.getNationalNumber() > pivot)
                {
                    right--;
                }

                while ((left < right) && lista.GetItem(left)->data.getNationalNumber() <= pivot)
                {
                    left++;
                }

                if (left < right)
                {
                    tmp = lista.GetItem(left)->data;
                    lista.GetItem(left)->data = lista.GetItem(right)->data;
                    lista.GetItem(right)->data = tmp;
                }
            }
        }

        tmp = lista.GetItem(right)->data;
        lista.GetItem(right)->data = lista.GetItem(start)->data;
        lista.GetItem(start)->data = tmp;

        return right;
    }


    void quicksortNN(Lista<pokemon> lista, int start, int end)
    {
        int pivot;
        if (start < end)
        {
            pivot = divideNN(lista, start, end);

            quicksortNN(lista, start, pivot - 1);
            quicksortNN(lista, pivot + 1, end);
        }
    }

    int divideNN(Lista<pokemon> lista, int start, int end)
    {
        int left, right, pivot;
        pokemon tmp;

        pivot = lista.GetItem(start)->data.getNationalNumber();
        left = start;
        right = end;

        while (left < right)
        {
            while (lista.GetItem(right)->data.getNationalNumber() > pivot)
            {
                right--;
            }

            while ((left < right) && lista.GetItem(left)->data.getNationalNumber() <= pivot)
            {
                left++;
            }

            if (left < right)
            {
                tmp = lista.GetItem(left)->data;
                lista.GetItem(left)->data = lista.GetItem(right)->data;
                lista.GetItem(right)->data = tmp;
            }
        }

        tmp = lista.GetItem(right)->data;
        lista.GetItem(right)->data = lista.GetItem(start)->data;
        lista.GetItem(start)->data = tmp;

        return right;
    }

};

