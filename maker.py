import glob
import sys
import subprocess

run = False

if len(sys.argv)>1:
    arg1 = sys.argv[1].lower()
    if arg1 == "r" or arg1 == "run":
        run = True

# find all cpp files in this directory
cpp_files = glob.glob("*.cpp")
cpp_files = [file[:-4] for file in cpp_files]

print("Found .cpp files:")
for file in cpp_files:
    print(file)

# write Makefile
with open("Makefile", "w") as makefile:
    makefile.write("CXX = g++\n")
    makefile.write("CXXFLAGS = -std=c++2a -O0 -ggdb3\n\n")
    makefile.write("all: clean stockmarket\n\n")
    makefile.write("stockmarket:")
    for file in cpp_files:
        makefile.write(" "+file)
    makefile.write("\n\t$(CXX) $(CXXFLAGS) -o stockmarket")
    for file in cpp_files:
        makefile.write(" "+file+".o")
    makefile.write("\n\n")
    for file in cpp_files:
        makefile.write(file+": "+file+".cpp\n")
        makefile.write("\t$(CXX) $(CXXFLAGS) -c "+file+".cpp\n\n")
    makefile.write("clean:\n")
    makefile.write("\trm -rf *o stockmarket")

if run:
    # Run make command
    make_result = subprocess.run(['make'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    # Check if the make command was successful
    if make_result.returncode == 0:
        print("Makefile executed successfully")
        print("Output:")
        print(make_result.stdout.decode())
        # Run the executable file
        exe_result = subprocess.run(['./stockmarket'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

        # Check if the execution was successful
        if exe_result.returncode == 0:
            print("Execution of stockmarket succeeded")
            print("Output:")
            print(exe_result.stdout.decode())
        else:
            print("Execution of stockmarket failed")
            print("Error:")
            print(exe_result.stderr.decode())
    else:
        print("Makefile execution failed")
        print("Error:")
        print(make_result.stderr.decode())
