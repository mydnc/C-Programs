The task is to develop a program that compares two given triangles in a 2D plane. The problem is an extension of the simple variant. This version accepts input triangles entered either by their vertices or by the lengths of their sides. Starting with the simple problem is highly recommended.

There are given two triangles in a 2D plane. Each triangle is defined either by its vertices or by the lengths of its sides:

triangle defined by its vertices is entered in the form of three coordinates. The three coordinates are enclosed in curly braces; individual coordinates are separated by commas. A coordinate consists of two decimal numbers separated by a semicolon, the two numbers are enclosed in square braces. An example:

    { [ 1.5; 2 ], [3;4.2], [ 0.5 ; 0.6 ] }

triangle defined by its sides is entered in the form of three decimal numbers. The three numbers are enclosed in curly braces and separated by commas. An example:

    {2.1, 3, 3.4}

Your program reads the triangles from the standard input. Next, the program decides one of the 4 cases:

    the input does not form a triangle (the three vertices defining the triangle are on a common line, or the sides do not obey triangle inequality),
    the triangles are identical,
    the triangles are not identical while their circumference is the same, or
    the triangles are entirely different.

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below), and terminate. If displayed, the error message must be sent to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The input is considered invalid, if:

    the coordinates or sides are invalid (are not valid decimals),
    some coordinate(s) or sides are missing,
    there are missing some separators (braces, commas, semicolons).

Sample program runs:
------------------------------------------------------------------------------------------------------------------
Triangle #1:
{[0;0],[5;0],[2.5;3]}
Triangle #2:
 { [ 4 ; -1 ] , [ 7 ; 1.5 ] , [ 4 ; 4 ] } 
The triangles are identical.
------------------------------------------------------------------------------------------------------------------
Triangle #1:
{
[
0
;
15
]
,	[	112	;	0	]	,[112;15]}
Triangle #2:
{96.0,40.0,104.0}
The triangles are not identical, however, they have the same circumference.
------------------------------------------------------------------------------------------------------------------
Triangle #1:
 { 10 , 15 , 10 } 
Triangle #2:
{12,8,17}
Triangle #2 has a longer circumference.
------------------------------------------------------------------------------------------------------------------
Triangle #1:
{[0;14.04],[11.2;0],[0;0]}
Triangle #2:
{[20.16;0],[0;2.7],[20.16;2.7]}
The triangles are not identical, however, they have the same circumference.
------------------------------------------------------------------------------------------------------------------
Triangle #1:
{[0.00;0.00],[0.24;0.70],[0.24;0.00]}
Triangle #2:
{0.65,0.78,0.25}
The triangles are not identical, however, they have the same circumference.
------------------------------------------------------------------------------------------------------------------
Triangle #1:
{51.09,49.49,4.94}
Triangle #2:
{37.92,50.11,17.49}
The triangles are not identical, however, they have the same circumference.
------------------------------------------------------------------------------------------------------------------
Triangle #1:
{[0;0],[10;0],[0;10]}
Triangle #2:
{[0;0],[10;10],[15;15]}
Invalid triangle.
------------------------------------------------------------------------------------------------------------------
Triangle #1:
{[10;0],[20;1],[25;1.5]}
Invalid triangle.
------------------------------------------------------------------------------------------------------------------
Triangle #1:
{1,2,3}
Invalid triangle.
------------------------------------------------------------------------------------------------------------------
Triangle #1:
{[0;0],[999.990;204.330],[899.991;183.897]}
Invalid triangle.
------------------------------------------------------------------------------------------------------------------
Triangle #1:
{1.923,59.240,61.163}
Invalid triangle.
------------------------------------------------------------------------------------------------------------------
Triangle #1:
{[1;2],[3;abcd],[7,9]}
Invalid input.
------------------------------------------------------------------------------------------------------------------