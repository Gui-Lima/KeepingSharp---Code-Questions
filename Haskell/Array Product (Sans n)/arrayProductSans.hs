module ArrayProductSansN.Kata (productSansN) where

    productSansN :: [Integer] -> [Integer]
    productSansN n = util2 (product n) n 0
 
    util2 :: Integer -> [Integer] -> Integer -> [Integer]
    util2 _ [] _ = []
    util2 mult n@(x:xs) index
                                | index == (fromIntegral (length n)) = util2 0 [] 0
                                | n!!(fromIntegral index) == 0 = product (deleteAt index n) : util2 mult n (index + 1)
                                | otherwise = quot mult (n!!(fromIntegral index)) : util2 mult n (index + 1)
    
    deleteAt :: Integer -> [Integer] -> [Integer]
    deleteAt idx xs = lft ++ rgt
            where (lft, (_:rgt)) = splitAt (fromIntegral idx) xs