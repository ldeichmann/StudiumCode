#!/bin/bash
echo "changing keyboard layout"
# sleep 5
setxkbmap -layout us -option caps:escape
setxkbmap -layout de -option caps:escape
setxkbmap -option grp:switch,grp:ctrl_alt_toggle us,de
