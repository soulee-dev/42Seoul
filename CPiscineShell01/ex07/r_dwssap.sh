#!/bin/sh
cat /etc/passwd | grep -v '\#' | awk 'NR%2==0' | cut -d ':' -f 1 | rev | sort -r | awk 'NR>=ENVIRON["FT_LINE1"] && NR <= ENVIRON["FT_LINE2"]' | xargs | sed 's/ /,/g' | sed 's/$/./' | tr -d '\n'
