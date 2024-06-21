# will re writes the for_each.h to support upto amount

amount = 1024

with open("for_each.h", "w") as h:
    h.write("""// dont worry all of this will be removed by the complier
#define FE_0(WHAT)
#define FE_1(WHAT, X) WHAT(X)
""")
    for i in range(1, amount):
        h.write(f"""#define FE_{i+1}(WHAT, X, ...) WHAT(X)FE_{i}(WHAT, __VA_ARGS__)\n""")
    h.write(f"""
#define GET_MACRO({','.join(['_'+str(x) for x in range(0, amount)])},NAME,...) NAME 
#define FOR_EACH(action,...) GET_MACRO(_0,__VA_ARGS__,{','.join(['FE_'+str(x) for x in reversed(range(0, amount))])})(action,__VA_ARGS__)
""")
    h.write("""// dont worry all of this will be removed by the complier
#define NO_FE_0(WHAT)
#define NO_FE_1(WHAT, X) WHAT
""")
    for i in range(1, amount):
        h.write(f"""#define NO_FE_{i+1}(WHAT, X, ...) WHAT NO_FE_{i}(WHAT, __VA_ARGS__)\n""")
    h.write(f"""
#define FOR_EACH_COUNT(action, ...) GET_MACRO(_0,__VA_ARGS__,{','.join(['NO_FE_'+str(x) for x in reversed(range(0, amount))])})(action,__VA_ARGS__)
""")