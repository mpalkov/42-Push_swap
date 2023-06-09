```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   PASSED with 96%                                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```
# 42-Push_swap
This project is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions.

To see the complete instructions, read the [subject.pdf](https://github.com/mpalkov/42-Push_swap/blob/master/42_files/en.subject.pdf)

[TOC]

#Preliminary concepts:
####Allowed stack-operations:
![stack_operations.jpg](https://file.notion.so/f/s/5e2b4af7-4a80-4b29-8e22-6328a3418eb4/IMG_20230608_134941.jpg?id=bf4b8036-5c50-4b76-82ba-f2163ab5922a&table=block&spaceId=5953c84b-f0a5-456e-bc70-a724f388cae3&expirationTimestamp=1686311604401&signature=7XSDMat09DCkToa8ltSuKNmIimH2C4I3OnqgNMQFpCg&downloadName=IMG_20230608_134941.jpg)

---
####Each stack node contains these variables:

`*next` - next node in the linked list
`nbr` - the actual number value
`idx` - **index**. It is the position of a number when all the stack is sorted. Starts with 1, so the very first number when sorted has index 1 and the next ones increase by 1, so it is continuous.
**Most of my sorting and sorted-checking algorhitms work with the index value**, as it is much easier to determine if the next number is the very-next one, because it will be + 1, so i don't have to figure out or compare anything else.
```c
    typedef struct	s_node
    {
    	struct s_node	*next; 
    	int		nbr;
    	unsigned int	idx;
    }			t_node;
```
---
Then there is the `t_var` structure with general control variables, where is, for example `stack_a` and `stack_b` pointer, `errno` to check which error (if) just happend, and more.

---
####Chunks
-- When sorting more than 5 numbers, the most optimal approach is to split the stack to various `chunks` of numbers. These numbers in a chunk should be adjacent (when stack is sorted). Like this, you will have stack_b half-way sorted, and you will not need to do too many unnecessary operations to get to the highest overall number when pushing from stack_b to stack_a, because it will be somewhere near very-top or very-bottom of the stack_b.
![chunks_b](https://file.134941.jpg)

#### select_stack function (`ft_ps_stacksel`)
-- I wanted to create the most versatile and modular functions, so I have created the ft_ps_stacksel to determine which stack am i working with (which stack is sent to the current function).
-- knowing the stack, the function can know in which order should the stack be (descending - stack_a OR ascending - stack_b), know what to write when push, swap, rotate or rrotate are executed as the code is the same for ra or rb, just the printed output depends on the input stack.

#The approach:

## Input parsing and checks
-- check if there is more than one arguments.
-- ft_atoi and check if the input arguments are valid `int` numbers.
-- check if no input number repeats.
-- check if the input arguments are unsorted.
-- fill an auxiliary `int` array with the input data and create the `stack_a` out of it.
-- use selection sort to sort the auxiliary array.
-- add the `index` values to the `stack_a` nodes.

## The actual sorting algorithms
### sort_2
-- there is really only 2 options, sorted or swap if not sorted.
###sort_3
-- While the stack is not sorted do:
-- search for the biggest number of the three.
-- If it is on top, `rotate` stack
-- if it is the last, `swap` stack
-- if it is in the middle `reverse rotate` stack.
-- evaluate the while condition again.
### sort_5 (and 4)
-- while stack a has more than 3 numbers, search for the lowest number in the stack_a and push it to stack_b
-- apply sort_3 to the three numbers left in stack_a
-- push everything from stack_b to stack_a in its actual order.
### sort_many (for everything over 5 numbers)
-- first, find the number with the lowest index in stack_a
-- while stack_a contains more than three numbres, do the following:
-- find a number which shall be included in the actual chunk transferred to the stack_b. The search goes like this: first check if the top number is one of the actual chunk indexes. If not, check if the first from bottom is it, if not, check if the second from top is it, if not, check if the second from bottom is it and so on untill you find any number from the actual chunk.
-- When foud, this numbre is pushed to stack_b.
-- the smaller half of the chunk numbers will go on bottom of stack_b (`pb`, `rb`). The bigger half of the chunk will go to the upper part of stack_b so at the end, the stack_b will have the smallest numbers in the center and biggest numbers in the top and bottom, so we will not need to search and do many extra operations to put the biggest number back to stack_a to it's correct position.
-- search from next number from the actual chunk untill the chunk is complete and then do the same for the next chunk.
-- when only 3 numbers left in the stack_a, use sort_3 algorithm to sort it.
-- then search for biggest index in the stack_b and push it to stack_a. untill stack_b is empty.

# Personal Notes:
## Get random numbers in terminal
important to execute in bash
-- Export environment variable ARG to random numbers from 1 to 100:
`export ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")`
-- execute push_swap and checker with new random set of numbers from 0 to 500 every time the line gets executed:
`ARG=$(ruby -e "puts (0..500).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./pro_checker $ARG`

##enum
https://www.geeksforgeeks.org/enumeration-enum-c/

--