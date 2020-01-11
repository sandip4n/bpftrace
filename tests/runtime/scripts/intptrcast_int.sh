#!/bin/sh

. $(dirname $0)/sarg.sh
sarg_expr=$(get_sarg_expr 0)
probe_expr="'uprobe:./testprogs/intptrcast:fn { \$a=*(uint16*)($sarg_expr); printf(\"%d\\n\", \$a); exit(); }'"
eval ../src/bpftrace -v -e $probe_expr
