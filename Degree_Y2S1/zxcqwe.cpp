/*
 * SortAlgo.h
 *
 *  Created on: Sep 19, 2016
 *      Author: recall
 */

#ifndef SORTALGO_H_
#define SORTALGO_H_
#include <iostream>
using namespace std;
int SIZE = 10;
template <typename DataType>

class SortAlgo {

	void swap(DataType &x, DataType &y){
		DataType temp = 0;
		temp = x;
		x = y;
		y = temp;
		cout << x << " swapped with " << y << endl;
	}

	void partition(DataType array[],int first, int last, int &flagIndex){
		DataType flag = array[first];
		int S1_end = first;
		int FirstUnknown = first +1;
		while(FirstUnknown <= last){
			if(flag > array[FirstUnknown]){
				swap(array[FirstUnknown],array[S1_end+1]);
				S1_end++;
			}
			FirstUnknown++;

		}
		swap(array[first],array[S1_end]);
		flagIndex = S1_end;
	}

	void merge(DataType array[],int first, int mid, int last){
		DataType newArray[SIZE];
		int leftFirst = first;
		int leftLast = mid;
		int rightFirst = mid + 1;
		int rightLast = last;

		int indexForNew = first;

		for(indexForNew=first;(leftFirst <= leftLast && rightFirst <= rightLast); indexForNew++){
			if(array[leftFirst] < array[rightFirst]){
				newArray[indexForNew] = array[leftFirst];
				++leftFirst;
			}
			else{
				newArray[indexForNew] = array[rightFirst];
				++rightFirst;
			}
		}

		while(leftFirst <= leftLast){
			newArray[indexForNew] = array[leftFirst];
			++leftFirst;
			++indexForNew;
		}

		while(rightFirst <= rightLast){
			newArray[indexForNew] = array[rightFirst];
			rightFirst++;
			indexForNew++;
		}

		for(int i = 0 ; i < last +1 ; i++){
			array[i] = newArray[i];
		}

	}


	public:
	void BubbleSort(DataType array[], int size){
		int notswapedIndex =size;
		while(notswapedIndex != 0){
			for(int i=0;i<notswapedIndex;i++){
				if(array[i]<array[i-1])
					swap(array[i],array[i-1]);
				for(int i =0;i<size;i++){
					cout << array[i] << " ";

				}
				cout << endl;
			}
			notswapedIndex--;

		}

	}



	void SelectionSort(DataType array[], int size){
		int notswapedIndex = size;
		int biggestIndex = 0;
		int trya = 0;
		while(notswapedIndex >=0)
		{
			DataType biggest = 0;
			for(int i=0;i <notswapedIndex; i++){
				if(array[i] > biggest){
					biggest = array[i];
					biggestIndex = i;
				}
			}
			swap(array[biggestIndex], array[notswapedIndex]);
			notswapedIndex--;
			trya++ ;
		}


	}

	void InsertionSort(DataType array[],int size){
		for(int sorted = 0;sorted < size + 1; sorted++){
			DataType nextItem = array[sorted];
			int loc = sorted;
			while((loc>0) && (array[loc-1] > nextItem)){
				array[loc] = array[loc-1];
				loc--;
			}
			array[loc] = nextItem;
		}

	}


	void QuickSort(DataType array[], int firstIndex,int lastIndex){
		int flagIndex;
		if(firstIndex < lastIndex){
			//partition the array
			partition(array,firstIndex,lastIndex,flagIndex);
			//sort the front
			QuickSort(array,firstIndex,flagIndex-1);
			//sort the back
			QuickSort(array,flagIndex+1,lastIndex);

		}

	}

	void displayArray( const DataType theArray[], int first, int last ){
	   for ( int i = first; i <= last; ++i )
	      cout << theArray[ i ] << " ";
	}

	void MergeSort(DataType array[],int firstIndex, int lastIndex){

		if(firstIndex < lastIndex){
			int sum = (firstIndex + lastIndex);
			int mid = sum/2;
			//sort the left half
			MergeSort(array,firstIndex, mid);
			//sort the another half
			MergeSort(array, mid + 1,lastIndex);
			//merge the both part;
			merge(array,firstIndex, mid, lastIndex);
		}
	}



};

#endif /* SORTALGO_H_ */
