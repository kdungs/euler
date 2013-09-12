p :: Integral a => a -> a
p n = n * (3 * n - 1) `quot` 2

is_p :: Integral a => a -> Bool
is_p x = p y == x || p z == x
    where
        y = truncate(1/3 + t);
        z = truncate(1/3 - t);
        t = sqrt(1/9 + 2/3 * fromIntegral(x))

ps :: Integral a => [a]
ps = map p [1..4995]

pairs :: Integral a => [(a, a)]
pairs = [(x, y) | x <- ps, y <- ps, is_p(x + y) && is_p(x - y)]

main = print (take 20 pairs)
