#!/bin/bash
awk '{for(i = 1; i <= NF; i++){data[NR][i] = $i;}} END {for(i = 1; i <= NF; i++){for(j = 1; j <= NR; j++) {printf("%s%c", data[j][i],j == NR ? "\n": " ")}}}' file.txt
