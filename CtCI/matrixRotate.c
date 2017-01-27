/*
Casey O'Kane 
Matrix Rotation Question Implementation 
*/

#include <stdio.h>


//Helper function used to display the passed  
void display2DArr(int n, int arr[][n]){
	
	int i, j;
	for(i=0; i < n; i++){

        for(j = 0; j < n; j++){

		    printf("\t%d\t ", arr[i][j]);

        }
        
        printf("\n");

	}

	printf("\n");

}


//Actual implementation `
void rotateMatrix(int n, int Matrix[][n]){

    int layer = 0; int temp = 0; int i = 0;
    int numLayers = n/2; int numElements = n-1;

    for(layer = 0; layer <  numLayers; layer++){

        for(i = layer; i < numElements - layer ; i++){
            //Store TL in temp variable
            temp = Matrix[layer][i];
            //Move BL to TL
            Matrix[layer][i] = Matrix[numElements - i][layer];
            //Move BR to BL
            Matrix[numElements - i][layer] = Matrix[numElements -layer][ numElements - i];
            //Move TR to BR
            Matrix[numElements -layer][numElements - i] = Matrix[i][numElements-layer];
            //Move temp to TR
            Matrix[i][numElements-layer] = temp;
        }

    }

    printf("Sorted Array: \n");
    display2DArr(n, Matrix);

}


//Driver program for testing purposes
int main(){


    int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    printf("Initial Array: \n");
    display2DArr(4, arr);

    rotateMatrix(4, arr);


	return 0;
}
