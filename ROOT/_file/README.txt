;;README.txt --- 
;;
;;Description: 
;;Author: Hongyi Wu(吴鸿毅)
;;Email: wuhongyi@qq.com 
;;Created: 六 5月  2 17:42:14 2015 (+0800)
;;Last-Updated: 六 5月  2 19:26:44 2015 (+0800)
;;          By: Hongyi Wu(吴鸿毅)
;;    Update #: 2
;;URL: http://wuhongyi.cn 

rootcint -f wuDict.cxx -c Hit.hh LinkDef.h

g++ `root-config --cflags --glibs` WriteObject.cc wuDict.cxx -o 123
g++ `root-config --cflags --glibs` readHits.cc  wuDict.cxx -o 456

;;
;;README.txt ends here
