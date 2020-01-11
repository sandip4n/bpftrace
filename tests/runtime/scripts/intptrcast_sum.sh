#!/bin/sh

. $(dirname $0)/sarg.sh
sarg_expr=$(get_sarg_expr 0)
probe_expr="'uprobe:./testprogs/intptrcast:fn { @=sum(*(uint16*)($sarg_expr)); exit(); }'"
eval ../src/bpftrace -v -e $probe_expr
