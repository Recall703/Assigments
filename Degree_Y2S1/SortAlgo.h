#ifndef SORTALGO_H_
#define SORTALGO_H_
#include <iostream>
using namespace std;
template <typename DataType>

class SortAlgo {
	public:
	void swap(DataType &x, DataType &y);
	void partition(DataType array[],int first, int last, int &flagIndex);
	void merge(DataType array[],int first, int mid, int last);
	void BubbleSort(DataType array[], int size);
	void SelectionSort(DataType array[], int size);
	void InsertionSort(DataType array[],int size);
	void QuickSort(DataType array[], int firstIndex,int lastIndex);
	void MergeSort(DataType array[],int firstIndex, int lastIndex);
};

#endif /* SORTALGO_H_ */
