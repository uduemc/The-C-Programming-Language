#include <stdio.h>
#include <stdlib.h>

#define COLUME 4

void arrayPrint(int arr[COLUME][COLUME], int n)
{
    int tmp = n ;
    int i, j;

    while(tmp-- > 0){
        j = tmp, i = 0;
        while(j < n){
            printf("%d ", arr[i++][j++]);
        }
    }
    ++tmp;
    while(++tmp < n){
        i = tmp, j = 0;
        while(i < n){
            printf("%d ", arr[i++][j++]);
        }
    }
}

int main()
{
    int arr[COLUME][COLUME] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    arrayPrint(arr,COLUME);

    return 0;
}

/*
有一个二维数组(n*n)，写程序实现从右上角到左下角沿主对角线方向打印。

测试样例：
给定一个二位数组arr及题目中的参数n，请返回结果数组。
[[1，2，3，4]，[5，6，7，8]，[9，10，11，12]，[13，14，15，16]]，4

返回：
[4，3，8，2，7，12，1，6，11，16，5，10，15，9，14，13]

思路
首先以矩形的方式打印出这个二维数组，然后观察其中的规律。
开始我还以为是打印从右上角到左下角这条斜线上所有的数字。看了给予的返回结果那么多数字后我懵逼了。
原来是打印反斜线所穿越过的数字。

实现
代码：

*/
