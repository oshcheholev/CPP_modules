#!/usr/bin/env python3
import subprocess, random, sys, re, time, math

BIN = './PmergeMe'
pattern = re.compile(r"Total comparisons:\s*(\d+)")

# Default starting sequence (the one you ran earlier)
start_seq = [3,5,6,9,1,43,12,4,8,987,654,75,88,19]

def comps_for(seq):
    args = [BIN] + [str(x) for x in seq] + ['--debug']
    p = subprocess.run(args, cwd='.', stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=6)
    out = p.stdout.decode('utf-8', errors='ignore')
    matches = pattern.findall(out)
    if not matches:
        return None, out
    # take last occurrence
    comps = int(matches[-1])
    return comps, out

random.seed(42)
# parameters
ITER = 20000
T0 = 1.0
cooling = 0.9995

cur = list(start_seq)
cur_comps, _ = comps_for(cur)
if cur_comps is None:
    print('Failed to parse comps for start sequence', file=sys.stderr)
    sys.exit(2)
best = list(cur)
best_comps = cur_comps
print('Start comps', cur_comps)
start_time = time.time()
T = T0
for i in range(1, ITER+1):
    # propose swap of two positions
    a,b = random.sample(range(len(cur)), 2)
    cand = list(cur)
    cand[a], cand[b] = cand[b], cand[a]
    cand_comps, _ = comps_for(cand)
    if cand_comps is None:
        continue
    delta = cand_comps - cur_comps
    accept = False
    if cand_comps <= cur_comps:
        accept = True
    else:
        # simulated annealing acceptance
        if random.random() < math.exp(-delta / max(1e-9, T)):
            accept = True
    if accept:
        cur = cand
        cur_comps = cand_comps
    if cand_comps < best_comps:
        best = cand
        best_comps = cand_comps
        print('New best at iter', i, 'comps', best_comps, 'seq', ' '.join(str(x) for x in best))
    # stop immediately if we find a sequence with exactly the target 37 comparisons
    if cand_comps == 37:
        print('\nFOUND sequence with 37 comparisons at iter', i)
        print('Sequence:', ' '.join(str(x) for x in cand))
        _, out = comps_for(cand)
        print('\n--- program output ---\n')
        print(out)
        print('elapsed', time.time()-start_time)
        sys.exit(0)
    # cool down
    T *= cooling
    if i % 100 == 0:
        print('iter', i, 'cur', cur_comps, 'best', best_comps, 'T', T)

print('Done. best_comps', best_comps, 'best_seq', ' '.join(str(x) for x in best), 'elapsed', time.time()-start_time)
sys.exit(1)
