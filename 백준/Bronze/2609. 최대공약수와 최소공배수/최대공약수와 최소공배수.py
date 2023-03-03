from sys import stdin
import math
if __name__ == "__main__":
    N, M = map(int,stdin.readline().split())

    print(math.gcd(N,M))
    print(math.lcm(N,M))