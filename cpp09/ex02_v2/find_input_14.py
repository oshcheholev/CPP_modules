#!/usr/bin/env python3
import subprocess, random, sys, re, time

# Try to find a permutation of 1..14 that makes ./PmergeMe report 37 comparisons.
# Adjust ITERATIONS if you want a longer/shorter search.
ITERATIONS = 20000
BIN = './PmergeMe'
TARGET = 37

pattern = re.compile(r"Total comparisons:\s*(\d+)")
random.seed(12345)
start = time.time()
for i in range(1, ITERATIONS+1):
    perm = list(range(1,15))
    random.shuffle(perm)
    args = [BIN] + [str(x) for x in perm] + ['--debug']
    try:
        p = subprocess.run(args, cwd='.', stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=6)
    except Exception as e:
        print('Run error:', e, file=sys.stderr)
        continue
    out = p.stdout.decode('utf-8', errors='ignore')
    m = pattern.search(out)
    if not m:
        # if parsing failed, print a short diagnostic every 1000 iterations
        if i % 1000 == 0:
            print('No parse at iter', i, 'exit', p.returncode, file=sys.stderr)
        continue
    comps = int(m.group(1))
    if comps == TARGET:
        print('FOUND in iter', i)
        print('Sequence:', ' '.join(str(x) for x in perm))
        # print the full program output for inspection
        print('\n--- program output ---\n')
        print(out)
        print('elapsed', time.time()-start)
        sys.exit(0)
    if i % 1000 == 0:
        print('iter', i, 'last comps', comps)

print('Not found after', ITERATIONS, 'iterations, elapsed', time.time()-start)
sys.exit(2)
