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
void displayArr(int arr[], size_t arrLen){
	
	int i;
	for(i=0; i < arrLen; i++){
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

//Used by quick sort to determine the pivot value to divide up array
int qsPartition(int arr[], int leftVal, int rightVal){

    int i;
    //First select the initial pivot value and left indices
    int iPivot = arr[rightVal];
    int leftInd = (leftVal -1);

    //Iterate through the array and make sure that values less than pivot are 
    //on the left side 
    for(i = leftVal; i < rightVal; i++){
	
	    //While left value is less than pivot, move the left pointer over to the right
        if(arr[i] < iPivot){
            //Move the left indices to the right if current index is less than pivot
            leftInd++;
            //NOTE: By swapping the left indices and current iterative position, the 
            //values larger than the pivot are swapped with the adjacent values
            swap(&arr[leftInd], &arr[i]);
        }

    }

    //After making sure that the values less than the pivot are in correct locs
    //place the pivot to the right of this location
    swap(&arr[leftInd + 1], &arr[rightVal]);

    //return the current location of the pivot
    return (leftInd+1);

}

void quickSort(int arr[], int min, int max){

    //Make sure that the min arg is less than that of the max to see if sort is 
    //  completed
    if(max > min){

	    //Find the pivot value by partitioning the array with qsPartition
	    int iPivotInd = qsPartition(arr, min, max);

	    //recursively quicksort the left partition 
	    quickSort(arr, min, iPivotInd-1);

	    //recursively quicksort the right partition
	    quickSort(arr, iPivotInd+1, max);
    }

}


//Driver program for testing purposes
int main(){

    int arr[] = {5,1,4,2,8};
    size_t arrLen = (int) ( sizeof(arr) / sizeof(arr[0]));

    printf("Initial Array: ");
    displayArr(arr, arrLen);

    quickSort(arr, 0, arrLen-1);

    printf("Sorted Array: ");
    displayArr(arr, arrLen);
	
    return 0;
}
