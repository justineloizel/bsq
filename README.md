# bsq
C program to find the biggest square on a board

## Prerequisites

- gcc
- make
- libc

## Compilation

```
make
```

## Usage

### To generate your own board

```
./bsq [size of board] [pattern]
```
Example: 
```
./bsq 10 "..ooo.." > board.txt
```
Redirect the result in a file to solve it afterwards.

### To find the biggest square

```
./bsq board.txt
```
This will fill the biggest square found with 'x'.

## Authors
[Justine Loizel](https://github.com/justineloizel)
