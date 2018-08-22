module Min where

    minValue :: [Int] -> Int
    minValue [] = 0
    minValue n = read (util n)
    
    util :: [Int] -> String
    util [] = ""
    util n = show (minimum n) ++ util(removeElements(minimum n) n)
    
    removeElements :: Int -> [Int] -> [Int]
    removeElements _ [] = []
    removeElements n (x:xs)
                      | n == x = removeElements n xs
                      | otherwise = x : removeElements n xs
    