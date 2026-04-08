#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution js.cc

compile gen_rand.py

samplegroup
sample sample01

group group1 100
include_group sample
tc g1-1 gen_rand n=1
tc g1-2 gen_rand n=2
tc g1-3 gen_rand n=3
tc g1-4 gen_rand n=4
tc g1-5 gen_rand n=10
tc g1-6 gen_rand n=20
tc g1-7 gen_rand n=26
tc_manual test01
tc_manual test02
tc_manual test03
