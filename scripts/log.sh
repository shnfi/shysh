#!/bin/bash

log_type=$(echo $1)
new_log=$(echo $2)
log_num=$(cat CHANGELOG.md | wc -l)

echo "<p>[$log_num] [$log_type] - $new_log</p>" >> CHANGELOG.md
