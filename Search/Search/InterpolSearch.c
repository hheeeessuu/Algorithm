//
//  InterpolSearch.c
//  Search
//
//  Created by kim on 2017. 8. 29..
//  Copyright © 2017년 kim. All rights reserved.
//

#include <stdio.h>

int ISearch(int arr[], int first, int last, int target)
{
    int mid;
    
//    if(first > last)
// 탐색대상이 존재하지 않을 경우, 탐색대상의 값은 탐색범위의 값을 넘어선다.
    if(arr[first] > target || arr[last] < target)
        return -1;      // -1의 반환은 탐색의 실패를 의미
    
    // 이진 탐색과의 차이점을 반영한 문장
    mid = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;
    
    if(arr[mid] == target)
        return mid;     // 탐색된 타겟의 인덱스 값 반환
    else if(target < arr[mid])
        return ISearch(arr, first, mid - 1, target);
    else
        return ISearch(arr, mid + 1, last, target);
}

/*int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx;
    
    idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);
    if(idx == -1)
        printf("탐색 실패 \n");
    else
        printf("타겟 저장 인덱스 : %d \n", idx);

    return 0;
}*/
