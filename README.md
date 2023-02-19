# Grid Generator
This project is used to generate a random NxN grid of integers uniformly distributed in a given range. Specifically, it generates an adjacency grid.

# Motivation
This is a component of a graduate research project for COMP 620 - Computer Architecture. [Click here](https://github.com/aciodev/TheTravelingSalesman)

# Special notes
* The grid has structure, and is not just "randomly" generated.
* The diagonal is always -1 because a node cannot be connected to itself.
* Back-tracking was used to generate all distinct subsets of size 2 in the range [0, n).
* Each pair will have the same cost, and as such `grid[0][1]` is the same as `grid[1][0]`.
