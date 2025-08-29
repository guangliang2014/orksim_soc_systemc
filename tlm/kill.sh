#!/bin/bash

# 一键kill所有 simple-soc 和 xterm 进程

for pname in simple-soc xterm; do
    pids=$(pgrep "$pname")
    if [ -n "$pids" ]; then
        echo "Killing $pname: $pids"
        kill $pids
    else
        echo "No $pname process found."
    fi
done