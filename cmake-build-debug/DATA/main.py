from os import listdir
from math import log2
from json import dumps

results = {}

for file in listdir('.'):
    fs = open(file, 'rb').read()
    size = len(fs)
    data = {}
    for char in fs:
        if char not in data.keys():
            data[char] = 1
        else:
            data[char] += 1
    H = 0
    for char in data.keys():
        w = data[char] / size
        H -= w * log2(w)
    results[file] = H

with open('results.json', 'w') as fs:
    fs.write(dumps(results))
