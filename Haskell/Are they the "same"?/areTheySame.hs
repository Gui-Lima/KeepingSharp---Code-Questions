module Codewars.Kata.Compare where
    import Data.List (nub, sort)
    
    comp :: [Integer] -> [Integer] -> Bool
    comp as bs
              | length as /= length bs = False
              | as == [] && bs == [] = True
              | otherwise = util as bs
    
    
    util :: [Integer] -> [Integer] -> Bool
    util [] _ = True
    util (x:xs) bs = elem (x^2) bs && util xs (removeItem (x^2) bs)
    

    removeItem :: Integer -> [Integer] -> [Integer]
    removeItem _ []                 = []
    removeItem x (y:ys) | x == y    = ys
                        | otherwise = y : removeItem x ys


