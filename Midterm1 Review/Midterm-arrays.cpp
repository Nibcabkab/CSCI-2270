int * arrayShift(int arr[],int length,int value)
{
    for(int i = 0 ; i < length; i++){
        if(arr[i] == value){
            for(int n = i; n < length-1; n++){
            arr[n] = arr[n+1];
            }
            break;
        }
    }
    return arr;
}

int maxRepeatingElement(int arr[],int length){
    int currentValue;
    int currentCount;
    int maxValue;
    int maxCount = 0;
    for(int i = 0; i < length; i++){
        currentValue = arr[i];
        currentCount = 0;
        for(int n = 0; n < length; n++){
            if(currentValue == arr[n])
                currentCount++;
        }
        if(currentCount > maxCount){
            maxValue = currentValue;
            maxCount = currentCount;
        }
    }
    return maxValue;
}
int secondLargest(int arr[],int size){
    int maxValue =-10000;
    int secondLargestValue=-999;
    for(int i = 0; i < size; i++){
        if(arr[i] > maxValue){
            secondLargestValue = maxValue;
            maxValue = arr[i];
        }
        else if(arr[i] > secondLargestValue && arr[i] != maxValue){
            secondLargestValue = arr[i];
        }
    }
    return secondLargestValue;
}
