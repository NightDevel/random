#!/usr/bin/python

import sys

if len(sys.argv) != 2:
    print "Usage: ", sys.argv[0], " number_of_submissions"
    sys.exit(0)

users = int(sys.argv[1])

print (80.0/(40+users))
