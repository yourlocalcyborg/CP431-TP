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
| x|-| 1|    2|    3|     4|     5|     6|    7|     8|    9|    10|count|
|--|-|--|-----|-----|------|------|------|-----|------|-----|------|-----|
| 1|-| 1|    2|    3|     4|     5|     6|    7|     8|    9|    10|   10|
| 2|-| x|~~4~~|~~6~~| ~~8~~|~~10~~|    12|   14|    16|   18|    20|    5|
| 3|-| x|    x|~~9~~|~~12~~|    15|~~18~~|   21|    24|   27|    30|    5|
| 4|-| x|    x|    x|~~16~~|~~20~~|~~24~~|   28|    32|   36|    40|    4|
| 5|-| x|    x|    x|     x|    25|~~30~~|   35|~~40~~|   45|    50|    4|
| 6|-| x|    x|    x|     x|     x|~~36~~|   42|    48|   54|    60|    4|
| 7|-| x|    x|    x|     x|     x|     x|   49|    56|   63|    70|    4|
| 8|-| x|    x|    x|     x|     x|     x|    x|    68|   72|    80|    3|
| 9|-| x|    x|    x|     x|     x|     x|    x|     x|   81|    90|    2|
|10|-| x|    x|    x|     x|     x|     x|    x|     x|    x|   100|    1|

$E(10) = \{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 27, 28, 30, 32, 35, 36, 40, 42, 45, 48, 49, 50, 54, 60, 56, 63, 68, 70, 72, 80, 81, 90, 100 \}$

$M(10) = |E(10)| = 42$

## Algorithm

All processes are workers, except for one collector. each worker calculates a column of the matrix $i$ (up to the point of mirroring where the value is $i*i$) and then sends it to the collector, which keeps track of which values have been found.

At large numbers, the sequential collector is made to execute far longer than the workers, mitigating benefit from parallel calculation. This is not a problem at the scales required for the assignment.
