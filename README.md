# WackyScript

WackyScript is a minimalistic programming language. In WackyScript there is a list of cells, the size of the list can change, also there is a pointer which points to a cell which you can move around. Here are the operations WackyScript supports:

'#' - input a number and store it in the current cell
';' - output the ASCII value of the number stored in the current cell
'>' - increase the pointer by one
'<' - decrease the pointer by one
'|' - insert a new cell after the current one with the same value as the current cell
'$+' - erase the current cell and add the value in the current cell to the previous cell
'$-' - erase the current cell and subtract the value in the current cell from the previous cell
'&' - set the value of the current cell to one
'[]' - this is a while loop which ends when the value of the current cell is 0
'{}' - this is a while loop which ends when there is only one cell

## Rules
1. A pointer can never pointer can never be negative (indexing from 0).
2. A pointer can never be greater than the amount of cells.
3. After a program executes there should be only one cell with the value 0.
4. The program should be written in the reverse order.

## Painometer
Painometer is a way of mesuring how "good" your program is. Let's imagine the painometer value of your program is X, than the chance that each individual command works is X. When i say a command didn't work i mean the command was skipped.

I will soon add a better explanation of the painometer.

## Hello World
The hello world program is written in main.wacs.


