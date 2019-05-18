#!/usr/bin/python3  
#-*-coding:utf-8-*-
# python.py --- 
# 
# Description: 
# Author: Hongyi Wu(吴鸿毅)
# Email: wuhongyi@qq.com 
# Created: 六 5月 18 16:12:31 2019 (+0800)
# Last-Updated: 六 5月 18 16:16:53 2019 (+0800)
#           By: Hongyi Wu(吴鸿毅)
#     Update #: 3
# URL: http://wuhongyi.cn 

from ctypes import *  
import numpy as npimport,codecs
import datetime

SHM_SIZE = 1024*1024*20  
SHM_KEY = 123559  
OUTFILE="httpd_cdorked_config.bin"  
try:  
    rt = CDLL('librt.so')  
except:  
    rt = CDLL('librt.so.1')  
shmget = rt.shmget  
shmget.argtypes = [c_int, c_size_t, c_int]  
shmget.restype = c_int  
shmat = rt.shmat  
shmat.argtypes = [c_int, POINTER(c_void_p), c_int]  
shmat.restype = c_void_p  
begin_time=datetime.datetime.now()     
shmid = shmget(SHM_KEY, SHM_SIZE, 0o666)
if shmid < 0:  
    print ("System not infected")  
else:   
    begin_time=datetime.datetime.now()
    addr = shmat(shmid, None, 0)  
    f=open(OUTFILE, 'wb')
    rate=int.from_bytes(string_at(addr,4), byteorder='little', signed=True)   #这里数据文件是小端int16类型
    len_a=int.from_bytes(string_at(addr+4,4), byteorder='little', signed=True)   
    len_b=int.from_bytes(string_at(addr+8,4), byteorder='little', signed=True)
    print(rate,len_a,len_b)
    f.write(string_at(addr+12,SHM_SIZE))
    f.close()  
#print ("Dumped %d bytes in %s" % (SHM_SIZE, OUTFILE))
print("Success!",datetime.datetime.now()-begin_time)

# 
# python.py ends here
