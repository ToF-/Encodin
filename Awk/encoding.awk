#! /usr/bin/awk -f
/\([A-Z]\)\(\1{2,9}\)/    { print $0, length($2) }
