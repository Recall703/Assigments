
#include "SortAlgo.h"
#include <iostream>
using namespace std;

int main(){
	int anArray[]= {9,4,2,7,4};
	SortAlgo <int> a;
	a.BubbleSort(anArray,5);
	for(int i=0;i<5;i++){
		cout << anArray[i] << " ";
	}


}
