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

from os import *
def translate(str):
    for l in str:
        a = Switcharoo()
        b = system(f"./bin/translate {l}")
        c = a.dispatcher(b)
        system(f"./scripts/movement.sh {c}")

from builtins import *
with open("data/command.text", "r") as f:
    translate(f.read())