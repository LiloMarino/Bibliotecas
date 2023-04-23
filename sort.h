#ifndef SORT_H
#define SORT_H

#include <stddef.h>

typedef void *Sort;

void SelectionSortInt(int V[], int n);

void BubbleSortInt(int V[], int n);

void InsertionSortInt(int V[], int n);

void ShellSortInt(int V[], int n);

void QuickSortInt(int V[], int n);

void HeapSortInt(int V[], int n);

void MergeSortInt(int V[], int n);

void SelectionSortChar(char V[], int n);

void BubbleSortChar(char V[], int n);

void InsertionSortChar(char V[], int n);

void ShellSortChar(char V[], int n);

void QuickSortChar(char V[], int n);

void HeapSortChar(char V[], int n);

void MergeSortChar(char V[], int n);

void Swap(Sort A, Sort B, size_t size);

#endif