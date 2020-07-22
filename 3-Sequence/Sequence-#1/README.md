The task is to develop a program that analyzes binary numbers from a given interval.

The input of the program consists of two integers. The integers define closed interval [ lo ; hi ]. Assume a string formed from all binary numbers from this interval, starting from the lower bound. The binary numbers form a sequence of zeros and ones. The program shall analyze the sequence and compute one of:

    -the overall length of the sequence (i.e., the total number of binary digits),
    -the number of zeros in the sequence,
    -the longest contiguous run of zeros in the sequence.

For example, input interval [10;20] defines binary sequence:

  1010 1011 1100 1101 1110 1111 10000 10001 10010 10011 10100

The sequence is 49 digits long, out of which, there is 22 zeros. The longest contiguous run of zeros is of length 4.

The input of the program is a pair of non-negative integers (i.e., positive or zero). The integers are enclosed in angle braces and delimited by a semicolon. The first integer defines the lower bound; the second is the upper bound. The lower bound must be less than or equal to the upper bound. Following the interval, there is one character. The character describes the computation required:

    -l to display the total length of the binary sequence (number of digits),
    -z to display the count of zeros in the sequence,
    -s to display the length of the longest contiguous run of zeros in the sequence.

The output of the program is the result of the desired computation. The exact output format is shown in the sample runs below.

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below), and terminate. If displayed, the error message must be sent to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The input is considered invalid, if:

    -the interval boundaries are invalid (are not valid integers),
    -the boundaries are negative, or
    -the lower bound is greater than the upper bound.
    -the required computation is not any of l, z, and s,
    -there are missing/redundant separators (angle brace, semicolon).

Sample program runs:
------------------------------------------------------------------------------------------------------------------
    Enter the interval:
    <0;11> l
    Digits: 34
------------------------------------------------------------------------------------------------------------------
    Enter the interval:
    <0;11> z
    Zeros: 14
------------------------------------------------------------------------------------------------------------------
    Enter the interval:
    <0;11> s
    Sequence: 3
------------------------------------------------------------------------------------------------------------------
    Enter the interval:
    <10;20> l
    Digits: 49
------------------------------------------------------------------------------------------------------------------
    Enter the interval:
    < 10 ; 20 > z
    Zeros: 22
------------------------------------------------------------------------------------------------------------------
    Enter the interval:
    <10;20>s
    Sequence: 4
------------------------------------------------------------------------------------------------------------------
    Enter the interval:
    <1492;2018> l
    Digits: 5797
------------------------------------------------------------------------------------------------------------------
    Enter the interval:
    <1123;2000> z
    Zeros: 4319
------------------------------------------------------------------------------------------------------------------
    Enter the interval:
    <1683;1999> s
    Sequence: 8
------------------------------------------------------------------------------------------------------------------
    Enter the interval:
    <4;4> l
    Digits: 3
------------------------------------------------------------------------------------------------------------------
    Enter the interval:
    <0;3> z
    Zeros: 2
------------------------------------------------------------------------------------------------------------------
    Enter the interval:
    <255;255> s
    Sequence: 0
------------------------------------------------------------------------------------------------------------------
    Enter the interval:
    <47;16> l
    Invalid input.
------------------------------------------------------------------------------------------------------------------
    Enter the interval:
    <23;asdf> z
    Invalid input.
------------------------------------------------------------------------------------------------------------------