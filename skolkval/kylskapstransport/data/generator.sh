#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution kylskap_js.cc

samplegroup
sample 1

group group1 33
limits onlya=1
tc_manual t3

group group2 67
include_group sample
include_group group1
tc_manual t1
tc_manual t2
