module Kata where

    isSortedAndHow :: [Int] -> String
    isSortedAndHow lst 
                      | isSortedAscending lst = "yes, ascending"
                      | isSortedDescending lst = "yes, descending"
                      | otherwise = "no"
    
    
    isSortedAscending :: [Int] -> Bool
    isSortedAscending [] = True
    isSortedAscending (x:y:xs) = x <= y && isSortedAscending(y:xs)
    isSortedAscending (x:xs) = True
    
    isSortedDescending :: [Int] -> Bool
    isSortedDescending [] = True
    isSortedDescending (x:y:xs) = x >= y && isSortedDescending(y:xs)
    isSortedDescending (x:xs) = True