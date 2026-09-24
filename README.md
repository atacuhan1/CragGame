# Crag

Console dice game in C for a METU NCC course. You choose how many rounds to play, then you and the computer each roll three dice per round. A starting roll decides who goes first.

On your turn you may keep two dice and reroll the third. The computer rerolls when it is one die away from a high straight (`4`, `5`, `6`).

## Scoring

The program checks the three dice in the order they were rolled:

| Result | Points |
| --- | --- |
| Crag: sum is 13 and two dice match | 50 |
| Thirteen: sum is 13 | 26 |
| Three of a kind | 25 |
| Low straight `1 2 3` | 20 |
| High straight `4 5 6` | 20 |
| Odd straight `1 3 5` | 20 |
| Even straight `2 4 6` | 20 |
| Anything else | sum of the dice |

Straights match that exact order. The higher total after all rounds wins.

## Build and run

```bash
gcc main.c -o crag
./crag
```
