-- Assignment Haskell, Caitlin Box 
-- made 9/25/25 

-- short Pi:
shortPi :: Double
shortPi = 16 * atan (1/5) - 4 * atan (1/239)

-- Simple Pi:
simplePi :: Double
simplePi = 4 * sum [((-1) ^ (x+1)) / fromIntegral (2*x - 1) | x <- [1..1000000]]

-- Wells Pi
wellsPi :: Double
wellsPi = sqrt (8 * sum [1 / (2*x -1)^2 | x <- [1..1000000]])

-- Euler Pi 
eulerPi :: Double
eulerPi = sqrt (6 * sum [1/x^2 | x <- [1..1000000]])

-- Wallis Formula 
wallisFormula :: Double
wallisFormula = 2 * product [(2*x)^2 / ((2*x -1)*(2*x +1)) | x <- [1..1000000]]

main :: IO()
main = do
    putStrLn "Simple Pi"
    print simplePi
    putStrLn ""

    putStrLn "Wells Pi"
    print wellsPi
    putStrLn ""

    putStrLn "Short Pi"
    print shortPi
    putStrLn ""

    putStrLn "Euler Pi"
    print eulerPi
    putStrLn ""

    putStrLn "WallisSum Pi"
    print wallisFormula
    putStrLn ""
