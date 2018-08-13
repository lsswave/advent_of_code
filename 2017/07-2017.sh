cat input-07-2017 | sed -E "s/\([0-9]+\)\ {0,}/\ /g; s/->/\ /g; s/,/\ /g; s/\ +/\ /g; s/\ $//g" | tr ' '  '\n' | sort | uniq -c | sort -r | tail -1
