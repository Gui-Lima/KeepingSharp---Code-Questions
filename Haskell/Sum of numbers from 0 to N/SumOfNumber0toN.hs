module Sequence.JorgeVS.Kata where
    sequenceSum :: Int -> String
    sequenceSum n
                | n > 0 = util n ++ " = " ++ show (sum [0..n])
                | n < 0 = show n ++ " < 0"
                | n == 0 = "0 = 0"
    
    util:: Int -> String
    util 0 = show 0 
    util n = util (n-1) ++ "+" ++ show n