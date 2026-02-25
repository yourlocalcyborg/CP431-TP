# CP431-TP

## Hand matrices
---
### M(5)
|x|-| 1|    2| 3| 4| 5|
|-|-|--|-----|--|--|--|
|1|-| 1|    2| 3| 4| 5|
|2|-| x|~~4~~| 6| 8|10|
|3|-| x|    x| 9|12|15|
|4|-| x|    x| x|16|20|
|5|-| x|    x| x| x|25|

an x designates that the given value is mirrored, strikethrough designates a number as a non-trivial duplicate.

$E(5) = \{ 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 20, 25 \}$

$M(5) = |E(5)| = 14$

## M(10)
| x|-| 1| 2| 3| 4| 5| 6| 7| 8| 9| 10|
|--|-|--|--|--|--|--|--|--|--|--|---|
| 1|-| 1| 2| 3| 4| 5|  |  |  |  |   |
| 2|-| x| 4| 6| 8|10|  |  |  |  |   |
| 3|-| x| x| 9|12|15|  |  |  |  |   |
| 4|-| x| x| x|16|20|  |  |  |  |   |
| 5|-| x| x| x| x|25|  |  |  |  |   |
| 6|-|  |  |  |  |  |  |  |  |  |   |
| 7|-|  |  |  |  |  |  |  |  |  |   |
| 8|-|  |  |  |  |  |  |  |  |  |   |
| 9|-|  |  |  |  |  |  |  |  |  |   |
|10|-|  |  |  |  |  |  |  |  |  |   |

## Algorithm

a dispatcher ($D$) gives a worker from a set of workers with ID $n$ $(W_n)$ a column $i$, and $W_n$ calculates $A_i = \{ i*1, i*2, ... , i*i \}$. $W_n$ finishes calculation, then sends $A_i$ to $D$, and $D$ sends $W_n$ some other column $i' > i$, before adding the numbers found in $A_i$ to its complete set of found numbers.