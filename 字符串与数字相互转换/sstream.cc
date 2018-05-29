// sstream.cc --- 
// 
// Description: 
// Author: HongyiWu,吴鸿毅
// Email: wuhongyi@qq.com 
// Created: 四 2月 27 16:50:41 2014 (+0800)
// Last-Updated: 六 4月 19 17:03:15 2014 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 3
// URL: http://wuhongyi.cn 

#include<vector>
#include<cstring>
#include<sstream>
#include <iostream>

using namespace std;

int main( ) {
    string real = "12.32 12 35 25.3 36.366";
    stringstream ss( real );
    vector< double > vd;

    // Collect all real numbers.
    double temp;
    while( ss >> temp )
      { vd.push_back( temp );
    	cout<<temp<<endl;}
    // Create the array.
    double *dbl_array = new double[ vd.size( ) ];
    for( int i = 0; i < vd.size( ); ++i )
        dbl_array[ i ] = vd[ i ];
  string a="$12.m";
  cout<<a[0]<<" "<<a[1]<< " "<<a[2]<<" "<<a[3]<<endl;
}
// 
// sstream.cc ends here
