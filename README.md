# SAT Solver

A learning project where I build a SAT (Boolean Satisfiability) solver from scratch in C.

## What is SAT?

The Boolean Satisfiability Problem asks: given a logical formula, is there an assignment of TRUE/FALSE values to its variables that makes the entire formula evaluate to TRUE? If yes, the formula is *satisfiable*. If no such assignment exists, it is *unsatisfiable*.

For example, `(a OR b) AND (NOT a OR b)` is satisfiable — set `a = FALSE` and `b = TRUE`. But `(a) AND (NOT a)` is unsatisfiable — no assignment works.

SAT was the first problem proven to be NP-complete (Cook-Levin theorem, 1971). This means every problem in NP can be reduced to SAT. Despite this worst-case hardness, modern SAT solvers handle industrial instances with millions of variables and clauses through clever heuristics.

## Why Build One?

SAT solvers power real-world tools: hardware verification, software testing, AI planning, constraint solving, and more. Building one teaches you about search algorithms, backtracking, clause learning, and the boundary between tractable and intractable problems.

## Project Structure

```
sat-solver/
├── CMakeLists.txt
├── include/
│   └── solver.h
├── src/
│   ├── main.c
│   └── solver.c
└── README.md
```

## Building

```bash
cmake -B build -S .
cmake --build build
```

## Running

```bash
./build/sat-solver <cnf-file>
```

Input files should be in DIMACS CNF format, the standard representation for SAT problems. A CNF formula is a conjunction of clauses, where each clause is a disjunction of literals. For example:

```
p cnf 3 2
1 2 0
-1 3 0
```

This encodes `(x1 OR x2) AND (NOT x1 OR x3)` with 3 variables and 2 clauses.

## Current State

This project is a work in progress. The solver currently reads input files and passes them to the solving engine. Core algorithms are being implemented incrementally.

## Roadmap

- [x] File I/O and DIMACS CNF parsing
- [ ] Literal and clause data structures
- [ ] Backtracking search (naive DPLL)
- [ ] Unit propagation
- [ ] Pure literal elimination
- [ ] Conflict-driven clause learning (CDCL)
- [ ] Decision heuristics (VSIDS)
- [ ] Restart strategies
- [ ] Output satisfying assignment

## Key Concepts

**Conjunctive Normal Form (CNF)** — Every formula can be converted to CNF: a product (AND) of sums (OR) of literals. This is the standard input format for SAT solvers.

**DPLL Algorithm** — The classic approach: pick a variable, try TRUE then FALSE, propagate consequences, backtrack on contradiction. With unit propagation and pure literal elimination, it solves many practical instances efficiently.

**CDCL (Conflict-Driven Clause Learning)** — Modern solvers learn from conflicts. When a contradiction is found, the solver analyzes the reason, derives a new clause that prevents the same mistake, and backtracks to the right decision level. This transforms brute-force search into a guided process.

**NP-Completeness** — SAT is the canonical NP-complete problem. There is no known polynomial-time algorithm for it, but practical instances are often far easier than worst-case bounds suggest.

## References

- [Boolean Satisfiability Problem — Wikipedia](https://en.wikipedia.org/wiki/Boolean_satisfiability_problem)
- [SAT Solving — University of Waterloo (PDF)](https://eceweb.uwaterloo.ca/~agurfink/stqam.w19/assets/pdf/W07-SAT.pdf)
- [MiniSat — A minimalistic, high-performance SAT solver](https://github.com/niklasso/minisat)
