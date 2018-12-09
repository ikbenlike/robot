: turn-right ( n -- )
    20 + 50 mod dup 0=
    if
        drop 20 .
    else
        .
    then ;