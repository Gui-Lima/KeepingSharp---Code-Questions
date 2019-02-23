module IntegerPartitions where

    -- todas as combinações de n numeros menores que n que somem d
    indices :: Int -> Int -> [[Int]]
    indices n 0 = [replicate n 0]
    indices n d = [x | x<-combinationsOfDigits n, sum x == d]

    combinationsOfDigits :: Int -> [[Int]]
    combinationsOfDigits 0 =  return []
    combinationsOfDigits n = do
    x <- [0..9]
    xs <- combinationsOfDigits (n - 1)
    return (x : xs)