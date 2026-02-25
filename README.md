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

All processes are workers, except for one collector. each worker calculates a column of the matrix $i$ (up to the point of mirroring where the value is $i*i$) and then sends it to the collector, which keeps track of which values have been found.

This is not a long-term solution though, as the sequential collector is quickly made to execute far longer than the workers, mitigating benefit from parallel calculation.