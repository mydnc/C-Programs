The task is to develop a program which prints out quotations.

The input of the program is an integer. The integer is in range 1 to 5 (inclusive). The value is an identifier of the quotation to print out.

The output of the program is a quotation. There is a total of 5 different quotations, the input value identifies the particular quotation to print out. The quotations are listed in the sample runs below. Please note the quotation is printed with newline character (\n) at the end.

The program must validate input data. If the input is invalid, the program detects it, outputs an error message and terminates. If displayed, the error message must be displayed on the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The input is considered invalid, if:

    the input number is not an integer or
    the input is an integer outside the 1 to 5 interval.

Sample program runs:
------------------------------------------------------------------------------------------------------------------
    ml' nob:
    1
    Qapla'
    noH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.
------------------------------------------------------------------------------------------------------------------
    ml' nob:
    2
    Qapla'
    Qu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.
------------------------------------------------------------------------------------------------------------------
    ml' nob:
    3
    Qapla'
    qaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.
------------------------------------------------------------------------------------------------------------------
    ml' nob:
    4
    Qapla'
    Ha'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.
------------------------------------------------------------------------------------------------------------------
    ml' nob:
    5
    Qapla'
    leghlaHchu'be'chugh mIn lo'laHbe' taj jej.
------------------------------------------------------------------------------------------------------------------
    ml' nob:
    0
    luj
------------------------------------------------------------------------------------------------------------------
    ml' nob:
    6
    luj
------------------------------------------------------------------------------------------------------------------
    ml' nob:
    abc
    luj
------------------------------------------------------------------------------------------------------------------