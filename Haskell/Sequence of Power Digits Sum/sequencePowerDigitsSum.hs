module PowerDigitsSum where
    import Data.List (findIndex)


    sumPowDigSeq :: Integer -> Int -> Int -> (Int,[Integer],Int,Integer)
    sumPowDigSeq initial nPower ktimes = findCycle cu
                                        where cu = makeListOfValues initial nPower ktimes 0
    

    makeListOfValues :: Integer -> Int -> Int -> Int -> [Integer]
    makeListOfValues initialN npower ktimes counter
                                                    | counter == ktimes = [] 
                                                    | otherwise         = cu : makeListOfValues cu npower ktimes (counter+1)
                            where cu = raiseDigitsToK initialN npower

    digs :: Integer -> [Integer]
    digs 0 = []
    digs x = digs (fromIntegral x `div` 10) ++ [fromIntegral x `mod` 10]
    
    raiseDigitsToK :: Integer -> Int -> Integer
    raiseDigitsToK n k =  sum (map (^k) (digs n))
 
    findCycle :: Eq a => [a] -> ([a], Int, Int)
    findCycle lst =
        do 
            l <- findCycleLength lst
            mu <- findIndex (uncurry (==)) $ zip lst (drop l lst)   
            let c = take l $ drop mu lst
            return (c, l, mu)
 
    findCycleLength :: Eq a => [a] -> Int
    findCycleLength [] = Nothing
    findCycleLength (x:xs) =
        let loop _ _ _ [] = Nothing
            loop pow lam x (y:ys)
                | x == y     = Just lam
                | pow == lam = loop (2*pow) 1 y ys
                | otherwise  = loop pow (1+lam) x ys
        in loop 1 1 x xs