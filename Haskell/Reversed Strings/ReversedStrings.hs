module Solution where

    solution :: String -> String
    solution [] = []
    solution (first:rest) =  solution rest ++ [first]
    