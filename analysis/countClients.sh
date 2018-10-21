#!/bin/bash
cat $1 | grep -aEo "Client [0-9]+" | sort -u | tee /dev/tty > count
echo -n "Total Clients: ";cat count | wc -l
rm count