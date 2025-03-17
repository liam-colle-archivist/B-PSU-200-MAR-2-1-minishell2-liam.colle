#!/usr/bin/bash
## Vars:
# - array: (str[])
#  - array[0] = file
#  - array[1] = line
#  - array[2] = type
#  - array[3] = err_code

while IFS=': '; read -r -a array
do
    echo "::error file={${array[0]}},line={${array[1]}},endLine={${array[1]}},title={${array[2]} coding style error}::{${array[3]}}"
done < coding-style-reports.log

if [ -s coding-style-reports.log ]; then
    exit 1
else
    exit 0
fi
