module PianoNrOne.JorgeVS.Kata where
    blackOrWhiteKey :: Int -> String
    blackOrWhiteKey keyT
                        | key  == 1 = "white"
                        | key  == 2 = "black"
                        | key  == 3 = "white"
                        | key == 0 = "white"
                        | pos == 1 || pos == 3 || pos == 6 || pos == 8 || pos == 10 = "black"
                        | otherwise = "white"
                        where pos = mod (key-4) 12
                              key = mod keyT 88