module Kata (replace) where
    import Data.Char
    
    replace :: String -> String
    replace [] = []
    replace (x:xs) 
                  | toLower x == 'a' || toLower x == 'e' || toLower x == 'i' || toLower x == 'o' || toLower x == 'u' = "!" ++ replace xs
                  | otherwise = x :[] ++ replace xs