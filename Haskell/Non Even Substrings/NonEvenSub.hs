module NonEvenSubstrings where 
    import Data.List
    import Data.Char

    solve :: String -> Int 
    solve xs = returnEvens(subLists xs)
    
    subLists :: String -> [String]
    subLists [] = [[]]
    subLists (x:xs) = [x:y | y <- inits xs] ++ subLists xs

    returnEvens :: [String] -> Int
    returnEvens [] = 0
    returnEvens (x:xs)
                        | x == "" = returnEvens xs
                        | odd (read x::Int) = 1 + returnEvens xs
                        | otherwise = returnEvens xs