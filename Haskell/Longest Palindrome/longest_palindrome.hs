module Codewars.Kata.LongestPalindrome where

    import Data.List
    
    isPalindrome :: String -> Bool
    isPalindrome [] = True
    isPalindrome n
                    | n == reverse n = True
                    | otherwise = False
    
    transformSubStringsIntoBooleans :: [String] -> [Bool]
    transformSubStringsIntoBooleans [] = []
    transformSubStringsIntoBooleans (x:xs)
                                            | isPalindrome x == True = True : transformSubStringsIntoBooleans xs
                                            | otherwise = False : transformSubStringsIntoBooleans xs
                                    
    longestPalindrome :: String -> Int
    longestPalindrome [] = 0
    longestPalindrome n = maximum (map length palindromeSubStrings   )
                        where
                                palindromeSubStrings = getPalindromeSubStrings(subLists n) (transformSubStringsIntoBooleans(subLists n))
     
    subLists :: String -> [String]
    subLists [] = [[]]
    subLists (x:xs) = [x:y | y <- inits xs] ++ subLists xs
    
    getPalindromeSubStrings :: [String] -> [Bool] -> [String]
    getPalindromeSubStrings [] _ = []
    getPalindromeSubStrings _ [] = []
    getPalindromeSubStrings (x:xs) (y:ys)
                                            | y == True = x : getPalindromeSubStrings xs ys
                                            | otherwise = getPalindromeSubStrings xs ys