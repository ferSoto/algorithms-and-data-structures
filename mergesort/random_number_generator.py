#!/usr/bin/env python

"""
Prints random numbers from 0 to 100000.

Example:
    python random_number_generator.py 1000 > output.txt
"""

import random
import sys

# -2147483646, 2147483647
for _ in range(int(sys.argv[1])):
    print(random.randint(0, 100000), end=' ')
print()
