module Snail where
    import Data.List

    snail :: [[Int]] -> [Int]
    snail [[]] = []
    snail n 
            | length n == 1 = getFirstArray n
            | otherwise =  values ++ snail newArray
                    where values = getFirstArray n ++ getLastElMidArrays n 1  ++ getLastArrayReverse n ++ getFirstElMidArrays n (length n -2)
                          newArray = modifyArray n values
    
    getFirstArray :: [[Int]] -> [Int]
    getFirstArray [[]] = []
    getFirstArray n@(x:xs) = x

    getLastElMidArrays :: [[Int]] -> Int -> [Int]
    getLastElMidArrays [[]] _ = []
    getLastElMidArrays n@(x:xs) m
                                    | m < 1 = []
                                    | m > length n-2 = []
                                    | otherwise = n !! m !! (length x-1) : getLastElMidArrays n (m+1)

    getLastArrayReverse :: [[Int]] -> [Int]
    getLastArrayReverse [[]] = []
    getLastArrayReverse n@(x:xs) = reverse (last n)

    getFirstElMidArrays :: [[Int]] -> Int -> [Int]
    getFirstElMidArrays [[]] _ = []
    getFirstElMidArrays n@(x:xs) m
                                    | m < 1 = []
                                    | otherwise = n !! m !! 0 : getFirstElMidArrays n (m-1)

    modifyArray :: [[Int]] -> [Int] ->[[Int]]
    modifyArray [[]] _ = []
    modifyArray n@(x:xs) m =  splitEvery (length n - 2) ((unifyArray n) \\ m)
    
    unifyArray :: [[Int]] -> [Int]
    unifyArray [[]] = []
    unifyArray n@(x:xs) 
                            | length xs == 0 = x
                            | otherwise =  x ++ unifyArray xs

    splitEvery :: Int -> [a] -> [[a]]
    splitEvery _ [] = []
    splitEvery n xs = as : splitEvery n bs 
                                            where (as,bs) = splitAt n xs