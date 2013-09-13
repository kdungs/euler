isInt x = x == fromIntegral(round(x))

b a = 1/6 + sqrt(1/36 + x*(x+1)/3)
    where x = fromIntegral(a)

c a = 1/4 + sqrt(1/16 + x*(x+1)/4)
    where x = fromIntegral(a)

t n = n * (n + 1) `quot` 2

tph = filter (\x -> isInt(b x) && isInt(c x)) [1..]

main = print $ t (tph !! 2)
