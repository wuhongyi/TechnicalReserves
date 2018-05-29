// reader.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 11月 20 15:47:53 2016 (+0800)
// Last-Updated: 日 11月 20 16:27:14 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 12
// URL: http://wuhongyi.cn 

// g++ reader.cc -ljsoncpp  -o 123
// http://www.cnblogs.com/kex1n/archive/2011/12/02/2272328.html
#include <fstream>
#include <iostream>

#include "jsoncpp/json/json.h"
 
int main()
{
  std::ifstream ifs;
  ifs.open("testjson.json");
 
  Json::Reader reader;
  Json::Value root;
  if (!reader.parse(ifs, root, false))
    {
      return -1;
    }
 
  std::string name;
  int age;
  int size = root.size();


  for (int i=0; i<size; ++i)
    {
      std::cout<<"size: "<<i<<std::endl;
      name = root[i]["name"].asString();
      age = root[i]["age"].asInt();
      
      if(root[i].isMember("location"))
	{
	  std::cout<<root[i]["location"].asString()<<std::endl;
	}
      
      std::cout<<name<<" "<<age<<std::endl;
    }
 
  return 0;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


// Json::Value
//   const char* asCString() const; ///< Embedded zeroes could cause you trouble!
//   std::string asString() const; ///< Embedded zeroes are possible.
//   Int asInt() const;
//   UInt asUInt() const;
//   LargestInt asLargestInt() const;
//   LargestUInt asLargestUInt() const;
//   float asFloat() const;
//   double asDouble() const;
//   bool asBool() const;

//   bool isNull() const;
//   bool isBool() const;
//   bool isInt() const;
//   bool isInt64() const;
//   bool isUInt() const;
//   bool isUInt64() const;
//   bool isIntegral() const;
//   bool isDouble() const;
//   bool isNumeric() const;
//   bool isString() const;
//   bool isArray() const;
//   bool isObject() const;

//   /// Number of values in array or object
//   ArrayIndex size() const;

//   /// \brief Return true if empty array, empty object, or null;
//   /// otherwise, false.
//   bool empty() const;

//   /// Remove all object members and array elements.
//   /// \pre type() is arrayValue, objectValue, or nullValue
//   /// \post type() is unchanged
//   void clear();

//   /// Resize the array to size elements.
//   /// New elements are initialized to null.
//   /// May only be called on nullValue or arrayValue.
//   /// \pre type() is arrayValue or nullValue
//   /// \post type() is arrayValue
//   void resize(ArrayIndex size);

//   /// \brief Remove and return the named member.
//   ///
//   /// Do nothing if it did not exist.
//   /// \return the removed Value, or null.
//   /// \pre type() is objectValue or nullValue
//   /// \post type() is unchanged
//   /// \deprecated
//   Value removeMember(const char* key);
//   /// Same as removeMember(const char*)
//   /// \param key may contain embedded nulls.
//   /// \deprecated
//   Value removeMember(const std::string& key);
//   /// Same as removeMember(const char* begin, const char* end, Value* removed),
//   /// but 'key' is null-terminated.
//   bool removeMember(const char* key, Value* removed);
//   /** \brief Remove the named map member.

//       Update 'removed' iff removed.
//       \param key may contain embedded nulls.
//       \return true iff removed (no exceptions)
//   */
//   bool removeMember(std::string const& key, Value* removed);
//   /// Same as removeMember(std::string const& key, Value* removed)
//   bool removeMember(const char* begin, const char* end, Value* removed);


//   /// Return true if the object has a member named key.
//   /// \note 'key' must be null-terminated.
//   bool isMember(const char* key) const;
//   /// Return true if the object has a member named key.
//   /// \param key may contain embedded nulls.
//   bool isMember(const std::string& key) const;
//   /// Same as isMember(std::string const& key)const
//   bool isMember(const char* begin, const char* end) const;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......









// 
// reader.cc ends here
