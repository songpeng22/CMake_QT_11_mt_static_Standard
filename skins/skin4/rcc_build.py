#rcc_build.py
import os
import sys

source_path = "skin"
source_name = "skin"
target_path = "../bin/"
target_name = "skin"
exe_path = "../../bin/"

# full path
current_path = os.path.dirname(sys.argv[0])
print( "os.path.dirName:",os.path.dirname(sys.argv[0]) )
qrcPath = os.path.join( current_path , "imagine-assets" ,"imagine-assets.qrc" )
print( "qrcPath:",qrcPath )
src_path = "\"" + qrcPath + "\""
tar_path = target_path +  "imagine-assets.rcc"
print("tar_path", ":",tar_path)
command = "rcc -binary " + src_path + " -o " + tar_path
print("command:",command)
ret = os.system( command )
print("rcc ret:",ret)
command2  = "cp " + tar_path + " " + exe_path + "imagine-assets.rcc"
print("command:",command2)
ret = os.system( command2 )
print("cp ret:",ret)

