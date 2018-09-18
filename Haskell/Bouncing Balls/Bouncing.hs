module Codewars.Kata.BouncingBall where

    bouncingBall :: Double -> Double -> Double -> Integer
    bouncingBall height bounce window
                                        | height < 0 || bounce <= 0 || bounce >= 1 || window >= height = -1
                                        | height * bounce > window = 2 + bouncingBall (height * bounce) bounce window
                                        | otherwise = 1