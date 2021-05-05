
import os
# create build folder if needed
if os.path.isdir('build'):	
	os.system('mkdir build')

os.system('cmake -S . -B build -G "Visual Studio 16 2019" -A x64')
os.system('cmake --build build')