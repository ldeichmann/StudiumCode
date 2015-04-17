#!/usr/bin/env python3

## config

#machines = ['192.168.0.10', '192.168.0.13'] #shepard, chromecast
machines = ['12:34:56:78:90:ab']
##
import os, nmap

def ping(host):
	return os.system("ping -c 1 " + host)

def main():
	up = False
	nm = nmap.PortScanner()
	nm.scan('192.168.0.10-20', arguments='-O')
	for h in nm.all_hosts():
		if 'mac' in nm[h]['addresses']:
#			print(nm[h]['addresses']['mac'], nm[h]['vendor'])
			if nm[h]['addresses']['mac'] in machines:
#				print(nm[h]['addresses']['mac'], "is up")
				up = True
				break

	if up == False:
		hibernate()


def hibernate():
	os.system("systemctl suspend")
	#print("systemctl suspend")

if __name__ == "__main__":
    main()