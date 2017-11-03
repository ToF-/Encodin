#ENCONDIN - Run Length Encoding

http://www.spoj.com/problems/ENCONDIN/

Your task is to write a program that performs a simple form of run-length encoding, as described by the rules below.

Any sequence of between 2 to 9 identical characters is encoded by two characters. The first character is the length of the sequence, represented by one of the characters 2 through 9. The second character is the value of the repeated character. A sequence of more than 9 identical characters is dealt with by first encoding 9 characters, then the remaining ones.

Any sequence of characters that does not contain consecutive repetitions of any characters is represented by a 1 character followed by the sequence of characters, terminated with another 1. If a 1 appears as part of the sequence, it is escaped with a 1, thus two 1 characters are output.

##Input Specification

The input consists of letters (both upper- and lower-case), digits, spaces, and punctuation. Every line is terminated with a newline character and no other characters appear in the input.

##Output Specification

Each line in the input is encoded separately as described above. The newline at the end of each line is not encoded, but is passed directly to the output.

##Sample Input

    AAAAAABCCCC
    12344

##Sample Output

    6A1B14C
    11123124
