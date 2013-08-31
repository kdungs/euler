import Data.List

rightTriangles :: (Enum t, Eq t, Fractional t) => t -> [[(t, t, t)]]
rightTriangles p = filter (not.null) [[(a, b, c) | b <- [1 .. a], let c=p-a-b, a^2+b^2-c^2 == 0] | a <- [1 .. p/2-1]]

numTriangles :: [a] -> Int
numTriangles tr = length tr

numsTriangles :: [Int]
numsTriangles = map numTriangles . map rightTriangles $ [1..]

euler39 :: Int -> Maybe Int
euler39 limit = elemIndex (maximum l) l
              where l = take limit numsTriangles

main = case res of
    Just value -> print (value + 1)
    Nothing -> print "This is strange..."
    where res = euler39 1000
