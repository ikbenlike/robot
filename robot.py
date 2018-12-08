class Switcharoo:
    def __init__(self):
        pass

    def dispatcher(self, nr):
        method_name = "opt_" + str(nr)
        method = getattr(self, method_name, lambda: "Not a direction")
        return method()

    def opt_1(self):
        return "RIGHT"

    def opt_2(self):
        return "LEFT"

    def opt_3(self):
        return "ADVANCE"

def translate(str):
    for l in str:
        a = Switcharoo()
        b = system(f"./translate {l}")
        c = a.dispatcher(b)
        system(f"./scripts/movement.sh {c}")