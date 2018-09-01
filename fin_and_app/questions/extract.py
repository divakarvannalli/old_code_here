import os

input="/home/user/Desktop/fin_and_app/questions/file1.pdf"
output="/home/user/Desktop/fin_and_app/questions/out.txt"
os.system(("ps2ascii %s %s") %( input , output))
