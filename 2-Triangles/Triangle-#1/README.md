The task is to develop a program that compares two given triangles in a 2D plane.

There are given two triangles in a 2D plane. Each triangle is defined by three vertices (i.e., there is a total of 6 vertices in the input). The vertices are described by their coordinates (pairs of decimal numbers). Your program reads the coordinates from the standard input. Next, the program decides one of the 4 cases:

    the input vertices do not form a triangle (the three vertices defining the triangle are on a common line),
    the triangles are identical,
    the triangles are not identical while their circumference is the same, or
    the triangles are entirely different.

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below), and terminate. If displayed, the error message must be sent to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The input is considered invalid, if:

    the coordinates are invalid (are not valid decimals),
    some coordinate(s) are missing.

Sample program runs:
------------------------------------------------------------------------------------------------------------------
    Triangle #1:
    Vertex A:
    0 0
    Vertex B:
    5 0
    Vertex C:
    2.5 3
    Triangle #2:
    Vertex A:
    4 -1
    Vertex B:
    7 1.5
    Vertex C:
    4 4
    The triangles are identical.
------------------------------------------------------------------------------------------------------------------
    Triangle #1:
    Vertex A:
    0


    15
    Vertex B:
    112 0 112 15
    Vertex C:
    Triangle #2:
    Vertex A:
    0 0
    Vertex B:
    96 0
    Vertex C:
    0 40
    The triangles are not identical, however, they have the same circumference.
------------------------------------------------------------------------------------------------------------------
    Triangle #1:
    Vertex A:
    0 0
    Vertex B:
    10 0
    Vertex C:
    0 10
    Triangle #2:
    Vertex A:
    -5 3
    Vertex B:
    12 8
    Vertex C:
    37 15
    Triangle #2 has a longer circumference.
------------------------------------------------------------------------------------------------------------------
    Triangle #1:
    Vertex A:
    0 14.04
    Vertex B:
    11.2 0
    Vertex C:
    0 0
    Triangle #2:
    Vertex A:
    20.16 0
    Vertex B:
    0 2.7
    Vertex C:
    20.16 2.7
    The triangles are not identical, however, they have the same circumference.
------------------------------------------------------------------------------------------------------------------
    Triangle #1:
    Vertex A:
    0 0
    Vertex B:
    10 0
    Vertex C:
    0 10
    Triangle #2:
    Vertex A:
    0 0
    Vertex B:
    10 10
    Vertex C:
    15 15
    The points do not form a triangle.
------------------------------------------------------------------------------------------------------------------
    Triangle #1:
    Vertex A:
    10 0
    Vertex B:
    20 1
    Vertex C:
    25 1.5
    The points do not form a triangle.
------------------------------------------------------------------------------------------------------------------
    Triangle #1:
    Vertex A:
    0 0
    Vertex B:
    999.990 204.330
    Vertex C:
    899.991 183.897
    The points do not form a triangle.
------------------------------------------------------------------------------------------------------------------
    Triangle #1:
    Vertex A:
    1 2
    Vertex B:
    3 abcd
    Invalid input.
------------------------------------------------------------------------------------------------------------------