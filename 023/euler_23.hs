import Data.List

divisors :: (Integral a) => a -> [a]
divisors n = foldl (\acc x -> if n `mod` x == 0 then x : acc else acc) [] [1..n-1]

abundant :: (Integral a) => a -> Bool
abundant n = n < sum (divisors n)

abundantNumbers :: (Integral a) => [a]
abundantNumbers = filter abundant [1..]

sumsOfTwoAbundantNumbers :: (Integral a) => [a]
sumsOfTwoAbundantNumbers = [x+y | x <- abundantNumbers, y <- abundantNumbers]

euler23 :: (Integral a) => a
euler23 =
    let upperLimit = 28123
        notSumsofTwoAbundantNumbers = [1..upperLimit] \\ (takeWhile (<=upperLimit) sumsOfTwoAbundantNumbers)
    in sum notSumsofTwoAbundantNumbers

main = putStr $ show euler23