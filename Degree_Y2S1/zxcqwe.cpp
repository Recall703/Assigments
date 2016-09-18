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
	//this is swap function for bubble, insertion and selection sort
	void swap(DataType &x, DataType &y){
		DataType temp = 0;
		temp = x;
		x = y;
		y = temp;
		cout << x << " swapped with " << y << endl;
	}
	//Partition only for quick sort, for Pivot
	void partition(DataType array[],int first, int last, int &flagIndex){
		DataType flag = array[first]; //first element as pivot
		int S1_end = first; //index of S1
		int FirstUnknown = first +1; //index of first unknown
		while(FirstUnknown <= last){ //loop if index of first unknown is still less than last index of array
			if(flag > array[FirstUnknown]){ // if flag bigger than the unknown
				swap(array[FirstUnknown],array[S1_end+1]); // swap the flag and the unknown, means now unknown in S1
				S1_end++;//increase the region of S1;
			}
			FirstUnknown++; //increment of first unknown

		}
		swap(array[first],array[S1_end]); //place the pivot in the correct place.
		flagIndex = S1_end; // get the flag index
	}
	//Merge for merge sort
	void merge(DataType array[],int first, int mid, int last){
		DataType newArray[SIZE]; //temp array
		//as the variable mean, first mean first element, mid is the mid point, last is the last index
		int leftFirst = first; 
		int leftLast = mid;
		int rightFirst = mid + 1;
		int rightLast = last;

		int indexForNew = first;

		for(indexForNew=first;(leftFirst <= leftLast && rightFirst <= rightLast); indexForNew++){
			if(array[leftFirst] < array[rightFirst]){ 
				newArray[indexForNew] = array[leftFirst]; // put the smaller value in the left first in the 
				//tempary array according to the index
				++leftFirst;
			}
			else{
				//same as above but right hand side
				newArray[indexForNew] = array[rightFirst];
				++rightFirst;
			}
		}

		while(leftFirst <= leftLast){ // put all left item into the temp array if nessary, in another words
		//this will happen if left array is bigger than right array
			newArray[indexForNew] = array[leftFirst]; 
			++leftFirst;
			++indexForNew;
		}

		while(rightFirst <= rightLast){
			//same as above but opposite site
			newArray[indexForNew] = array[rightFirst];
			rightFirst++;
			indexForNew++;
		}

		for(int i = 0 ; i < last +1 ; i++){
			//put the sorted array to the orignal array
			array[i] = newArray[i];
		}

	}


	public:
	void BubbleSort(DataType array[], int size){ // this is bubble sort 
		int notswapedIndex = size; //assign the counter
		while(notswapedIndex != 0){
			for(int i=0;i<notswapedIndex;i++){
				if(array[i]<array[i-1]) //if back < front, the swapping
					swap(array[i],array[i-1]);
				for(int i =0;i<size;i++){ //this is for checking usage 
					cout << array[i] << " ";

				}
				cout << endl;
			}
			notswapedIndex--; //decrement counter to avoid infinity loop

		}

	}



	void SelectionSort(DataType array[], int size){
		//declare variable, the variable are meant as their name
		int notswapedIndex = size;
		int biggestIndex = 0;
		while(notswapedIndex >=0)
		{
			DataType biggest = 0;
			//find and compare the biggest value in the array
			for(int i=0;i <notswapedIndex; i++){
				if(array[i] > biggest){
					biggest = array[i];
					biggestIndex = i;
				}
			}
			//swap the biggest value with the last index which are not sorted.
			swap(array[biggestIndex], array[notswapedIndex]);
			//decrement counter
			notswapedIndex--;
		}


	}

	void InsertionSort(DataType array[],int size){
		for(int sorted = 0;sorted < size + 1; sorted++){
			DataType nextItem = array[sorted]; //get the item, for comparison
			int loc = sorted; //get the location of the sorted index
			//this is where copy occur
			while((loc>0) && (array[loc-1] > nextItem)){
				array[loc] = array[loc-1]; // i
				loc--; //
			}
			// the pasting occur
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
