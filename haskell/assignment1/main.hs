-- Assignment Haskell, Caitlin Box 
-- made 9/25/25 

-- short Pi, just did this to practice before the others
shortPi :: Double
shortPi = 16 * atan (1/5) - 4 * atan (1/239)

-- Simple Pi:
-- i had to change how many times it summed up bc it wasn't as accurate
simplePi :: Double
simplePi = 4 * sum [((-1) ^ (x+1)) / fromIntegral (2*x - 1) | x <- [1..700]]

-- Wells Pi
wellsPi :: Double
wellsPi = sqrt (8 * sum [1 / (2*x -1)^2 | x <- [1..200]])

-- Euler Pi
-- i had to change how many times it summed up bc it wasn't as accurate
eulerPi :: Double
eulerPi = sqrt (6 * sum [1/x^2 | x <- [1..600]])

-- Wallis Formula 
-- i had to change how many times it summed up bc it wasn't as accurate
wallisFormula :: Double
wallisFormula = 2 * product [(2*x)^2 / ((2*x -1)*(2*x +1)) | x <- [1..500]]

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
