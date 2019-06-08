This is an adaptation of the puzzle at https://www.nsa.gov/news-features/puzzles-activities/puzzle-periodical/2015/puzzle-periodical-september.shtml

The problem addressed here is: Find the best search sequence for Chris, given that he knows Bob's search sequence. The general answer is to stay one step ahead of Bob, as much as possible. That is, he should begin with the second box (B) and then continue searching the boxes in alphabetic order with A left to last.
	
The truth table resulting from the puzzle, of all possible choices of the pair of boxes for hiding the Easter eggs) can be derived using the binomial coefficient, and there are 66 such combinations. Examination of that table leads to the conclusion that Chris will win slightly more often than Bob.

I was interested to know how much better Chris' strategy might be if he was allowed to open the boxes in any sequence but I have not found an algegraic solution. Therefore this program amounts to a proof that the following solution has the equal best outcome. Alternative solutions with equally good results are almost the same, varying only in the last few steps.

Chris' maximum number of wins is 55, with 10 losses and 1 tie, determined from prior experimentation. The program examines all possible permutations of Chris' search sequence and prints out those that results in 55 or more wins. It also prints the number of permutations examined, as a cross-check against the expected, algebraic total of n!

