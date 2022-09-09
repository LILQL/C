#include <stdio.h>
#include <stdlib.h>

int InsList(PSeqList L, int i, DataType e)
{

    //判断插入位置是否合法
    if (i < 1 || L->length > (LengthList(L) + 1))
    {
        printf("插入位置不合法!\n");
        return 0;
    }
    //判断顺序表是否已满
    else if (L->length >= ListSize)
    {
        printf("顺序表已满，不能插入！\n");
        return 0;
    }
    else
    {
        for (int k = i; k <= L->length; k--)
        {
            L->data[k + 1] = L->data[k];
        }
        L->data[i - 1] = e;
        L->length++; //数据表的长度加1
        return 1;
    }
    return 0;
}