-- Functions to get fizzbuzz

fizzbuzz :: [String]
fizzbuzz = map (toFizzBuzz) [1 .. 100]

toFizzBuzz :: Int -> String
toFizzBuzz x
    | (mod x 3 == 0) && (mod x 5 == 0) = "FizzBuzz"
    | mod x 3 == 0 = "Fizz"
    | mod x 5 == 0 = "Buzz"
    | otherwise = show x
