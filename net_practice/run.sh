#!/usr/bin/env bash

myport='49242'

if command -v ss >/dev/null 2>&1; then
	for port in $(seq 49152 65535); do
		if ! ss -lnt | grep -q ":$port "; then
			myport=$port
			break
		fi
	done
else
    echo "ss not available, using port 49242."
fi


if command -v xdg-open >/dev/null 2>&1; then
	echo "Netpractice server is starting, web browser will open."
	( sleep 2 ; xdg-open "http://localhost:$myport" >/dev/null 2>&1 || true ) &
else
	if command -v open >/dev/null 2>&1; then
		echo "Netpractice server is starting, web browser will open."
		( sleep 2 ; open "http://localhost:$myport" >/dev/null 2>&1 || true ) &
	else
		echo "Netpractice server is starting. Open your web browser with URL: http://localhost:$myport"
	fi
fi

echo "Type Ctrl-C to shutdown the server."

python3 -m http.server $myport
