module Example (mixbonacci) where

    mixbonacci :: [String] -> Int -> [Integer]
    mixbonacci [] _ = []
    mixbonacci _ 0 = []
    mixbonacci pattern length' = util pattern (length'+1) 0 0 0 0 0 0 0 1


    util :: [String] -> Int -> Integer -> Integer -> Integer -> Integer -> Integer -> Integer -> Int -> Int -> [Integer]
    util choose nTimes fibC padC pellC jacC triC tetC atualT atualP
                                    | atualP == (fromIntegral nTimes)           = []
                                    | atualT == length choose                   = util choose nTimes fibC padC pellC jacC triC tetC 0 atualP
                                    | choose !! atualT == "fib"                 = fibList !! (fromIntegral fibC) : util choose nTimes (fibC + 1) padC pellC jacC triC tetC (atualT + 1)(atualP + 1)
                                    | choose !! atualT == "pad"                 = padList !! (fromIntegral padC) : util choose nTimes fibC (padC+1) pellC jacC triC tetC (atualT + 1)(atualP + 1)
                                    | choose !! atualT == "pel"                 = pellList !! (fromIntegral pellC) : util choose nTimes fibC padC (pellC + 1) jacC triC tetC (atualT + 1)(atualP + 1)
                                    | choose !! atualT == "jac"                 = jacList !! (fromIntegral jacC) : util choose nTimes fibC padC pellC (jacC + 1) triC tetC (atualT + 1)(atualP + 1)
                                    | choose !! atualT == "tri"                 = triList !! (fromIntegral triC) : util choose nTimes fibC padC pellC jacC (triC+1) tetC (atualT + 1)(atualP + 1)
                                    | choose !! atualT == "tet"                 = tetList !! (fromIntegral tetC) : util choose nTimes fibC padC pellC jacC triC (tetC+1) (atualT + 1)(atualP + 1)
                                    | otherwise = []


    fibList = reverse (fibH 100)
    padList = reverse (padH 100)
    pellList = reverse (pellH 100)
    jacList = reverse (jacH 100)
    triList = reverse (triH 100)
    tetList = reverse (tetH 100)

    fibH :: Integer -> [Integer]
    fibH 0 = [0]
    fibH n = fib n : fibH (n-1)                                

    padH :: Integer -> [Integer]
    padH 0 = [1]
    padH n = pad n : padH (n-1)

    pellH :: Integer -> [Integer]
    pellH 0 = [0]
    pellH n = pell n : pellH (n-1)

    jacH :: Integer -> [Integer]
    jacH 0 = [0]
    jacH n = jac n : jacH (n-1)

    triH :: Integer -> [Integer]
    triH 0 = [0]
    triH n = tri n : triH (n-1)

    tetH :: Integer -> [Integer]
    tetH 0 = [0]
    tetH n = tet n : tetH (n-1)

    fib :: Integer -> Integer
    fib 0 = 0
    fib 1 = 1
    fib n = fib' (n-2) 0 1
        where fib' 0 x y = x + y
              fib' i x y = fib' (i-1) y (x+y)


    pad :: Integer -> Integer
    pad 0 = 1
    pad 1 = 0
    pad 2 = 0
    pad n = pad' (n-2) 1 0 0
        where pad' 0 x y z = z
              pad' i x y z = pad' (i-1) y z (y+x) 
              
    pell :: Integer -> Integer
    pell 0 = 0
    pell 1 = 1
    pell n = pell' (n-2) 0 1
         where pell' 0 x y = x + 2*y
               pell' i x y = pell' (i-1) y (2*y + x) 

    jac :: Integer -> Integer
    jac 0 = 0
    jac 1 = 1
    jac n = jac' (n-2) 0 1
            where jac' 0 x y = 2*x + y
                  jac' i x y = jac' (i-1) y (2*x + y)

    tri :: Integer -> Integer
    tri 0 = 0
    tri 1 = 0
    tri 2 = 1
    tri n = tri' (n-2) 0 0 1
            where tri' 0 x y z = z
                  tri' i x y z = tri' (i-1) y z (x+y+z)

    tet :: Integer -> Integer
    tet 0 = 0
    tet 1 = 0
    tet 2 = 0
    tet 3 = 1
    tet n = tet' (n-2) 0 0 0 1
            where tet' 0 w x y z = y
                  tet' i w x y z = tet' (i-1) x y z (w+x+y+z)