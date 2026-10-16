#!/bin/bash
if [ ! -d "data_analysis" ]; then
    mkdir data_analysis
    echo "The folder was succesfully created"
fi
touch data_analysis/research_themes

awk -F',' '{print $3}' faculty_3.csv | tr '+' '\n' | sed 's/^[ \t]*//;s/[ \t]*$//' | grep -v '^$' | sort | uniq > data_analysis/research_themes
wc -l < data_analysis/research_themes >> data_analysis/research_themes

touch data_analysis/unique.txt

awk -F',' '$3 !~ /\+/ {print $0}' faculty_3.csv > data_analysis/unique.txt

touch data_analysis/joined.csv

awk -F',' '$3 ~ /Computational Education/ && $3 ~ /Computer Systems/ {print $0}' faculty_3.csv > data_analysis/joined.csv

touch data_analysis/names.txt

awk -F',' '{ if (split($3, a, "+") >= 3) print $1}' faculty_3.csv > data_analysis/names.txt

