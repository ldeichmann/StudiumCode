#!/usr/bin/env python3

## config

machines = ['192.168.0.10', '192.168.0.13'] #shepard, chromecast

##
import os

def ping(host):
	return os.system("ping -c 1 " + host)

def main():
	up = False
	for host in machines:
		response = ping(host)
		print("host: ", host, "response", response)
		if response == 0:
			up = True
			break

	if up == False:
		hibernate()


def hibernate():
	#os.system("systemctl suspend")
	print("systemctl suspend")

if __name__ == "__main__":
    main()