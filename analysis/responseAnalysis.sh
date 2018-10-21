#!/bin/bash
cat $1 | grep -aEo "[0-9]+\.[0-9]+ ms$" | cut -d" " -f1 | awk '{printf("%d,%s\n",NR,$0)}' | python3 plot.py