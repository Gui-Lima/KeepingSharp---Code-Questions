module Primorial where 
    numPrimorial :: Int -> Integer
    numPrimorial n = product (take n primes)

    primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53]