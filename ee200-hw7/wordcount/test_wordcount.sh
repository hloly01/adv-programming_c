#! /bin/bash

# Put whatever tests you want here, e.g., 
# echo "words, words, words" | ./wordcount
# to run: chmod +x test_wordcount.sh
./wordcount test_wc.tsv
wc test_wc.tsv
echo " "
./wordcount -c test_wc.tsv
wc -c test_wc.tsv
echo ""
./wordcount -c -w test_wc.tsv
wc -c -w test_wc.tsv
echo ""
./wordcount -l -c -w test_wc.tsv
wc -l -c -w test_wc.tsv
echo ""
./wordcount -w -l -c test_wc.tsv
wc -w -l -c test_wc.tsv
echo ""
./wordcount ../README.md
wc ../README.md
echo ""
./wordcount -w ../README.md 
wc -w ../README.md 
echo ""
./wordcount
echo ""
./wordcount -a
echo ""
wc -a


