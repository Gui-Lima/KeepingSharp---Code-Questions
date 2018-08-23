module Codewars.Kata.LongestPalindrome where
    import Data.List
    
    isPalindrome w = w == reverse w
    
    longestPalindrome :: String -> Int
    longestPalindrome [] = 0
    longestPalindrome n
                        | isPalindrome n = length n
                        | otherwise = maximum (map length palindromeSubStrings)
                        where
                                palindromeSubStrings = getPalindromes subSequencesN
                                subSequencesN = subsequences n

    getPalindromes :: [String] -> [String]
    getPalindromes [] = []
    getPalindromes (x:xs)
               | isPalindrome x = x : getPalindromes xs
               | otherwise = getPalindromes xs