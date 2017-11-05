import Data.Char (intToDigit,digitToInt)
import Data.List (group)

process = interact (unlines . map encode . lines)

data Enclosing = Out | In

encode :: String -> String
encode = enclose Out . concatMap run_length . group 
    where
    run_length s | length s <= 9 = intToDigit (length s) : head s : []
                 | otherwise     = '9':head s : run_length (drop 9 s)

    enclose In   []       = '1' : []
    enclose Out  []       = []
    enclose Out ('1':c:s) = '1' : enclose In ('1':c:s)
    enclose Out (n:c:s)   = n : c : enclose Out s
    enclose In  ('1':'1':s) = '1':'1': enclose In s
    enclose In  ('1':c:s) = c : enclose In s 
    enclose In  s         = '1' : enclose Out s

main = process
