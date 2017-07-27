#include <iostream>
using namespace std;
#define left(x) 2*x+1
#define right(x) 2*(x+1) 

/******************调整堆为大顶堆***********************/
template <typename T>
void maxHeapFix(T heapArray[], int parentIndex, int lowIndex, int highIndex)
{
	int leftIndex = left(parentIndex);
	int rightIndex = right(parentIndex);
	int largestIndex ;
	T tempData;
	
	if(leftIndex <= highIndex && heapArray[leftIndex] > heapArray[parentIndex])
	{
		largestIndex = leftIndex;
	}
	else
	{
		largestIndex = parentIndex;
	}

	if(rightIndex <= highIndex && heapArray[rightIndex] > heapArray[largestIndex])
	{
		largestIndex = rightIndex;
	}
	
	if(largestIndex != parentIndex)
	{
		tempData = heapArray[parentIndex];
		heapArray[parentIndex] = heapArray[largestIndex];
		heapArray[largestIndex] = tempData;
		maxHeapFix(heapArray,largestIndex,lowIndex,highIndex); 
	} 
} 

/******************建立大顶堆***********************/
template<typename T> 
void buildMaxHeap(T heapArray[], int length)
{
	for(int i = length / 2 - 1; i >= 0; i--)
	{
		maxHeapFix(heapArray, i, 0, length - 1);
	}
}

/******************堆排序***************************/
template<typename T> 
void heapSort(T heapArray[], int length)
{
	T tempData;
	buildMaxHeap(heapArray, length);
	for(int i = length - 1; i >= 1; i--)
	{
		tempData = heapArray[i];
		heapArray[i] = heapArray[0];
		heapArray[0] = tempData;
		maxHeapFix(heapArray, 0, 0, i - 1);
	}
}

int main()
{
	int heapArray[] = {3, 5, 2, 8, 9, 0, 10};
	heapSort(heapArray, sizeof(heapArray) / sizeof(int));
	for(int i = 0; i <  sizeof(heapArray) / sizeof(int); i ++)
	{
		cout<< heapArray[i]<<endl;
	}
	return 0;
}
