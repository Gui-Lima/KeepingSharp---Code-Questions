module Difference where

    difference :: Eq a => [a] -> [a] -> [a]
    difference [] _ = []
    difference x [] = x
    difference n (x:xs) = difference (deleteAllInstances x n) xs
    
    deleteAllInstances :: Eq a => a -> [a] -> [a]
    deleteAllInstances a = filter (/=a)