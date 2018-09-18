module Haskell.SylarDoom.Ticker where
    import Data.Sequence hiding (length, take)
    import Data.Char

    interpreter :: String -> String
    interpreter [] = []
    interpreter n = util n 0 (fromList (take 100000 zeros))
                                        where zeros = 0 : zeros

    util :: String -> Int -> Seq Int -> String
    util [] _ _ = []
    util cmdsTape@(x:xs) position resultTape
                                                    | x == '>' = util xs (position+1) resultTape
                                                    | x == '<' = util xs (position-1) resultTape
                                                    | x == '*' =  chr (index resultTape position) : util xs position resultTape
                                                    | x == '+' = util xs position (update position (index resultTape position +1) resultTape)
                                                    | x == '-' = util xs position (update position (index resultTape position -1) resultTape)
                                                    | x == '/' = util xs position (update position 0 resultTape)
                                                    | x == '!' = util xs position resultTape
                                                    | otherwise = util xs position resultTape