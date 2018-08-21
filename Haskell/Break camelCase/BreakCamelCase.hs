module Codewars.Kata.BreakCamelCase where
    import Data.Char
    
    solution :: String -> String
    solution [] = []
    solution n@(x:xs)
                  | isUpper x = tail (util n)
                  | otherwise = util n
    
    util :: String -> String
    util [] = []
    util (x:xs)
                  | isUpper x = " " ++ x :  util xs
                  | otherwise = x : util xs