module Codewars.Kata.Unique where

    findUnique :: [Int] -> Int
    findUnique [] = 0
    findUnique n@(x:xs)
                        | length xs == 0 = x
                        | otherwise = util n n
                        

    util :: [Int] -> [Int] -> Int
    util [] _ = 0
    util (x:xs) staticlist
                                        | numTimesFound x staticlist == 1 = x
                                        | numTimesFound x staticlist > 1 = util xs staticlist
                    
    
    numTimesFound x xs = (length . filter (== x)) xs

    