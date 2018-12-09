if [ $1 = "RIGHT" ]; then
    a=$(sbcl --script scripts/lissp/extract.lisp D)
    b=$(gforth -e "$(echo $a)" scripts/forths/move_right.forth -e "turn-right bye")
    a=$b
    bash -c "bin/genxml $(sbcl --script scripts/lissp/extract.lisp X) $(sbcl --script scripts/lissp/extract.lisp Y) $a"
fi

if [ $1 = "LEFT" ]; then
$0 RIGHT; $0 RIGHT; $0 RIGHT;
fi

if [ $1 = "ADVANCE" ]; then
bash -c 'bin/a*'
fi
