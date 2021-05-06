import os
# create build folder if needed
if os.path.isdir('../build'):	
	os.system('mkdir build')

os.system('cd ..')
os.system('cmake -S . -B build -G Ninja')
os.system('cmake --build build')