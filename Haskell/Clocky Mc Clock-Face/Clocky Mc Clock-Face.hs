module Kata.ClockyMcClockFace (whatTimeIsIt) where

    whatTimeIsIt :: Float -> String
    whatTimeIsIt angle
                        | angle < 5 = (show (hours+12)) ++ ":0" ++ (show minutes)
                        | angle < 30 = (show (hours+12)) ++ ":" ++ (show minutes)
                        | hours < 10 && minutes >= 10 =  "0" ++ ( show hours ) ++ ":" ++ (show minutes)
                        | hours >= 10 && minutes < 10 = (show hours) ++ ":0" ++ (show minutes)
                        | hours >= 10 && minutes >= 10 = (show hours) ++ ":" ++ (show minutes)
                        | hours < 10 && minutes < 10 = "0" ++ (show hours) ++ ":0" ++ (show minutes)
                        where hours = mod (floor ((angle*2)/60)) 13
                              minutes = mod (floor (angle*2)) 60
