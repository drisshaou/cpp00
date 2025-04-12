# cpp00

ex02:

paste <(cut -c18- 1234.log) <(cut -c18- 19920104_091532.log) | awk -F'\t' '($1 != $2) { print "Diff: \nF1: " $1 "\nF2: " $2 }'