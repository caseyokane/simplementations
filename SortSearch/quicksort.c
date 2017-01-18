/*
Casey O'Kane 
Quick Sort Implementation 
*/

#include <stdio.h>

	
//Helper function used to swap two elements in an array
void swap(int *e1, int *e2){
	//Set the temporary value to that of the dereferenced value of e1
	int temp  = *e1;
	*e1 = *e2;
	*e2 = temp;
}

//Helper function used to display a given array (for testing results )
void displayArr(int arr[], size_t arrLen, int currIter){
	
	int i;
	printf("Iteration: %d; Array: ", currIter);
	for(i=0; i < arrLen, i++){
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

//Used by quick sort to determine the pivot value to divide up array
int qsPartition(int arr[], int iLeft, int iRight){

	int i;
	//First select the initial pivot value
	int iPivot = arr[iRight];

	//Iterate through the array until the value before the initial pivot is selected 
	for(i = 0; i < iRight; i++){
		
		//While left value is less than pivot, move the left pointer over to the right
		//While right value is greater than pivot move the right pointer to the left
		//If both don't match then swap left and right
		//If the left is greater than the right, swap the right position with the pivot 	
			//This will generate the partitions for the quickSort		
	}

}

void quickSort(int arr[], int min, int max){

	//Find the pivot value by partitioning the array with qsPartition
	int iPivot = qsPartition(arr, min, max);

	//recursively quicksort the left partition 
	quicksort(arr, min, iPivot-1);

	//recursively quicksort the right partition
	quicksort(arr, iPivot+1, max);

}


//Driver program for testing purposes
int main(){

	int arr[] = {5,1,4,2,8};
	size_t arrLen = (int) ( sizeof(arr) / sizeof(arr[0]));

	quickSort(arr, 0, arrLen-1);

	return 0;
}