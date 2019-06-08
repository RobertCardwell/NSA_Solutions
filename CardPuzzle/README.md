# CardPuzzle
A program that proves a strategy for solving the NSA's periodical puzzle
of 2016.08.17. The puzzle is given here:
<https://www.nsa.gov/news-features/puzzles-activities/puzzle-periodical/2016/puzzle-periodical-05.shtml>

The author did not look at the NSA's published answer nor anyone else's
answer prior to publishing this program.

The puzzle has an easy part and a hard part. The solution to the easy part
is as follows: The first player (player 0) writes down the colour of the card
displayed by the other player (player 1). Player 1 writes down the OPPOSITE
colour to that displayed by player 0.

The solution to the puzzle's hard part is to generalize the solution given
above, to four players and card suits rather than colors, as follows:

Consider each suit to have two binary properties: "colour" and "sharpness"
(look at the upper part of the suit's symbol: it is either rounded
(i.e., sharpness = 0) or pointed (i.e., sharpness = 1)

Summarizing:

<pre>
black:		0
red:  		1
rounded:	0
pointed: 	1
</pre>

Thus we have the following one-to-one mapping:

<pre>
club:		00
spade:		01
heart:		10
diamond:	11
</pre>

Now consider a 'deal' of four cards to the players. We represent this as an
integer where the numerical places of the bytes represent the four players:

<pre>
000000xx Charles
0000xx00 Doug
00xx0000 Emily
xx000000 Fran
</pre>

Example:

<pre>deal == 11100100</pre> means that:

<pre>
Charles has a club card,
Doug has a spade card,
Emily has a heart card,
Fran has a diamond card.
</pre>

The proposed strategy to guarantee that the players win is as follows:

1) Each player XORs together the values of the other three players' cards.
This result is the "seen" variable. [see explanation below]

2) Each player XORs "seen" with a mask that represents a rule set.
The mask (rule set) for each player is listed in the following table:

<pre>
                  Color     Sharpness	      ->		Mask (rule set)

Player 0:		    0    		  0	  		  ->		00

Player 1:		    0	     	  1		  	  ->		01

Player 2:		    1		      0			  ->		10

Player 3:		    1		      1			  ->		11
</pre>

3) The player then writes down the card suit corresponding to the result
of the preceding XOR operation.

Explanation:

Bitwise XOR either leaves an operand bit unchanged (if the corresponding mask
bit is 0) or toggles it (if the corresponding mask bit is 1). The operation
represents the use of a set of rules whereby each player writes down either
what he "sees" (color and sharpness) or its opposite, with such choices
spread across the four players such that each player has a unique rule set.
Note that each mask is (conveniently) the same as the index number of the
respective player.

More explanation of the "seen" variable (describing the author's method):

The "seen" variable is a generalization, for four players and four card values,
of the step in the first part of the puzzle where the player sees one value
(color) of the card shown by the one other player. It is a way of reducing (or
"averaging") the three values of the other players' cards to a single two-place
binary number, to which the player's rule set can then be applied. My search for
a method of achieving such a reduction began with finding the majority, for each
bit place, of the other three players' cards, so that the result "seen" would be
the color/sharpness of two or three of the three cards. That method almost
worked: 204 won deals and 52 lost deals, and exactly 256 matches, but not
distributed evenly enough to win every deal). That suggested to me that I was on
the right path but that I was overlooking some small detail. My next approach to
"averaging" the three cards was to bitwise XOR them together (lines 38-40) since
I was already accustomed to using XOR as a bitwise method of processing. That
approach gave a perfect score of 256 won deals. I can't offer a mathematical
reason for why that step works. 
