module StringReduction where 

    solve :: String -> String -> Int 
    solve xs ys@(y:yn)
                | length ys > length xs = 0
                | length ys == 1 && elem y xs == False = 0
                | util xs ys = length xs - length ys
                | otherwise = 0

    util :: String -> String -> Bool
    util xs (y:ys)
                        | length ys == 0 = True
                        | elem y xs = util (removeItem y xs) ys
                        | otherwise = False


    removeItem _ []                 = []
    removeItem x (y:ys) | x == y    = ys
                        | otherwise = y : removeItem x ys