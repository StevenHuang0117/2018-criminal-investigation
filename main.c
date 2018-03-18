/**
*****************************************************************************
**
**  File        : main.c
**
**  Abstract    : main function.
**
**  Functions   : main
**
**  Distribution: 《2018刑侦科推理试题》解法
**
**
*****************************************************************************
*/

#include<stdio.h>
#include<string.h>
#include<math.h>

//ABCD答案对应的数值
#define A       (0)
#define B       (1)
#define C       (2)
#define D       (3)

int a[11] = {0};//10道题的答案, 为了直观，创建11个元素，元素0无用
void GetMinNumAnswer(int *Answer, int *AnswerNum);
void GetMaxNumAnswer(int *Answer, int *AnswerNum);
void PrintAnswer(void);

int main(void)
{
    int Cnt;//穷举的次数
    int MaxCnt = 1 << 20;//最大的次数
    int MinAnswer;
    int MinAnswerNum;
    int MaxAnswer;
    int MaxAnswerNum;

    for(Cnt = 0; Cnt < MaxCnt; Cnt++)
    {
        //提取10道题的答案
        a[1]  = Cnt & 0x03;
        a[2]  = (Cnt >>  2) & 0x03;
        a[3]  = (Cnt >>  4) & 0x03;
        a[4]  = (Cnt >>  6) & 0x03;
        a[5]  = (Cnt >>  8) & 0x03;
        a[6]  = (Cnt >> 10) & 0x03;
        a[7]  = (Cnt >> 12) & 0x03;
        a[8]  = (Cnt >> 14) & 0x03;
        a[9]  = (Cnt >> 16) & 0x03;
        a[10] = (Cnt >> 18) & 0x03;

        //第1题不判断

        //判断第2题
        if(((a[2] == A) && (a[5] == C)) ||
           ((a[2] == B) && (a[5] == D)) ||
           ((a[2] == C) && (a[5] == A)) ||
           ((a[2] == D) && (a[5] == B)))
        {
        }
        else
        {
            continue;
        }

        //判断第3题
        if(((a[3] == A) && (a[2] != a[3]) && (a[2] == a[4]) && (a[2] == a[6])) ||
           ((a[3] == B) && (a[2] != a[6]) && (a[2] == a[3]) && (a[2] == a[4])) ||
           ((a[3] == C) && (a[2] != a[3]) && (a[3] == a[4]) && (a[3] == a[6])) ||
           ((a[3] == D) && (a[2] != a[4]) && (a[2] == a[3]) && (a[2] == a[6])))
        {
        }
        else
        {
            continue;
        }

        //判断第4题
        if(((a[4] == A) && (a[1] == a[5])) ||
           ((a[4] == B) && (a[2] == a[7])) ||
           ((a[4] == C) && (a[1] == a[9])) ||
           ((a[4] == D) && (a[6] == a[10])))
        {
        }
        else
        {
            continue;
        }

        //判断第5题
        if(((a[5] == A) && (a[5] == a[8])) ||
           ((a[5] == B) && (a[5] == a[4])) ||
           ((a[5] == C) && (a[5] == a[9])) ||
           ((a[5] == D) && (a[5] == a[7])))
        {
        }
        else
        {
            continue;
        }

        //判断第6题
        if(((a[6] == A) && (a[8] == a[2]) && (a[8] == a[4]))  ||
           ((a[6] == B) && (a[8] == a[1]) && (a[8] == a[6]))  ||
           ((a[6] == C) && (a[8] == a[3]) && (a[8] == a[10])) ||
           ((a[6] == D) && (a[8] == a[5]) && (a[8] == a[9])))
        {
        }
        else
        {
            continue;
        }

        //判断第7题
        GetMinNumAnswer(&MinAnswer, &MinAnswerNum);//获取次数最少的答案及次数
        if(((a[7] == A) && (MinAnswer == C))  ||
           ((a[7] == B) && (MinAnswer == B))  ||
           ((a[7] == C) && (MinAnswer == A))  ||
           ((a[7] == D) && (MinAnswer == D)))
        {
        }
        else
        {
            continue;
        }

        //判断第8题
        if(((a[8] == A) && (abs(a[7]  - a[1]) != 1))  ||
           ((a[8] == B) && (abs(a[5]  - a[1]) != 1))  ||
           ((a[8] == C) && (abs(a[2]  - a[1]) != 1))  ||
           ((a[8] == D) && (abs(a[10] - a[1]) != 1)))
        {
        }
        else
        {
            continue;
        }

        //判断第9题
        if(a[1] == a[6])
        {
            if(((a[9] == A) && (a[5] != a[6] ))  ||
               ((a[9] == B) && (a[5] != a[10]))  ||
               ((a[9] == C) && (a[5] != a[2] ))  ||
               ((a[9] == D) && (a[5] != a[9] )))
            {
            }
            else
            {
                continue;
            }
        }
        else
        {
            if(((a[9] == A) && (a[5] == a[6] ))  ||
               ((a[9] == B) && (a[5] == a[10]))  ||
               ((a[9] == C) && (a[5] == a[2] ))  ||
               ((a[9] == D) && (a[5] == a[9] )))
            {
            }
            else
            {
                continue;
            }
        }

        //判断第10题
        GetMaxNumAnswer(&MaxAnswer, &MaxAnswerNum);//获取次数最多的答案及次数
        if(((a[10] == A) && ((MaxAnswerNum - MinAnswerNum) == 3))  ||
           ((a[10] == B) && ((MaxAnswerNum - MinAnswerNum) == 2))  ||
           ((a[10] == C) && ((MaxAnswerNum - MinAnswerNum) == 4))  ||
           ((a[10] == D) && ((MaxAnswerNum - MinAnswerNum) == 1)))
        {
            break;//10道题答案全部符合条件，退出穷举
        }
        else
        {
            continue;
        }

    }

    PrintAnswer();//打印答案
    while(1);
    return 0;
}


//获取次数最少的答案以及它的次数
void GetMinNumAnswer(int *Answer, int *AnswerNum)
{
    int Num[4] = {0, 0, 0, 0};
    int Min;
    int i;

    for(i = 1; i < 11; i++)
    {
        switch(a[i])
        {
            case A: Num[A]++; break;
            case B: Num[B]++; break;
            case C: Num[C]++; break;
            case D: Num[D]++; break;
            default:break;
        }
    }

    Min = (Num[A]   <= Num[B]) ?   A : B;
    Min = (Num[Min] <= Num[C]) ? Min : C;
    Min = (Num[Min] <= Num[D]) ? Min : D;

    *Answer     = Min;
    *AnswerNum  = Num[Min];
}


//获取次数最多的答案以及它的次数
void GetMaxNumAnswer(int *Answer, int *AnswerNum)
{
    int Num[4] = {0, 0, 0, 0};
    int Max;
    int i;

    for(i = 1; i < 11; i++)
    {
        switch(a[i])
        {
            case A: Num[A]++; break;
            case B: Num[B]++; break;
            case C: Num[C]++; break;
            case D: Num[D]++; break;
            default:break;
        }
    }

    Max = (Num[A]   >= Num[B]) ?   A : B;
    Max = (Num[Max] >= Num[C]) ? Max : C;
    Max = (Num[Max] >= Num[D]) ? Max : D;

    *Answer     = Max;
    *AnswerNum  = Num[Max];
}


//打印答案
void PrintAnswer(void)
{
    int i;

    printf("Answer is\n");
    for(i = 1; i < 11; i++)
    {
        printf("a%d = %c \n", i, ('A' + a[i]));
    }
}
