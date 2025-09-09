squares :: Float -> Float -> Float 
squares x y = x * x + y * y

main :: IO()
main = do
    putStrLn "hypothenus is"
    print(sqrt (squares 3 4)) -- sqrt works with floats 
    putStrLn("hypothenus is" ++ show(sqrt(squares 3 4)))
    