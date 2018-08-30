module TheShellGame where

    findTheBall :: Int -> [(Int, Int)] -> Int
    findTheBall x [] = x
    findTheBall x (y:ys)
                        | x == fst y  = findTheBall (snd y) ys
                        | x == snd y  = findTheBall (fst y) ys
                        | otherwise = findTheBall x ys
      