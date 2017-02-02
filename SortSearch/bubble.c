/*
Casey O'Kane 
Bubble Sort Implementation 
*/

#include <stdio.h>


//Continue comparing the elements in the array until the end of the array is reached
	//After reaching the end, the last element will be confirmed in the right position
//After the array is iterated through, loop until each position is found

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


//NOTE: when determining the size of an array that is passed as a parameter. 
//	use an extra parameter instead of sizeof(arr)/sizeof(arr[0])
void bubbleSort(int arr[], size_t arrLen){

	//Initialize counters
	int i, j;

	//Number of iterations needed 
	for(i = 0; i < arrLen; i++){
		//Number of steps through the array needed
		for(j = 0; j < arrLen; j++){
			//Look at the first two elements and checks which one is greater
			if(arr[j] > arr[j+1]){

				//If not in correct order, values are swapped
				swap(&arr[j], &arr[j+1]);

//NOTE: Can be optimized slightly if no elements were swapped by the inner loop
//  in the case that the array was already sorted. Can be accomplished using a 
//  boolean flag.

			}			
		}
	}
    //Display results after current iteration with update last element
    printf("Sorted Array: ");
    displayArr(arr, arrLen);
}


//Driver program for testing purposes
int main(){

    int arr[] = {1,8,4,6,0,3,5,2,7,9};
    int i;
    size_t arrLen = (int) ( sizeof(arr) / sizeof(arr[0]));

    printf("Initial Array: ");
    displayArr(arr, arrLen);

    bubbleSort(arr, arrLen);

    return 0;
}
