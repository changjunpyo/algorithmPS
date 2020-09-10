class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        h1, h2 = {}, {}
        A, B = 0, 0
        for idx, val in enumerate(secret):
            if h1.get(val, -1) == -1:
                h1[val] = 0
            if h2.get(guess[idx], -1) == -1:
                h2[guess[idx]] = 0
            h1[val] += 1
            h2[guess[idx]] += 1
            if secret[idx] == guess[idx]:
                A += 1
        for k, v in h1.items():
            if h1.get(k, -1) > 0 and h2.get(k, -1) > 0:
                B += min(h1[k], h2[k])

        return str(A) + "A" + str(B-A) + "B"
