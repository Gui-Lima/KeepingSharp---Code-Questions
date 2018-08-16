module Codewars.Kata.AlternatingCase where
import Data.List
import Data.Char

toAlternatingCase :: String -> String
toAlternatingCase [] = []
toAlternatingCase (x:xs) = if isLower x
                           then toUpper x : toAlternatingCase xs
                           else toLower x : toAlternatingCase xs

  