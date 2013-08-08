# Solution for problem no 15

Let ${m \times n}$ be the number of possible paths for a m by n grid.

It is ${0 \times n} = {n \times 0} = 1$ and ${m \times n} = {0 \times 1} \cdot {m \times n - 1} + {1 \times 0} \cdot {m \times 1, n}$.

It is easy to show that
${1 \times n} = {n \times 1} = n + 1$,
${2 \time, n} = {n \time, 2} = \frac{1}{2} (n + 1) \cdot (n + 2)$
and via induction
${m \times n} = {n \times m} = \frac{1}{m!} \prod_{k=1}^{m}(n + m) = \frac{(n + m)!}{n! \cdot m!} = \binom{n + m}{n}$.

For the special case of the $20 \times 20$ grid, the solution therefore is $\binom{40}{20}$.
