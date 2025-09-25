-- Assignment Haskell, Caitlin Box 
-- made 9/25/25 

-- short pi: 
-- just returning a double, using atan for the arctan 
shortPi :: Double
shortPi = 16 * atan (1/5) - 4 * atan (1/239)

-- Simple Pi:
-- i had to change how many times it summed up bc it wasn't as accurate(for the rest too)
simplePi :: Double
simplePi = 4 * sum [((-1) ^ (x+1)) / fromIntegral (2*x - 1) | x <- [1..700]]

-- Wells Pi
-- taking the sum of the formula given, 8 will be moved over first then square root 
wellsPi :: Double
wellsPi = sqrt (8 * sum [1 / (2*x -1)^2 | x <- [1..200]])

-- Euler Pi
-- going from 1 to 600, i will sum up 1 over x^2 then * 6 
eulerPi :: Double
eulerPi = sqrt (6 * sum [1/x^2 | x <- [1..600]])

-- Wallis Formula 
-- from 1 to 500, ill do the product of each iteration then * 2 
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
