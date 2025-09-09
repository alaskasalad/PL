fFunc :: Int -> Int
fFunc x = 2 * x 

add:: Int -> Int -> Int
add x y = x + y

gFunc :: Int -> Int
gFunc x = x + 5 

main :: IO()
main = do
    print(fFunc(gFunc(4))) -- 18
    print(fFunc (gFunc 4)) -- 18
    print( add 3 (fFunc 5)) -- 13 