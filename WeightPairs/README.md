<h2>WeightPairs</h2>

This is a complete solution to the puzzle at:
https://www.nsa.gov/news-features/puzzles-activities/puzzle-periodical/2016/puzzle-periodical-01.shtml

Formulate the problem as follows:

Call the weights: w, x, y, and z.

We are told all the pair combinations of the weights have totals of:
6, 8, 10, 12, 14, 16		....(1)

We can also say that every weight is less than the largest sum of pairs
--> Each number is less than or equal to 15	....(2)

We can also say that all the weights are integers. This is because, for any
pair of floating-point weights, the parts to the right of the decimal point
must add to one, and that means those fractional parts must all be 0.5 since
any two less than 0.5 would add to less than one, and any two greater than 0.5
would add to more than one but less than two. Also, if the fractional parts
were 0.5 then the whole parts would have to add up to an odd number because
all the sums of pairs are even. But if the whole parts of each pair added to
an odd number then one must be odd while the other is even. But that is not
true for every possible pair combination of the four weights.

We can therefore find all possible solutions by iterating through the integers
1 to 15, nested four loops deep (by condition (2)), and testing each such
quad against condition (1).
