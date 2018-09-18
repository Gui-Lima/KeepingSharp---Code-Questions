module Haskell.SylarDoom.MiniBitMove where

    interpreter :: String -> String -> String
    interpreter _ [] = ""
    interpreter tape array@(x:xs)
                                        | y == '1' =  interpreter ys (invert x : xs)
                                        | y == '0' =  x : interpreter ys xs
                                        | otherwise = "ERROR"
                                        where tape2@(y:ys) = duplicateNTimes tape (length array)
                    
    duplicateNTimes :: String -> Int -> String
    duplicateNTimes list 0 = list
    duplicateNTimes list nTimes = list ++ duplicateNTimes list (nTimes-1)

    invert :: Char -> Char
    invert n
                | n == '1' = '0'
                | n == '0' = '1'