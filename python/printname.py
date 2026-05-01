from os import listdir
from os.path import isfile, join

def printname(dir):
	for file in sorted(listdir(dir)):
		fullpath = join(dir, file)
		if isfile(fullpath):
			print(file)
		else:
			printname(fullpath)

printname("pics")
