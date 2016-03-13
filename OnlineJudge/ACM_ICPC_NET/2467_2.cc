#include <stdio.h>
 
int main()
{
 
 
     
    int N = 0; // 전체 용액의 수
    int Array[100010] = {0,};// 용액을 담을 배열
    int Sum  = 0; // 두 용액의 합
    int ABSSum = 0;// 두 용액의 절대값 저장
    int result[2] = {0,};// 두 용액의 결과값을 담을 배열
    int i, j;
 
    scanf("%d",&N);// 전체 용액의 수를 입력 받음
 
    for(i = 1 ; i <=N ; i++) // 용액의 특성값을들 입력 받음
    {
        scanf("%d", &Array[i]);
    }
     
    // 여기서부터 나만의 알고리즘이 들어감.
 
    int left  = 1;
    int right = N;
    int Min = 1234567890; // 최대값을 기본값으로 설정함.
 
    while(left < right)
    {
        Sum = Array[left] + Array[right];
        ABSSum = Sum;
        if(ABSSum < 0)
            ABSSum = Sum * -1;
 
        if(Min > ABSSum)
        {
            Min = ABSSum;
            result[0] = Array[left];
            result[1] = Array[right];
        }
        if(Sum > 0)
            right--;
        else
            left++;
 
 
    }
 
    printf("%d %d", result[0],result[1]);
 
    return 0;
 
}
