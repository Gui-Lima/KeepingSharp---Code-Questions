module Codewars.G964.Braking where

    dist :: Double -> Double -> Double
    dist v mu = velocityInMS + (velocityInMS**2) / (2 * mu * 9.81)
                where velocityInMS = (v*0.277778)
    
    speed :: Double -> Double -> Double
    speed d mu =  (sqrt(((2 * d * 9.81 * mu)) + ((9.81 ** 2) * (mu ** 2))) - (9.81* mu)) * 3.6

