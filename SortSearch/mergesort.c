/*
Casey O'Kane 
 Merge Sort Implementation 
*/

#include <stdio.h>

//Helper function used to swap two elements in an array
void swap(int *e1, int *e2){
	//Set the temporary value to that of the dereferenced value of e1
	int temp  = *e1;
	*e1 = *e2;
	*e2 = temp;
}

void displayArr(int arr[], size_t arrLen){
	
	int i;
	for(i=0; i < arrLen; i++){
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

//Function used to merge the elements that are split intially
void merge(int arr[], int iMin, int iMid, int iMax){

    //Merge the sub arrays

    //First initialize some temporary arrays to store left and right indices

    //Put relative data into these arrays

    //Merge arrays and update arr[]

    //Accounting for remaining elements in the temp arrays 

}

//The actual Merge Sort algorithm which operates recursively
void mergeSort(int arr[], int min, int max){

    //Divide array into two halves by finding the midpoint
    int iMid = (min+max)/2;
    

    //Merge sort the left and right halves seperately
    mergeSort(arr, min, iMid);
    mergeSort(arr, iMid+1, max);

    //Merge the two halves together 
    merge(arr, min, iMid, max);

}


//Driver program for testing purposes
int main(){

	int arr[] = {1,8,4,6,0,3,5,2,7,9};
    int i;
	size_t arrLen = (int) ( sizeof(arr) / sizeof(arr[0]));

    printf("Initial Array: ");
	displayArr(arr, arrLen);

	mergeSort(arr, 0, arrLen-1);

	return 0;
}
