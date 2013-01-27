divisors :: (Integral a) => a -> [a]
divisors n = foldl (\acc x -> if n `mod` x == 0 then x : acc else acc) [] [1..n-1]

amicable :: (Integral a) => a -> Bool
amicable n =
    let sd = sum (divisors n)
    in n /= sd && n == sum (divisors sd)

amicableNumbers :: (Integral a) => [a]
amicableNumbers = filter amicable [1..]

euler21 :: (Integral a) => a
euler21 = sum (takeWhile (<10000) amicableNumbers)
