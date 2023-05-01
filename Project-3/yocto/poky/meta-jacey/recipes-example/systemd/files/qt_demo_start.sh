#!/bin/sh

start() {
    /usr/bin/HelloWorldService  & /usr/bin/HelloWorldClient

}

stop() {
    /usr/bin/killall QtDemo
}

case "$1" in
    start|restart)
        echo "Starting QtDemo"
        stop
        start
        ;;
    stop)
        echo "Stopping QtDemo"
        stop
        ;;
esac
