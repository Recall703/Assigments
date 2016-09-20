
#include "SortAlgo.h"
#include <iostream>
using namespace std;

int main(){
	int anArray[]= {9,4,2,7,5};
	cout << "Bubble Sort(initial Array): ";
	for(int i=0;i<5;i++){
		cout << anArray[i] << " ";
	}
	cout << endl;
	
	SortAlgo <int> a;
	a.BubbleSort(anArray,5);
	
	for(int i=0;i<5;i++){
		cout << anArray[i] << " ";
	}
	
	int anotherArray[] = {5, 6 ,7 ,3 ,4, 2};
	cout << endl;
	cout << "Selection Sort(Initial Array): ";
	for(int i=0;i<5;i++){
		cout << anotherArray[i] << " ";
	}
	a.SelectionSort(anotherArray,5);
	cout << endl;
	cout << "end of the Array: ";
	for(int i=0;i<5;i++){
		cout << anotherArray[i] << " ";
	}
	

}
