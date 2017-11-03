module Encoding
where
import Data.List
import Data.Char    

encode :: String -> String
encode = normalize False
        . concatMap (uncurry run_length) 
        . map (\g -> (length g, head g)) 
        . group 
    where
    run_length n c | n < 10    = [intToDigit n,c]
                   | otherwise = run_length 9 c ++ run_length (n-9) c 
    normalize False [] = []
    normalize True  [] = '1' : []
    normalize False ('1':c:cs) = '1' : c   : normalize True  cs
    normalize False (n:c:cs)   = n   : c   : normalize False cs
    normalize True  ('1':'1':cs) = '1':'1' : normalize True  cs
    normalize True  ('1':c:cs) = c   :       normalize True  cs
    normalize True  (n:c:cs)   = '1' :       normalize False (c:cs)
