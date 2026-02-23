*This activity has been created as part of the 42 curriculum by aalbess, jaldeek*

# push_swap

## Description
push_swap is a sorting program that organizes a stack of integers using the minimal number of operations defined in the Push_swap model.
It implements multiple strategies with different time complexities:

- Simple (O(n²)): selection sort adaptation.
- Medium (O(n√n)): chunk-based .
- Complex (O(n log n)):  or radix sort adaptations.
- Adaptive: selects the algorithm dynamically based on the disorder of the input.

The goal is to produce the sorted stack with as few operations as possible, while validating performance across various input sizes.

## Algorithms and Strategy Justification

- Simple (O(n²))
Chosen algorithm: selection sort adaptation.
Justification: Provides a reliable baseline for small stacks, straightforward to implement in a two-stack
 model.
- Medium (O(n√n))
Chosen algorithm: chunk-based sorting using dynamic widow.
Justification: initialize a window size and iterates throw the stack with incrementing it.

- Complex (O(n log n))
Chosen algorithm: radix sort adaptation (LSD).
Justification: Efficient for large inputs, handles integers with minimal operations, maintains O(n log n) time complexity within the Push_swap model.

- Adaptive Algorithm
Internal design:
- Low disorder (<0.2): linear pass extraction and minimal push operations (O(n)).
- Medium disorder (0.2–0.5): chunk-based partitioning (O(n√n)).
- High disorder (≥0.5): radix sort adaptation (O(n log n)).
Thresholds were chosen to balance performance against input disorder, validated with benchmark tests.

## Project Structure
├── bench.c
├── complex.c
├── ft_atoi.c
├── ft_split.c
├── chunks_algo.c
├── chunks_utils.c
├── min_max.c
├── operations.c
├── operations2.c
├── operations3.c
├── push_swap.h
├── push_swap.c
├── push_swap2.c
├── simple.c
├── sort.c
├── utils.c
├── validation.c
├── Makefile
└── README.md

## contribution

ayham did the header,simple algorethrem, bench, README and part of thr main program.
jude did the complex algo, medium algo,Makefile and the other part of the main program.

## Resources

- 42 push_swap PDF.
- Peer discussions on stack-based sorting algorithms (aalbess, jaldeek).
- YouTube tutorials on push_swap strategies and operations.
- AI for help in some cases.

### Compilation

To compile the project, run:

```bash
git clone <git@github.com:42learners/Common-Core---Push_Swap-626ac9b4-7a48-4374-9c7e-74964cad5fd5.git>
make
