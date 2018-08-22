module Row where

    rowWeights :: [Int] -> [Int]
    rowWeights n= sum(map snd $ filter (even . fst) (zip [0 .. ] n)) : [] ++ (sum(map snd $ filter (odd . fst) (zip [0 .. ] n)) : [])
    