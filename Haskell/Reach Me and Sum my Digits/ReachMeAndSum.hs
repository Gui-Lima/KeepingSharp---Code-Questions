module Codewars.G964.Sumdignth where

    sumDigNthTerm :: Int -> [Int] -> Int -> Int
    sumDigNthTerm initval patternl nthTerm =  sumOfDigits ( initval + (howManyTimesSum (nthTerm-1) (length patternl) * sum patternl) + (sum (drop (elementToSumUntil (nthTerm-1) (length patternl)) (reverse patternl) )))

    howManyTimesSum :: Int -> Int -> Int
    howManyTimesSum _ 0 = 0
    howManyTimesSum n m = floor((fromIntegral n)/(fromIntegral m))

    elementToSumUntil :: Int -> Int -> Int
    elementToSumUntil _ 0 = 0
    elementToSumUntil n m = m - (mod n m)

    sumOfDigits:: Int -> Int
    sumOfDigits 0 = 0
    sumOfDigits x = (x `mod` 10) + sumOfDigits (x `div` 10)


    -- First get the last number and do a -1
    -- now do x = (new Last Number) / arraySize
    -- x is how many times the sum of Array will be counted
    -- now do y = (new Last Number) mod arraySize
    -- y is now how many numbers to sum in the array
    -- now firstNumber + (x * sum) + (sum array[0:y]) is the result
    -- now sum Digits of result
