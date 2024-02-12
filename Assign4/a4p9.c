#include <stdio.h>

int main() {
  int m, k, i, j, min, max, sum, digit;
  scanf("%d %d", &m, &k); // read input
  min = -1; // initialize min to -1
  max = -1; // initialize max to -1
  for (i = 0; i < m; i++) { // loop over m digits
    digit = (i == 0) ? 1 : 0; // first digit cannot be zero
    while (digit <= 9) { // loop over possible values of digit
      sum = digit; // initialize sum to digit
      for (j = i + 1; j < m; j++) { // loop over remaining digits
        sum += 9; // add 9 to sum
      }
      if (sum >= k) { // check if sum is greater than or equal to k
        min = digit; // update min
        break; // break the loop
      }
      digit++; // increment digit
    }
    if (min == -1) break; // no such number exists
    k -= min; // subtract min from k
    min = min * 10 + 9; // append 9 to min
  }
  if (min != -1) min /= 10; // remove the extra 9 from min
  for (i = 0; i < m; i++) { // loop over m digits
    digit = 9; // start from 9
    while (digit >= 0) { // loop over possible values of digit
      sum = digit; // initialize sum to digit
      for (j = i + 1; j < m; j++) { // loop over remaining digits
        sum += 0; // add 0 to sum
      }
      if (sum <= k) { // check if sum is less than or equal to k
        max = digit; // update max
        break; // break the loop
      }
      digit--; // decrement digit
    }
    if (max == -1) break; // no such number exists
    k -= max; // subtract max from k
    max = max * 10; // append 0 to max
  }
  if (max != -1) max /= 10; // remove the extra 0 from max
  printf("%d %d\n", min, max); // print output
  return 0;
}
