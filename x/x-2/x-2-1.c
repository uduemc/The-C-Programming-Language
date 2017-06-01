#include <stdio.h>
#include <stdlib.h>

#define NUM 5

float getMin(float arr[], int len)
{
    float total = 0.0f;
    int i;
    for(i=0;i<len;i++)
        total += arr[i];
    return total / (len/2 + 1);
}

float getResult(float arr[], int len)
{
    float min = getMin(arr, len);
    int i, j, count;

    for(i=0;i<len;i++){
        if(arr[i] > min)
            continue;
        count = 0;
        for(j=0;j<len;j++){
            if(arr[i] == arr[j])
                count++;
        }
        if(count > len/2)
            return arr[i];
    }
    return 0;
}

int main()
{
    // 准备两组红包
    float f1[NUM] = {1.0f, 2.0f, 3.0f, 2.0f, 2.0f};
    float f2[NUM] = {0.7f, 3.1f, 3.1f, 2.1f, 1.0f};

    printf("f1: %.2f\n",getResult(f1, NUM));
    printf("f2: %.2f",getResult(f2, NUM));

    return 0;
}

/*
春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额出现的次数超过了红包总数的一半。请帮小明找到该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。

给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。

若没有金额超过总数的一半，返回0。


测试样例：
[1，2，3，2，2]，5

返回：
2

思路
首先这个情况非常的多，仅仅实现了测试样例也未必是正确的（这是百度出来的结果。各式各样的代码，有一些是有问题的）
注意一句话"某个红包金额出现的次数超过了红包总数的一半"
很明显，出现的次数跟这个金额是有一定关系的。
比如总金额是10， 发 5个红包。那出现5个相同金额的红包，这个金额就不可能大于2。
这里就需要一个数学公式来计算。
假设总额为 total
红包数量为 x
超过红包次数的一半为 n = x/2 + 1; (x 为int型)
得到极值 y = total / n;
也就是说，红包里面的金额小于 y， 并且出现的次数要大于 n
这样就缩小了查询的范围

实现
代码：

*/
