import sys
N, L = map(int, input().split())
names = [input() for _ in range(N)]

for i in range(L):
    name = list(names[0])
    for ch in range(ord('A'), ord('Z') + 1):
        name[i] = chr(ch)
        cand = "".join(name)

        ok = True
        for nm in names:
            diff = 0
            for k in range(L):
                if cand[k] != nm[k]:
                    diff += 1
                    if diff > 1:
                        ok = False
                        break
            if not ok:
                break
        
        if ok:
            print(cand)
            sys.exit()

print("CALL FRIEND")
