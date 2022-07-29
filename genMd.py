import os
 
path = '/home/doufugan/repos/Basic-algorithm-exercise/src/practices/'
 
files = os.listdir(path)
 
i = 0
 
for file in files:
  with open(path + file) as file_object:
    contents = 
    '''```'''
    contends += file_object.read()
    contends += '''```\n'''
    
