## How to make a chess game in C?

1. Create the characters (chess pieces) and their actions (valid moves)
---

In this case I used C macro to define constanst that translate to unique numbers (bit combinatinos) for each chess piece.
I used a 3 bit space (numbers from 0 to 7) and created a bit mask.

I then created another 2 bit space two bit masks to mark white and black pieces that can be used in the same number 

I also created 6 validation functions, one for each chess piece, establishing which moves are allowed
in the chess board.


2. Define the world/space where the characters live (chess board), create and initialize one real version of it
---

I created a two-dimension variable to represent the real chess board's rows and columns, the points held by the white 
player and the black player, and the pieces lost by white player and black player, and the current turn

I created a function to initialize it by the standard chess rules, placing the pieces in their starting positions.

I created a function to create a new chess board from a copy of an old one.



3. Create machine intelligence that reacts to character actions (or time) 
---