/*
Casey O'Kane 
 Geeks For Geeks Merge Sort Implementation 
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
	int leftArrSize = (iMid - iMin) + 1;
	int rightArrSize = iMax - iMid;
	int currArrSize = iMax - iMin;

    //Create new arrays for the two seperate subarrays
	int currLeftArr[leftArrSize]; int currRightArr[rightArrSize];

	//Fill temp arrays with values 
    for (iLeftCtr = 0; iLeftCtr < leftArrSize; iLeftCtr++){
       currLeftArr[iLeftCtr] = arr[iMin + iLeftCtr];
    }

    for (iRightCtr = 0; iRightCtr < rightArrSize; iRightCtr++){
        currRightArr[iRightCtr] = arr[iMid + 1+ iRightCtr];
    }

	//Reinitialize counter values 
	iLeftCtr = 0; iRightCtr = 0; 

    //Iterate for values less than the combined length
    for(iArrCtr = iMin; iArrCtr <= currArrSize; iArrCtr++){

    	//Check if end of array has been reached
    	if((iLeftCtr < leftArrSize) && (iRightCtr < rightArrSize)){
    	//while((iLeftCtr < leftArrSize) && (iRightCtr < rightArrSize)){
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
    	//Check if right array has been exhausted
		else if(iLeftCtr < leftArrSize){
    		arr[iArrCtr] = currLeftArr[iLeftCtr];
    		iLeftCtr++;			
		}

		//Include case to check for empty left array
		else{
    		arr[iArrCtr] = currRightArr[iRightCtr];
    		iRightCtr++;  			
		}

	}
	
}

//The actual Merge Sort algorithm which operates recursively
void mergeSort(int arr[], int min, int max){

	//Make sure that array is at least one element in length 
	if(min < max){
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

	int arr[] = {12, 11, 13, 5, 6, 7};
	//NOTE: Explore alternatives for determining array length in C
	size_t arrLen = (int) ( sizeof(arr) / sizeof(arr[0]));

    printf("Initial Array: ");
	displayArr(arr, arrLen);

	mergeSort(arr, 0, arrLen-1);

	printf("Sorted Array: ");
	displayArr(arr, arrLen);

	return 0;
}
