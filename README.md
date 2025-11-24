here is some reference for my project: 
https://medium.com/@dansylvain84/my-implementation-of-the-42-push-swap-project-2706fd8c2e9f

Now, the real push_swap algo (for 5 nbs and +).
its recommended and alot easier to work with the index of each value and not the value itself.
the index is the placement of the value if they were sorted.
here is a diagram that shows you how i computed that:

![build index array diagram](diagrams/index_array.png)

ok, the largest increasing subsequence is actually pretty hard to code. here is a diagram to better understand:

![LIS diagram](diagrams/ft_LIS_prt1.png)
