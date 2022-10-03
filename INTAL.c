#include <stdio.h>
#include <stdlib.h>

/*char* check(char* c, int length, int )// this function is used to check and remove any preceding zeros
{
    int i=0, j=0, k=0;
    while(i<length)
    {
        if(c[i]!='0'||k!=0)
        {
            k=1;
            c[j]=c[i];
            c[i]='0';
            j++;
        }
        i++;
    }
    printf("%d",j);
    length=j;
    printr(c,j);
    return c;
}*/
char *initialise() // for initialising the array
{
    char *c = (char *)malloc(1001 * sizeof(char));
    int i;
    for (i = 0; i < 1000; i++)
        c[i] = '0';
    c[i] = '\0';
    return c;
}
int comparator(char *intal1, char *intal2, int length1, int length2)
{
    if (length1 > length2)
        return 1;
    else if (length1 < length2)
        return -1;
    else
    {
        int j = 0;
        while (j < length1)
        {
            if (intal1[j] > intal2[j])
                return 1;
            else if (intal1[j] < intal2[j])
                return -1;
            j++;
        }
        return 0;
    }
}
void adder(char *intal1, char *intal2, int length1, int length2)
{
    if (length1 >= length2)
    {
        int j = length1 - 1;
        int k = length2 - 1;
        int carry = 0, sum = 0;
        while (k >= 0)
        {
            sum = intal1[j] + intal2[k] - 96 + carry;
            carry = sum / 10;
            intal1[j] = (48 + (sum % 10));
            j--;
            k--;
        }
        while (j >= 0)
        {
            sum = intal1[j] - 48 + carry;
            carry = sum / 10;
            intal1[j] = (48 + (sum % 10));
            j--;
        }
        if (carry != 0)
            printf("%d", carry);
        printr(intal1, length1);
    }
    else
    {
        int j = length1 - 1;
        int k = length2 - 1;
        int carry = 0, sum = 0;
        while (j >= 0)
        {
            sum = intal1[j] + intal2[k] - 96 + carry;
            carry = sum / 10;
            intal2[k] = (48 + (sum % 10));
            j--;
            k--;
        }
        while (k >= 0)
        {
            sum = intal2[k] - 48 + carry;
            carry = sum / 10;
            intal2[k] = (48 + (sum % 10));
            j--;
        }
        if (carry != 0)
            printf("%d", carry);
        printr(intal2, length2);
    }
}
void subtractor(char *intal1, char *intal2, int length1, int length2)
{
    if (length1 > length2)
    {
        int j = length1 - 1;
        int k = length2 - 1;
        int borrow = 0, diff = 0;
        while (k >= 0)
        {
            if (intal2[k] > intal1[j])
            {
                if (intal1[j] == '0')
                {
                    if (borrow == 0)
                        diff = 10 - intal2[k] + 48;
                    else
                        diff = 9 - intal2[k] + 48;
                    borrow = 1;
                }
                else
                {
                    diff = 10 + intal1[j] - borrow - intal2[k];
                    if (borrow == 0)
                        borrow = 1;
                }
            }
            else
            {
                diff = intal1[j] - borrow - intal2[k];
                if (borrow == 1)
                    borrow == 0;
            }
            intal1[j] = (48 + diff);
            j--;
            k--;
        }
        while (j >= 0)
        {
            if (intal1[j] == '0')
            {
                if (borrow == 0)
                    intal1[j] = '0';
                else
                    intal1[j] = '9';
            }
            else
            {
                if (borrow == 1)
                {
                    diff = intal1[j] - 1;
                    intal1[j] = diff;
                    borrow = 0;
                }
            }
            j--;
        }
        printr(intal1, length1);
    }
    else if (length1 == length2)
    {
        int comp = comparator(intal1, intal2, length1, length2);
        if (comp == 1)
        {
            int j = length1 - 1;
            int k = length2 - 1;
            int borrow = 0, diff = 0;
            while (k >= 0)
            {
                if (intal2[k] > intal1[j])
                {
                    if (intal1[j] == '0')
                    {
                        if (borrow == 0)
                            diff = 10 - intal2[k] + 48;
                        else
                            diff = 9 - intal2[k] + 48;
                        borrow = 1;
                    }
                    else
                    {
                        diff = 10 + intal1[j] - borrow - intal2[k];
                        if (borrow == 0)
                            borrow = 1;
                    }
                }
                else
                {
                    diff = intal1[j] - borrow - intal2[k];
                    if (borrow == 1)
                        borrow == 0;
                }
                intal1[j] = (48 + diff);
                j--;
                k--;
            }
            while (j >= 0)
            {
                if (intal1[j] == '0')
                {
                    if (borrow == 0)
                        intal1[j] = '0';
                    else
                        intal1[j] = '9';
                }
                else
                {
                    if (borrow == 1)
                    {
                        diff = intal1[j] - 1;
                        intal1[j] = diff;
                        borrow = 0;
                    }
                }
                j--;
            }
            printr(intal1, length1);
        }
        else if (comp == 0)
        {
            printf("0\n");
        }
        else
        {
            int j = length1 - 1;
            int k = length2 - 1;
            int borrow = 0, diff = 0;
            while (j >= 0)
            {
                if (intal1[j] > intal2[k])
                {
                    if (intal2[k] == '0')
                    {
                        if (borrow == 0)
                            diff = 10 - intal1[j] + 48;
                        else
                            diff = 9 - intal1[j] + 48;
                        borrow = 1;
                    }
                    else
                    {
                        diff = 10 + intal2[k] - borrow - intal1[j];
                        if (borrow == 0)
                            borrow = 1;
                    }
                }
                else
                {
                    diff = intal2[k] - borrow - intal1[j];
                    if (borrow == 1)
                        borrow == 0;
                }
                intal2[k] = (48 + diff);
                j--;
                k--;
            }
            while (k >= 0)
            {
                if (intal2[k] == '0')
                {
                    if (borrow == 0)
                        intal2[k] = '0';
                    else
                        intal2[k] = '9';
                }
                else
                {
                    if (borrow == 1)
                    {
                        diff = intal2[k] - 1;
                        intal2[k] = diff;
                        borrow = 0;
                    }
                }
                k--;
            }
            printf("-");
            printr(intal2, length1);
        }
    }
    else
    {
        int j = length1 - 1;
        int k = length2 - 1;
        int borrow = 0, diff = 0;
        while (j >= 0)
        {
            if (intal1[j] > intal2[k])
            {
                if (intal2[k] == '0')
                {
                    if (borrow == 0)
                        diff = 10 - intal1[j] + 48;
                    else
                        diff = 9 - intal1[j] + 48;
                    borrow = 1;
                }
                else
                {
                    diff = 10 + intal2[k] - borrow - intal1[j];
                    if (borrow == 0)
                        borrow = 1;
                }
            }
            else
            {
                diff = intal2[k] - borrow - intal1[j];
                if (borrow == 1)
                    borrow == 0;
            }
            intal2[k] = (48 + diff);
            j--;
            k--;
        }
        while (k >= 0)
        {
            if (intal2[k] == '0')
            {
                if (borrow == 0)
                    intal2[k] = '0';
                else
                    intal2[k] = '9';
            }
            else
            {
                if (borrow == 1)
                {
                    diff = intal2[k] - 1;
                    intal2[k] = diff;
                    borrow = 0;
                }
            }
            k--;
        }
        printf("-");
        printr(intal2, length2);
    }
}
void multiplier(char *intal1, char *intal2, int length1, int length2)
{
    char *result = initialise();
    if ((intal1[0] == '0' && length1 == 1) || (intal2[0] == '0' && length2 == 1))
    {
        result[0] = '0';
        printr(result, 1);
    }
    else if (intal1[1] == '1' && length1 == 1)
        printr(intal2, length2);
    else if (intal2[1] == '1' && length2 == 1)
        printr(intal1, length1);
    else
    {
        int i, j, ptr1=1;
        for (i = length2 - 1; i >= 0; i--)
        {
            int sum = 0, carry = 0;
            int ptr2 = length1 + length2 - ptr1;
            for (j = length1 - 1; j >= 0; j--)
            {
                sum = (intal1[j] - '0') * (intal2[i] - '0') + (result[ptr2] - '0') + carry;
                result[ptr2] = 48 + (sum % 10);
                carry = sum / 10;
                --ptr2;
            }
            while(carry!=0)
            {
                int sum1=(result[ptr2]+carry-48);
                result[ptr2]=48+(sum1%10);
                carry=sum1/10;
                --ptr2;
            }
            ++ptr1;
        }
        printr(result, length1 + length2);
    }
}
void printr(char *c, int length)
{
    for (int i = 0; i < length; i++)
        printf("%c", c[i]);
}
int main()
{
    int length1 = 0, length2 = 0;
    char *intal1 = initialise();
    char *intal2 = initialise();
    char c = '\0';
    while (c != 10)
    {
        scanf("%c", &c);
        if (c == 10)
            break;
        intal1[length1++] = c;
    }
    scanf("\n");
    c = '\0';
    while (c != 10)
    {
        scanf("%c", &c);
        if (c == 10)
            break;
        intal2[length2++] = c;
    }
    // adder(intal1, intal2, length1, length2);
    // int t = comparator(intal1, intal2, length1, length2);
    // printf("%d",t);
    // char* intal3=check(intal1, length1);
    // printr(intal3, length1);
    // subtractor(intal1, intal2, length1, length2);
    // multiplier(intal1, intal2, length1, length2);
    return 0;
}