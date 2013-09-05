import Numeric
import Data.Char

is_palindrome :: [Char] -> Bool
is_palindrome xs = xs == reverse(xs)

to_string_binary :: Int -> [Char]
to_string_binary x = showIntAtBase 2 intToDigit x ""

is_double_base_palindrome :: Int -> Bool
is_double_base_palindrome x = is_palindrome(show x) && is_palindrome(to_string_binary(x))

main = print (sum (filter is_double_base_palindrome [1 .. 1000000]))
