function run(){
    a=$(gforth -e "s\" $1\"" ./forths/translate.forth -e "move-to-number bye")
    case $a in
        "10"*) return 10;;
        "20"*) return 20;;
        "30"*) return 30;;
        "40"*) return 40;;
    esac
}

run $1
exit $?