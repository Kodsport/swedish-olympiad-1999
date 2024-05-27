#!/usr/bin/python3
import sys
from sys import stdin
import re
entire_regex = re.compile("^[A-Z]{1,26}$")
line1 = stdin.readline()
assert entire_regex.match(line1), "First line does not consist of alpha string" 
assert len(line1) == len(set(line1)), "Multiple chars of the same type"
sys.exit(42)

