// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME wuDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "Hit.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *Hit_Dictionary();
   static void Hit_TClassManip(TClass*);
   static void *new_Hit(void *p = 0);
   static void *newArray_Hit(Long_t size, void *p);
   static void delete_Hit(void *p);
   static void deleteArray_Hit(void *p);
   static void destruct_Hit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Hit*)
   {
      ::Hit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Hit));
      static ::ROOT::TGenericClassInfo 
         instance("Hit", "Hit.hh", 15,
                  typeid(::Hit), DefineBehavior(ptr, ptr),
                  &Hit_Dictionary, isa_proxy, 0,
                  sizeof(::Hit) );
      instance.SetNew(&new_Hit);
      instance.SetNewArray(&newArray_Hit);
      instance.SetDelete(&delete_Hit);
      instance.SetDeleteArray(&deleteArray_Hit);
      instance.SetDestructor(&destruct_Hit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Hit*)
   {
      return GenerateInitInstanceLocal((::Hit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Hit*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Hit_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Hit*)0x0)->GetClass();
      Hit_TClassManip(theClass);
   return theClass;
   }

   static void Hit_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_Hit(void *p) {
      return  p ? new(p) ::Hit : new ::Hit;
   }
   static void *newArray_Hit(Long_t nElements, void *p) {
      return p ? new(p) ::Hit[nElements] : new ::Hit[nElements];
   }
   // Wrapper around operator delete
   static void delete_Hit(void *p) {
      delete ((::Hit*)p);
   }
   static void deleteArray_Hit(void *p) {
      delete [] ((::Hit*)p);
   }
   static void destruct_Hit(void *p) {
      typedef ::Hit current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Hit

namespace ROOT {
   static TClass *vectorlEHitmUgR_Dictionary();
   static void vectorlEHitmUgR_TClassManip(TClass*);
   static void *new_vectorlEHitmUgR(void *p = 0);
   static void *newArray_vectorlEHitmUgR(Long_t size, void *p);
   static void delete_vectorlEHitmUgR(void *p);
   static void deleteArray_vectorlEHitmUgR(void *p);
   static void destruct_vectorlEHitmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Hit*>*)
   {
      vector<Hit*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Hit*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Hit*>", -2, "vector", 214,
                  typeid(vector<Hit*>), DefineBehavior(ptr, ptr),
                  &vectorlEHitmUgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<Hit*>) );
      instance.SetNew(&new_vectorlEHitmUgR);
      instance.SetNewArray(&newArray_vectorlEHitmUgR);
      instance.SetDelete(&delete_vectorlEHitmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEHitmUgR);
      instance.SetDestructor(&destruct_vectorlEHitmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Hit*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<Hit*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEHitmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Hit*>*)0x0)->GetClass();
      vectorlEHitmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEHitmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEHitmUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<Hit*> : new vector<Hit*>;
   }
   static void *newArray_vectorlEHitmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<Hit*>[nElements] : new vector<Hit*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEHitmUgR(void *p) {
      delete ((vector<Hit*>*)p);
   }
   static void deleteArray_vectorlEHitmUgR(void *p) {
      delete [] ((vector<Hit*>*)p);
   }
   static void destruct_vectorlEHitmUgR(void *p) {
      typedef vector<Hit*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Hit*>

namespace {
  void TriggerDictionaryInitialization_wuDict_Impl() {
    static const char* headers[] = {
"Hit.hh",
0
    };
    static const char* includePaths[] = {
"/opt/root60304/include",
"/home/wuhongyi/CodeProject/User'sGuide/技术储备/ROOT/root_file/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$LinkDef.h")))  Hit;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$string")))  allocator;
}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "Hit.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Hit", payloadCode, "@",
"vector<Hit*>", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("wuDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_wuDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_wuDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_wuDict() {
  TriggerDictionaryInitialization_wuDict_Impl();
}
