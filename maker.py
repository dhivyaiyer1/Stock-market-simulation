import glob

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