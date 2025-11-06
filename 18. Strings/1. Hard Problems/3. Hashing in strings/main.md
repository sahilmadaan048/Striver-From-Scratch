// https://takeuforward.org/data-structure/hashing-in-strings

Hashing in Strings

Introduction

Need of Hashing
    - efficient comparisons
    - faster lookups
    - detect duplicates or anagrams
    - pattern matching

How does string hashing work ?

Hash(s) = (s[0] * p^0 + s[1] * p^1 + s[2] * p^2 + ... + s[n-1] * p^(n-1)) % m

these power values can be precomputed and thus later takes O(1) for each p^m value


Handling Collisions
    - to avoid collisions, we use a large m (like 1e9 + 7)
    - double hashing (combine two different hash functions) or  use a good base (p) that spreads values well

