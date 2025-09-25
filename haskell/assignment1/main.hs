-- Assignment Haskell, Caitlin Box 

-- short Pi:
shortPi :: Floating a => a
shortPi = 16 * atan (1/5) - 4 * atan (1/239)

-- Simple Pi:
simplePi = 4 * sum [((-1) ^ x+1) / fromIntegral (2*x - 1) | x <- [1..1000000]]

-- Wells Pi

-- Euler Pi 
eulerPi = sqrt (6 * sum [1/x^2 | x <- [1..1000000]])

-- Wallis Formula 

main :: IO()
main = do
    putStrLn "Simple Pi"
    print simplePi
    putStrLn ""

    putStrLn "Wells Pi"
    putStrLn ""

    putStrLn "short Pi"
    print shortPi
    putStrLn ""

    putStrLn "euler Pi"
    print eulerPi
    putStrLn ""

    putStrLn "wallisSum Pi"
    putStrLn ""
