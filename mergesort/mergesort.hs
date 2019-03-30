-- Author: Fernando de Jesús Soto

mergesort :: Ord a => [a] -> [a]
mergesort [] = []
mergesort [x] = [x]
mergesort xs = merge (mergesort xs')  (mergesort xs'')
    where (xs', xs'') = halfs xs

merge :: Ord a => [a] -> [a] -> [a]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys)
    | x < y = x : merge xs (y:ys)
    | otherwise = y : merge (x:xs) ys

halfs :: [a] -> ([a], [a])
halfs [] = ([], [])
halfs xs = (take mid xs, drop mid xs)
    where mid = length xs `div` 2
