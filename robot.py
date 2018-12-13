class Switcharoo:
    def __init__(self):
        pass

    def dispatcher(self, nr):
        method_name = "opt_" + str(nr)
        method = getattr(self, method_name, lambda: "Not a direction")
        return method()

    def opt_256(self):
        return "RIGHT"

    def opt_512(self):
        return "LEFT"

    def opt_768(self):
        return "ADVANCE"

class Const:
    S=' '
    MAGIC='THIS IS A NOT SERIOUS THING PLEASE STOP WORRYING'
    MAGICS={str(k):v for k,v in enumerate(MAGIC)}

from os import *
def translate(str):
    for l in str:
        a = Switcharoo()
        try:#use the new f-strings because it's cool
        	b = system(eval('f"./bin/translate {l}"'))
        except Exception:#if don't work use the old
        	b = system(Const.S.join(['./bin/translate', l]))
        c = a.dispatcher(b)
        try:#same thing here see above
        	system(eval('f"./scripts/movement.sh {c}"'))
        except Exception:
        	system("./scripts/movement.sh" + Const.S + c)
    with open("data/data.xml", "r") as f:
        count = 0
        for l in f:
            if count == 0:
                count = count ** count
            elif count and count <3 :
                count = count + count / count
                print(l.split('>')[1].split('<')[0], end=Const.S)
            elif count==3:
                print(Const.MAGICS[l.split('>')[1][:2]], end='')
from builtins import * # fix open()
with open("data/command.text", "r") as f:
    translate(f.read())