#include <stdio.h>

int stringLength(char str[])
{
    for(int i=0;i<100001;i++)
    	if(str[i]=='\0')
    		return i;
}
int len1,len2,maxLen;
void add(char num1[], char num2[], char result[]) {
    int carry = 0;
    for (int i = 0; i < maxLen; i++)
    {
        int digit1 = i < len1 ? (num1[len1 - 1 - i] - '0') : 0;
        int digit2 = i < len2 ? (num2[len2 - 1 - i] - '0') : 0;        

        int sum = digit1 + digit2 + carry;
        result[maxLen - i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry > 0)
        result[0] = carry + '0';
    else
        result++;
}
void subtract(char num1[], char num2[], char result[]) {
    int borrow = 0;
    for (int i = 0; i < len1; i++)
    {
        int digit1 = num1[len1 - 1 - i] - '0';
        int digit2 = i < len2 ? (num2[len2 - 1 - i] - '0') : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        result[len1 - i - 1] = diff + '0';
    }
    int k=0;
    // Remove leading zeros
    for(int i=0;i<100001;i++)
    {
       if(result[i]=='0' && result[i+1]!='\0')
         k++;
    }
    // Shift the result to the beginning
    for (int i = 0;i<100001; i++)
    {
    	if(result[i+k]!='\0')
        	result[i] = result[i+k];
    }
}
void firsthalf(char num[],char target[],int len,int half)
{
    int j = len - 2 * half;
    for (int i = 0; i < half; i++, j++) {
        target[i] = (j >= 0) ? num[j] : '0';
    }
    target[half] = '\0';
}
void secondhalf(char num[],char target[],int len,int half)
{
    int j = len - half;
    for (int i = 0; i < half; i++, j++) {
        target[i] = num[j];
    }
    target[half] = '\0';
}
void karatsuba(char num1[], char num2[], char result[]) {

    // Base case: If the numbers are small, use regular multiplication
    if (len1 <= 1 || len2 <= 1) {
        int product = (num1[0] - '0') * (num2[0] - '0');
        sprintf(result, "%d", product);
        return;
    }

    // Split the numbers into two halves
    int half = (len1 > len2 ? len1 : len2) / 2;

    // Extract high and low parts without using strncpy
    char aFirstHalf[half + 1], aSecondHalf[half + 1], bFirstHalf[half + 1], bSecondHalf[half + 1];
    
    firsthalf(num1,aFirstHalf,len1,half);
    firsthalf(num2,bFirstHalf,len2,half);
    secondhalf(num1,aSecondHalf,len1,half);
    secondhalf(num2,bSecondHalf,len2,half);
    
    char z0[2 * half + 1], z1[2 * half + 1], z2[2 * half + 1];
    karatsuba(aSecondHalf, bSecondHalf, z0);
    karatsuba(aSecondHalf, bFirstHalf, z1);
    karatsuba(aFirstHalf, bSecondHalf, z2);

    // Calculate intermediate results
    char temp[2 * half + 1];
    add(z0, z1, temp);
    add(temp, z2, result);

    // Combine the results
    for (int i = 0; i < half; i++) {
        result[i] = z0[i];
    }
    for (int i = half; i < 2 * half; i++) {
        result[i] = z2[i - half];
    }
}

int main() {
    char num1[100001], num2[100001], result[200002];

    scanf("%s", num1);
    scanf("%s", num2);
    len1=stringLength(num1);
    len2=stringLength(num2);
    maxLen=len1 > len2 ? len1 : len2;

    karatsuba(num1, num2, result);

    printf("%s\n", result);

    return 0;
}

