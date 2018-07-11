
def pushDominoes(dominoes):
    symbols = [(i, x) for i, x in enumerate(dominoes) if x != '.']
    symbols = [(-1, 'L')] + symbols + [(len(dominoes), 'R')]
    print zip(symbols,symbols[1:])
    ans = list(dominoes)

    for (i, x), (j, y) in zip(symbols, symbols[1:]):
        if x == y:
            for k in xrange(i+1, j):
                ans[k] = x
        elif x > y: #RL
            for k in xrange(i+1, j):
                ans[k] = '.LR'[cmp(k-i, j-k)]

    return "".join(ans)


dominoes="R.R.L"
print pushDominoes(dominoes)
