# push_swap
```
FINAL GRADE: 100/100
```
- C Programming
- Stack

**Project goal:** Design and implement a program in C to sort a stack of integers using a limited set of operations in the most efficient way possible.

### Mandatory

The objective of this project is to create a program, which will sort numbers into stack **`a`** using the least possible number of operations. This will be done with two stacks (**`a`** and **`b`**) and a set of instructions to manipulate both stacks.

The sorting result will be checked using a special program called `checker_OS`, which will confirm whether the output of your program correctly sorted the stack.

* For a minimalist validation (`80/100`), you must be able to sort 100 random numbers in fewer than 700 operations.
  
| Program name | push_swap |
|:--- |:---|
| Turn in files | Makefile, *.h, *.c |
| Makefile  | NAME, all, clean, fclean, re |
| Arguments | stack a: A list of integers |
| External functs. | - read, write, malloc, free, exit<br>- ft_printf and any equivalent  YOU coded |
| Libft authorized | Yes |
| Description  | Sort stacks  |


### Bonus

* For maximal project validation, for 500 random numbers, there should be no more than 5500 operations.
* Develop your own `checker` program that will verify the sequence of operations applied to sort the stack.

You can visualize algorithm in action with: [O-reo's push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)

The project has been tested with:
[gemartin99/Push-Swap-Tester](https://github.com/gemartin99/Push-Swap-Tester)

Subject version: 8.
