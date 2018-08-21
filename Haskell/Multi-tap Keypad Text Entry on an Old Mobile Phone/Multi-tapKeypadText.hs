module Haskell.Codewars.KeypadEntry where
    import Data.Char
    
    presses :: String -> Int
    presses [] = 0
    presses (x:xs)
                  | elem (toLower x) ones = 1 + presses xs
                  | elem (toLower x) twos = 2 + presses xs
                  | elem (toLower x) threes = 3 + presses xs
                  | elem (toLower x) fours = 4 + presses xs
                  | elem (toLower x) ws = 1 + presses xs
                  | elem (toLower x) fives = 5  + presses xs
                  | otherwise = presses xs
                  where 
                      ones = ['a', 'd', 'g', 'j', 'm', 'p', 't', 'w', '1']
                      twos = ['b', 'e', 'h', 'k', 'n', 'q', 'u', 'x', '0']
                      threes = ['c', 'f', 'i', 'l', 'o', 'r', 'v', 'y']
                      fours = ['s', 'z', '2', '3', '4', '5', '6','8']
                      fives = ['7', '9']
                      ws = [' ']