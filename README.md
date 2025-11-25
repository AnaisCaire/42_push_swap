here is some reference for my project: 
https://medium.com/@dansylvain84/my-implementation-of-the-42-push-swap-project-2706fd8c2e9f

So this is the first project of 42 where you acctually need to sit down and figure out what 
you want to do.
I am some diagrams and documentation to feel less lost.
so here is the general pipeline of my project:

for the more difficult parts, i am some seperate diagrams to better understand them.

mettre diagram pipeline.

Now, the real push_swap algo (for 5 nbs and +).
first of all, 
its recommended and alot easier to work with the index of each value and not the value itself.
the index is the placement of the value if they were sorted.

here is a diagram that shows you how i computed that:

![build index array diagram](diagrams/index_array.png)

ok, now the largest increasing subsequence is actually pretty hard to code. 
here is a diagram to better understand:

![LIS diagram](diagrams/ft_LIS_prt1.png)

After that, we will insert the values of stack B in stack A using the greedy insertion.
Meaning, what value should we insert that will be the cheapest (less moves).

Here is the logic:

![Greedy insertion diagram](diagrams/greedyinsertion2.png)
