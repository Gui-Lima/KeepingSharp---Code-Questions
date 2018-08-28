module Codewars.G964.Revrot where
    import Data.Char

    revRot :: [Char] -> Int -> [Char]
    revRot [] _ = []
    revRot strng chunkSize
                            | chunkSize <= 0 = []
                            | chunkSize > length(strng) = []
                            | mod (util (transformStringIntoListOfNumbers (take chunkSize strng))) 2  == 0 = reverse' (take chunkSize strng) ++ revRot (drop chunkSize strng) chunkSize
                            | otherwise = rotate 1 (take chunkSize strng) ++ revRot (drop chunkSize strng) chunkSize
    
    transformStringIntoListOfNumbers :: [Char] -> [Int]
    transformStringIntoListOfNumbers [] = [0]
    transformStringIntoListOfNumbers (x:xs) = digitToInt x : transformStringIntoListOfNumbers xs

    po3 :: Int -> Int
    po3 n = n*n*n

    util :: [Int] -> Int
    util [] = 0
    util n = sum (map po3 n)
    
    reverse' :: [a] -> [a]  
    reverse' = foldl (\acc x -> x : acc) [] 

    rotate :: Int -> [a] -> [a]
    rotate _ [] = []
    rotate n xs = zipWith const (drop n (cycle xs)) xs
