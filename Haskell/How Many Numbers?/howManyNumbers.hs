module Codewars.G964.Howmany where

    selNumber :: Int -> Int -> Int
    selNumber 0 d = 0
    selNumber n d
                  | digitCount n >= 2 && isSortedAscending (digs n) && isRangeLessThanN (digs n) d && allDifferent (digs n) = 1 + selNumber (n-1) d
                  | otherwise = selNumber (n-1) d
    
    
    digitCount :: Int -> Int
    digitCount = go 1 . abs
        where
            go ds n = if n >= 10 then go (ds + 1) (n `div` 10) else ds
            
    digs :: Integral x => x -> [x]
    digs 0 = []
    digs x = digs (x `div` 10) ++ [x `mod` 10]

    isSortedAscending :: [Int] -> Bool
    isSortedAscending [] = True
    isSortedAscending (x:y:xs) = x <= y && isSortedAscending(y:xs)
    isSortedAscending (x:xs) = True

    isRangeLessThanN :: [Int] -> Int -> Bool
    isRangeLessThanN [] n = True
    isRangeLessThanN (x:y:xs) n = (y-x) <= n && isRangeLessThanN(y:xs) n
    isRangeLessThanN (x:xs) n = True

    allDifferent :: (Eq a) => [a] -> Bool
    allDifferent []     = True
    allDifferent (x:xs) = x `notElem` xs && allDifferent xs