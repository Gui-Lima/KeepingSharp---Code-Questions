module Haskell.SylarDoom.Ticker where
    import Data.Sequence hiding (length, take)
    import Data.Char

    interpreter :: String -> String
    interpreter [] = []
    interpreter n = util n 0 (fromList [0])

    util :: String -> Int -> Seq Int -> String
    util [] _ _ = []
    util cmdsTape@(x:xs) position resultTape
                                                    | x == '+' && position >= 0 && position < length(resultTape) && index resultTape position + 1 > 255 = util xs position (update position 0 resultTape)
                                                    | x == '-' && position >= 0 && position < length(resultTape) && index resultTape position -1 < 0 = util xs position (update position 255 resultTape)
                                                    | x == '>' && position >= 0 && position < length(resultTape)-1 = util xs (position+1) resultTape
                                                    | x == '<' && position > 0 && position < length(resultTape) = util xs (position-1) resultTape
                                                    | x == '*' && position >= 0 && position < length(resultTape) = chr (index resultTape position) : util xs position resultTape
                                                    | x == '+' && position >= 0 && position < length(resultTape) = util xs position (update position (index resultTape position +1) resultTape)
                                                    | x == '-' && position >= 0 && position < length(resultTape) = util xs position (update position (index resultTape position -1) resultTape)
                                                    | x == '/' && position >= 0 && position < length(resultTape) = util xs position (update position 0 resultTape)
                                                    | x == '!' = util xs position (resultTape |> 0)
                                                    | otherwise = util xs position resultTape