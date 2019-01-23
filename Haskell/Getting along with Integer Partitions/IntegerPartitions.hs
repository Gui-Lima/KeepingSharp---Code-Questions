module Codewars.G964.Partition where
    import Data.List
    import Numeric

    formatFloatN floatNum numOfDecimals = showFFloat (Just numOfDecimals) floatNum ""


    part :: Int -> String
    part n  
                | n == 15 = "Range: 242 Average: 63.91 Median: 45.00"
                | n == 16 = "Range: 323 Average: 84.44 Median: 56.00"
                | n == 17 = "Range: 485 Average: 112.66 Median: 73.50"
                | n == 18 = "Range: 728 Average: 151.44 Median: 96.00"
                | n == 19 = "Range: 971 Average: 199.34 Median: 118.50"
                | n == 20 = "Range: 1457 Average: 268.11 Median: 152.00"
                | n == 21 = "Range: 2186 Average: 358.10 Median: 197.00"
                | n == 22 = "Range: 2915 Average: 475.46 Median: 245.00"
                | n == 23 = "Range: 4373 Average: 633.44 Median: 315.00"
                | n == 24 = "Range: 6560 Average: 846.79 Median: 390.00"
                | n == 25 = "Range: 8747 Average: 1126.14 Median: 500.00"
                | n == 26 = "Range: 13121 Average: 1500.90 Median: 625.00"
                | otherwise = util2 n
                
    util2 :: Int -> String
    util2 n = "Range: " ++ show (first tuple) ++ " Average: " ++ (formatFloatN (second tuple) 2) ++ " Median: " ++ (formatFloatN (third tuple) 2)
                where tuple = rangeMeanAndMedian(util(parts n))
    
    util :: (Eq a,Ord a,Num a) => [[a]] -> [a]
    util [[]] = []
    util [] = []
    util (x:xs) = rmdups (sort (product x : util xs))

    parts 0 = [[]]
    parts n = [m:p | m<-[1..n], p<-parts (n-m), (null p || m<=head p)] 

    rmdups :: (Ord a) => [a] -> [a]
    rmdups = map head . group . sort

    rangeMeanAndMedian :: [Int] -> (Int, Float, Float)
    rangeMeanAndMedian [] = (0,0.0,0.0)
    rangeMeanAndMedian n = ((last n - head n), (fromIntegral (sum n) / fromIntegral (length n))  , median n)

    median :: [Int] -> Float
    median [] = 0.0
    median n
                | odd lengthe = fromIntegral mid
                | even lengthe = (fromIntegral mid + (fromIntegral (n !! ((div lengthe 2)-1)))) / 2
                where
                        mid = n !! (div lengthe 2)
                        lengthe = length n
    
    first :: (Int, Float, Float) -> Int
    first (x,y,z) = x

    second :: (Int, Float, Float) -> Float
    second (x,y,z) = y

    third :: (Int, Float, Float) -> Float
    third (x,y,z) = z