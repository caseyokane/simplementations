/*
Casey O'Kane 
 Merge Sort Implementation 
*/

#include <stdio.h>


void displayArr(int arr[], size_t arrLen){
	
	int i;
	for(i=0; i < arrLen; i++){
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

//Function used to merge the elements that are split intially
void merge(int arr[], int iMin, int iMid, int iMax){

	//Use seperate iterators to keep track of left and right
	int iLeftCtr = 0; int iRightCtr = 0; int iArrCtr = 0;

	//Determine the total current array size
	int currArrSize = iMax - iMin;
	int leftArrSize = (iMid - iMin) + 1;
	int rightArrSize = iMax - iMid;

    //Create new arrays for the two seperate subarrays
	int currLeftArr[leftArrSize]; int currRightArr[rightArrSize];

	//Fill temp arrays with values 
	while(iArrCtr < currArrSize){
		
		//Append left elements up until the midpoint 
		if(iArrCtr <= iMid){
			currLeftArr[iLeftCtr] = arr[iArrCtr];
			iLeftCtr++;
		}
		//Append right elements
		else{
			currRightArr[iRightCtr] = arr[iArrCtr];
			iRightCtr++;
		}

		//Append array counter
		iArrCtr++;

	}

	//Reinitialize counter values 
	int iLeftCtr = 0; int iRightCtr = 0;

    //Iterate for values less than the combined length
    for(iArrCtr = 0; iArrCtr <= currArrSize; iArrCtr++){

    	//Check if end of array has been reached
    	if((iLeftCtr) < leftArrSize && (iRightCtr < rightArrSize)){
	    	//Compare elements of each list (use seperate iterators)
	    	if(currLeftArr[iLeftCtr] <= currRightArr[iRightCtr]){
	    		arr[iArrCtr] = currLeftArr[iLeftCtr];
	    		iLeftCtr++;
	    	}

	    	else{
	    		arr[iArrCtr] = currRightArr[iRightCtr];
	    		iRightCtr++;    		
	    	}
    	}

		//If counters at the end of respective lists, select smallest element
    	//Check if left array has been exhausted
		else if(iLeftCtr >= leftArrSize){
    		arr[iArrCtr] = currRightArr[iRightCtr];
    		iRightCtr++;  			
		}

		//Include case to check for empty right array
		else{
    		arr[iArrCtr] = currLeftArr[iLeftCtr];
    		iLeftCtr++;			
		}

	}

}

//The actual Merge Sort algorithm which operates recursively
void mergeSort(int arr[], int min, int max){

	//Make sure that array is at least one element in length 
	if(min <= max){
	    //Divide array into two halves by finding the midpoint
	    int iMid = (min+max)/2;
	    
	    //Merge sort the left and right halves seperately
	    mergeSort(arr, min, iMid);
	    mergeSort(arr, iMid+1, max);

	    //Merge the two halves together 
	    merge(arr, min, iMid, max);
	}

}


//Driver program for testing purposes
int main(){

	int arr[] = {1,8,4,6,0,3,5,2,7,9};
	//NOTE: Explore alternatives for determining array length in C
	size_t arrLen = (int) ( sizeof(arr) / sizeof(arr[0]));

    printf("Initial Array: ");
	displayArr(arr, arrLen);

	mergeSort(arr, 0, arrLen-1);

	printf("Sorted Array: ");
	displayArr(arr, arrLen);

	return 0;
}
