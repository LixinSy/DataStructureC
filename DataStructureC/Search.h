#ifndef SEARCH_H
#define SEARCH_H

#define EQ(a, b) ((a) == (b))
#define LQ(a, b) ((a) <= (b))
#define LT(a, b) ((a) <  (b))


/************** º¯ÊýÉùÃ÷ *****************/
int SearchBin()
{
    int arr[10] = {0};
    int key = 21;

    int low=0, high = 9;
    int mid;
    while(low <= high){
        mid = (low+high) / 2;
        if (arr[mid] > key)
            high = mid - 1;
        else if (arr[mid] < key)
            low = mid + 1;
        if (arr[mid] == key)
            return mid;
    }
    return -1;
}



#endif
