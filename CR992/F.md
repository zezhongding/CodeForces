# Problem F
- Recall Burnside's lemma: the number of orbits of a group action is the average number of fixed points of the group action.
$$
    \frac{1}{|G|} \sum_{g \in G}\sum_{x \in X} [g \cdot x = x]
$$
Let's try to iterate over the elements of the action group -- all triplets of numbers $[0, a)$, $[0, b)$, $[0, c)$. When applying a fixed action $(i, j, l)$, the element moves to this vector.

Let's choose a cell and add a vector to it until we reach it again. We have drawm a cycle -- all cells on it must be of the same type.

The length of all cycles is the same and equals $N = lcm(\frac{a}{gcd(a, i)}, \frac{b}{gcd(b, j)}, \frac{c}{gcd(c, l)})$

What's good about the equal length of the cycles? Because the formula for calculating the number of stationary parallelepipeds is simple. First, all $d_i$ must be divisible by N. Then, we distribute them among the cycles. This is the multinomial coefficient for $\frac{d_1}{N}, \frac{d_2}{N}, \cdot, \frac{d_k}{N}$

Current total time $O(abck)$: iterated over $abc$ vector triplets, calculated N, checked divisivility for all $k$ numbers, and calculated the multinomial coefficient of size $k$.

Let's speed up the solution. Let's calculate $G = gcd(d_1, d_2, \cdot, d_k)$. Since all $d_i$ are divisivle by $N$, then $G$ is also divisible by $N$. There are no more different $N$ than the number of divisors of $abc$. Let's calculate the number of triplets that give each value of $N$, and at the end we will calculate the multimal coefficient for all identical value of $N$ at once.

The total time is $O(abclogC$