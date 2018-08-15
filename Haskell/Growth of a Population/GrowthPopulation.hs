module Codewars.G964.Arge where

    nbYear :: Int -> Double -> Int -> Int -> Int
    nbYear p0 percent aug p = if calc >= p
                              then 1
                              else 1 + nbYear calc percent aug p
                              where calc = floor (fromIntegral p0 + (fromIntegral p0 * (percent/100)) + fromIntegral aug)
                              