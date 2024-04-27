#include <stdio.h>
int main()
{
   int n, k;
   scanf("%d %d",&n, &k);
   char str1[n];
   scanf("%s", str1);
   char str2[n];
   for (int i = 0; i < n; i++) {str2[i] = str1[i];}
   int i = 0, tmp = k;
   while (i < n - 1)
   {
       if (str2[i] > str2[i + 1] && tmp)
       {
           str2[i] = '_';
           tmp--;
       }
       i++;
   }
   for (int i = n - 1; i >= 0; i--)
   {
       if (str2[i] != '_')
       {
           int j = i + 1;
           while (j < n && str2[j] == '_')
           {
               str2[j] = str2[j - 1];
               str2[j - 1] = '_';
               j++;
           }
       }  
    }
   for (int i = k; i < n; i++) {
       int a = str1[i] - '0';
       int b = str2[i] - '0';
       int ans = a - b;
       str1[i] = ans + '0';
   }
   printf("%s", str1);
   return 0;
}