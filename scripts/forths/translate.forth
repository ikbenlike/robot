: 0compare ( s1 l1 s2 l2 -- n )
    compare 0= ;

: move-to-number ( s1 l1 -- )
    2dup s" N" 0compare
    if
        ." 10"
    else
    2dup s" S" 0compare
    if
        ." 20"
    else
    2dup s" E" 0compare
    if
        ." 30"
    else
    2dup s" W" 0compare
    if
        ." 40"
    else
        ." error"
    then then then then ;

\ move-to-number